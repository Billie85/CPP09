#include "PmergeMe.hpp"

//========Constructor========

Unit::Unit(){}//not use

Unit::Unit(int value):MainNumber(value),ChildIndex(-1),prevOfset(0),Haspair(false){}

Unit::~Unit(){}

//============operator============
Unit &Unit::operator=(const Unit &other)
{
	if(this != &other)
	{
		this->MainNumber = other.MainNumber;
		this->ChildIndex = other.ChildIndex;
		this->prevOfset = other.prevOfset;
		this->Haspair = other.Haspair;
	}
	return(*this);
}
bool operator>(const Unit &a, const Unit &b)
{
	return (a.MainNumber > b.MainNumber);
}

bool operator<(const Unit &a, const Unit &b)
{
	return (a.MainNumber < b.MainNumber);
}

std::ostream &operator<<(std::ostream &os, const Unit &obj)
{
	os << obj.MainNumber;
	return(os);
}

//=========function==============
void divideIntoThree(std::vector<Unit> &src, std::vector<Unit> \
	&destFront, std::vector<Unit> &destBack, std::vector<Unit> &remainder){
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

void SwapBigger(std::vector<Unit> &Front, std::vector<Unit> &Back)
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

void Copy(std::vector<Unit> &src, std::vector<Unit> &dest){
	
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

void SetHaspair(std::vector<Unit> &target){
	for (size_t i = 0; i < target.size(); i++)
	{
		target[i].Haspair = true;
	}
}

std::vector<Unit>::iterator BinarySearch(std::vector<Unit> &target, Unit &searchNumber, size_t len)
{
	//std::vector<Unit>::iterator ここのイテレータでoperator[]が必要になる。
	std::vector<Unit>::iterator left = target.begin();

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
void openPair(std::vector<Unit> &Src, std::vector<Unit> &Front, std::vector<Unit> &Back){
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

void VectorSort(std::vector<Unit> &src)
{
	if (src.size() <= 1){
		return;
	}
	std::vector<Unit> Front;
	std::vector<Unit> Back;
	std::vector<Unit> Remainder;

	divideIntoThree(src, Front, Back, Remainder);
	SwapBigger(Front, Back);
	Copy(Front, src);
	VectorSort(src);
	SetHaspair(src);
	openPair(src, Front, Back);
	size_t i = Remainder.size();
	while (i--){
		src.insert(BinarySearch(src, Remainder[i], src.size()),Remainder[i]);
	}

}

// void ListSort(std::list<Unit> &src)
// {

// }