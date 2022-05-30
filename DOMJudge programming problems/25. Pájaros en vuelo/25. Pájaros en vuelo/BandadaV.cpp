//Marcos Herrero

#include <iostream>
#include <queue>


bool resuelveCaso() {
	int mediana, N;
	std::cin >> mediana>> N;
	if (N == 0)return false;

	std::priority_queue<int, std::vector<int>, std::greater<int>> mayores;
	std::priority_queue<int> menores;
	int edadMayor, edadMenor;

	std::cin >> edadMayor >> edadMenor;
	if (edadMayor < edadMenor) std::swap(edadMayor, edadMenor);

	if (mediana > edadMayor) {
		mayores.push(mediana);
		menores.push(edadMenor);
		menores.push(edadMayor);
		mediana = menores.top();
		menores.pop();
	}

	else if (mediana < edadMenor) {
		menores.push(mediana);
		mayores.push(edadMenor);
		mayores.push(edadMayor);
		mediana = mayores.top();
		mayores.pop();
	}

	else {
		menores.push(edadMenor);
		mayores.push(edadMayor);
	}

	std::cout << mediana;

	for (int i = 1; i < N; ++i) {
		std::cin >> edadMayor >> edadMenor;
		if (edadMayor < edadMenor) std::swap(edadMayor, edadMenor);

		if (mediana > edadMayor) {
			mayores.push(mediana);
			menores.push(edadMenor);
			menores.push(edadMayor);
			mediana = menores.top();
			menores.pop();
		}

		else if (mediana < edadMenor) {
			menores.push(mediana);
			mayores.push(edadMenor);
			mayores.push(edadMayor);
			mediana = mayores.top();
			mayores.pop();
		}

		else {
			menores.push(edadMenor);
			mayores.push(edadMayor);
		}
		std::cout << ' '<<mediana;
	}

	std::cout << '\n';
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}