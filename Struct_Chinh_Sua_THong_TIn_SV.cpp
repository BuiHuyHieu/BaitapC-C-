#include<bits/stdc++.h>

using namespace std;
typedef struct namsinh NAMSINH;
struct hocsinh
{
    string hoten;
    int namsinh;
    int toan;
    int van;
    int anh;
    float tb;
};
typedef struct hocsinh HOCSINH;
void Extraif(HOCSINH &hs)
{
        cout << "Ten sinh vien: ";
        getline(cin,hs.hoten);
        cout <<"Sinh vien sinh nam: ";
        cin >>hs.namsinh;
        cout <<"Diem toan sinh vien: ";
        cin >> hs.toan;
        cout <<"Diem van sinh vien: ";
        cin >> hs.van;
        cout <<"Diem toan sinh vien: ";
        cin >> hs.anh;
        hs.tb=(hs.toan+hs.van+hs.anh)/3;
        cin.ignore();
}
void PRINT(HOCSINH *hs, int &n)
{
    for(int i=0;i<n;i++)
    {
        cout << "Ten sinh vien la: " << hs[i].hoten <<"Sinh nam: "<<hs[i].namsinh <<"Diem toan: "<<hs[i].toan <<"Diem anh: "<<hs[i].anh << "Diem van: "<<hs[i].van <<"Diem trung binh:"<<hs[i].tb <<endl;
    }
}
void AddSinhVien(HOCSINH *hs, int &n)
{
    cout << "Nhap thong tin sinh vien can them: ";
    cin.ignore();
    Extraif(hs[n]);
    n++;
}
void DeleteSinhVien(HOCSINH *hs, int &n,int vitri)
{
    for(int i=vitri;i<n;i++)
    {
        hs[i]=hs[i+1];
    }
    n--;
}
void SortGiamDiem(HOCSINH *hs,int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
        {
            if(hs[i].tb<hs[j].tb)
            {
                HOCSINH TEMP;
                TEMP=hs[i];
                hs[i]=hs[j];
                hs[j]=TEMP;
            }
        }
}
void SortTangten(HOCSINH *hs,int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
        {
            if(hs[i].hoten>hs[j].hoten)
            {
                HOCSINH TEMP;
                TEMP=hs[i];
                hs[i]=hs[j];
                hs[j]=TEMP;
            }
        }
}
int main()
{
    int n;
    HOCSINH hs[1000];
    int choose;
    cout <<"\t=========================\t\n";
    cout <<"\t\t  MENU\n";
    cout <<"\t=========================\t\n";
    cout <<"\t0.Ket thuc \n \t1.Tao danh sach sinh vien \n \t2.In danh sach sinh vien \n \t3.Them mot sinh vien \n \t4.Xoa sinh vien theo thu tu \n\t5.Sap xep theo thu tu diem giam dan \n\t6.Sap xem theo thu tu Alphabet" << endl;
    cout <<"\t=========================\t\n";
    cout << "Xin moi ban chon chuc nang: ";
    cin >> choose;
    cout << endl;
    if(choose!=1)
    {cout << "tao danh sach truoc da nhe :(( \n\n";main();}
    else
    {
   while(choose!=0)
    {
    switch(choose)
    {
    case 0: break;
    case 1:
    {
    cout << "Nhap so sinh vien can them: ";
    cin >>n;
    cin.ignore();
    for(int i=0;i<n;i++)
    {
    cout <<"Nhap thong tin sinh vien thu "<<i+1<<":"<<endl;
    Extraif(hs[i]);
    }
    break;
    }
    case 2:
    {
    PRINT(hs,n);break;
    }
    case 3:
    {
        AddSinhVien(hs,n);break;
    }
    case 4:
    {
        int vt;
        cout << "Nhap vi tri can xoa >=0: ";
        cin >> vt;
        DeleteSinhVien(hs,n,vt);break;
    }
    case 5:
    {
        SortGiamDiem(hs,n);break;
    }
    case 6:
    {
      SortTangten(hs,n);break;}
    default:
    {
    cout <<"Khong chon chuc nang nao thi nhan 6 !!! \n";break;
    }
    }
    if(choose==0) break;
      else
      {
    cout <<"Ban muon chon them chuc nang nao: ";
    cin >>choose;
    }
    }
    }
    return 0;
}
