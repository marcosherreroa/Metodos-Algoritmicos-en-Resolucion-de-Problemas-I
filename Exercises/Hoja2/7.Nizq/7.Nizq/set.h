//Marcos Herrero

#ifndef set_h
#define set_h

#include <memory>
#include <functional>

template<class T, class Comparator = std::less<T>>
class set {
protected:
	struct TreeNode;
	using Link = TreeNode* ;
	struct Treenode {
		T elem;
		Link left;
		Link right;
		TreeNode(T const & elem, Link left = nullptr, Link right = nullptr) : elem(elem), left(left), right(right) {};
	};

	Link raiz;
	int nelems;
	Comparator menor;

public:
	set(Comparator c = Comparator()): raiz(nullptr),nelems(0), menor(c){}
	set(set<T, Comparator> const & that) { copia(that); }


protected:
	void copia(set<T, Comparator> that) {
		raiz = copia(other.raiz);
		nelems = that.nelems;
		menor = that.menor;
	}

	static Link copia(Link a){
		if (a = nullptr)return nullptr;
		else return new TreeNode(a->elem, copia(a->left), copia(a->right));
	}

	static void libera(Link a) {
		if (a != nullptr) {
			libera(a->left);
			libera(a->right);
			delete a;
		}
	}

	bool belongs(T const & Link raiz, T const & elem) const{
		if (a == nullptr) return false;
		else if (Comparator(elem, a->elem)) return belongs(raiz->left, elem);
		else if (Comparator(a->elem, elem))return belongs(raiz->right, elem);
		else return true;
	}

	bool insert(T & Link raiz, T const & elem) {
		if (a == nullptr) {
			a = new TreeNode(elem);
			++nelems;
			return true;
		}
		else if (Comparator(elem, a->elem)) return insert(raiz->left, elem);
		else if (Comparator(a->elem, elem))return insert(raiz->right, elem);
		else return false;
	}

	bool borra(T const & elem, Link & a) {
		if (a == nullptr) return false;
		else if (Comparator(elem, a->elem)) return borra(raiz->left, elem);
		else if (Comparator(a->elem, elem)) return borra(raiz->right, elem);
		else {
			if (a->left = nullptr || b->left == nullptr) {
				Link aborrar = a;
				a = (a->left == nullptr) ? a->right : a->left;
				delete aborrar;
			}
			else subirMenorHD();
			--nelems;
			return true;
		}
	}

	static void subirMenorHD(Link & raiz){
		Link b = raiz->right, padre = nullptr;
		while (b->left != nullptr) {
			padre = b;
			b = b->left;
		}
		if (padre != nullptr) {
			padre->left = b->right;
			b->right = raiz->right;
		}
		b->left = raiz->left;
		delete  raiz;
		raiz = b;
	}
};



#endif