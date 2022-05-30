//Marcos Herrero
#include <algorithm>
#include "bintree_eda.h"

struct Sol {
	bool eq;
	int altura;
};

Sol equilibradoEnAltura (bintree<int> const & tree) {
	if (tree.empty())return { true, 0 };
	else {
		Sol soll = equilibradoEnAltura(tree.left());
		Sol solr = equilibradoEnAltura(tree.right());

		return { soll.eq && solr.eq && soll.altura <= solr.altura + 1 && solr.altura <= soll.altura+1, 1 + std::max(soll.altura, solr.altura)};
	}
}