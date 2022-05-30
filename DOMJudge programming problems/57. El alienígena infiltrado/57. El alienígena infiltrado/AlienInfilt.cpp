//Marcos Herrero
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct intervalo {
	int c;
	int f;

	bool operator<(intervalo const & that)const {
		if (c < that.c)return true;
		else if (c == that.c && f > that.f) return true;
		else return false;
	}
};

bool resuelveCaso() {
	int C, F, N;
	std::cin >> C >> F >> N;
	if (C == 0 && F == 0 && N == 0)return false;

	std::vector<intervalo> v;
	int c, f;
	for (int i = 0; i < N; ++i) {
		std::cin >> c >> f;
		v.push_back({ c, f });
	}

	std::sort(v.begin(), v.end());

	int cubierto = C, i = 0 , sol = 0;
	while (cubierto < F && i < N && v[i].c <= cubierto) {
		int finMejor = v[i].f;
		while (i < N-1 && v[i + 1].c <= cubierto) {
			++i;
			if (v[i].f > finMejor) finMejor = v[i].f;
		}

		cubierto = finMejor;
		++sol;
		++i;
	}


	if (cubierto < F)std::cout << "Imposible\n";
	else std::cout << sol << '\n';

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}