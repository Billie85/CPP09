#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <utility>
#include <fstream>
#include <sstream>
#include <climits>
#include <string>
#include <vector>
#include <string>
#include <cctype> 
#include <cfloat>
#include <map>
#include <queue>
#include <ctime>
#include <iomanip>

template <typename T>
void Sort(T start, int len);
template <typename T>
void print(T start, T end, std::string str);
void VecPart(std::stringstream &ss);
void DeqPart(std::stringstream &ss);
#endif