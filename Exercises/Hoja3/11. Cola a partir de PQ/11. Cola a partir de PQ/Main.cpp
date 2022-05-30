//Marcos Herrero
#include <iostream>
#include "queuet.h"

int main() {
	queuet q;
	int v;
	for (int i = 0; i < 6; ++i) {
		std::cin >> v;
		q.push(v);
	}

	for (int i = 0; i < 6; ++i) {
		std::cout << q.front();
		q.pop();
	}

	system("PAUSE");
}