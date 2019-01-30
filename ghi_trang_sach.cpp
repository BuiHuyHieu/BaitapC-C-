#include<bits/stdc++.h>

using namespace std;
int main()
{
    int ngay, trang;
    cout <<"Nhap ngay: ";
    cin >> ngay;
    cout <<"Nhap trang: ";
    cin >> trang;
    int a[ngay];
    for(int i=1;i<=ngay;i++)
    cin >> a[i];
    int thua=0;
    for(int i=1;i<=ngay;i++)
    {
        cout <<"Ngay thu "<<i<<" lat so trang: "<<(a[i]+thua)/trang;
        int temp=(a[i]+thua)/trang;
        thua=a[i]-trang*temp;
        cout <<"\n";
    }
}
