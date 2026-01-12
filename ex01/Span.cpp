#include "Span.hpp"

Span::Span()
: _maxSize(0), _numbers(){}

Span::Span(unsigned int n)
: _maxSize(n), _numbers(){}

Span::Span(const Span &other)
: _maxSize(other._maxSize), _numbers(other._numbers){}

Span& Span::operator=(const Span &other)
{
  if (this != &other)
  {
    _maxSize = other._maxSize;
    _numbers = other._numbers;
  }
  return *this;
}

Span::~Span() {}

const char* Span::FullSpanException::what() const throw()
{
  return "Span is full!";
}

const char* Span::NoSpanException::what() const throw()
{
  return "Not enough numbers to find a span";
}

void Span::addNumber(int value)
{
  if (_numbers.size() >= _maxSize)
    throw FullSpanException();
  _numbers.push_back(value);
}

int Span::longestSpan() const
{
  if (_numbers.size() < 2)
    throw NoSpanException();

  int minVal = *std::min_element(_numbers.begin(), _numbers.end());
  int maxVal = *std::max_element(_numbers.begin(), _numbers.end());

  return maxVal - minVal;
}

int Span::shortestSpan() const
{
  if (_numbers.size() < 2)
    throw NoSpanException();

  std::vector<int> tmp(_numbers);
  std::sort(tmp.begin(), tmp.end());

  int bestSpan = std::numeric_limits<int>::max();
  for (std::vector<int>::size_type i = 1; i < tmp.size(); ++i)
  {
    int currentSpan = tmp[i] - tmp[i - 1];
    if (currentSpan < bestSpan)
      bestSpan = currentSpan;
  }
  return bestSpan;
}

