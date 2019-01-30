#include<bits/stdc++.h>

using namespace std;

int dequifibo(int n)
{
    if(n==0) return 0;
    else
    {
        if(n==1) return 1;

        else
        {
            return dequifibo(n-1)+dequifibo(n-2);
        }
    }
}
    int main()
    {
        cout << dequifibo(40);
        return 0;
    }
