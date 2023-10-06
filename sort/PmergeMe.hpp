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

bool checkValueError(const std::string& arg);

template <typename T>
T pushToContainer(const std::string& value) {
    T container;
    std::istringstream array(value);
    
    int num;
    while (array >> num) {
        container.push_back(num);
    }
    
    return container;
}

#endif