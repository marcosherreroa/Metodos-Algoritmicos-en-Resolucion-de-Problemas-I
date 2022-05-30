//Marcos Herrero
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

void countingSort(std::vector<int> & v, int n, int k) { // Coste(n+k) en tiempo y en espacio adicional
	std::vector<int> count(k, 0);

	for (int i = 0; i < n;  ++i) ++count[v[i]]; // contamos cuantos hay en cada grupo

	int empieza = 0, aux;
	for (int i = 0; i < k; ++i) {
		aux = count[i] + empieza;   // grupos[i] <= indice en el que empieza la clave i,
		count[i] = empieza;         // empieza guarda donde podra empezar el siguiente grupo
		empieza = aux;
	}

	std::vector<int> w(n);
	for (int i = 0; i < n; ++i) {
		w[count[v[i]]] = v[i];      // los elementos cuya clave es v[i] empiezan a encajar a partir de v[i]. Cuando aparece el primero, se coloca
		++count[v[i]];           // y se actualiza el índice
	}

	v = std::move(w);
}


void pigeonholeSort(std::vector<int> & v, int n, int k) {
	std::vector<std::vector<int>> holes(k);

	for (int i = 0; i < n; ++i)holes[v[i]].push_back(v[i]);

	int ind = 0, j = 0;

	for (int i = 0; i < n; ++i) {
		while (holes[ind].size() <= j) {
			j = 0; 
			++ind;
		}

		v[i] = holes[ind][j];
		++j;
	}
}

void bucketSort(std::vector<int> & v, int n, float a, float b) { // coste n asumiendo distribucion uniforme de las claves
	if (n > 1) {
		std::vector<std::vector<int>> buckets(n);

		for (int i = 0; i < n; ++i) buckets[floor(n*(v[i] - a) / (b - a))].push_back(v[i]);
		for (int i = 0; i < n; ++i) bucketSort(buckets[i], buckets[i].size(), a + i * (b - a) / n, a + (i + 1)*(b - a) / n);

		int ind = 0, j = 0;
		for (int i = 0; i < n; ++i) {
			while (buckets[ind].size() <= j) {
				++ind;
				j = 0;
			}

			v[i] = buckets[ind][j];
			++j;
		}
	}
}

void MSDradixSortPalomar(std::vector<std::string> & v, int n, int d) {
	const int k = 10;
	if (n > 1 && d > 0) {
		std::vector<std::vector<std::string>> digitos(k);
		for (int i = 0; i < n; ++i) {
			if (v[i].size() < d) digitos[0].push_back(v[i]);
			else digitos[int(v[i].at(v[i].size() - d)) - int('0')].push_back(v[i]);
		}

		int ind = 0;
		for (int i = 0; i < k; ++i) {
			MSDradixSortPalomar(digitos[i], digitos[i].size(), d - 1); // ordena cada bucket

			for (int j = 0; j < digitos[i].size(); ++j) {
				v[ind] = digitos[i][j];
				++ind;
			}

		}
	}
}

void LSDradixSortPalomar(std::vector<std::string> & v, int n, int d) { // en cada iteración radix ordena según un  digito
	const int k = 10;
	for (int i = 0; i < d; ++i) {
		std::vector<std::vector<std::string>> digitos(k);

		for (int j = 0; j < n; ++j) {
			if (v[j].size() < i+1) digitos[0].push_back(v[j]);
			else digitos[int(v[j].at(v[j].size() - i-1)) - int('0')].push_back(v[j]);
		}

		int ind = 0;
		for (int j = 0; j < k; ++j) {

			for (int l = 0; l < digitos[j].size(); ++l) {
				v[ind] = digitos[j][l];
				++ind;
			}

		}
	}
}

void LSDradixSortCounting(std::vector<std::string> & v, int n, int d, int k) { // en cada iteración radix ordena según un  digito
	for (int i = 0; i < d; ++i) {
		std::vector<int> grupos(k);
		for (int j = 0; j < n; ++j) {
			if (v[j].size() < i+1) ++grupos[0];
			else ++grupos[int(v[j].at(v[j].size() - i-1)) - int('0')];
		}

		int empieza = 0, aux;
		for (int j = 0; j < k; ++j) {
			aux = grupos[j] + empieza;   // grupos[i] <= indice en el que empieza la clave i,
			grupos[j] = empieza;         // empieza guarda donde podra empezar el siguiente grupo
			empieza = aux;
		}

		std::vector<std::string> w(n);
		for (int j = 0; j < n; ++j) {
			if (v[j].size() < i+1) {
				w[grupos[0]] = v[j];
				++grupos[0];
			}
			else {
				w[grupos[int(v[j].at(v[j].size() - i-1)) - int('0')]] = v[j];      // los elementos cuya clave es v[i] empiezan a encajar a partir de v[i]. Cuando aparece el primero, se coloca
				++grupos[int(v[j].at(v[j].size() - i-1)) - int('0')];           // y se actualiza el índice
			}
		}

		v = std::move(w);
	}
}

bool resuelveCaso() {
	int n; 
	std::cin >> n;
	if (n == 0)return false;
	std::vector<int> v(n);

	for (int i = 0; i < n; ++i)std::cin >> v[i];
	pigeonholeSort(v, n,20);
	for (int i = 0; i < n; ++i)std::cout << v[i]<<' ';

	return true;
}

int main() {
	while (resuelveCaso());
}