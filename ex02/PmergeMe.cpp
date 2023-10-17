#include "PmergeMe.hpp"

//========Constructor========

VectorUnit::VectorUnit(){}//not use

VectorUnit::VectorUnit(int value):MainNumber(value),ChildIndex(-1),prevOfset(0),Haspair(false){}

VectorUnit::~VectorUnit(){}

//============operator============
VectorUnit &VectorUnit::operator=(const VectorUnit &other)
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
bool operator>(const VectorUnit &a, const VectorUnit &b)
{
	return (a.MainNumber > b.MainNumber);
}

bool operator<(const VectorUnit &a, const VectorUnit &b)
{
	return (a.MainNumber < b.MainNumber);
}

std::ostream &operator<<(std::ostream &os, const VectorUnit &obj)
{
	os << obj.MainNumber;
	return(os);
}

//=========function==============
void divideIntoThree(std::vector<VectorUnit> &src, std::vector<VectorUnit> \
	&destFront, std::vector<VectorUnit> &destBack, std::vector<VectorUnit> &remainder){
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

void SwapBigger(std::vector<VectorUnit> &Front, std::vector<VectorUnit> &Back)
{
	size_t len = Front.size();
	for (size_t i = 0; i < len; i++)
	{
		if (Front[i] < Back[i])
		{
			VectorUnit buff = Front[i];
			Front[i] = Back[i];
			Back[i] = buff;
		}
	}
}

void Copy(std::vector<VectorUnit> &src, std::vector<VectorUnit> &dest){
	
	size_t len = src.size();
	dest.clear();
	dest.reserve(len);
	for (size_t i = 0; i < len; i++){
		VectorUnit buff = src[i].MainNumber;
		buff.ChildIndex = i;
		buff.prevOfset = i;
		buff.Haspair = false;
		dest.push_back(buff);
	}
}

void SetHaspair(std::vector<VectorUnit> &target){
	for (size_t i = 0; i < target.size(); i++)
	{
		target[i].Haspair = true;
	}
}

std::vector<VectorUnit>::iterator BinarySearch(std::vector<VectorUnit> &target, VectorUnit &searchNumber, size_t len)
{
	std::vector<VectorUnit>::iterator left = target.begin();

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
void openPair(std::vector<VectorUnit> &Src, std::vector<VectorUnit> &Front, std::vector<VectorUnit> &Back){
	size_t i = 0;
	
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

void VectorSort(std::vector<VectorUnit> &src)
{
	if (src.size() <= 1){
		return;
	}
	std::vector<VectorUnit> Front;
	std::vector<VectorUnit> Back;
	std::vector<VectorUnit> Remainder;

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

// void ListSort(std::list<VectorUnit> &src)
// {

// }