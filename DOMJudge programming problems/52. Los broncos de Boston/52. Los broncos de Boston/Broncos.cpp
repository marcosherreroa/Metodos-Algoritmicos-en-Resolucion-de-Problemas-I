//Marcos Herrero
#include <iostream>
#include <vector>
#include <algorithm>

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0)return false;

	std::vector<int> vRivales(N), vBroncos(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> vRivales[i];
	}

	for (int i = 0; i < N; ++i) {
		std::cin >> vBroncos[i];
	}

	std::sort(vRivales.begin(), vRivales.end());
	std::sort(vBroncos.begin(), vBroncos.end(), std::greater<int>());

	int dif = 0;
	for (int i = 0; i < N && vRivales[i] < vBroncos[i]; ++i) dif += (vBroncos[i] - vRivales[i]);

	std::cout << dif << '\n';
	return true;
}

int main() {
	while (resuelveCaso());
}