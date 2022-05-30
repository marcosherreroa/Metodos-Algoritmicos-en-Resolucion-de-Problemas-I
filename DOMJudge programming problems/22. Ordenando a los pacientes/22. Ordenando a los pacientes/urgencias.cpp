//Marcos Herrero
#include <iostream>
#include <string>
#include <queue>

struct pac {
	std::string id;
	int grav;
	int entrada;

	bool operator<( pac const & that)const {
		if (grav < that.grav) return true;
		else if (grav == that.grav && entrada > that.entrada)return true;
		else return false;
	}
};

bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (n == 0)return false;

	std::priority_queue<pac> lista;
	char evento;  std::string nombre; int grav, turno = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> evento;
		
		if (evento == 'I') {
			std::cin >> nombre >> grav;
			lista.push({nombre, grav, turno});
			++turno;
		}

		else {
			std::cout << lista.top().id<<'\n';
			lista.pop();
		}
	}

	std::cout << "---\n";

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}