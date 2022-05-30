//Marcos Herrero
#include <iostream>
#include <vector>
#include <algorithm>

void resuelveCaso() {
	int N, V;
	std::cin >> N >> V;
	std::vector<int> pilas(N);
	for (int i = 0; i < N; ++i) std::cin >> pilas[i];

	std::sort(pilas.begin(), pilas.end());
	int i = 0, j = N - 1;
	int sol = 0;
	while (i < j) {
		if (pilas[i] + pilas[j] >= V) {
			++sol;
			++i;
			--j;
		}
		else ++i;
	}

	std::cout << sol << '\n';
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}