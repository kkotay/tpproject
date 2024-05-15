FROM ubuntu:22.04 AS build
RUN apt-get update
RUN apt-get install -y g++ make cmake
RUN apt-get install -y libsfml-dev
RUN apt-get install -y libx11-dev
RUN apt-get install -y x11-xserver-utils
RUN export DISPLAY=localhost:0.0
COPY . .
RUN ./run.sh runned
