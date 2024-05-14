#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief  This function is to perform the merge sort
 *
 * @param arr is the array to be sort
 * @param left is the left side of the array
 * @param middle is the middle side of the array
 * @param right is the right side of the arrat
 */
void merge(vector<int> &arr, int left, int middle, int right);

/**
 * @brief This function is entry point for the merge sort
 *
 * @param arr is the array to be sort
 * @param left is the left side of the array
 * @param right is the right side of the arrat
 */
void mergeSort(vector<int> &arr, int left, int right);

int main()
{
  vector<int> arr = {12, 11, 13, 5, 6, 7};
  for (int arr_i : arr)
  {
    cout << arr_i << " ";
  }
  cout << endl;
  mergeSort(arr, 0, arr.size() - 1);
  for (int arr_i : arr)
  {
    cout << arr_i << " ";
  }
  cout << endl;
  return 0;
}

void merge(vector<int> &arr, int left, int middle, int right)
{
  int n1 = middle - left + 1;
  int n2 = right - middle;

  vector<int> L(n1), R(n2);

  for (int i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[middle + 1 + j];

  int i = 0, j = 0, k = left;

  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(vector<int> &arr, int left, int right)
{
  if (left >= right)
    return;
  int middle = left + (right - left) / 2;
  mergeSort(arr, left, middle);
  mergeSort(arr, middle + 1, right);
  merge(arr, left, middle, right);
}
