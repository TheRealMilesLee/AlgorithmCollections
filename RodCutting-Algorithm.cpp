#include <climits>  // For INT_MIN
#include <iostream>
using namespace std;

/**
 * @brief A utility function to get the maximum of two integers
 * @param a is the first integer
 * @param b is the second integer
 * @return int is the maxium integer
 */
int max(int a, int b);

/**
 * @brief A function to get the maximum obtainable value for a rod of length n and price[] as prices of different pieces
 * @param price is the array of prices of different pieces
 * @param index is the index of the price array
 * @param n is the length of the rod
 * @return int is the maximum obtainable value
 */
int cutRod(int price[], int index, int n);

int main()
{
  int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
  int size = sizeof(arr) / sizeof(arr[0]);
  cout << "Maximum Obtainable Value is " << cutRod(arr, size - 1, size) << endl;
  return 0;
}

int max(int a, int b) { return (a > b) ? a : b; }

int cutRod(int price[], int index, int n)
{
  // base case
  if (index == 0)
  {
    return n * price[0];
  }
  // if n is 0 we cannot cut the rod anymore.
  if (n == 0)
  {
    return 0;
  }

  // At any index we have 2 options either
  // cut the rod of this length or not cut
  // it
  int notCut = cutRod(price, index - 1, n);
  int cut = INT_MIN;
  int rod_length = index + 1;

  if (rod_length <= n)
    cut = price[index] + cutRod(price, index, n - rod_length);

  return max(notCut, cut);
}
