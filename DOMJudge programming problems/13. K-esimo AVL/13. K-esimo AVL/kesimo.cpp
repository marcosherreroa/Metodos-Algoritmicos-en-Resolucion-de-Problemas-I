//Marcos Herrero

#include <iostream>
#include <vector>
#include "TreeMap_AVL.h"

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0)return false;

	map<int, int> tree;
	int clave;
	for (int i = 0; i < N; ++i) {
		std::cin >> clave;
		tree.insert({ clave,0 });
	}

	int M; 
	std::cin >> M;
	std::vector<int> pos(M);
    for (int i = 0; i < M; ++i) std::cin >> pos[i];

	for (int i = 0; i < M; ++i) {
		try {
			std::cout << tree.kesimoMenor(pos[i]).clave << '\n';
		}
		catch (std::out_of_range) {
			std::cout << "??\n";
		}
	}
	std::cout << "---\n";

	return true;
}

int main() {
	while (resuelveCaso());
}