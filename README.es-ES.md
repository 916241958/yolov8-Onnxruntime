# yolov8-opencv-onnxruntime-cpp
Implementación de inferencia de detección y segmentación de yolov8 utilizando el framework onnxruntime. Soporta CPU y GPU; actualmente no es compatible con la ejecución asíncrona ni el salto de frames.

## requirements for opencv-dnn
1. > OpenCV>=4.7.0<br>
OpenCV>=4.7.0<br>
OpenCV>=4.7.0<br>

2. export for opencv-dnn:</br>
> ```yolo export model=path/to/model.pt format=onnx dynamic=False  opset=16```</br>

## requirements for onnxruntime （only yolo*_onnx.h/cpp）
>opencv>=4.5.0 </br>
ONNXRuntime>=1.9.0 </br>
