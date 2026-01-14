#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>
#include <limits>
#include <iterator>



class Span
{
  private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

  public:
    Span();
    Span(unsigned int n);
    Span(const Span &other);
    Span& operator=(const Span &other);
    ~Span();

    void addNumber(int value);

    template<typename InputIter>
    void addRange(InputIter first, InputIter last);

    long long shortestSpan() const;
    long long  longestSpan() const;

    class FullSpanException: public std::exception
    {
      public:
        virtual const char* what() const throw();
    };

    class NoSpanException: public std::exception
    {
      public:
        virtual const char* what() const throw();
    };
};

template<typename InputIter>
void Span::addRange(InputIter first, InputIter last)
{
  std::size_t count = static_cast<std::size_t>(std::distance(first, last));
  if (_numbers.size() + count > _maxSize)
    throw FullSpanException();

  _numbers.insert(_numbers.end(), first, last);
}

#endif
