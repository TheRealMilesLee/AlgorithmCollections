#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief This function is to solve knapsack problem using Dynamic Programming
 * @param W is the weight of the bag
 * @param wt is the weight of the item
 * @param val is the value of the item
 * @param n is the number of item
 * @return int is the total value you can get
 */
int knapsack(int W, const vector<int> &wt, const vector<int> &val, int n);

int main()
{
  int W;  // Knapsack capacity
  cout << "Enter the capacity of Knapsack: ";
  cin >> W;

  int n;  // Number of items
  cout << "Enter the number of items: ";
  cin >> n;

  vector<int> val(n);  // Values of items
  vector<int> wt(n);   // Weights of items

  cout << "Enter the values of items: ";
  for (int i = 0; i < n; ++i)
  {
    cin >> val[i];
  }

  cout << "Enter the weights of items: ";
  for (int i = 0; i < n; ++i)
  {
    cin >> wt[i];
  }

  int maxVal = knapsack(W, wt, val, n);
  cout << "The maximum value that can be obtained is: " << maxVal << endl;

  return 0;
}

int knapsack(int W, const vector<int> &wt, const vector<int> &val, int n)
{
  vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

  for (int i = 1; i <= n; ++i)
  {
    for (int w = 1; w <= W; ++w)
    {
      if (wt[i - 1] <= w)
      {
        dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
      }
      else
      {
        dp[i][w] = dp[i - 1][w];
      }
    }
  }

  return dp[n][W];
}
