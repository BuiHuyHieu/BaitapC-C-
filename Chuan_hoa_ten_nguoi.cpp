#include<bits/stdc++.h>

using namespace std;



int main()
{
    string S;
    getline(cin,S);
    int i;
    S=" "+S;
    for(i=0;i<S.length();i++)
    {
        if(S[i]==' ')
        {
            if((int)S[i+1]>=97) S[i+1]=S[i+1]-32;
        }
       else
        {
        if(S[i-1]!=' ')
        {
            if((int)S[i]<97) S[i]=S[i]+32;
        }
        }
    }
    S.erase(0,1);
    cout <<S;

	return 0;
}
