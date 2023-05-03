#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <cstdlib>

void removeSpaces(std::string& str) {
    std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
    str.erase(end_pos, str.end());
}

bool FindMinus(std::string& str) {
    return str.find('-') == std::string::npos;
}

bool CheckDecimals(std::string& str) {
    return str.find('.') != std::string::npos;
}

void inputData(std::ifstream &file, std::map<std::string, double>& CsvArray) {
    if (!file.is_open()) {
        std::cout << "Error: could not open file." << std::endl;
        return;
    }

    std::string str;
    std::string data;
    int numInt = 0;
    double numDouble = 0;
    while (getline(file, str, '|')) 
    {
        getline(file, data, '\n');
        removeSpaces(str);
        if (!FindMinus(data)) {//マイナスがあったら。
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        std::map<std::string, double>::iterator find = CsvArray.find(str);
        if (!CheckDecimals(data) && find != CsvArray.end()) 
        {//少数じゃない。
            printf("Int\n");
            numInt = atoi(data.c_str());
            std::cout << str << " => " << CsvArray[str] << " = " << CsvArray[str] * numInt << std::endl;
        }
        if (CheckDecimals(data) && find != CsvArray.end()) 
        {//少数。
            printf("double\n");
            numDouble = atof(data.c_str());
            std::cout << str << " => " << CsvArray[str] << " = " << CsvArray[str] * numDouble << std::endl;
        }
        else 
        {
            std::cout << "Error: bad input => " << str << std::endl;
            continue;
        }
    }
    file.close();
}
