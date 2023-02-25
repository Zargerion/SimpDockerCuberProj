FROM alpine:latest

RUN apk update \
    && apk update

RUN apk add g++ git wget python3 zip curl bison bash cmake asio-dev make
RUN wget -O opencv.zip https://github.com/opencv/opencv/archive/4.x.zip
RUN bash -c "unzip opencv.zip"
RUN bash -c "mkdir -p build && cd build"
RUN bash -c "cmake  ../opencv-4.x"
RUN bash -c "cmake --build ."

COPY . /wndth

WORKDIR /wndth

RUN cd /wndth && rm cmake_install.cmake && rm CMakeCache.txt && rm Makefile && cmake . && cmake --build .

CMD ["./app"]