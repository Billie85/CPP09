//version:1.0.0

#ifndef DEBUG_H
#define DEBUG_H
#include <iostream>
#include <unistd.h>
#include <sys/time.h>
#define TEST(msg) std::cout<<"[("<< __FILE__<<"/"<<__LINE__<<") "<<__func__<<" ]"<<msg<<std::endl;
#define TEST_(msg) std::cout<<"---------------------------------------------[("<< __FILE__<<"/"<<__LINE__<<") "<<__func__<<" ]"<<msg<<std::endl;
#define TESTv(msg, i) std::cout<<"[("<< __FILE__<<"/"<<__LINE__<<") "<<__func__<<" ]"<<msg<<":"<<i<<std::endl;
#define T std::cout<<"[("<< __FILE__<<"/"<<__LINE__<<") "<<__func__<<" ]"<<std::endl;
#define T_ std::cout<<"---------------------------------------------[("<< __FILE__<<"/"<<__LINE__<<") "<<__func__<<" ]"<<std::endl;
#define Tv(i) std::cout<<"[("<< __FILE__<<"/"<<__LINE__<<") "<<__func__<<" ]"<<#i<<":"<<i<<std::endl;
#define FOR(x,j) {std::cout<<"[("<< __FILE__<<"/"<<__LINE__<<") "<<__func__<<" ]"<<#x<<":";for(size_t i = 0; x + i != j; i++){std::cout<<x[i]<<",";}std::cout<<std::endl;}
#define TAKE(i,j) {static size_t test_arg = 0; if(!(test_arg % j)){i} test_arg++;}
#define STOP {char c; read(STDIN_FILENO, &c, sizeof(char));}
#endif



#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <sys/types.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <stdlib.h>



class VectorUnit
{
private:
	VectorUnit(); //not use private
public:
	int MainNumber;
	size_t ChildIndex; //ssize_t wanna use minus
	size_t prevOfset; //maeno index no offset
	bool Haspair; //tenkai saretaka
	VectorUnit(int value);
	~VectorUnit();

	VectorUnit &operator=(const VectorUnit &other);
};
bool operator>(const VectorUnit &a, const VectorUnit &b);
bool operator<(const VectorUnit &a, const VectorUnit &b);
std::ostream &operator<<(std::ostream &os, const VectorUnit &other);
// void ListSort(std::list<VectorUnit> &src);
void VectorSort(std::vector<VectorUnit> &src);
void divideIntoThree(std::vector<VectorUnit> &src, std::vector<VectorUnit> \
	&destFront, std::vector<VectorUnit> &destBack, std::vector<VectorUnit> &remainder);
void SwapBigger(std::vector<VectorUnit> &Front, std::vector<VectorUnit> &Back);

void openPair(std::vector<VectorUnit> &Src, std::vector<VectorUnit> &Front, std::vector<VectorUnit> &Back);
#endif