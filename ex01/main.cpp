#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

static void basicTest()
{
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

static void bigTest()
{
    const unsigned int N = 10000;
    Span sp(N);

    std::srand(static_cast<unsigned int>(std::time(NULL)));

    std::vector<int> values;
    values.reserve(N);
    for (unsigned int i = 0; i < N; ++i)
        values.push_back(std::rand());

    sp.addRange(values.begin(), values.end());

    std::cout << "Big test (" << N << " numbers)" << std::endl;
    std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
    std::cout << "longestSpan : " << sp.longestSpan() << std::endl;
}

static void exceptionTest()
{
    try {
        Span sp(1);
        sp.addNumber(42);
        std::cout << sp.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception test (no span): " << e.what() << std::endl;
    }

    try {
        Span sp(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
    } catch (const std::exception& e) {
        std::cout << "Exception test (full): " << e.what() << std::endl;
    }
}

int main()
{
    try {
        basicTest();
        exceptionTest();
        bigTest();
    }
    catch (const std::exception& e) {
        std::cout << "Unhandled exception: " << e.what() << std::endl;
    }
    return 0;
}
