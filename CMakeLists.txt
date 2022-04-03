cmake_minimum_required(VERSION 3.21)
project(Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project main.cpp courier.cpp courier.h order.cpp order.h defs.h load.cpp load.h manageOrders.cpp manageOrders.h)
