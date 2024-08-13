# yolov8-Onnxruntime
通过onnxruntime实现yolov8在CPU和GPU上面部署
## 版本
onnxruntime==1.11.1
opencv==4.x
## 注意
在使用yolov8导出onnx模型的时候要设置opset为16，防止出现onnx读取模型失败（版本冲突），具体的版本对接可以看--<https://blog.csdn.net/x1131230123/article/details/120422132>
