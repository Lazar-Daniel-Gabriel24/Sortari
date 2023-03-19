#include <iostream>

using namespace std;

int partitie(int list[], int low, int high)
{
    int pivot=(rand()%(high-low+1))+low,i=low-1,j;
    swap(list[pivot], list[high]);
    for(j=low; j<high; j++)
        if(list[j]<list[high])
        {
            i++;
            swap(list[i],list[j]);
        }
    swap(list[high],list[i+1]);
    return i+1;
}
void quicksort(int list[], int low, int high)
{
    int p;
    if(low<high)
    {
        p=partitie(list,low,high);
        quicksort(list,low,p-1);
        quicksort(list,p+1,high);
    }
}
