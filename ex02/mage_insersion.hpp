#pragma once
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
					Src[i] = Front[Src[i].prevOfset];//情報交換
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

	divideIntoThree(src, Front, Back, Remainder);//3つにただ分けてるだけ
	SwapBigger(Front, Back); //分けたものを上の部分をおきい方にする
	Copy(Front, src);//大きい方をコピー
	FordJohnsonAlgorithm(src);
	SetHaspair(src);
	openPair(src, Front, Back);  //もうペアができなくなくなったら、ここに入って、オープンしていく
	size_t i = Remainder.size(); 
	while (i--){//あまりぶち込む
		src.insert(BinarySearch(src, Remainder[i], src.size()),Remainder[i]);
	}
}
