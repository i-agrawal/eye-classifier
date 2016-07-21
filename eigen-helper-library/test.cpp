#include "helper.h"
#include <iostream>

int main() {
	Mat vals(1, 5);
	vals << -1, -0.5, 0, 0.5, 1;
	std::cout << "[ Testing Double + Matrix ]" << std::endl;
	std::cout << 1 + vals << std::endl << std::endl;
	std::cout << "[ Testing Matrix + Double ]" << std::endl;
	std::cout << vals + 1 << std::endl << std::endl;
	std::cout << "[ Testing Matrix - Double ]" << std::endl;
	std::cout << vals - 1 << std::endl << std::endl;
	std::cout << "[ Testing Double - Matrix ]" << std::endl;
	std::cout << 1 - vals << std::endl << std::endl;
	std::cout << "[ Testing Double / Matrix ]" << std::endl;
	std::cout << 1 / vals << std::endl << std::endl;
	std::cout << "[ Testing e ^ Matrix ]" << std::endl;
	std::cout << exp(vals) << std::endl << std::endl;
	std::cout << "[ Testing Matrix ^ 2 ]" << std::endl;
	std::cout << pow(vals, 2) << std::endl << std::endl;
	std::cout << "[ Testing 2 ^ Matrix ]" << std::endl;
	std::cout << pow(2, vals) << std::endl << std::endl;
	std::cout << "[ Testing Log Matrix ]" << std::endl;
	std::cout << log(vals) << std::endl << std::endl;
	std::cout << "[ Testing Sigmoid Matrix ]" << std::endl;
	std::cout << mult(vals, vals) << std::endl << std::endl;
	std::cout << "[ Testing Sigmoid Matrix ]" << std::endl;
	std::cout << div(vals, vals) << std::endl << std::endl;

	return 0;
}
