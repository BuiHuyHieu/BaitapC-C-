#include<bits/stdc++.h>

using namespace std;

void nhapMATRIX(int a[][100],int &n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            {
                cout << "Nhap phan tu a[" << i << "]"<<"["<<j<<"]: ";
                cin >> a[i][j];
            }
}
int tinhDINHTHUC(int a[100][100],int n)
{
    if(n==1) return a[0][0];
    if(n==2) return (a[0][0]*a[1][1]-a[0][1]*a[1][0]);
    int dau,sum,bienChay;

        for(bienChay=0;bienChay<n;bienChay++)
        {
            int DINHTHUCBE[100][100];
                for(int i=1;i<n;i++)
                    for(int j=0;j<n;j++)
                    if(j<bienChay)
                    {
                    DINHTHUCBE[i-1][j]=a[i][j];
                    }
                        else
                        {
                        if(j>bienChay) DINHTHUCBE[i-1][j-1]=a[i][j-1];
                        }
            if(bienChay%2==0) dau=1; else dau=-1;
            sum+=a[0][bienChay]*dau*tinhDINHTHUC(DINHTHUCBE,n-1);
        }
        return sum;
}

void xuatMATRAN(int a[][100],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout << a[i][j]<<"   ";
                cout << endl;
    }
}
int main()
{
    int C[100][100],n;
    cout << "Nhap dinh thuc cap : ";
    cin >>n;
    nhapMATRIX(C,n);
    xuatMATRAN(C,n);
    cout <<"\n\nKET QUA DINH THUC LA: ";
    cout << tinhDINHTHUC(C,n);
    return 0;
}
