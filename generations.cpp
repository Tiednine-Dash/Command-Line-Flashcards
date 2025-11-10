#include <stack>
#include "generations.hpp"

std::string
convertDecimalToHex (size_t decimal)
{
  return convertDecimalToBase (decimal, HEX);
}

std::string
convertDecimalToBase (size_t decimal, int base)
{
  std::stack<char> s;

  do
  {
    s.push(DIGITS[decimal % base]);
    decimal /= base;
  } while(decimal > 0);

  std::string output = "";

  while (!s.empty())
  {
    output += s.top();
    s.pop();
  }

  return output;
}
