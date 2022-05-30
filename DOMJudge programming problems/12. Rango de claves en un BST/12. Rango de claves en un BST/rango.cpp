//Marcos Herrero
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include "TreeMap_AVL.h"

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0)return false;

	std::map<int, int> map;
	int clave;
	for (int i = 0; i < N; ++i) {
		std::cin >> clave;
		map.insert({ clave, 0 });
	}
	
	int k1, k2;
	std::cin >> k1 >> k2;

	std::vector<int> lista;
	auto it = map.lower_bound(k1);
	
	while (it != map.end() && it->first <= k2) {
		lista.push_back(it->first);
		++it;
	}
	
	if(lista.size() != 0) std::cout << lista[0];
	for (int i = 1; i < lista.size(); ++i) std::cout <<' '<< lista[i];
    std::cout<<'\n';

	return true;
}

int main() {
	while (resuelveCaso());
}