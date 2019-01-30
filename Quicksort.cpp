#include<bits/stdc++.h>

using namespace std;
int *taomang(int *n)
{
    int* a=NULL;
    a = new int[*n];
    for(int i=1;i<=*n;i++)
    cin >> a[i];
    return a;
}
void Quicksort(int *a,int first, int End)
{
    int i,j,temp;
    i = first;
    j = End;
    srand(time(NULL));
    int choice = a[first+random ()%(j-i)];
    while(i<=j)
    {
        while(a[i]<choice) i++;
        while (a[j]>choice) j--;
        if(i<=j)
        {
            int temp;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
            j--;
        }
    }
    if(first < j) Quicksort(a,first,j);
    if(i< End) Quicksort(a,i,End);
}
int main() {

    int n;
    cin >> n;
    int *A=taomang(&n);
    Quicksort(A,1,n);
    for(int i=1;i<=n;i++)
    cout <<A[i]<<" ";
	return 0;
}
