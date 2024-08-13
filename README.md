# yolov8-opencv-onnxruntime-cpp
使用onnxruntime框架实现yolov8的检测和分割推理，支持CPU和GPU，目前不支持异步执行和跳帧

## requirements for opencv-dnn
1. > OpenCV>=4.7.0<br>
OpenCV>=4.7.0<br>
OpenCV>=4.7.0<br>

2. export for opencv-dnn:</br>
> ```yolo export model=path/to/model.pt format=onnx dynamic=False  opset=12```</br>

## requirements for onnxruntime （only yolo*_onnx.h/cpp）
>opencv>=4.5.0 </br>
ONNXRuntime>=1.9.0 </br>