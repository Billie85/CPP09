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

void removeSpaces(std::string& str);
bool FindMinus(std::string &str);
bool CheckDecimals(std::string &str);
std::map<std::string, float> CsvData(std::ifstream &file);
void inputData(std::ifstream &file, std::map<std::string, float> CsvArray);
void FloatPart(std::string &str, std::map<std::string, float> CsvArray);
void IntPart(std::string &str, std::map<std::string, float> CsvArray);
#endif