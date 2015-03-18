cmake_minimum_required(VERSION 2.6)

project(cart_opt)

set(CMAKE_MODULE_PATH ${cart_opt_SOURCE_DIR}/cmake)

find_package(Boost REQUIRED)
find_package(CURL REQUIRED)
find_package(XercesC REQUIRED)
find_package(LibTidy REQUIRED)

if(NOT MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

include_directories(
	"include" 
	"${Boost_INCLUDE_DIRS}"
	"${CURL_INCLUDE_DIRS}"
	"${XercesC_INCLUDE_DIRS}"
	"${LIBTIDY_INCLUDE_DIRS}"
)

add_executable(sandbox test/sandbox.cpp src/curl.cpp)
target_link_libraries(sandbox "${CURL_LIBRARIES}" boost_system boost_filesystem)
