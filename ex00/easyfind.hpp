#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>
#include <list>


class NotFoundException: public std::exception
{
  public:
    virtual const char* what() const throw()
    {
      return "Easyfind: value not found";
    }
};

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
  typename T::iterator iter = std::find(container.begin(), container.end(), value);
  if (iter == container.end())
    throw NotFoundException();
  return iter;
}

template <typename T>
typename T::const_iterator easyfind(const T& container, int value)
{
  typename T::const_iterator iter = std::find(container.begin(), container.end(), value);
  if (iter == container.end())
    throw NotFoundException();
  return iter;
}

#endif
