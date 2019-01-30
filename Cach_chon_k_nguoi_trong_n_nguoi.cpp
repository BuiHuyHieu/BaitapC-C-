#include<bits/stdc++.h>

using namespace std;

int gt(int n)
{
    if(n>=1)
    {
    return n*gt(n-1);
    }
    else return 1;
}

int main()
{
    int i,n,k;
    cin >>n >>k;
    cin.ignore();
    int a[n];
    for(i=1;i<=k;i++) a[i]=i;
    vector<string>Ten;
    Ten.push_back("Start");
    i=1;
    while(i<=n)
    {
        string s;
        getline(cin,s);
        Ten.push_back(s);
        i++;
    }
    cout << "Co " <<gt(n)/(gt(k)*gt(n-k)) << " cach chon va do la: "<<endl;
    while(1)
    {
    int j;
    for(j=1;j<k;j++)
    cout << Ten[a[j]] << " ";
    cout <<Ten[a[k]];
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
