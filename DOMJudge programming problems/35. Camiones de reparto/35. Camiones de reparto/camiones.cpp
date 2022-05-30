//Marcos Herrero

#include <iostream>
#include "GrafoValorado.h"

bool DFS(GrafoValorado<int> const & G, int origen, int destino, std::vector<bool> & visitados, int anchura) {
	bool encontrado = false;

	for (int i = 0; !encontrado && i < G.ady(origen).size(); ++i) {
		int vert = G.ady(origen)[i].otro(origen), anchMax = G.ady(origen)[i].valor();

		if (!visitados[vert] && anchura <= anchMax) {
			visitados[vert] = true;
			if (vert == destino)encontrado = true;
			else encontrado = DFS(G, vert, destino, visitados, anchura);
		}
	}

	return encontrado;
}


bool resuelveCaso() {
	int V, E;
	std::cin >> V >> E;
	if (!std::cin)return false;

	GrafoValorado<int> G(V);
	int e1, e2, a;
	for (int i = 0; i < E; ++i) {
		std::cin >> e1 >> e2 >> a;
		G.ponArista(Arista<int>(e1-1, e2-1, a));
	}

	int K;
	std::cin >> K;
	std::vector<bool> sol(K);
	for (int i = 0; i < K; ++i) {
		std::cin >> e1 >> e2>> a;
		std::vector<bool> visitados(V,false);
		sol[i] = DFS(G, e1-1, e2-1, visitados,a);
	}

	for (int i = 0; i < K; ++i) {
		if (sol[i]) std::cout << "SI\n";
		else std::cout << "NO\n";
	}

	return true;
}

int main() {
	while (resuelveCaso());
}