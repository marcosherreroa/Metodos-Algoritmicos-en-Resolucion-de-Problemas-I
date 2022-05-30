//Marcos Herrero
#include <iostream>
#include <vector>
#include <algorithm>


int minima(std::vector<int> & alturas, std::vector<int> & longit, int N) {
	std::sort(alturas.begin(), alturas.end());
	std::sort(longit.begin(), longit.end());

	int suma = 0;
	for (int i = 0; i < N; ++i) suma += abs(alturas[i] - longit[i]);
	return suma;
}

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0) return false;

	std::vector<int> alturas(N);
	std::vector<int> longit(N);
	for (int i = 0; i < N; ++i)std::cin >> alturas[i];
	for (int i = 0; i < N; ++i) std::cin >> longit[i];

	std::vector<bool> marcaje(N, false);
	int csup = 0;
	for (int i = 0; i < N; ++i)csup += abs(alturas[i] - longit[i]);

	std::cout << minima(alturas, longit, N) << '\n';
	return true;
}

int main() {
	while (resuelveCaso());
}