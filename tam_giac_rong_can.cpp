#include<bits/stdc++.h>

using namespace std;

int main()
{
    int h;
    cout << "Nhap chieu cao: ";
    cin >>h;
    for(int i=1;i<h;i++)
    {
        for(int j=1;j<=(2*h-1);j++)
        {
        if((j==h-i+1)||(j==h+i-1)) // Muon ke them chieu cao tu dinh xuong day thi them dieu kien j==h
        {
            cout << "* ";
            }
            else{
            cout <<"  ";
            }
        }
        cout << endl;
    }
    for(int i=1;i<=(2*h-1);i++)
    cout <<"* ";
}

