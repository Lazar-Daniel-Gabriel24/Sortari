#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <algorithm>
#include <fstream>
#include "bubblesort.cpp"
#include "mergesort.cpp"
#include "quicksort.cpp"
#include "shellsort.cpp"
#include "radixsort.cpp"
using namespace std;
using namespace std::chrono;
ifstream fin("Test.txt");
#define SIZE 100000001

void GenerateList(int list[], int len, int min, int max) {
    for (int i = 0; i < len; i++)
        list[i] = rand() % (max - min + 1) + min;
}

void AfisList(const int list[], int len){
    for(int i = 0; i < len; i++)
        cout<<list[i]<<" ";
    cout<<"\n";
}

void CopyList(int newList[], int oldList[], int len) {
    for(int i = 0; i < len; i++)
        newList[i] = oldList[i];
}

bool tester(int list[], int n)
{
    for(int i=1; i<n; i++)
        if(list[i]<list[i-1]) return false;

    return true;
}

int numere[SIZE], copie[SIZE];

int main()
{
    srand(time(NULL));

    int i, T, maxim,n;
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    fin>>T;
    for(int i=1;i <= T;i++)
    {
        fin>>n>>maxim;
        GenerateList(numere, n, 0, maxim);
        cout<<"N:"<<n<<" "<<"Max:"<<maxim<<"\n";
        if(n<=1000000)
        {   CopyList(copie, numere, n);
            start = high_resolution_clock::now();
            bubblesort(copie,n);
            stop = high_resolution_clock::now();
            if(tester(copie, n))
                cout<<"succes\n";
            else cout<<"esec\n";
            duration = duration_cast<microseconds>(stop - start);
            cout<<"bubblesort:"<<duration.count()<<" microsecunde\n";
        }

        if(n<=1000000)
        {CopyList(copie, numere, n);
        start = high_resolution_clock::now();
        mergesort(copie,0,n - 1);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        if(tester(copie, n))
            cout<<"succes\n";
        else cout<<"esec\n";
        cout<<"mergesort:"<<duration.count()<<" microsecunde\n";}

        if(n<=1000000)
        {CopyList(copie, numere, n);
        start = high_resolution_clock::now();
        quicksort(copie,0,n-1);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        if(tester(copie, n))
            cout<<"succes\n";
        else cout<<"esec\n";
        cout<<"quicksort:"<<duration.count()<<" microsecunde\n";}

        if(n<=1000000)
        {CopyList(copie, numere, n);
        start = high_resolution_clock::now();
        shellsort(copie,n);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        if(tester(copie, n))
            cout<<"succes\n";
        else cout<<"esec\n";
        cout<<"shellsort:"<<duration.count()<<" microsecunde\n";}

        if(n<=1000000)
        {CopyList(copie, numere, n);
        start = high_resolution_clock::now();
        radixsort(copie,n);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        if(tester(copie, n))
            cout<<"succes\n";
        else cout<<"esec\n";
        cout<<"radixsort:"<<duration.count()<<" microsecunde\n";}

        if(n<=1000000)
        {CopyList(copie, numere, n);
        start = high_resolution_clock::now();
        sort(copie,copie+n);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        if(tester(copie, n))
            cout<<"succes\n";
        else cout<<"esec\n";
        cout<<"sort:"<<duration.count()<<" microsecunde\n";}

    }


}
