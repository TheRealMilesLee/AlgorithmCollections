#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief This function is used to search for a target element in a sorted vector using binary search algorithm
 * @param IncomingVector is a sorted vector
 * @param Target is the element to be searched
 * @return int is the index of the target element in the vector
 */
int BinarySearch(vector<int> IncomingVector, int Target);

int main()
{
  vector<int> IncomingVector = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int Target = 5;
  int Result = BinarySearch(IncomingVector, Target);
  if (Result == -1)
  {
    cout << "Element not found" << endl;
  }
  else
  {
    cout << "Element found at index " << Result << endl;
  }
  return 0;
}

int BinarySearch(vector<int> IncomingVector, int Target)
{
  int Left = 0;
  int Right = IncomingVector.size() - 1;
  while (Left <= Right)
  {
    int Mid = Left + (Right - Left) / 2;
    if (IncomingVector.at(Mid) == Target)
    {
      return Mid;
    }
    if (IncomingVector.at(Mid) < Target)
    {
      Left = Mid + 1;
    }
    else
    {
      Right = Mid - 1;
    }
  }
  return -1;
}
