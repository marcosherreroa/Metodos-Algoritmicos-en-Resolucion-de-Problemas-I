//Marcos Herrero
#include <algorithm>
using namespace std;

class AVLtree {
private:
	
	using elem = int;

	class Nodo {
	public:
		elem e;
		int h;
		Nodo* izq;
		Nodo* der;
		
		Nodo( const int & x , Nodo* i = nullptr, Nodo* d = nullptr, int alt = 1)
			: e(x), izq(i), der(d), h(alt) {}
	};

	Nodo* raiz;

	AVLtree(Nodo* r) : raiz(r) {};

public:

	int altura(AVLtree const & t) const{ 
		if (t.raiz == nullptr) return 0;
		else return t.raiz->h;
	}

	AVLtree crear(AVLtree & i, elem x, AVLtree & d) {
		AVLtree t (new Nodo(x, i.raiz, d.raiz));
		t.raiz->h = 1 + max(altura(i), altura(d));
		return AVLtree(raiz);
	}

	
	 t const & consulta(const clave &clave) {
		nodo* p = busca(clave, raiz);
		if (p == null)
			throw eclaveerronea("la clave no se puede consultar");
		return p->valor;
	}
private:
	static nodo* busca(const clave& c, nodo* a) {
		if (a == null)
			return null;
		else if (a->clave == c)
			return a;
		else if (c < a->clave)
			return busca(c, a->iz);
		else // c > a->clave
			return busca(c, a->dr);
	}

public:
	void inserta(const clave& c, const valor& v) {
		inserta(c, v, raiz);
	}
private:
	static void inserta(const clave& c, const valor& v, nodo*& a) {
		if (a == null) {
			a = new nodo(c, v);
		}
		else if (c == a->clave) {
			a->valor = v;
		}
		else if (c < a->clave) {
			inserta(c, v, a->iz);
			reequilibrader(a);
		}
		else { // c > a->clave
			inserta(c, v, a->dr);
			reequilibraizq(a);
		}
	}

	static void rotader(nodo*& k2) {
		nodo* k1 = k2->iz;
		k2->iz = k1->dr;
		k1->dr = k2;
		k2->altura = max(altura(k2->iz), altura(k2->dr)) + 1;
		k1->altura = max(altura(k1->iz), altura(k1->dr)) + 1;
		k2 = k1;
	}

	static int altura(nodo* a) {
		if (a == null) return 0;
		else return a->altura;
	}

	static void rotaizq(nodo*& k1) {
		nodo* k2 = k1->dr;
		k1->dr = k2->iz;
		k2->iz = k1;
		k1->altura = max(altura(k1->iz), altura(k1->dr)) + 1;
		k2->altura = max(altura(k2->iz), altura(k2->dr)) + 1;
		k1 = k2;
	}

	static void rotaizqder(nodo*& k3) {
		rotaizq(k3->iz);
		rotader(k3);
	}
};