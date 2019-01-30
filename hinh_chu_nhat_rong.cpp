#include<bits/stdc++.h>

using namespace std;

int main()
{
    int height,width;
    cout <<" Enter the height: ";
    cin >> height;
    cout <<" Enter the width: ";
    cin >> width;
    cout <<"Rectangle\n\n";
    for(int i=0;i<height;i++)
    {
        if((i==0)||(i==height-1))
        {
        for(int j=0;j<width;j++)
        cout <<"*  ";
        }
        else
        {
        for(int j=0;j<width;j++)
        if(j==0||j==width-1) cout <<"*  ";
        else
        {
            cout <<"   ";
        }
        }
        cout <<endl;
    }
}

