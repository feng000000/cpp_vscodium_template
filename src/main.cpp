#include <iostream>
#include <vector>
#include <fstream>

#include "test/include_example.h"

int main()
{
    test::Example t;
    std::cout << "t.a: " << t.a << std::endl;

    std::vector<int> a;

    for (auto v : a)
    {
        std::cout << v << std::endl;
    }

    return 0;
}