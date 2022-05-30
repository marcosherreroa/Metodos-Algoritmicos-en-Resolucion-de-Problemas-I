//Marcos Herrero
#include <iostream>
#include <algorithm>
#include "bintree_eda.h"

struct Sol {
	int altura;
	bool eq;
};

Sol equilibrado(bintree<char> const & tree) {
	if (tree.empty()) return{ 0, true };
	else {
		Sol izq = equilibrado(tree.left());
		Sol dch = equilibrado(tree.right());

		int altura = 1 + std::max(izq.altura, dch.altura);
		bool eq = izq.eq && dch.eq && abs(izq.altura - dch.altura) <= 1;
		return { altura, eq };
	}
}

void resuelveCaso() {
	bintree<char> tree = leerArbol('.');
	if (equilibrado(tree).eq) std::cout << "SI\n";
	else std::cout << "NO\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}