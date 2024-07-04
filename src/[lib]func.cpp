#include <iostream>
#include <algorithm>

#include "[h]func.hpp"

int ecount(int v[9], int element)
{
    int element_count = std::count(v, v + 9, element);
    return element_count;
};
