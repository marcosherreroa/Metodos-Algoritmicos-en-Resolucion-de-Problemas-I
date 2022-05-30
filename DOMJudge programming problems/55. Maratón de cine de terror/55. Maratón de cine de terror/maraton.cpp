//Marcos Herrero
#include <iostream>
#include <vector>
#include <algorithm>

struct pelic {
	int ini;
	int fin;

	bool operator<(pelic const & that)const {
		if (fin < that.fin)return true;
		else if (fin == that.fin && ini > that.ini)return true;
		else return false;
	}
};

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0)return false;

	std::vector<pelic> v(N);
	int hora, min, dur; char aux;
	for (int i = 0; i < N; ++i) {
		std::cin >> hora >>aux >> min;
		v[i].ini = 60*hora + min;
		std::cin >> dur;
		v[i].fin = v[i].ini + dur;
	}

	std::sort(v.begin(), v.end());

	int i = 0, cont = 0;
	while (i < N) {
		pelic actual = v[i];
		while (i < N - 1 && v[i + 1].ini < actual.fin + 10)++i;

		++cont;
		++i;
	}

	std::cout << cont << '\n';

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}