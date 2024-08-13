CMAKE_MINIMUM_REQUIRED(VERSION 3.6.0)
project(YOLOv8)


SET (ONNXRUNTIME_DIR "/home/yjam/下载/gitClone/onnxruntime")
FIND_PACKAGE(OpenCV REQUIRED)
#include_directories("")
ADD_EXECUTABLE(YOLOv8 include/yolov8.h include/yolov8_onnx.h include/yolov8_seg.h include/yolov8_seg_onnx.h include/yolov8_utils.h
			 main.cpp include/yolov8.cpp include/yolov8_onnx.cpp include/yolov8_seg.cpp include/yolov8_seg_onnx.cpp include/yolov8_utils.cpp)

SET(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

TARGET_INCLUDE_DIRECTORIES(YOLOv8 PRIVATE "${ONNXRUNTIME_DIR}/include")

TARGET_COMPILE_FEATURES(YOLOv8 PRIVATE cxx_std_14)
TARGET_LINK_LIBRARIES(YOLOv8 ${OpenCV_LIBS})


if (WIN32)
    TARGET_LINK_LIBRARIES(YOLOv8 "${ONNXRUNTIME_DIR}/lib/onnxruntime.lib")
endif(WIN32)

if (UNIX)
    TARGET_LINK_LIBRARIES(YOLOv8 "${ONNXRUNTIME_DIR}/build/Linux/Release/libonnxruntime.so")
endif(UNIX)