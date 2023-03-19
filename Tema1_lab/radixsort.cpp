#include <iostream>
using namespace std;
void radixsort(int list[],int n){
	int maxim = list[0],buckets[10] = {0},out[n],nivel;
    for (int i = 1; i < n;i++)
    {
        if (maxim < list[i])
            maxim = list[i];
    }
    for (nivel = 1; maxim/nivel > 0;nivel *=10)
    {
        for (int i = 0; i < n;i++)
            buckets[(list[i] / nivel)%10]++;
        for (int i = 1; i < 10;i++)
            buckets[i] += buckets[i-1];
        for (int i = n - 1; i >= 0;i--)
        {
            out[buckets[(list[i] / nivel)%10]-1] = list[i];
            buckets[(list[i] / nivel) % 10]--;
        }
        for (int i = 0; i < 10;i++)
            buckets[i] = 0;
        for (int i = 0; i < n;i++)
            list[i] = out[i];
    }
}
