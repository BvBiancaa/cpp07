#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string.h>

template <class T> void iter(T p[], int len, void (*func)(const T &x))
{
	for (int i = 0; i < len; i++)
		func(p[i]);
}

#endif