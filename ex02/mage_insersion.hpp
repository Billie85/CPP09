#pragma once

template <typename Container>
int Count(const Container &src){
	
	int count = 0;
	typename Container::const_iterator it;
	for(it = src.begin(); it != src.end(); it++) {
		count++;
	}
	return (count);
}

// Copy(Front, src);
template <typename Container>
void Copy(Container &front, Container &src){
	size_t len = front.size();
	src.clear();
	src.reserve(len);

	for (size_t i = 0; i < len; i++){
		//std::cout << "Frontの " << front[i].MainNumber << " をbuffにコピーしてる" << std::endl;

		Unit buff = front[i].MainNumber;
		buff.Index = i;// indexを作ってる。
		//buff.prevOfset = i; //いらない。
		buff.Haspair = false;
		src.push_back(buff);
	}

	//src にIndexgが渡されたか確認してる。
// 	//std::cout << "Index src After: " << std::endl;
// 	for (size_t i = 0; i < len; i++) {
//     int Index = src[i].Index;  // Index の値を取得
//     //std::cout << "src[" << i << "].Index = " << Index << std::endl;
// }
}

template <typename Container>
void SetHaspair(Container &src){
	for (size_t i = 0; i < src.size(); i++)
	{
		src[i].Haspair = true;
	}
}

template <typename Container>
typename Container::iterator BinarySearch(Container &target, Unit &searchNumber, size_t len)
{
	//std::listの場合ここのイテレータでoperator[]が必要になる。
	typename Container::iterator left = target.begin();

	while (len > 1) {
		if (searchNumber < left[len/2]) {
			len /= 2;
		} else {
			left += len / 2;
			len = len / 2 + len % 2;
		}
	}
	if (searchNumber < *left || !len){
		return(left);
	} else {
		return(left + 1);
	}
}

// J(0) = 0
// J(1) = 1
// J(n) = J(n-1) + 2 * J(n-2) （n > 1）

template <typename Container>
void openPair(Container &src, Container &Front, Container &Back){

    size_t i = 0;
    
    //std::list<Unit> ここのlistでoperator[]が必要になる。
    if (src.size()){

        size_t n1 = 1;
        size_t n2 = 1;
        size_t open = 1;
				//src のサイズが0でない場合回る
        while(open){
            for (; open; i--){
                while (src[i].Haspair && open){
                    size_t Index = src[i].Index;
                    src[i] = Front[Index];
                    src.insert(BinarySearch(src, Back[Index], i), Back[Index]);
                    open--;
                }
                if (!i)
                    break;
            }
            size_t hoge = n1 + 2 * n2;
            n2 = n1;
            n1 = hoge;
            hoge = n1 - n2;
            size_t len = src.size();
            for (; true; i++){
                if (src[i].Haspair){
                    open++;
                }
                if (open >= hoge || i + 1 >= len){
                    break;
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
		//std::cout << std::endl;
		//std::cout << " srcのサイズが1になりました。" << std::endl;
		return;
	}
	Container Front;
	Container Back;
	Container Remainder;
	//std::cout << std::endl;

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
