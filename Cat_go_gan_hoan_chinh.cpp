#include<bits/stdc++.h>

    //Cat go co ban la dung con thieu so du, lam tuong tu voi thanh go so du la thanh go nho hon thoi
    //Luoi khong muon code lai :((

using namespace std;

int main()
{
    int n,m,i,j,k,resl=0,moneyfix,summoney;
    cin >> n;
    cout <<endl;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin >> a[i];
        cout <<endl;
    }
    cin >>m;
    cout << endl;
    int b[m],c[m];;
    for(i=0;i<m;i++)
    {
        cin >>b[i]>>c[i];
        cout <<endl;
    }
    for(k=0;k<n;k++)
    {
    summoney=0;
    int i=1;
    int MAX = 0;
    int local=0;int LENGTH=a[k];
    while(i<LENGTH)
    {
        int temp = c[0]*b[i];
        int comp = c[i]-temp;
        if (comp>=MAX)          // Kiem tra cat co thuan loi hay khong
        {
        MAX=comp;
        local=i;                //Lay phan cat
        }
        if (i==m-1) break;   // Neu ma so phan cat ma den cuoi thi dung lay cai max truoc
        else i++;
    }
    int cc = LENGTH/(b[local]);
    i=0;
    while(i<cc)
    {
        moneyfix++; // Tien chi phi sua may
        if (moneyfix>=c[local]) break;else      // Neu cat thay lo thi dung
        {
        summoney+=c[local]-moneyfix;       // tong tien thuc te
        i++;
        }
    }
    if(LENGTH-b[local]*cc>0) summoney+=c[LENGTH-b[local]*cc-1]; // Day chinh la phan luoi code
                                                                //cau nay chi la khi ma cat het phan thi lay luon
                                                                //tien con lai khong xet co thuan loi hay khong??
    cout << summoney <<endl;
    resl+=summoney;     // cong tong tien cac khuc go
    }
    cout <<resl;
    return 0;
}
