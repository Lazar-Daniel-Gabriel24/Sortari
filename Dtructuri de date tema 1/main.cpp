#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main()
{
    srand(time(NULL));
    const int SIZE = 1000;
    int numere[SIZE]={0}, maxim, buckets[10] = {0}, nivel, i, out[SIZE];
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    start = high_resolution_clock::now();
    for (i = 0; i < SIZE;i++)
        numere[i] = rand() % 100;
    maxim = numere[0];
    for (i = 1; i < SIZE;i++)
    {
        if (maxim < numere[i])
            maxim = numere[i];
    }
    for (nivel = 1; maxim/nivel > 0;nivel *=10)
    {
        for (i = 0; i < SIZE;i++)
            buckets[(numere[i] / nivel)%10]++;
        for (i = 1; i < 10;i++)
            buckets[i] += buckets[i-1];
        for (i = SIZE - 1; i >= 0;i--)
        {
            out[buckets[(numere[i] / nivel)%10]-1] = numere[i];
            buckets[(numere[i] / nivel) % 10]--;
        }
        for (i = 0; i < 10;i++)
            buckets[i] = 0;
        for (i = 0; i < SIZE;i++)
            numere[i] = out[i];
    }
    for (i = 0; i < SIZE;i++)
        cout<<numere[i]<<" ";
    cout << endl;
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout<<duration.count()<<"\n";
}
