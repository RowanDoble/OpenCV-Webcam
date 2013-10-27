#include <opencv2\opencv.hpp>

using namespace cv;

int main() {
	VideoCapture capture;
	capture.open(0);
	Mat frame;

	namedWindow("WebCam");

	while(true) {
		capture >> frame;
		imshow("WebCam", frame);

		char c = waitKey(10);

		if (c == 27)
			break;
	}
	return 0;
}