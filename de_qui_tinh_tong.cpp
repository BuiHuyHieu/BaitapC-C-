#include<bits/stdc++.h>

using namespace std;

int dequytong(int n)
{
    if(n==0) return 0;else return n+(dequytong(n-1));

}
int main()
{
    cout << dequytong(5);

}
