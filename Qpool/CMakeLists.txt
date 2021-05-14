cmake_minimum_required(VERSION 3.19)
project(Qpool)

set(CMAKE_CXX_STANDARD 14)

add_executable(Qpool main.cpp Qpool.h TaskQueue.cpp TaskQueue.h Task.cpp Task.h ThreadPool.cpp ThreadPool.h)