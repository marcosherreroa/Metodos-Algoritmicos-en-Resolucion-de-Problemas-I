//Marcos Herrero
#include <iostream>
#include <vector>
#include <queue>

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0)return false;

	std::priority_queue<long long int,std::vector<long long int>, std::greater<long long int>> cola;
	int num;
	for (int i = 0; i < N; ++i) {
		std::cin >> num;
		cola.push(num);
	}

	long long int esfuerzo = 0, suma;
	while (!cola.empty()) {
		suma = cola.top();
		cola.pop();

		if (!cola.empty()) {
			suma += cola.top();
			cola.pop();
			cola.push(suma);
			esfuerzo += suma;
		}
	}

	std::cout << esfuerzo << '\n';
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}