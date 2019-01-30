#include<bits/stdc++.h>

using namespace std;

void Swap(int &a,int &b)
{
    int temp;
    temp = a;
    a=b;
    b=temp;
}

int main()
{
    string s;
    int i,n,CHOT;
    cin >>n;
    int a[n];
    for(i=1;i<=n;i++) a[i]=i;
    while(1)
    {
    int j;
    for(j=1;j<n;j++)
    cout << a[j] << " ";
    cout <<a[n];
    cout <<endl;
    i=n-1;
    while((i>0) && (a[i]>a[i+1])) i--;
    if(i>0)
    {
        CHOT=n;
        while(a[CHOT]<a[i]) CHOT--;
        Swap(a[CHOT],a[i]);
        int b=i+1,c=n;
        while(b<c)
        {
            Swap(a[b],a[c]);
            b++;
            c--;
        }
    }

    if(i==0) break;
    }

	return 0;
}
