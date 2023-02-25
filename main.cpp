#include "header.h"
#include <opencv2/core/ocl.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <string>

#define CROW_MAIN
//#include "crow_all.h"

int main()
{   
    cv::UMat img, gray;

    imread("static/img.png", cv::IMREAD_COLOR).copyTo(img);

    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(gray, gray, cv::Size(7, 7), 1.5);
    cv::Canny(gray, gray, 0, 50);

    try {
        cv::imwrite("static/imgProcessed.png", gray);

    } 
    catch(const cv::Exception& e) {
        fprintf(stderr, "e occured converting to...: %s\n", e.what());
    }

    crow::SimpleApp app; //define your crow application

    //define your endpoint at the root directory
    CROW_ROUTE(app, "/")([](){
        return "Change URL on /<random string>";
    });
    
    CROW_ROUTE(app, "/<string>")([](std::string name){
        auto page = crow::mustache::load("index.html");
        crow::mustache::context ctx({{"qweqweqwe", name}});
        return page.render(ctx);
    });
    

    //set the port, set the app to run on multiple threads, and run the app
    app.port(80).multithreaded().run();
}