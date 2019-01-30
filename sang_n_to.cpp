#include<bits/stdc++.h>

using namespace std;


int main(){
    int i,j,n;
    cout << "Enter the number: ";
    cin >> n;
    vector<bool>mark(n+1,true);
    mark[0]=mark[1]=false;
    int choice = sqrt(n);
    while (i<=choice)
    {
        if (mark[i])
        {
            for(j=i*i;j<=n;j+=i)
            mark[j]=false;
        }
        i++;
    }
    cout << "Result is: " <<endl;
    for(i=0;i<=n;i++)
    if (mark[i]) cout << i <<" ";
}
