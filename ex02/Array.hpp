#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <cstdlib>

template <class T>
class Array
{
	public:
	T *copy(Array const &src)
	{
		T *prio = new T[miao]();
		for (unsigned int i = 0; i < miao; i++)
			prio[i] = src.prio[i];
		return prio;
	}
	Array()
	{
		this->miao = 0;
		this->prio = NULL;
	};
	~Array()
	{
		if (this->prio != NULL)
			delete [] this->prio;
		return ;
	};
	Array(unsigned int n)
	{
		this->miao = n;
		this->prio = new T[n];
	};
	Array(Array const &src)
	{
		*this = src;
	};
	Array &operator=(Array const &src)
	{
		if (this == &src)
     			return *this;
		miao = src.miao;
		prio = copy(src);
		return *this;
	};
 	class IndexError : public std::exception
	{
		public:
			virtual const char * what() const throw()
			{
				return ("Index error");
			}
	};
	T &operator[](unsigned int n) const
	{
		if (static_cast<long int>(n) < 0 || n > this->size())
			throw IndexError();
		return (prio[n]);
	};
	unsigned int size(void) const
	{
		return (this->miao);
	};
	unsigned int miao;
	T *prio;
};

#endif