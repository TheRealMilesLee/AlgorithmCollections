#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief A utility function to print the solution
 * @param parent is the vector of parent indices
 * @param n is the length of the parent vector
 * @return int is the number of lines
 */
int printSolution(const vector<int> &parent, int n);

/**
 * @brief A function to pretty print the words in a paragraph
 * @param words is the vector of lengths of words
 * @param maxWidth is the maximum width of each line
 */
void prettyPrint(const vector<int> &words, int maxWidth);

int main()
{
  vector<int> words = {10, 5, 3, 7, 5};  // Lengths of words
  int maxWidth = 15;                     // Maximum width of each line

  prettyPrint(words, maxWidth);

  return 0;
}

int printSolution(const vector<int> &parent, int n)
{
  int k;
  if (parent[n] == 0)
  {
    k = 1;
  }
  else
  {
    k = printSolution(parent, parent[n] - 1) + 1;
  }
  cout << "Line " << k << ": " << parent[n] << " to " << n << endl;
  return k;
}

void prettyPrint(const vector<int> &words, int maxWidth)
{
  int n = words.size();
  vector<int> dp(n, INT_MAX);
  vector<int> parent(n, 0);

  dp[0] = pow(maxWidth - words[0], 2);

  for (int i = 1; i < n; ++i)
  {
    int remainingSpace = maxWidth - words[i];
    dp[i] = dp[i - 1] + pow(remainingSpace, 2);
    parent[i] = 0;

    for (int j = i - 1; j >= 0; --j)
    {
      remainingSpace -= (words[j] + 1);  // Adding one for space between words
      if (remainingSpace < 0)
      {
        break;
      }
      int cost = (remainingSpace == 0) ? 0 : pow(remainingSpace, 2);
      int newCost = dp[j] + cost;
      if (newCost < dp[i])
      {
        dp[i] = newCost;
        parent[i] = j + 1;
      }
    }
  }

  cout << "Total minimum cost: " << dp[n - 1] << endl;
  cout << "Printing solution:" << endl;
  printSolution(parent, n - 1);
}
