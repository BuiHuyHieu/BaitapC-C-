#include<bits/stdc++.h>

using namespace std;

int StoI(char CHAR)
{
    return int(CHAR)-48;
}

int main()
{
    string tempNumBer="",Bignumber;
    int number,i;
    cout << "Enter the BigNumber: " ;
    cin >> Bignumber;
    cout <<"Enter the Number: " ;
    cin >> number;
    cout << endl;
    for(i=Bignumber.size()-1;i>=0;i--)
    {
        int mod=0;
        char temp = StoI(Bignumber[i]);
        int sum = temp*number;
       if(i==0)
       {
           ostringstream convert;
           int sum1 = sum+mod;
          convert << sum1;
          string tempo = convert.str();
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
    cout << "Result is: " << tempNumBer;

}
