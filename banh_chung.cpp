#include<bits/stdc++.h>

using namespace std;


int main()
{
    int n,i,j;
    cout << "Nhap n le: ";
    cin >>n;
    for(int i=0;i<n;i++)
    {
        if((i==0)||(i==n-1)||(i==n/2))
        {
            for(j=0;j<n;j++)
            cout <<"* ";
        }
        else
        {
        for(j=0;j<n;j++)
        {
            if((j==i)||(j==n-1)||(j==0)||(j==n-i-1)) cout << "* "; else cout <<"  ";
        }
        }
        cout <<endl;
    }
}
