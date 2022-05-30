//Marcos Herrero

#include <iostream>
#include <vector>
#include <queue>

struct caja {
	int id;
	int libre;

	bool operator<(caja const & that)const {
		if (libre > that.libre) return true;
		else if (libre == that.libre && id > that.id) return true;
		else return false;
	}
};

bool resuelveCaso() {
	int n, c;

	std::cin >> n >> c;
	if (n == 0 && c == 0) return false;

	int seg;
	if (c < n) {
		for (int i = 0; i < c; ++i) std::cin >> seg;
		std::cout << c + 1 << '\n';
	}

	else {
		int tiempo = 0;
		std::priority_queue<caja> pq; 
		for (int i = 0; i < n; ++i) {
			std::cin >> seg;
			pq.push({ i+1, seg });
		}
		

		for (int i = 0; i < c-n; ++i) {
			std::cin >> seg;
			caja aux = pq.top();
			pq.pop();

			if (aux.libre > tiempo) tiempo = aux.libre;
			
			pq.push({ aux.id, tiempo + seg });
		}

		std::cout << pq.top().id << '\n';

	}
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}