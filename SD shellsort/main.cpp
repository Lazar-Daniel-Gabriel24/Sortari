#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std;
using namespace std::chrono;
int shellSort(int ar[], int n)
{
    int gap,i,temp,j;
    for(gap = n/2; gap > 0; gap /= 2)
    {

        for(i = gap; i < n; i += 1)
        {
            temp = ar[i];
            for(j=i;j>=gap && ar[j-gap]>temp;j -=gap)
                ar[j] = ar[j-gap];
            ar[j] = temp;
        }
    }
    return 0;
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

    shellSort(numere,SIZE);

    for (i = 0; i < SIZE;i++)
        cout<<numere[i]<<" ";
    cout << endl;
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout<<duration.count()<<"\n";
}
