cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 17)
project(exp4)

set(OpenCV_DIR "/Users/rodion/Documents/opencv_cpp/build_opencv")
find_package(OpenCV REQUIRED)
find_package(Iconv REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

include_directories("./")

add_executable(exp4 main.cpp utils/constants.h core/trackers/medianflow.cpp core/trackers/medianflow.h core/trackers/kcf.cpp core/trackers/kcf.h core/tracker.h utils/tracker_type.h utils/tracker_creator.h core/result_structures/tracking_result.cpp core/result_structures/tracking_result.h core/result_structures/correction_controller.cpp core/result_structures/correction_controller.h core/trackers/core_utils/core_utils.h)

target_link_libraries(exp4 ${OpenCV_LIBRARIES})