//Marcos Herrero
#include <iostream>
#include <vector>
#include <queue>

struct cosaVisitado {
	char cosa;
	bool visitado;
};

struct coord {
	int x;
	int y;
};

const std::vector<int> coordx = { -1, 0, 1, 0 };
const std::vector<int> coordy = { 0, 1, 0, -1 };

bool dentroMapa(int M, int N, coord c) {
	return 0 <= c.x && c.x < M && 0 <= c.y && c.y < N;
}

void resuelveCaso() {
	int M, N;
	std::cin >> N >> M;

	std::vector<std::vector<cosaVisitado>> mapa(M, std::vector<cosaVisitado>(N, { ' ',false }));

	coord entrada = { -1,-1 }, salida = { -1,-1 };
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cin >> mapa[i][j].cosa;
			if (mapa[i][j].cosa == 'E') entrada = { i,j };
			if (mapa[i][j].cosa == 'P') salida = { i,j };
		}
	}

	bool imposible = (entrada.x == -1 || salida.x == -1);

	for (int i = 0; !imposible && i < M; ++i) {
		for (int j = 0; !imposible && j < N; ++j) {
			if (isdigit(mapa[i][j].cosa)) {
				int k = int(mapa[i][j].cosa) - int('0');
				mapa[i][j].cosa = 'v';

				for (int p = 0; !imposible && p < 4; ++p) {
					for (int q = 1; !imposible && q <= k && dentroMapa(M, N, { i + q * coordx[p],j + q * coordy[p] })
						&& mapa[i + q * coordx[p]][j + q * coordy[p]].cosa != '#'; ++q) {
						if (mapa[i + q * coordx[p]][j + q * coordy[p]].cosa == '.') mapa[i + q * coordx[p]][j + q * coordy[p]].cosa = 'v';
						else if (mapa[i + q * coordx[p]][j + q * coordy[p]].cosa == 'E' || mapa[i + q * coordx[p]][j + q * coordy[p]].cosa == 'P') {
							imposible = true;
						}
					}
				}
			}

		}
	}

	bool fin = false;  int dist = 0;
	if (!imposible) {

		std::queue<coord> q; 
		mapa[entrada.x][entrada.y].visitado = true;
		q.push(entrada);
		while (!fin && !q.empty()) {
			++dist;
			int n = q.size();

			for (int i = 0; !fin && i < n; ++i) {
				coord sig = q.front();

				for (int p = 0; !fin && p < 4; ++p) {
					if (dentroMapa(M, N, { sig.x + coordx[p],sig.y + coordy[p] }) &&
						!mapa[sig.x + coordx[p]][sig.y + coordy[p]].visitado) {

						if (mapa[sig.x + coordx[p]][sig.y + coordy[p]].cosa == 'P') {
							fin = true;
						}
						else if (mapa[sig.x + coordx[p]][sig.y + coordy[p]].cosa == '.') {
							mapa[sig.x + coordx[p]][sig.y + coordy[p]].visitado = true;
							q.push({ sig.x + coordx[p],sig.y + coordy[p] });
						}

					}
				}

				q.pop();
			}

		}

	}

	if (imposible || !fin)std::cout << "NO\n";
	else std::cout << dist << '\n';

}

int main() {
	std::ios_base::sync_with_stdio(false);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}