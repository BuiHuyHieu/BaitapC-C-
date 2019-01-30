#include<bits/stdc++.h>

using namespace std;


int main()
{
    string S = "Xin chao tat ca cac ban ",token
    ;
   int i=0,j;
    vector<string>temp;
   while(i<S.length())
   {
        j=S.find(" ",i);
        string xuat = S.substr(i,j-i);
        temp.push_back(xuat);
        i=j+1;
   }
   for(j=0;j<temp.size();j++)
   cout << temp[j] <<endl;
    return 0;
}
