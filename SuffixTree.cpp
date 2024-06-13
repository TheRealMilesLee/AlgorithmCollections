#include <cstddef>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> suffixTree(string incomingString);
int main()
{
  string incomingString;
  cout << "Input the string:";
  cin >> incomingString;

  vector<int> suffixArray = suffixTree(incomingString);
  cout << "The suffix tree is: ";
  for (size_t loop = 0; loop < suffixArray.size(); loop++)
  {
    cout << suffixArray.at(loop);
  }
}

vector<int> suffixTree(string incomingString)
{
  vector<int> suffixArray;
  vector<int> SA12;
  vector<int> SA0;
  // Grouping the incoming string into SA1,2 and SA 0
  for (size_t loop = 0; loop < incomingString.length(); loop++)
  {
    if (loop % 3 == 1 || loop % 3 == 2)
    {
      SA12.push_back(loop); // Is the suffix number that mod 3 = 1 or 2
    }
    else
    {
      SA0.push_back(loop); // Is the suffix number that mod 3 = 0
    }
  }
  vector<string> Group1;
  // Convert the SA number to 3 mers
  for (size_t loop = 0; loop < SA12.size(); loop++)
  {
    string concate =
        strcat(incomingString.at(SA12.at(loop)), incomingString.at(loop + 1));
    string concate2 = strcat(concate, incomingString.at(loop + 2));
    cout << concate << " " << endl;
    Group1.push_back(concate);
  }

  return suffixArray;
}
