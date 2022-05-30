//Marcos Herrero

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

void cubrimientoOptimo(std::vector<int> & c,int N,  int k, std::vector<int> & cubrimiento) {
    int sumakanteriores = 0;

	for (int i = 0; i < k-1 && i < N - k; ++i) {
		cubrimiento[i] = std::max(0, c[i] - sumakanteriores);
		sumakanteriores += c[i];
	}

	for (int i = k-1; i < N - k; ++i) {
		cubrimiento[i] = std::max(0, c[i] -sumakanteriores);
		sumakanteriores += (c[i] - c[i-k+1]);
	}

	int max = 0;
	for (int i = N - k; i < N; ++i) {
		if (c[i]- sumakanteriores > max)max = c[i] - sumakanteriores;
		if (i >= k-1) sumakanteriores -= c[i - k+1];
	}

	cubrimiento[N - k] = max;

}

bool resuelveCaso() {
	int N, k;
	std::cin >> N >> k;
	if (N == 0 || k == 0) return false;

	std::vector<int> c(N);
	for (int i = 0; i < N; ++i) std::cin >> c[i];
	
	std::vector<int> cubrimiento(N - k + 1);
	cubrimientoOptimo(c, N, k, cubrimiento);

	for (int i = 0; i < N - k + 1; ++i)std::cout << cubrimiento[i] << ' ';
	std::cout << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
}