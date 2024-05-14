#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief This function is to partition the array
 *
 * @param arr is the array to be sort
 * @param low is the low index of the array
 * @param high is the high index of the array
 * @return int is the partition index
 */
int partition(vector<int> &arr, int low, int high);

/**
 * @brief This function is to perform the quick sort
 *
 * @param arr is the array to be sort
 * @param low is the low index of the array
 * @param high is the high index of the array
 */
void quickSort(vector<int> &arr, int low, int high);

int main()
{
  // Input array
  vector<int> arr = {9, 5, 1, 8, 3, 2, 7, 6, 4};

  // Perform QuickSort
  quickSort(arr, 0, arr.size() - 1);

  // Print sorted array
  for (int num : arr)
  {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}

// Function to partition the array
int partition(vector<int> &arr, int low, int high)
{
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swap(arr[i], arr[j]);
    }
  }

  swap(arr[i + 1], arr[high]);
  return i + 1;
}

// Function to perform QuickSort
void quickSort(vector<int> &arr, int low, int high)
{
  if (low < high)
  {
    int pivotIndex = partition(arr, low, high);

    quickSort(arr, low, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, high);
  }
}
