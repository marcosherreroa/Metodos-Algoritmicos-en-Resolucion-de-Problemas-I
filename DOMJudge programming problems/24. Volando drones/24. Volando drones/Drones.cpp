//Marcos Herrero

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

bool resuelveCaso() {
	int n, a, b;
	std::cin >> n >> a >> b;
	if (!std::cin)return false;

	std::priority_queue<int> pilasA;
	int horas;
	for (int i = 0; i < a; ++i) {
		std::cin >> horas;
		if(horas != 0)pilasA.push(horas);
	}

	std::priority_queue<int> pilasB;
	for (int i = 0; i < b; ++i) {
		std::cin >> horas;
		if(horas != 0)pilasB.push(horas);
	}

	
	int tiempoSabado, pa, pb;
	std::queue<int> usadasA, usadasB;

	tiempoSabado = 0;

	for (int i = 0; !pilasA.empty() && !pilasB.empty() && i < n; ++i) {
		pa = pilasA.top();
		pilasA.pop();
		pb = pilasB.top();
		pilasB.pop();
		horas = std::min(pa, pb);

		tiempoSabado += horas;

		if (pa > horas)usadasA.push(pa - horas);
		if (pb > horas)usadasB.push(pb - horas);
	}

	while (!usadasA.empty()) {
		pilasA.push(usadasA.front());
		usadasA.pop();
	}

	while (!usadasB.empty()) {
		pilasB.push(usadasB.front());
		usadasB.pop();
	}

	std::cout << tiempoSabado;

	while (!pilasA.empty() && !pilasB.empty()) {
		tiempoSabado = 0;

		for (int i = 0; !pilasA.empty() && !pilasB.empty() && i < n; ++i) {
			pa = pilasA.top();
			pilasA.pop();
			pb = pilasB.top();
			pilasB.pop();
			horas = std::min(pa, pb);

			tiempoSabado += horas;

			if (pa > horas)usadasA.push(pa - horas);
			if (pb > horas)usadasB.push(pb - horas);
		}

		while (!usadasA.empty()) {
			pilasA.push(usadasA.front());
			usadasA.pop();
		}

		while (!usadasB.empty()) {
			pilasB.push(usadasB.front());
			usadasB.pop();
		}

		std::cout << ' '<< tiempoSabado ;
	}

	std::cout << '\n';

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}