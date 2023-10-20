//version:1.0.0

// #ifndef DEBUG_H
// #define DEBUG_H
#include <iostream>
#include <unistd.h>
#include <sys/time.h>
// #define TEST(msg) std::cout<<"[("<< __FILE__<<"/"<<__LINE__<<") "<<__func__<<" ]"<<msg<<std::endl;
// #define TEST_(msg) std::cout<<"---------------------------------------------[("<< __FILE__<<"/"<<__LINE__<<") "<<__func__<<" ]"<<msg<<std::endl;
// #define TESTv(msg, i) std::cout<<"[("<< __FILE__<<"/"<<__LINE__<<") "<<__func__<<" ]"<<msg<<":"<<i<<std::endl;
// #define T std::cout<<"[("<< __FILE__<<"/"<<__LINE__<<") "<<__func__<<" ]"<<std::endl;
// #define T_ std::cout<<"---------------------------------------------[("<< __FILE__<<"/"<<__LINE__<<") "<<__func__<<" ]"<<std::endl;
// #define Tv(i) std::cout<<"[("<< __FILE__<<"/"<<__LINE__<<") "<<__func__<<" ]"<<#i<<":"<<i<<std::endl;
// #define FOR(x,j) {std::cout<<"[("<< __FILE__<<"/"<<__LINE__<<") "<<__func__<<" ]"<<#x<<":";for(size_t i = 0; x + i != j; i++){std::cout<<x[i]<<",";}std::cout<<std::endl;}
// #define TAKE(i,j) {static size_t test_arg = 0; if(!(test_arg % j)){i} test_arg++;}
// #define STOP {char c; read(STDIN_FILENO, &c, sizeof(char));}

#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <sys/types.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <stdlib.h>
#include <iterator>

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
		private:
			iterator():std::list<T>::iterator(){}
		public:
			iterator(typename std::list<T>::iterator&v):std::list<T>::iterator(v){}
			iterator(iterator &v):std::list<T>::iterator(v){}
			iterator &operator=(const iterator &other){ static_cast<typename std::list<T>::iterator>(*this) = static_cast<typename std::list<T>::iterator>(other); return *this;}
		T& operator[](size_t n)
		{
			typename std::list<T>::iterator it = *this;
	    	std::advance(it, n);
    		return *it;
		}
	};
};


bool operator>(const Unit &a, const Unit &b);
bool operator<(const Unit &a, const Unit &b);
std::ostream &operator<<(std::ostream &os, const Unit &other);
// void ListSort(std::list<Unit> &src);
void VectorSort(std::vector<Unit> &src);
void divideIntoThree(std::vector<Unit> &src, std::vector<Unit> \
	&destFront, std::vector<Unit> &destBack, std::vector<Unit> &remainder);
void SwapBigger(std::vector<Unit> &Front, std::vector<Unit> &Back);
void openPair(std::vector<Unit> &Src, std::vector<Unit> &Front, std::vector<Unit> &Back);
#endif