//Marcos Herrero

#include <iostream>
#include "Grafo.h"

void BFS(Grafo const & G, int u, std::vector<bool> & marcado, int N, std::vector<int> & cconexa) {
	for (int v : G.ady(u)) {
		if (!marcado[v]) {
			marcado[v] = true;
			if(v < N) cconexa.push_back(v);
			BFS(G, v, marcado, N, cconexa);
		}
	}
}

bool resuelveCaso() {
	int N, M;
	std::cin >> N >> M;
	if (!std::cin)return false;

	Grafo G(N+M);
	int n, id;

	for (int i = 0; i < M; ++i) {
		std::cin >> n;
		for (int j = 0; j < n; ++j) {
			std::cin >> id;
			G.ponArista(id-1, N + i);
		}

	}

	std::vector<bool> marcado(N+ M, false);
	std::vector<int> sol(N);
	for (int u = 0; u < N; ++u) {
		if (!marcado[u]) {
			std::vector<int> cconexa;
			cconexa.push_back(u);
			marcado[u] = true;
			BFS(G, u, marcado,N, cconexa);
			
			for (int i = 0; i < cconexa.size(); ++i) {
				sol[cconexa[i]] = cconexa.size();
			}
		}
	}

	std::cout << sol[0];
	for (int i = 1; i < sol.size(); ++i) std::cout << ' ' << sol[i];
	std::cout << '\n';


	return true;
}

int main() {
	while (resuelveCaso());
}