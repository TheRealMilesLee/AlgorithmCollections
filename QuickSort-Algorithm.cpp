#include <iostream>
#include <vector>

using namespace std;

void mergeSort(vector<int>& arr);

int main()
{
  vector<int> arr = {12, 11, 13, 5, 6, 7};
  for (int arr_i : arr)
  {
    cout << arr_i << " ";
  }
  cout << endl;
  mergeSort(arr);
  for (int arr_i : arr)
  {
    cout << arr_i << " ";
  }
  cout << endl;
  return 0;
}

void mergeSort(vector<int>& arr)
{
  vector<vector<int>> splitVector;
  for (int i = 0; i < arr.size(); i++)
  {
    vector<int> temp;
    temp.push_back(arr[i]);
    splitVector.push_back(temp);
  }
  while (splitVector.size() > 1)
  {
    vector<vector<int>> mergedVector;
    for (int i = 0; i < splitVector.size(); i += 2)
    {
      if (i + 1 < splitVector.size())
      {
        vector<int> merged;
        int left = 0;
        int right = 0;
        while (left < splitVector[i].size() && right < splitVector[i + 1].size())
        {
          if (splitVector[i][left] < splitVector[i + 1][right])
          {
            merged.push_back(splitVector[i][left]);
            left++;
          }
          else
          {
            merged.push_back(splitVector[i + 1][right]);
            right++;
          }
        }
        while (left < splitVector[i].size())
        {
          merged.push_back(splitVector[i][left]);
          left++;
        }
        while (right < splitVector[i + 1].size())
        {
          merged.push_back(splitVector[i + 1][right]);
          right++;
        }
        mergedVector.push_back(merged);
      }
      else
      {
        mergedVector.push_back(splitVector[i]);
      }
    }
    splitVector = mergedVector;
  }
  arr = splitVector[0];
}
