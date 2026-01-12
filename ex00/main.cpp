#include "easyfind.hpp"

int main()
{
    try {
        std::vector<int> v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);

        std::vector<int>::iterator itv = easyfind(v, 20);
        std::cout << "Found in vector: " << *itv << std::endl;

        // test not found
        easyfind(v, 99);
    }
    catch (const std::exception& e) {
        std::cout << "Vector test: " << e.what() << std::endl;
    }

    try {
        std::list<int> l;
        l.push_back(1);
        l.push_back(2);
        l.push_back(3);

        std::list<int>::iterator itl = easyfind(l, 3);
        std::cout << "Found in list: " << *itl << std::endl;

        // test not found
        easyfind(l, -1);
    }
    catch (const std::exception& e) {
        std::cout << "List test: " << e.what() << std::endl;
    }

    return 0;
}
