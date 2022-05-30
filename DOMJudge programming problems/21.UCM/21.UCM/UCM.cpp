//Marcos Herrero

#include <iostream>
#include <string>
#include <queue>

struct user{
	int id;
	int periodo;
	long int orden;
	
	bool operator<(user const & that)const {
		if (orden > that.orden) return true;
		else if (orden == that.orden && id > that.id) return true;
		else return false;
	}
};

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0)return false;

	std::priority_queue<user> cola;
	int id, periodo;
	for (int i = 0; i < N; ++i) {
		std::cin >> id >> periodo;
		cola.push({ id, periodo, periodo});
	}

    int k;
	std::cin >> k;
	
	user aux;
	for (int i = 0; i < k; ++i) {
		aux = cola.top();
		std::cout << aux.id<<'\n';
		cola.push({ aux.id , aux.periodo,aux.orden + aux.periodo });
		cola.pop();
	}

	std::cout << "---\n";
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}