#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std;
using namespace std::chrono;
void interclasare(int *ar, int st, int mi, int dr)
{
    int ar1 = mi - st + 1,ar2 = dr - mi,leftar[ar1],rightar[ar2],i,j;
    for(i = 0;i<ar1;i++)
        leftar[i]=ar[st + i];
    for(j = 0;j<ar2;j++)
        rightar[j]=ar[mi + 1 + j];
    int index1=0,index2=0,index=st;
    while(index1 < ar1  && index2 < ar2)
    {
        if(leftar[index1] <= rightar[index2])
        {
            ar[index] = leftar[index1];
            index1++;
        }
        else
        {
            ar[index] = rightar[index2];
            index2++;
        }
        index++;
    }
    while(index1<ar1)
    {
        ar[index]=leftar[index1];
        index++;
        index1++;
    }
    while(index2<ar2)
    {
        ar[index]=rightar[index2];
        index++;
        index2++;
    }

}
void mergesort(int *ar, int st, int dr)
{
    int mi=(st+dr)/2;
    if(st<dr)
    {
        mergesort(ar,st,mi);
        mergesort(ar,mi+1,dr);
        interclasare(ar,st,mi,dr);
    }
}
int main()
{
    srand(time(NULL));
    const int SIZE = 1000;
    int numere[SIZE]={0},i,j;
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    start = high_resolution_clock::now();
    for (i = 0;i<SIZE;i++)
        numere[i] = rand() % 100;
    mergesort(numere,0,SIZE-1);
    for(i = 0;i<SIZE;i++)
        cout<<numere[i]<<" ";
    cout<<endl;
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout<<duration.count()<<"\n";

}
