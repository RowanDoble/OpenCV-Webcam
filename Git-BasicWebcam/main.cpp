#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;

int main() {
	VideoCapture capture;
	capture.open(0);
	Mat frame;
	bool flipped = false;

	std::cout << "Press m to toggle image horizontal flip" << std::endl;

	namedWindow("WebCam");

	while(true) {
		capture >> frame;

		if (flipped)
			flip(frame, frame, 1);

		imshow("WebCam", frame);

		char c = waitKey(10);

		if (c == 'm') {
			flipped = !flipped;
			string s = (flipped) ? "Flip on" : "Flip off";
			std::cout << s << std::endl;
		}

		if (c == 27)
			break;
	}
	return 0;
}