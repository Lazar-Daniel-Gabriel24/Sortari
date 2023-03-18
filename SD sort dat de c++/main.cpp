#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;

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

    sort(numere,numere + SIZE);

    for (i = 0; i < SIZE;i++)
        cout<<numere[i]<<" ";
    cout << endl;
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout<<duration.count()<<"\n";
}
