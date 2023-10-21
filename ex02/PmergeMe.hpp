#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <sys/types.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <stdlib.h>
#include <iterator>
#include <iostream>
#include <unistd.h>
#include <sys/time.h>

class Unit
{
private:
	Unit(); //not use private
public:
	int MainNumber;
	size_t ChildIndex; //ssize_t wanna use minus
	size_t prevOfset; //maeno index no offset
	bool Haspair; //tenkai saretaka
	Unit(int value);
	~Unit();

	Unit &operator=(const Unit &other);
};


//////////////////////////////////////////////// std::list operator[] ////////////////////////////////////////////////////////////
template <typename T>
class MyList : public std::list<T>{

	//constructor
		public:
			MyList():std::list<T>(){}
			MyList(MyList &v):std::list<T>(static_cast<typename std::list<T> >(v)){}
			MyList &operator=(const MyList &other){ static_cast<typename std::list<T> >(*this) = static_cast<typename std::list<T> >(other); return *this;}


	//begin function
	typename MyList<T>::iterator begin()
	{
		MyList<T>::iterator hoge = this->std::list<T>::begin();
		return(hoge);
	}

	//listの中にoperator[]が無いため、std::listはクラスだからそれを継承してあげてから、operator[]の実装をしてあげる。classを使わないとできない。
	T& operator[](size_t n)
	{
		typename std::list<T>::iterator it = this->std::list<T>::begin();
	    std::advance(it, n);
    	return *it;
	}

	//list iteratorの中にoperator[]が無いため、operator[]の実装をしてあげる。classを使わないとできない。
	class iterator : public std::list<T>::iterator
	{
		//constructor
		public:
			iterator():std::list<T>::iterator(){}

			iterator(typename std::list<T>::iterator &it):std::list<T>::iterator(it){}

			iterator(iterator& v):std::list<T>::iterator(v){}

			iterator& operator=(const iterator& other) {
            std::list<T>::iterator::operator=(other);
            return *this;
			}

			T& operator[](size_t n) {
				iterator it = *this;
				std::advance(it, n);
				return *it;
			}
	};
};


//////////////////////////////////////////// Operator ////////////////////////////////////////////////////////////////

bool operator>(const Unit &a, const Unit &b);
bool operator<(const Unit &a, const Unit &b);
std::ostream &operator<<(std::ostream &os, const Unit &other);

/////////////////////////////////////////// Templat Function /////////////////////////////////////////////////////////////////

template <typename Container>
void Copy(Container &src, Container &dest){
	
	size_t len = src.size();
	dest.clear();
	dest.reserve(len);
	for (size_t i = 0; i < len; i++){
		Unit buff = src[i].MainNumber;
		buff.ChildIndex = i;
		buff.prevOfset = i;
		buff.Haspair = false;
		dest.push_back(buff);
	}
}

template <typename Container>
void SetHaspair(Container &target){
	for (size_t i = 0; i < target.size(); i++)
	{
		target[i].Haspair = true;
	}
}

template <typename Container>
typename Container::iterator BinarySearch(Container &target, Unit &searchNumber, size_t len)
{
	//std::listの場合ここのイテレータでoperator[]が必要になる。
	typename Container::iterator left = target.begin();

	while (len > 1) {
		if (searchNumber < left[len/2]){
			len /= 2;
		}else{
			left += len / 2;
			len = len / 2 + len % 2;
		}
	}
	if (searchNumber < *left || !len){
		return(left);
	}else{
		return(left + 1);
	}
}

// J(0) = 0
// J(1) = 1
// J(n) = J(n-1) + 2 * J(n-2) （n > 1）

template <typename Container>
void openPair(Container &Src, Container &Front, Container &Back){
	size_t i = 0;
	
	//std::list<Unit> ここのlistでoperator[]が必要になる。
	if (Src.size()){
		size_t n1 = 1;
		size_t n2 = 1;
		size_t open = 1;
		while(open){
			for (; open ; i--){
				while (Src[i].Haspair && open){
					size_t ChildIndex = Src[i].ChildIndex;
					Src[i] = Front[Src[i].prevOfset];
					Src.insert(BinarySearch(Src, Back[ChildIndex], i),Back[ChildIndex]);
					open--;
				}
				if (!i)
					break;
			}
			size_t hoge = n1 + 2 * n2;
			n2 = n1;
			n1 = hoge;
			hoge = n1 - n2;
			size_t len = Src.size();
			for (; i < len && open < hoge; i++){
				if (Src[i].Haspair){
					open++;
					if (open >= hoge){
						break;
					}
				}
			}
		}
	}
}

template <typename Container>
void SwapBigger(Container &Front, Container &Back)
{
	size_t len = Front.size();
	for (size_t i = 0; i < len; i++)
	{
		if (Front[i] < Back[i])
		{
			Unit buff = Front[i];
			Front[i] = Back[i];
			Back[i] = buff;
		}
	}
}

template <typename Container>
void divideIntoThree(Container &src, Container &destFront, Container &destBack, Container &remainder){
		size_t len = src.size() / 2;
		size_t i = 0;
		for (; i < len; i++){
			destFront.push_back(src[i]);
		}
		len *= 2;
		for (; i < len; i++){
			destBack.push_back(src[i]);
		}
		for (; i < src.size(); i++){
			remainder.push_back(src[i]);
		}
}

template <typename Container>
void FordJohnsonAlgorithm(Container &src)
{
	if (src.size() <= 1){
		return;
	}
	Container Front;
	Container Back;
	Container Remainder;

	divideIntoThree(src, Front, Back, Remainder);
	SwapBigger(Front, Back);
	Copy(Front, src);
	FordJohnsonAlgorithm(src);
	SetHaspair(src);
	openPair(src, Front, Back);
	size_t i = Remainder.size();
	while (i--){
		src.insert(BinarySearch(src, Remainder[i], src.size()),Remainder[i]);
	}
}

#endif