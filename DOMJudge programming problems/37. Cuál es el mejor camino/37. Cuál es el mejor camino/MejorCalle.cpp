//Marcos Herrero

#include <iostream>
#include <vector>
#include <queue>
#include <memory>
#include <stdexcept>
#include "GrafoValorado.h"



struct vDist {
	int v;
	int dist;

	bool operator<(vDist const & that)const {
		return dist > that.dist;
	}
};


struct sol {
	int dist;
	bool menorCalles;
};

bool resuelveCaso(){
	int V, E;
	std::cin >> V >> E;
	if (!std::cin)return false;

	GrafoValorado<int> G(V);
	int v1,v2, dist;
	for (int i = 0; i < E; ++i) {
		std::cin >> v1 >> v2 >> dist;
		G.ponArista(Arista<int>(v1-1, v2-1, dist));
	}

	int K;
	std::cin >> K;
	int orig, dest;

	std::vector<sol> vsol(K);
	for (int i = 0; i < K; ++i) {
		std::cin >> orig >> dest;
		--orig;
		--dest;

		std::vector<int> distTo(V, -1);
		std::vector<int> callesMinDist(V, -1);
		distTo[orig] = 0;
		callesMinDist[orig] = 0;

		int minCallesToDest = -1;
		std::queue<int> q; std::vector<bool> visitados(V, false);
		q.push(orig);
		visitados[orig] = true;
		int calles = 0;
		while (minCallesToDest == -1 && !q.empty()) {
			int n = q.size();

			for (int i = 0; minCallesToDest == -1 && i < n; ++i) {
				if (q.front() == dest) minCallesToDest = calles;
				else {
					int u = q.front();
					for (Arista<int> a : G.ady(u)) {
						if (!visitados[a.otro(u)]) {
							visitados[a.otro(u)] = true;
							q.push(a.otro(u));
						}
					}
				}

				q.pop();
			}

			++calles;
		}

		std::priority_queue<vDist> pq;
		pq.push({ orig, 0 });

		while (!pq.empty()) {
			int u = pq.top().v;
			
			for (Arista<int> a : G.ady(u)) {
				int v = a.otro(u);
				

				if (v == dest && (distTo[v] == -1 || distTo[v] > distTo[u] + a.valor())) {
					distTo[v] = distTo[u] + a.valor();
					callesMinDist[v] = callesMinDist[u] + 1;
				}
				else if (v == dest && distTo[v] == distTo[u] + a.valor()) {
					if (callesMinDist[v] > callesMinDist[u] + 1) callesMinDist[v] = callesMinDist[u] + 1;
				}
				else if (distTo[v] == -1 || distTo[v] > distTo[u] + a.valor()) {
					distTo[v] = distTo[u] + a.valor();
					callesMinDist[v] = callesMinDist[u] + 1;
					pq.push({ v, distTo[v] });
				}
				else if (distTo[v] == distTo[u] + a.valor()) {
					if (callesMinDist[v] > callesMinDist[u] + 1) {
						callesMinDist[v] = callesMinDist[u] + 1;
						pq.push({ v, distTo[v] });
					}
				}

			}

			pq.pop();
		}

		vsol[i].dist = distTo[dest];
		vsol[i].menorCalles = (minCallesToDest == callesMinDist[dest]);
	}

	for (int i = 0; i < K; ++i) {
		if (vsol[i].dist == -1) std::cout << "SIN CAMINO\n";
		else {
			std::cout << vsol[i].dist << ' ';
			if (vsol[i].menorCalles) std::cout << "SI\n";
			else std::cout << "NO\n";
		}

	}

	std::cout << "---\n";

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}