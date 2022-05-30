//Marcos Herrero

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct evento {
	int cuando;
	bool empieza;

	bool operator<(evento const & that)const {
		if (cuando < that.cuando) return true;
		else if (cuando == that.cuando && !empieza && that.empieza) return true;
		else return false;
	}
};

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N==0)return false;

	std::vector<int> c(N), f(N);
	for (int i = 0; i < N; ++i) std::cin >> c[i] >> f[i];


	std::sort(c.begin(), c.end());
	std::sort(f.begin(), f.end());

	int maxInter = 1, i = 0, j= 0, inter= 0;
	
	while (i < N && j <N) {

		while (i < N && c[i] < f[j]) {
			++i;
			++inter;
			if (inter > maxInter)maxInter = inter;
		}

		while (i <N && j < N && f[j] <= c[i]) {
			++j;
			--inter;
		}
	}


	std::cout << maxInter-1<< '\n';

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
	return 0;
}