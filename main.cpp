#include <iostream>
#include<opencv2/opencv.hpp>

#include<cmath>
#include "include/yolov8_onnx.h"

template<typename _Tp>
int yolov8_onnx(_Tp& cls, cv::Mat& img)
{
	std::vector<cv::Scalar> color;
	srand(0);
	for (int i = 0; i < 80; i++) {
		int b = rand() % 256;
		int g = rand() % 256;
		int r = rand() % 256;
		color.push_back(cv::Scalar(b, g, r));
	}
	std::vector<OutputSeg> result;
	if (cls.OnnxDetect(img, result)) {
		DrawPred(img, result, cls._className, color);
	}
	else {
		std::cout << "Detect Failed!" << std::endl;
	}
	// system("pause");
	return 0;
}

int main() {

	std::string detect_model_path = "/home/yjam/CLionProjects/yolov8_onnx_cpp-main/models/yolov8n.onnx";
	Yolov8Onnx task_detect_onnx;
	task_detect_onnx.ReadModel(detect_model_path, true);
	cv::VideoCapture cap;
	cap.open("rtsp://admin:pwd@ip");
	cv::Mat frame;
	if (!cap.isOpened()){
		std::cout<<"Error open camera"<<std::endl;
	}
	while (true)
	{
		int64 start = cv::getTickCount();
		cap.read(frame);
		yolov8_onnx(task_detect_onnx, frame);
		double fps = cv::getTickFrequency() / (cv::getTickCount() - start);
		std::cout<<"fps: "<< fps<<std::endl;
		cv::imshow("image", frame);
		cv::waitKey(1);
	}
	
	return 0;
}


