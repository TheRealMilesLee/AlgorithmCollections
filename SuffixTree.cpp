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
  cout << endl;
}

vector<int> suffixTree(string incomingString)
{
  vector<int> suffixArray;
  if (incomingString.length() == 0)
  {
    return suffixArray;
  }
  if (incomingString.length() == 1)
  {
    suffixArray.push_back(0);
    return suffixArray;
  }

  // Add a $ to the end of the string
  incomingString += "$";

  // Initialize the suffix array
  suffixArray.resize(incomingString.length());
  for (int i = 0; i < incomingString.length(); i++)
  {
    suffixArray[i] = i;
  }

  // Sort the suffix array using counting sort
  int alphabetSize = 256; // Assuming ASCII characters
  vector<int> count(alphabetSize, 0);
  vector<int> temp(suffixArray.size(), 0);

  for (int k = 0; k < incomingString.length(); k++)
  {
    count[incomingString[k]]++;
  }

  for (int k = 1; k < alphabetSize; k++)
  {
    count[k] += count[k - 1];
  }

  for (int k = incomingString.length() - 1; k >= 0; k--)
  {
    int c = incomingString[k];
    count[c]--;
    temp[count[c]] = suffixArray[k];
  }

  suffixArray = temp;

  return suffixArray;
}
