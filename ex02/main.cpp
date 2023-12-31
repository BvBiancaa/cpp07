#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

int main()
{
  {
  Array<int> a(10);

  for (unsigned int i = 0; i < a.size(); i++)
    a[i] = i + 1;
  
  for (unsigned int i = 0; i < a.size(); i++)
    std::cout << a[i] << std::endl;
  
  Array<int> b = a;
  
  for (unsigned int i = 0; i < b.size(); i++)
    std::cout << b[i] << std::endl;
  
  Array<int> c;
  for (unsigned int i = 0; i < c.size(); i++)
    std::cout << c[i] << std::endl;
  
  Array<std::string> strings(5);
  for (unsigned int i = 0; i < strings.size(); i++)
    strings[i] = "ciao";
  for (unsigned int i = 0; i < strings.size(); i++)
    std::cout << strings[i] << std::endl;
  }
  {
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    std::cout << "OK" << std::endl;
    return 0;
  }
}