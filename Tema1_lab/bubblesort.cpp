#include <iostream>
using namespace std;

void bubblesort(int list[], int n)
{
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(list[i]>list[j]) swap(list[i],list[j]);
}
