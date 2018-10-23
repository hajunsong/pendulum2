#include <iostream>
#include "pendulum.h"

int main() {
	//uint num_body = 6;
	for (uint num_body = 1; num_body <= 6; num_body++) {
		Pendulum *pendulum = new Pendulum(num_body);
		pendulum->run();
		delete pendulum;
	}

	system("pause");
	return 0;
}