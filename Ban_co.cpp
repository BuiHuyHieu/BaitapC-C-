#include<bits/stdc++.h>
using namespace std;
int sumA=0,sumB=0;
int ketthuc(vector<vector<int>>mark)
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
            if(mark[i][j]==1) return 1;
    }
    return 0;
}
vector<vector<int>>taoDanhDau(vector<vector<int>>&mark)
{
    mark.resize(8);
    for(int i=0; i<8; i++)
    {
        mark[i].resize(8);
        for(int j=0; j<8; j++)
            mark[i][j]=1;
    }
    return mark;
}
vector<vector<string>>taoBanCo(vector<vector<string>>&banco)
{
    int dem=0;
    for(int i=0; i<34; i++)
        if(i%4==0&&i!=0)
        {
            banco[0][i]=(char)dem+48;
            dem++;
        }
        else
        {
            if(i%4==1) banco[0][i]="|";
            else banco[0][i]=" ";
        }
    dem=0;
    for(int i=1; i<18; i++)
    {
        if(i%2==0)
        {
            banco[i][0]=(char)dem+48;
            dem++;
            for(int j=1; j<34; j++)
                if(j%4==1) banco[i][j]="|";
                else
                    banco[i][j]=" ";

        }
        else
        {
            banco[i][0]=" ";
            for(int j=1; j<34; j++)
                if(j%4==1) banco[i][j]="|";
                else
                    banco[i][j]="-";
        }

    }
    return banco;
}
void printBanCo(vector<vector<string>>banco)
{
    for(int i=0; i<18; i++)
    {
        cout<<"\n\t     ";
        for(int j=0; j<34; j++)
            cout << banco[i][j];
    }
}
vector<vector<string>>xuLiBanCo(vector<vector<int>>&mark,vector<vector<string>>&banco,int pp,int m,int n)
{
    if(mark[m][n]==1)
    {
        if (pp==1)
        {
            banco[(m+1)*2][(n+1)*4]="A";
            sumA++;
        }
        else
        {
            banco[(m+1)*2][(n+1)*4]="B";
            sumB++;
        }
        mark[m][n]=0;
    }
    int kt=0;
    for(int i=2; i<18; i+=2)
    {
        if(mark[kt][n]==1)
        {
            if(pp==1)
            {
                banco[i][(n+1)*4]="a";
                sumA++;
            }
            else
            {
                banco[i][(n+1)*4]="b";
                sumB++;
            }
            mark[kt][n]=0;
        }
        kt++;
    }
    kt=0;
    for(int i=4; i<34; i+=4)
    {
        if(mark[m][kt]==1)
        {
            if(pp==1)
            {
                banco[(m+1)*2][i]="a";
                sumA++;
            }
            else
            {
                banco[(m+1)*2][i]="b";
                sumB++;
            }
            mark[m][kt]=0;
        }
        kt++;
    }

    return banco;
}

int main()
{
    cout << "\t\t\tCHESS BOARD\n";
    vector<vector<string>>banco;
    vector<vector<int>>mark;
    mark=taoDanhDau(mark);
    banco.resize(18);
    for(int i=0; i<18; i++)
        banco[i].resize(34);
    banco=taoBanCo(banco);
    printBanCo(banco);
    cout << endl;
    while(1)
    {
        if(ketthuc(mark)==1)
        {
            cout << endl;
            cout <<"Luot nguoi A\n";
            cout <<"Nguoi choi A chon: ";
            int m,n;
            cin >>m >>n;
            system("clear");
            banco=xuLiBanCo(mark,banco,1,m,n);
            printBanCo(banco);

        }
        else break;
        if(ketthuc(mark)==1)
        {
            cout <<endl;
            cout <<"Luot nguoi B\n";
            cout <<"Nguoi choi B chon: ";
            int m,n;
            cin >>m >>n;
            system("clear");
            banco=xuLiBanCo(mark,banco,2,m,n);
            printBanCo(banco);
        }
        else break;
    }
    cout <<"\n";
    cout <<"A: "<<sumA << " B: "<< sumB <<"\n";
    if(sumA>sumB) cout <<"A thang"; else cout <<"B thang ";
    return 0;
}
