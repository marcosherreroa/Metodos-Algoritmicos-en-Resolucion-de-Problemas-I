//Marcos Herrero

#include <iostream>
#include <queue>
#include "GrafoValorado.h"
#include "ConjuntosDisjuntos.h"

bool operator<(Arista<int> const & a1, Arista<int> const & a2) {
	return a1.valor()> a2.valor();
}

bool resuelveCaso() {
	int V, E;
	std::cin >> V >> E;
	if (!std::cin)return false;

	GrafoValorado<int> G(V); 
	std::priority_queue<Arista<int>> pq;
	ConjuntosDisjuntos conexas(V);
	int u, v, coste;
	for (int i = 0; i < E; ++i) {
		std::cin >> u >> v >> coste;
		Arista<int> a(u-1, v-1, coste);
		pq.push(a);
		G.ponArista(a);
	}

	int aristas = 0, costeMinimo = 0;
	while (!pq.empty() && aristas < G.V() - 1) {
		int u = pq.top().uno(), v = pq.top().otro(u);
		if (!conexas.unidos(u, v)) {
			conexas.unir(u, v);
			++aristas;
			costeMinimo += pq.top().valor();
		}

		pq.pop();
	}

	if (aristas == G.V() - 1)std::cout << costeMinimo << '\n';
	else std::cout << "No hay puentes suficientes\n";

	return true;
}

int main() {
	while (resuelveCaso());
}

