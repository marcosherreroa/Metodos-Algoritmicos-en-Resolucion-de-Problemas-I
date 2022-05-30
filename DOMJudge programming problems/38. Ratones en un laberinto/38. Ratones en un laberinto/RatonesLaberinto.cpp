//Marcos Herrero

#include <iostream>
#include <queue>
#include "GrafoDirigidoValorado.h"

struct vDist{
	int v;
	int dist;

	bool operator<(vDist const & that)const {
		return dist > that.dist;
	}
};

bool resuelveCaso() {
	int V, S, T, E;
	std::cin >> V >> S >> T >> E;
	if (!std::cin)return false;
	--S;

	GrafoDirigidoValorado<int> G(V);
	int v1, v2, c;
	for (int i = 0; i < E; ++i) {
		std::cin >> v1 >> v2 >> c;
		G.ponArista(AristaDirigida<int>(v2-1, v1-1, c));
	}

	std::priority_queue<vDist> pq;
	std::vector<int> distTo(V,-1);
	distTo[S] = 0;
	pq.push({ S,0 });
	
	while (!pq.empty()) {
		int u = pq.top().v;

		for (AristaDirigida<int> a : G.ady(u)) {
			int v = a.to();

			if (distTo[v] == -1 || distTo[v] > distTo[u] + a.valor()) {
				distTo[v] = distTo[u] + a.valor();
				pq.push({ v, distTo[v] });
			}
		}

		pq.pop();
	}

	int cont = -1;
	for (int u = 0; u < V; ++u) {
		if (distTo[u] != -1 && distTo[u] <= T)++cont;
	}

	std::cout << cont << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
}