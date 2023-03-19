#include <iostream>

using namespace std;

int shellsort(int list[], int n)
{
    int gap,i,temp,j;
    for(gap = n/2; gap > 0; gap /= 2)
    {

        for(i = gap; i < n; i += 1)
        {
            temp = list[i];
            for(j=i;j>=gap && list[j-gap]>temp;j -=gap)
                list[j] = list[j-gap];
            list[j] = temp;
        }
    }
    return 0;
}
