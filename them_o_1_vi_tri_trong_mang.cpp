#include<bits/stdc++.h>

using namespace std;


int main()
{
    int n,k,add;
    cin >>n>>k>>add;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    cin >>a[i];
    n=n+1;
    for(int i=k;i<n;i++)
    a[i+1]=a[i];
    a[k]=add;
    for(int i=0;i<n;i++)
    cout << a[i];
}
