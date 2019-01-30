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
        for(int j=0;j<width;j++)
        cout <<"*  ";
        cout <<endl;
    }
}

