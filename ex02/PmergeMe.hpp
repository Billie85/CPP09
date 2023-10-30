#pragma once

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
#include <ctime>
#include <cctype>

class Unit
{
private:
	//Unit(); //not use private
public:
	Unit(); //not use private
	int MainNumber;
	size_t Index; //ssize_t wanna use minus
	//size_t prevOfset; //maeno index no offset
	bool Haspair; //tenkai saretaka
	Unit(int value);
	~Unit();

	Unit &operator=(const Unit &other);
};


//////////////////////////////////////////////// std::list operator[] ////////////////////////////////////////////////////////////
template <typename T>
class MyList : public std::list<T>{

	public:
		//list iteratorの中にoperator[]が無いため、operator[]の実装をしてあげる。classを使わないとできない。
		class iterator : public std::list<T>::iterator
		{
			//constructor
			public:
				iterator():std::list<T>::iterator(){}
				iterator(const typename std::list<T>::iterator &it):std::list<T>::iterator(it){}
				iterator(const iterator &it):std::list<T>::iterator(it){}
				iterator& operator=(const typename std::list<T>::iterator &other) {
    	        this->std::list<T>::iterator::operator=(other);
    	        return *this;
				}

				T& operator[](size_t n) {
					iterator it = *this;
					std::advance(it, n);
					return *it;
				}

				iterator &operator+=(size_t n) {
					std::advance(*this, n);
					return *this;
				}

				iterator operator+(size_t n) {
					iterator it = *this;
					std::advance(it, n);
					return it;
				}
		};

		//constructor
		MyList():std::list<T>(){}
		MyList(MyList &v):std::list<T>(static_cast<typename std::list<T> >(v)){}
		MyList &operator=(const MyList &other){ static_cast<typename std::list<T> >(*this) = static_cast<typename std::list<T> >(other); return *this;}

		void reserve(size_t _){(void)_;}
	
		//listの中にoperator[]が無いため、std::listはクラスだからそれを継承してあげてから、operator[]の実装をしてあげる。classを使わないとできない。
		T& operator[](size_t n)
		{
			typename std::list<T>::iterator it = this->std::list<T>::begin();
		    std::advance(it, n);
    		return *it;
		}

};

//////////////////////////////////////////// Operator ////////////////////////////////////////////////////////////////

bool operator>(const Unit &a, const Unit &b);
bool operator<(const Unit &a, const Unit &b);
std::ostream &operator<<(std::ostream &os, const Unit &other);