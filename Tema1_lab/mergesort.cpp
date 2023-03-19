#include <iostream>

using namespace std;

void interclasare(int list[], int st, int mi, int dr)
{
    int list1 = mi - st + 1,list2 = dr - mi,leftlist[list1],rightlist[list2],i,j;
    for(i = 0;i<list1;i++)
        leftlist[i]=list[st + i];
    for(j = 0;j<list2;j++)
        rightlist[j]=list[mi + 1 + j];
    int index1=0,index2=0,index=st;
    while(index1 < list1  && index2 < list2)
    {
        if(leftlist[index1] <= rightlist[index2])
        {
            list[index] = leftlist[index1];
            index1++;
        }
        else
        {
            list[index] = rightlist[index2];
            index2++;
        }
        index++;
    }
    while(index1<list1)
    {
        list[index]=leftlist[index1];
        index++;
        index1++;
    }
    while(index2<list2)
    {
        list[index]=rightlist[index2];
        index++;
        index2++;
    }

}
void mergesort(int ar[], int st, int dr)
{
    int mi=(st+dr)/2;
    if(st<dr)
    {
        mergesort(ar,st,mi);
        mergesort(ar,mi+1,dr);
        interclasare(ar,st,mi,dr);
    }
}
