#include <iostream>
#include <vector>

#include "core/core.h"
#include "example_header/include_example.h"

namespace App
{
int run()
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

}  // namespace App
