#include <iostream>

using namespace std;

int fibonacci(int n);

int main()
{
  cout << "The fibonacci sequence of 6 is: " << fibonacci(6) << endl;
  return 0;
}

int fibonacci(int n)
{
  if (n == 0 || n == 1)
  {
    return n;
  }
  else
  {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}
