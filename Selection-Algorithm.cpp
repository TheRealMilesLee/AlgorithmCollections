#include <iostream>
#include <random>
#include <vector>
using namespace std;  // namespace std;

int find_nth_smallest(vector<int> &MyVector, int n);
int main()
{
  vector<int> MyVector;
  // Initialize random number generator with a seed
  random_device rd;
  mt19937 gen(rd());  // Mersenne Twister pseudo-random number generator

  // Define a distribution for integers between 1 and 100
  std::uniform_int_distribution<> dis(1, 100);

  // Generate and print 10 random numbers
  for (int i = 0; i < 25; ++i)
  {
    int random_number = dis(gen);
    MyVector.push_back(random_number);
  }
  cout << "Current list is: ";
  for (int iterator : MyVector)
  {
    cout << iterator << " ";
  }
  cout << endl << "The 15rd smallest element is: " << find_nth_smallest(MyVector, 15) << endl;
  return 0;
}

int find_nth_smallest(vector<int> &MyVector, int n)
{
  int pivot = MyVector[0];
  vector<int> less;
  vector<int> greater;
  for (size_t iter = 1; iter < MyVector.size(); iter++)
  {
    if (MyVector[iter] < pivot)
    {
      less.push_back(MyVector[iter]);
    }
    else
    {
      greater.push_back(MyVector[iter]);
    }
  }
  if (less.size() == n)
  {
    return pivot;
  }
  else if (less.size() > n)
  {
    return find_nth_smallest(less, n);
  }
  else
  {
    return find_nth_smallest(greater, n - less.size() - 1);
  }
  return 0;
}
