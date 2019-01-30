#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i,j,m,n,hang,cot;
    cout <<"Nhap so hang: ";
    cin >> m;
    cout <<"Nhap so cot: ";
    cin >>n;
    int a[m][n];
    int b[m-1][n-1];
     for (i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            cout <<"Nhap cac phan tu a" <<"["<<i<<j<<"]: ";
            cin >>a[i][j];
        }
    }
    for (i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            cout <<a[i][j] <<" ";
        }
        cout <<endl;
    }
    cout <<"Xoa hang nao: ";
    cin >>hang;
    cout <<"Xoa cot nao: ";
    cin >>cot;
    int i1=1;
     for (i=1;i<=m;i++)
    {
        int j1=1,kt=1;                  //kt la bien kiem tra xem hang day co duoc chon hay khong??
                                        //j1 la bien cot cho ma tran moi
        for(j=1;j<=n;j++)
        {
            if(i==hang)                 // Neu chay den hang thi thoat chay toi hang tiep theo thu tu
            {
                    break;
            }
            else
            {
                if(j!=cot)              // Neu khac cot thi gan gia tri tai vi tri do vao mang moi theo thu tu con khong thi thoi
                {
                b[i1][j1]=a[i][j];
                j1++;
                kt=0;                   //neu hang dc chon thi kt=0
                }
            }

        }
        if(kt==0)                       //kiem tra kt co thoa man ko
        {
        i1++;                           //tang hang cho ma tran moi
        }
    }
    for(i=1;i<m;i++)
    {
    for(j=1;j<n;j++)
       cout << b[i][j] <<" ";
       cout <<endl;
    }
    return 0;
}
