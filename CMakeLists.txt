cmake_minimum_required(VERSION 2.6)

project(cart_opt)

set(CMAKE_MODULE_PATH ${cart_opt_SOURCE_DIR}/cmake)

find_package(CURL REQUIRED)
find_package(XercesC REQUIRED)
find_package(LibTidy REQUIRED)

if(NOT MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()
