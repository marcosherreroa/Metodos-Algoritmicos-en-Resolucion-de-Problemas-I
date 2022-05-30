//Marcos Herrero
#include <iostream>
#include <vector>
#include <queue>
#include "GrafoDirigido.h"

GrafoDirigido cuadrado(GrafoDirigido const & G) {
	GrafoDirigido H(G.V());
	
	for (int u = 0; u < G.V(); ++u) {
		std::vector<bool> marcados(G.V()); 

		for (int v : G.ady(u)) {
			for (int w : G.ady(v)) {
				 
				if (!marcados[w]) {
					marcados[w] = true;
					H.ponArista(u, w);
				}
			}
		}
   
	}

	return H;


	/*
	CON MATRIZ DE ADYACENCIA

	for(int u = 0; u < G.V(); ++u){
	  for(int v = 0; v < G.V(); ++v){
	    if(G[u][v] == 1){
		  for(int w = 0; w < G.V(); ++w){
			 if(G[v][w] == 1) H.ponArista(u,w);
		   }
		}

	
	*/
}

bool resuelveCaso() {
	int V, E;
	std::cin >> V >> E;
	if (V == 0)return false;

	GrafoDirigido G(V);

	int a, b;
	for (int i = 0; i < E; ++i) {
		std::cin >> a >> b;
		G.ponArista(a, b);
	}

	GrafoDirigido H = cuadrado(G);
	H.print();

	return true;
}

int main() {
	while (resuelveCaso());
}