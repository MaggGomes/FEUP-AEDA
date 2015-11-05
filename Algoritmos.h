#ifndef ALGORITMOS_H_
#define ALGORITMOS_H_

#include <vector>

using namespace std;

// Colocar aqui os algoritmos de pesquia e ordenação que se utilizem

template <class Comparable>
int sequentialSearch(const vector<Comparable> &v, Comparable x)
{
	for (unsigned int i = 0; i < v.size(); i++)
		if (v[i] == x)
			return i;
	return -1;
}

#endif /*ALGORITMOS_H_*/
