#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>

#include <Eigen/Dense>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgcodecs.hpp>

int main(int argc, char ** argv) {
	clock_t t = clock();

	if (argc == 3) {
		std::string path = argv[1];
		std::string cmd = "bash numfiles " + path;
		system(cmd.c_str());
		std::ifstream input("number.txt");
		if(input.is_open()) {
			int numpics, rows = 20, cols = 30;
			input >> numpics;
			Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> datamat(numpics, rows * cols);
			system("rm -f number.txt");
			std::stringstream sstr;
			std::string style = argv[2];
			cv::Mat img, resz;
			cv::namedWindow("Display", 1);
			for (unsigned i = 0; i < numpics; i++) {
				sstr.str(std::string());
				sstr.clear();
				sstr << path << "/" << style << i << ".jpg";
				std::cout << sstr.str() << "\n";
				img = cv::imread(sstr.str(), CV_LOAD_IMAGE_GRAYSCALE);
				cv::resize(img, resz, cv::Size(cols, rows));
				cv::imshow("Display", resz);
				std::vector<uchar> datavec;
				for (unsigned j = 0; j < datavec.size(); j++) {
					std::cout << datavec[j] << " " << std::flush;
				}
				std::cout << "\n";
				if (cv::waitKey(1000) != -1) {
					break;
				}
			}
		}
		else {
			std::cout << "Failed to find Number of Files --Terminating" << "\n";
		}
	}
	else {
		std::cout << "Invalid Number of Argument --Terminating" << "\n";
	}

	t = clock() - t;
	std::cout << "Time Elapsed | " << static_cast<double>(t) / CLOCKS_PER_SEC << "\n";
	return 0;
}
