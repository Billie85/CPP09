#pragma once
/////////////////////////////////////////// Templat Function /////////////////////////////////////////////////////////////////

template <typename Container>
int Count(const Container &src){
	
	int count = 0;
	typename Container::const_iterator it;
	for(it = src.begin(); it != src.end(); it++) {
		count++;
	}
	return (count);
}

template <typename Container>

// Copy(Front, src);
void Copy(Container &front, Container &src){


// static int callCount = 0;
// //std::cout << std::endl;
// if (callCount == 0) {
// std::cout << "\033[36m"; // 赤色
// std::cout << "Copy に入った回数: " << ++callCount << std::endl;
// std::cout << "\033[0m";  // 色をリセット
// } else {
// callCount++;
// std::cout << "\033[36m"; // 緑色
// std::cout << "Copy に入った回数: " << callCount << std::endl;
// std::cout << "\033[0m";  // 色をリセット
// }

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

//origina src が渡ってくる。
void SetHaspair(Container &src){
	for (size_t i = 0; i < src.size(); i++)
	{
		src[i].Haspair = true;
	}
	//std::cout << std::endl;
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

	//src -> 9 , Front -> 9 7 10 , Back -> 8 1 4
void openPair(Container &src, Container &Front, Container &Back){

// static int callCount = 0;
// std::cout << std::endl;
// if (callCount == 0) {
// std::cout << "\033[31m"; // 赤色
// std::cout << "openPair に入った回数: " << ++callCount << std::endl;
// std::cout << "\033[0m";  // 色をリセット
// } else {
// callCount++;
// std::cout << "\033[31m"; // 緑色
// std::cout << "openPair に入った回数: " << callCount << std::endl;
// std::cout << "\033[0m";  // 色をリセット

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
					//std::cout << "src[i].Index の中身 ->" << Index << " [" <<  src[i] << "]" << std::endl;

                    src[i] = Front[Index];//ここで、srcとfrontを入れ替える、srcをとってそこに、frontがはいる。そして０番目の子供
					std::cout << "Front[Index] の中身 ->" << Front[Index] << " [" << Index <<  "]"<< std::endl;

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

static int callCount = 0;
//std::cout << std::endl;
if (callCount == 0) {
//std::cout << "\033[33m"; // 赤色
//std::cout << "SwapBigger に入った回数: " << ++callCount << std::endl;
//std::cout << "\033[0m";  // 色をリセット
} else {
callCount++;
//std::cout << "\033[33m"; // 緑色
//std::cout << "SwapBigger に入った回数: " << callCount << std::endl;
//std::cout << "\033[0m";  // 色をリセット
}



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
	for (size_t i = 0; i < len; i++)
	{
		//std::cout << i << "回" << " Front [" << Front[i] << "]" << std::endl;
	}
	//std::cout << std::endl;
	for (size_t i = 0; i < len; i++)
	{
		//std::cout << i << "回" << " Back [" << Back[i] << "]" << std::endl;
	}
	
}

template <typename Container>
void divideIntoThree(Container &src, Container &destFront, Container &destBack, Container &remainder){
		size_t len = src.size() / 2;
		size_t i = 0;

static int callCount = 0;
//std::cout << std::endl;
if (callCount == 0) {
//std::cout << "\033[31m"; // 赤色
//std::cout << "divideIntoThree に入った回数: " << ++callCount << std::endl;
//std::cout << "\033[0m";  // 色をリセット
} else {
callCount++;
//std::cout << "\033[31m"; // 緑色
//std::cout << "divideIntoThree に入った回数: " << callCount << std::endl;
//std::cout << "\033[0m";  // 色をリセット
}


		for (; i < len; i++){
			destFront.push_back(src[i]);
//std::cout << i << "回" << " Front [" << destFront[i] << "]" << std::endl;
		}
//std::cout << std::endl;

		len *= 2;
		for (; i < len; i++){
			destBack.push_back(src[i]);
		}

//destBackの出力確認
for (size_t i = 0; i < destBack.size(); i++)
{
//std::cout << i << "回" << " Back [" << destBack[i] << "]" << std::endl;
}
//std::cout << std::endl;
		
		for (; i < src.size(); i++){
			remainder.push_back(src[i]);
		}

//remainderの出力確認
for (size_t i = 0; i < remainder.size(); i++)
{
//std::cout << i << "回" << " remainder [" << remainder[i] << "]" << std::endl;
}
}



const char *color[] = {"\033[31m", "\033[32m", "\033[33m", "\033[34m", "\033[35m", "\033[36m", "\033[37m"};
size_t color_i = 0;

template <typename Container>
void FordJohnsonAlgorithm(Container &src)
{
size_t c_i = color_i % 7;
color_i++;
std::cout << color[c_i];

std::cout << "==Init src== の中身 " << std::endl;
for (size_t i = 0; i < src.size(); i++){
	std::cout << "[" << src[i] << "]";
}
std::cout << std::endl;


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

std::cout << "==before src== の中身 " << std::endl;
for (size_t i = 0; i < src.size(); i++){
	std::cout << "[" << src[i] << "]";
}
std::cout << std::endl;

std::cout << "==Front== の中身 " << std::endl;
for (size_t i = 0; i < Front.size(); i++){
	std::cout << "[" << Front[i] << "]";
}
std::cout << std::endl;

std::cout << "==Back== の中身 " << std::endl;
for (size_t i = 0; i < Back.size(); i++){
	std::cout << "[" << Back[i] << "]";
}
std::cout << std::endl;

	FordJohnsonAlgorithm(src);
std::cout << color[c_i];
std::cout << "==after src== の中身 " << std::endl;
for (size_t i = 0; i < src.size(); i++){
	std::cout << "[" << src[i] << "]";
}
std::cout << std::endl;

	SetHaspair(src);
	openPair(src, Front, Back);  //もうペアができなくなくなったら、ここに入って、オープンしていく
	size_t i = Remainder.size(); 
	while (i--){//あまりぶち込む
		src.insert(BinarySearch(src, Remainder[i], src.size()),Remainder[i]);
	}
}
