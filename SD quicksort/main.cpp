#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std;
using namespace std::chrono;

int partitie(int *ar, int low, int high)
{
    int pivot=(rand()%(high-low+1))+low,i=low-1,j;
    swap(ar[pivot], ar[high]);
    for(j=low; j<high; j++)
        if(ar[j]<ar[high])
        {
            i++;
            swap(ar[i],ar[j]);
        }
    swap(ar[high],ar[i+1]);
    return i+1;
}
void quicksort(int *ar, int low, int high)
{
    int p;
    if(low<high)
    {
        p=partitie(ar,low,high);
        quicksort(ar,low,p-1);
        quicksort(ar,p+1,high);
    }
}
int main()
{
    srand(time(NULL));
    const int SIZE = 1000;
    int numere[SIZE]={0},i;
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    start = high_resolution_clock::now();
    for (i = 0; i < SIZE;i++)
        numere[i] = rand() % 100;

    quicksort(numere,0,SIZE-1);

    for (i = 0; i < SIZE;i++)
        cout<<numere[i]<<" ";
    cout << endl;
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout<<duration.count()<<"\n";

}
