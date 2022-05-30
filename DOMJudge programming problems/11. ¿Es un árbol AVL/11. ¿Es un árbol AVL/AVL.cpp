//Marcos Herrero
#include <iostream>
#include <algorithm>
#include "bintree_eda.h"

struct Sol {
	int altura;
	int min;    //-1 indica que no existe
    int max;
	bool avl;
};

Sol AVL(bintree<int> const & tree) { 
	if (tree.empty()) return{ 0, -1, -1, true };
	else {
		Sol izq = AVL(tree.left());
		Sol dch = AVL(tree.right());

		int altura = 1 + std::max(izq.altura, dch.altura);
		int max = std::max(tree.root(), std::max(izq.max, dch.max));

		int min;
		if (izq.min == -1 && dch.min == -1) min = tree.root();
		else if (izq.min == -1) min = std::min(tree.root(), dch.min);
		else if (dch.min == -1) min = std::min(tree.root(), izq.min);
		else min = std::min(tree.root(), std::min(izq.min, dch.min));
        
		
		bool avl = izq.avl && dch.avl && abs(izq.altura - dch.altura) <= 1;
		if (izq.max != -1) avl = avl && izq.max < tree.root();
		if (dch.min != -1) avl = avl && dch.min > tree.root();
		return { altura, min, max, avl };
	}
}

void resuelveCaso() {
	bintree<int> tree = leerArbol(-1);
	if (AVL(tree).avl) std::cout << "SI\n";
	else std::cout << "NO\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}