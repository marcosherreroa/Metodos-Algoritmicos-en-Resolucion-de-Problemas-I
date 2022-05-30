//Marcos Herrero
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include "Grafo.h"

int DFSCConexa(Grafo const & G, int N, int u, std::vector<bool> & visitados) {
	std::vector<bool> prohib(N, false);
	std::vector<int> dist(N);
	std::queue<int> q;
	bool par = true, imposible = false;
	int guardias = 0, distancia = 0;

	visitados[u] = true;
	dist[u] = 0;
	q.push(u);

	while (!imposible && !q.empty()) {
		++distancia;
		int n = q.size();
		for (int i = 0; i < n; ++i) {
			int v = q.front();

			for (int w : G.ady(v)) {
				if (!visitados[w]) {
					visitados[w] = true;
					dist[w] = distancia;
					q.push(w);
				}
				else if (v == w && !par) imposible = true;
				else if (v != w && dist[v] % 2 == dist[w] % 2) imposible = true;
			}

			if (!imposible && par) {
				++guardias;
				prohib[v] = true;
				for (int w : G.ady(v)) prohib[w] = true;
			}

			q.pop();
		}

		par = !par;
	}

	if (imposible) return -1;
	else return guardias;
}
	

bool resuelveCaso() {
	int N, C;
	std::cin >> N >> C;

	if (!std::cin)return false;

	Grafo G(N);
	int c1, c2;
	for (int i = 0; i < C; ++i) {
		std::cin >> c1 >> c2;
		G.ponArista(c1-1, c2-1);
	}
	
	std::vector<bool> marcados(N, false);
	bool imposible = false; int solMejor = 0;
	for (int u = 0; !imposible && u < N; ++u) {
		if (!marcados[u]) {
			marcados[u] = true;
			if (G.ady(u).size() != 0) {
				int v = G.ady(u)[0];
				std::vector<bool> aux(N, false);
				int sol1 = DFSCConexa(G, N,u,marcados);
				int sol2 = DFSCConexa(G, N, v, aux);

				if (sol1 == -1 && sol2 == -1) imposible = true;
				else if (sol1 == -1) solMejor += sol2;
				else if (sol2 == -1) solMejor += sol1;
				else solMejor += std::min(sol1, sol2);
			}
		}
	}
	
	if (imposible)std::cout << "IMPOSIBLE\n";
	else std::cout << solMejor<<'\n';
	
	return true;
}

int main() {
	while (resuelveCaso());
}