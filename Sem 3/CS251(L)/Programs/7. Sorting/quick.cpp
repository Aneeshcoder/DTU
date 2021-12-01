#include<iostream>
using namespace std;

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(int a[], int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = partition(a, low, high);
        quickSort(a, low, pivot - 1);
        quickSort(a, pivot + 1, high);
    }
}

int main(){
    int a[] = {5,3,2,4,1};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<endl<<"Before Quick Sort: ";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    quickSort(a, 0, n-1);
    cout<<endl<<endl<<"After Quick Sort: ";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl<<endl;
    return 0;
}