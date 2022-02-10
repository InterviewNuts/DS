/**
 * @file QuickSort.cpp
 * @author Haramohan Sahu (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-02-10
 *
 * @copyright Copyright (c) 2022
 *
 */

 /*
 Time Complexities
 Worst Case Complexity [Big-O]: O(n2)
 It occurs when the pivot element picked is either the greatest or the smallest element.

 This condition leads to the case in which the pivot element lies in an extreme end of the sorted array. One sub-array is always empty and another sub-array contains n - 1 elements. Thus, quicksort is called only on this sub-array.

 However, the quicksort algorithm has better performance for scattered pivots.
 Best Case Complexity [Big-omega]: O(n*log n)
 It occurs when the pivot element is always the middle element or near to the middle element.
 Average Case Complexity [Big-theta]: O(n*log n)
 It occurs when the above conditions do not occur.
 2. Space Complexity
 The space complexity for quicksort is O(log n).
 */
#include<iostream>
using namespace std;

void swap(int arr[], int i, int pindex)
    {
    int temp = arr[i];
    arr[i] = arr[pindex];
    arr[pindex] = temp;
    }


int Partition(int* arr, int start, int end)
    {
    int pindex = start;
    int pivot = arr[end];
    for (int i = start; i < end; i++)
        {
        if (arr[i] <= pivot)
            {
            swap(arr, i, pindex);
            pindex++;
            }
        }
    swap(arr, pindex, end);
    return pindex;
    }

void qSort(int* arr, int start, int end)
    {

    if (start < end)
        {
        int pindex = Partition(arr, start, end);
        qSort(arr, start, pindex - 1);
        qSort(arr, pindex + 1, end);
        }
    }

int main()
    {
    int arr[] = { 7,2,1,6,8,5,3,4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << " Before \n";
    for (int i = 0; i < 8; i++)
        cout << arr[i] << " ";
    qSort(arr, 0, n - 1);
    cout << "\n After  \n";
    for (int i = 0; i < 8; i++)
        cout << arr[i] << " ";

    cout << "\n";
    return 0;
    }
