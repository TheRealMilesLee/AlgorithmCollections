#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool shuffle_BruteForce(string s, string PatternX, string PatternY);

bool shuffle_DynamicProgramming(string s, string PatternX, string PatternY);
int main()
{
  string s = "caaabaacb";
  string PatternX = "aabacb";
  string PatternY = "caa";
  if (shuffle_BruteForce(s, PatternX, PatternY))
  {
    cout << "Yes, " << s << " are shuffle of " << PatternX << " and " << PatternY << endl;
  }
  else
  {
    cout << "No, " << s << " are not shuffle of " << PatternX << " and " << PatternY << endl;
  }

  string s2 = "ccaaaabab";
  if (shuffle_BruteForce(s2, PatternX, PatternY))
  {
    cout << "Yes, " << s2 << " are shuffle of " << PatternX << " and " << PatternY << endl;
  }
  else
  {
    cout << "No, " << s2 << " are not shuffle of " << PatternX << " and " << PatternY << endl;
  }

  cout << "Now using DP" << endl;
  if (shuffle_DynamicProgramming(s, PatternX, PatternY))
  {
    cout << "Yes, " << s << " are shuffle of " << PatternX << " and " << PatternY << endl;
  }
  else
  {
    cout << "No, " << s << " are not shuffle of " << PatternX << " and " << PatternY << endl;
  }

  if (shuffle_DynamicProgramming(s2, PatternX, PatternY))
  {
    cout << "Yes, " << s2 << " are shuffle of " << PatternX << " and " << PatternY << endl;
  }
  else
  {
    cout << "No, " << s2 << " are not shuffle of " << PatternX << " and " << PatternY << endl;
  }
  return 0;
}

bool shuffle_BruteForce(string s, string PatternX, string PatternY)
{
  string X = "";
  string Y = "";
  int X_size = 0;
  int Y_size = 0;
  for (size_t iterator = 0; iterator < s.size(); iterator++)
  {
    if (X_size < PatternX.size() && s[iterator] == PatternX[X_size])
    {
      X_size++;
      X += s[iterator];
    }
    else if (Y_size < PatternY.size() && s[iterator] == PatternY[Y_size])
    {
      Y_size++;
      Y += s[iterator];
    }
    else
    {
      return false;
    }
  }
  if (X_size < PatternX.size() || Y_size < PatternY.size())
  {
    return false;
  }
  else if (X != PatternX || Y != PatternY)
  {
    cout << "X: " << X << " Y: " << Y << endl;
    return false;
  }
  return true;
}

bool shuffle_DynamicProgramming(string s, string PatternX, string PatternY)
{
  vector<vector<bool>> dp(PatternX.size() + 1, vector<bool>(PatternY.size() + 1, false));
  dp[0][0] = true;
  for (size_t i = 0; i <= PatternX.size(); i++)
  {
    for (size_t j = 0; j <= PatternY.size(); j++)
    {
      if (i > 0 && s[i + j - 1] == PatternX[i - 1])
      {
        dp[i][j] = dp[i][j] || dp[i - 1][j];
      }
      if (j > 0 && s[i + j - 1] == PatternY[j - 1])
      {
        dp[i][j] = dp[i][j] || dp[i][j - 1];
      }
    }
  }
  return dp[PatternX.size()][PatternY.size()];
}
