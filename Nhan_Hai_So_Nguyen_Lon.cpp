#include<bits/stdc++.h>

using namespace std;

int StoI(char CHAR)
{
    return int(CHAR)-48;
}
string nhan(string Bignumber, int number)
{
 string tempNumBer="";
    int i,sum,mod=0;

    for(i=Bignumber.size()-1;i>=0;i--)
    {
        //int mod=0;
        char temp = StoI(Bignumber[i]);
        sum = temp*number+mod;
       if(i==0)
       {
           ostringstream convert;   // khai bao phuong thuc chuyen so sang xau
           //int sum1 = sum+mod;
           convert << sum;         // dua so vao phuong thuc
           string tempo = convert.str(); // chuyen tu so sang xau
           tempNumBer = tempo + tempNumBer;
        }
        else
        {
            mod = sum/10;
            int les = sum-mod*10;
            char nb = les+48;
            tempNumBer = nb+tempNumBer;
        }
    }
    return tempNumBer;
}
string cong(string pharse1, string pharse2)
{
   string temp,temp1,res="";
    if (pharse1.size()>pharse2.size())
   {
   temp=pharse2;
    temp1=pharse1;
    }
    else
   {
    temp=pharse1;
    temp1=pharse2;
    };
   int i,mod=0,j,dem,t,t1,plut,sum;
    i=temp.size();
    j=temp1.size()-1;
    for(dem=0;dem<(j-i+1);dem++)
    temp="0"+temp;
    while (j>=0)
    {
        if(j==0)
       {
           ostringstream convert;
           t=StoI(temp[j]);
           t1=StoI(temp1[j]);
           int sum1 = t+t1+mod;
           convert << sum1;
           string tempo = convert.str();
           res= tempo + res;
        }
        else
     {
        t=StoI(temp[j]);
        t1=StoI(temp1[j]);
        sum=t+t1+mod;
        mod=(t+t1)/10;
        plut = sum-mod*10;
        res = (char) (plut+48)+res  ;

    }
    j--;
    }
    return res ;
}
string Purpose(string Number1, string Number2)
{
    int i=Number2.size()-1;
    int dem,run,j,j1;
    string k1="0",temp;
    for(run=i;run>=0;run--)
    {
        temp=nhan(Number1,StoI(Number2[run]));
        for(j1=0;j1<j;j1++)
        temp=temp+"0";
        j++;
        k1=cong(k1,temp);
    }
    return k1;
}
int main()
{
    string Number1,Number2;
    cout <<"Enter Number1: ";
    cin >>Number1;
    cout <<"Enter Number2: ";
    cin >>Number2;
    cout <<Purpose(Number1,Number2);
}
