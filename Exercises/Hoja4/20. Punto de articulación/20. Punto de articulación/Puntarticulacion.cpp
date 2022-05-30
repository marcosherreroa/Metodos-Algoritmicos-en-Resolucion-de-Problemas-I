//Marcos Herrero
#include <iostream>
#include <vector>
#include <queue>
#include "Grafo.h"


void DFS(Grafo const & G, int v, std::vector<bool> & marcados) {
	for (int w : G.ady(v)) {
		if (!marcados[w]) {
			marcados[w] = true;
			DFS(G, w, marcados);
		}
	}
}

bool puntoDeArticulacion(Grafo const & G, int v)  {
	if (v > G.V() || G.ady(v).empty()) return false;

	std::vector<bool> marcados(G.V(), false);
	marcados[v] = true;
	DFS(G, G.ady(v)[0], marcados);

	bool pArt = false;
	for (int i = 1; !pArt && i < G.ady(v).size(); ++i) {
		if (!marcados[G.ady(v)[i]]) pArt = true;
	}

	//Coste E
	
	return pArt;
}

bool resuelveCaso() {
	int V, E;
	std::cin >> V >> E;
	if (V == 0)return false;

	Grafo G(V);

	int a, b;
	for (int i = 0; i < E; ++i) {
		std::cin >> a >> b;
		G.ponArista(a, b);
	}

	int v;
	std::cin >> v;

	if (puntoDeArticulacion(G,v)) std::cout << "SI\n";
	else std::cout << "NO\n";

	return true;
}

int main() {
	while (resuelveCaso());
}