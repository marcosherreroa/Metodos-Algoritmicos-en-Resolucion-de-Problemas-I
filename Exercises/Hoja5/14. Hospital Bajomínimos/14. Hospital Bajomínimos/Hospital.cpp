//Marcos Herrero

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

struct horaMin {
	int hora;
	int min;

	bool operator<(horaMin const & that) {
		if (hora < that.hora)return true;
		else if (hora == that.hora && min < that.min)return true;
		else return false;
	}
};

std::istream &  operator>>(std::istream & flujo, horaMin & hm) {
	flujo >> hm.hora >> hm.min;
	return flujo;
}

void intervaloMasInyecciones(std::vector<horaMin> & pacientes, int k, horaMin & a , horaMin & b) {
	std::sort(pacientes.begin(), pacientes.end());

	a = pacientes[0]; b = a + k;
	int j = 0;
	while (j < pacientes.size() - 1 && pacientes[j + 1] < b) ++j;


	int ini = pacientes[0], fin = a + k;
	while (fin < pacientes[pacientes.size() - 1]) {
		
	}
	
}

bool resuelveCaso() {
	int nPac, k;
	std::cin >> nPac>> k;
	if (nPac == 0)return false;

	std::vector<horaMin> pacientes(nPac);
	for (int i = 0; i < nPac; ++i)std::cin >> pacientes[i];

	int k
	return true;
} 
int main() {
	while (resuelveCaso());
}