#include <iostream>
#include <stdlib.h>
#include <time.h>

void random_bernoulli_coin() {
	double probability;
	std::cin >> probability;
	srand(time(NULL));
	for(int i = 0; i < 10; i++) {
		double random = (double)rand() / RAND_MAX;
		if (random <= probability) {
			std::cout << "1" << std::endl;
		}
		else {
			std::cout << "0" << std::endl;
		}
	}
}