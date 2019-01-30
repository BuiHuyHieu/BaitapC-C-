#include<bits/stdc++.h>

    //Cat go co ban la dung con thieu so du, lam tuong tu voi thanh go so du la thanh go nho hon thoi
    //Luoi khong muon code lai :((

using namespace std;

int main()
{
    string s;
    int a[256]={0};
    getline(cin,s);
    for(int i=0;i<s.size();i++)
    a[s[i]]++;
    for(int i=0;i<256;i++)
    if(a[i]!=0) printf("%d%c",a[i],i);
    return 0;
}
