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
    for (int i = start; i < end;i++)
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
    for (int i = 0;i < 8;i++)
        cout << arr[i] << " ";
    qSort(arr, 0, n - 1);
    cout << "\n After  \n";
    for (int i = 0;i < 8;i++)
        cout << arr[i] << " ";

    cout << "\n";
    return 0;
}
