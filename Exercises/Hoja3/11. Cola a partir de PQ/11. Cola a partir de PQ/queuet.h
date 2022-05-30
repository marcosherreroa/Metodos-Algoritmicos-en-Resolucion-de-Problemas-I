//Marcos Herrero

#ifndef QUEUE_H
#define QUEUE_H

#include <queue>
using namespace std;


class queuet {
private:
	priority_queue<pair<int, int>, std::vector<pair<int,int>>, std::greater<pair<int,int>>> pq;
	int i;
public:
	queuet() {
		i = 0;
	}

	int front()const {
		return pq.top().second;
	}

	void push(int elem) {
		pq.push({ i, elem });
		++i;
	}

	void pop() {
		pq.pop();
	}

};


#endif