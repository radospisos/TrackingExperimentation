cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 17)
project(exp4)

file(GLOB_RECURSE core_src "core/*.cpp")
file(GLOB_RECURSE core_hdr "core/*.h")
file(GLOB_RECURSE utils_hdr "utils/*.h")
file(GLOB_RECURSE unit_tests "tests/*.cpp")
file(GLOB main "demo.cpp")

set(OpenCV_DIR "/Users/rodion/Documents/opencv_cpp/build_opencv")
find_package(OpenCV REQUIRED)
find_package(Iconv REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories("./")

add_executable(Main ${core_src} ${core_hdr} ${utils_hdr} ${main} core/trackers/core_utils/errors.h)

include(GoogleTest)
find_package(GTest REQUIRED)
include_directories(${GMOCK_INCLUDE_DIR})

add_executable(Tests ${unit_tests} ${core_src} ${core_hdr} ${utils_hdr})
set(GMOCK_L "/Users/rodion/Downloads/googletest/googlemock/include/gmock/")
target_link_libraries(Tests GTest::GTest GTest::Main /usr/local/lib/libgmock.a /usr/local/lib/libgmock_main.a)
target_link_libraries(Tests ${OpenCV_LIBRARIES})

target_link_libraries(Main ${OpenCV_LIBRARIES})
gtest_discover_tests(Tests)