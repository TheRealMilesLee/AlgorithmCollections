#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool shuffle_BruteForce(string s, string PatternX, string PatternY);

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
  if (X != PatternX && Y != PatternY)
  {
    cout << "X: " << X << " Y: " << Y << endl;
    return false;
  }
  return true;
}
