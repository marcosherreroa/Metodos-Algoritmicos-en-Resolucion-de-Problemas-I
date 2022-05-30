//Marcos Herrero

#include <iostream>
#include <vector>
#include <algorithm>

//
//  ConjuntosDisjuntos.h
//
//  Implementación de estructuras de partición o conjuntos disjuntos
//  con unión por tamaño y compresión de caminos
//
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2015-2019  Alberto Verdejo
//

#ifndef CONJUNTOSDISJUNTOS_H_
#define CONJUNTOSDISJUNTOS_H_

#include <vector>
#include <iostream>

class ConjuntosDisjuntos {
public:

	// crea una estructura de partición con los elementos 0..N-1, cada uno en un conjunto
	ConjuntosDisjuntos(int N) : nelems(N), /*ncjtos(nelems),*/ id(nelems, -1) {}

	// devuelve el número de conjuntos disjuntos
	//int num_cjtos() const { return ncjtos; }

	//  devuelve el identificador del conjunto que contiene a p
	int buscar(int p) const {
		if (id.at(p) < 0) // es una raíz
			return p;
		else
			return id[p] = buscar(id[p]);
	}

	// unir los conjuntos que contengan a p y q
	void unir(int p, int q) {
		auto i = buscar(p);
		auto j = buscar(q);
		if (i == j) return;
		if (id[i] < id[j]) { // i es la raíz del mayor árbol
			id[i] += id[j]; id[j] = int(i);
		}
		else {
			id[j] += id[i]; id[i] = int(j);
		}
		//--ncjtos;
	}

	int tam(int p) const {
		return -id[buscar(p)];
	}

	bool unidos(int p, int q) const {
		return buscar(p) == buscar(q);
	}

protected:
	int nelems;           // los elementos son 0 .. nelems-1
	//int ncjtos;           // número de conjuntos disjuntos
	mutable std::vector<int> id;  // si id[i]>=0 es el padre de i, si no es el tamaño del conjunto de i

};


#endif

void DFS(char mapa[], ConjuntosDisjuntos & conexas, int orig, int & F, int & C) {
	mapa[orig] = '$';

	if (orig - C >= 0) {
		if (mapa[orig - C] == '#') {
			conexas.unir(orig, orig - C);
			DFS(mapa, conexas, orig - C, F, C);
		}
		if (orig % C != 0 && mapa[orig - C - 1] == '#') {
			conexas.unir(orig, orig - C - 1);
			DFS(mapa, conexas, orig - C - 1, F, C);
		}
		if ((orig + 1) % C != 0 && mapa[orig - C + 1] == '#') {
			conexas.unir(orig, orig - C + 1);
			DFS(mapa, conexas, orig - C + 1, F, C);
		}
	}

	if (orig % C != 0 && mapa[orig - 1] == '#') {
		conexas.unir(orig, orig - 1);
		DFS(mapa, conexas, orig - 1, F, C);
	}
	if ((orig + 1) % C != 0 && mapa[orig + 1] == '#') {
		conexas.unir(orig, orig + 1);
		DFS(mapa, conexas, orig + 1, F, C);
	}

	if (orig + C < F*C) {
		if (mapa[orig + C] == '#') {
			conexas.unir(orig, orig + C);
			DFS(mapa, conexas, orig + C, F, C);
		}
		if (orig % C != 0 && mapa[orig + C - 1] == '#') {
			conexas.unir(orig, orig + C - 1);
			DFS(mapa, conexas, orig + C - 1, F, C);
		}
		if ((orig + 1) % C != 0 && mapa[orig + C + 1] == '#') {
			conexas.unir(orig, orig + C + 1);
			DFS(mapa, conexas, orig + C + 1, F, C);
		}
	}

}

void unificar(char mapa[], ConjuntosDisjuntos & conexas, int orig, int F, int C) {
	if (orig - C >= 0) {
		if (mapa[orig - C] == '$') {
			conexas.unir(orig, orig - C);
		}
		if (orig % C != 0 && mapa[orig - C - 1] == '$') {
			conexas.unir(orig, orig - C - 1);
		}
		if ((orig + 1) % C != 0 && mapa[orig - C + 1] == '$') {
			conexas.unir(orig, orig - C + 1);
		}
	}

	if (orig % C != 0 && mapa[orig - 1] == '$') {
		conexas.unir(orig, orig - 1);
	}

	if ((orig + 1) % C != 0 && mapa[orig + 1] == '$') {
		conexas.unir(orig, orig + 1);
	}

	if (orig + C < F*C) {
		if (mapa[orig + C] == '$') {
			conexas.unir(orig, orig + C);
		}
		if (orig % C != 0 && mapa[orig + C - 1] == '$') {
			conexas.unir(orig, orig + C - 1);
		}
		if ((orig + 1) % C != 0 && mapa[orig + C + 1] == '$') {
			conexas.unir(orig, orig + C + 1);
		}
	}
}


bool resuelveCaso() {
	int F, C;
	std::cin >> F >> C;
	if (!std::cin)return false;

	int M = F * C;
	//std::vector<char> mapa(M, ' '); // true es que hay petroleo
	char mapa[1000000];

	std::cin.ignore(1);
	for (int i = 0; i < F; ++i) {
		for (int j = 0; j < C; ++j) std::cin.get(mapa[C*i + j]);
		std::cin.ignore(1);
	}

	ConjuntosDisjuntos conexas(M);

	for (int i = 0; i < M; ++i) {
		if (mapa[i] == '#') DFS(mapa, conexas, i, F, C);
	}

	int N;
	std::cin >> N;
	int sol = 0;
	for (int i = 0; i < M; ++i) {
		if (mapa[i] == '$' && conexas.tam(i) > sol) sol = conexas.tam(i);
	}

	std::cout << sol;

	int x, y;
	for (int i = 0; i < N; ++i) {
		std::cin >> x >> y;
		int p = C * (x - 1) + y - 1;

		if (mapa[p] == ' ') {
			mapa[p] = '$';
			unificar(mapa, conexas, p, F, C);
		}

		sol = std::max(sol,conexas.tam(p));
		std::cout << ' ' << sol;
	}

	std::cout << '\n';

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
	return 0;
}