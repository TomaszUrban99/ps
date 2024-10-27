cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_COMPILER g++)
project(poligon CXX)

#add_library(dataPacket src/dataPacket.c)
#target_include_directories(dataPacket PUBLIC inc/)

add_library(fading src/fading.cpp)
target_include_directories(fading PUBLIC inc/)
target_include_directories(fading PUBLIC /home/tomasz/opt/AudioFile-master/*)


add_executable(ps src/main.cpp)
target_include_directories(ps PUBLIC inc/*)
target_include_directories(ps PUBLIC /home/tomasz/opt/AudioFile-master/*)
target_link_libraries(ps fftw3 m fading)
