//Marcos Herrero
#include "bintree_eda.h"

struct Sol {
	bool zurdo;
	int descendientes;
};

Sol zurdo(bintree<int> const & tree) {
	if (tree.empty())return { true, 0};
	else {
		Sol soll = zurdo(tree.left());
		Sol solr = zurdo(tree.right());

		return { soll.zurdo && solr.zurdo && soll.descendientes > (solr.descendientes + soll.descendientes) / 2 , //Mejor separar
			1+soll.descendientes+solr.descendientes};
	}
}