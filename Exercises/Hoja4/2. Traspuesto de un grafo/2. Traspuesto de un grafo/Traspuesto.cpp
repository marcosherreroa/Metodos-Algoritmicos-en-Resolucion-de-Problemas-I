//Marcos Herrero
#include <iostream>
#include "GrafoDirigido.h"

GrafoDirigido traspuesto(GrafoDirigido const & G){
	GrafoDirigido H(G.V());
	
	for (int i = 0; i < G.V(); ++i) {
		for (int j = 0; j < G.ady(i).size(); ++j) {
			H.ponArista(G.ady(i)[j], i);
		}
	}
    
	/*
	con matrices

	for(int i = 0; i< G.V();++i){
	  for(int j = 0; j< G.V(); ++j){
	    if(G.adj(i,j))H.ponArista(j,i);
	}
	}
	
	*/

	return H;
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

	GrafoDirigido H = traspuesto(G);
	H.print();

	return true;
}

int main() {
	while (resuelveCaso());
}