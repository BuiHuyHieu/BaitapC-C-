#include<bits/stdc++.h>

using namespace std;


int main()
{
    int i,n,k;
    cin >>n >>k;
    int a[n];
    for(i=1;i<=k;i++) a[i]=i;
    while(1)
    {
    int j;
    for(j=1;j<k;j++)
    cout << a[j] << " ";
    cout <<a[k];
    cout <<endl;
    i=k ;
    while((i>0) && (a[i]==(n-k+i))) i--;
    if(i>0)
    {
        a[i]++;
        for(j=i+1;j<=k;j++) a[j]=a[j-1]+1;
    }

    if(i==0) break;
    }

	return 0;
}
