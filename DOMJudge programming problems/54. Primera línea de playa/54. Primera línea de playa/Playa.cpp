//Marcos Herrero
#include <iostream>
#include <vector>
#include <algorithm>

struct interv {
	int ini;
	int fin;

	bool operator<(interv const & that)const {
		return fin < that.fin;
	}
};

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0)return false;


	std::vector<interv> edif(N);
	int ini, fin;
	for (int i = 0; i < N; ++i) {
		std::cin >> ini >> fin;
		edif[i] = { ini, fin };
	}

	std::sort(edif.begin(), edif.end());

	std::vector<bool> comuni(N, false);
	int sol = 0;
	for (int i = 0; i < N; ++i) {
		if (!comuni[i]) {
			for (int j = i+1; j < N && edif[j].ini < edif[i].fin; ++j) comuni[j] = true;
			comuni[i] = true;
			++sol;
		}
	}

	std::cout << sol << '\n';

	return true;
}


int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}