cmake_minimum_required(VERSION 2.6)

project(cart_opt)

set(CMAKE_MODULE_PATH ${cart_opt_SOURCE_DIR}/cmake)

find_package(Boost REQUIRED)
find_package(CURL REQUIRED)
find_package(LibTidy REQUIRED)

SET(PUGIXML_DIR "libs/pugixml/src")

if(NOT MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -pedantic -pedantic-errors")
endif()

include_directories(
	"include" 
	"${PUGIXML_DIR}"
	"${Boost_INCLUDE_DIRS}"
	"${CURL_INCLUDE_DIRS}"
	"${LIBTIDY_INCLUDE_DIRS}"
)

add_executable(sandbox test/sandbox.cpp src/curl.cpp src/skapiec_scraper.cpp src/tidy.cpp "${PUGIXML_DIR}/pugixml.cpp")
target_link_libraries(sandbox "${CURL_LIBRARIES}" boost_system boost_filesystem)
