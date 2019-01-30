#include<bits/stdc++.h>

using namespace std;
// Cai dat cau truc du lieu cho Node

struct sinhvien
{
    string Hoten;
    int tuoi;
    float diem_TB;
};
typedef struct sinhvien SINHVIEN;
struct Node
{
    SINHVIEN Data;
    struct Node* pNext;
};
typedef struct Node NODE;

struct List
{
    NODE *pHead;
    NODE *pTail;
};
typedef struct List LIST;
 // Khoi tao node
void init(LIST &l)
{
    l.pHead=l.pTail=NULL;
};
void NhapSinhVien(SINHVIEN &x)
{
    cout <<"TEN: ";
    getline(cin,x.Hoten);
    cout <<"TUOI: ";
    cin >>x.tuoi;
    cout <<"DIEM TB: ";
    cin >>x.diem_TB;
    cin.ignore();
}
void XuatSinhVien(SINHVIEN x)
{
    cout <<"\t\t"<< x.Hoten <<"\t\t" << x.tuoi <<"\t\t" <<x.diem_TB<<"\n";
}
//Tao node
NODE* GetNode(SINHVIEN x)
{
    NODE*p = new NODE;
    if(p==NULL)
    {
        return NULL;
    }
    else
    {
        p->Data=x;
        p->pNext=NULL;
    }
    return p;
}
// Them node theo kieu node nhap sau se day len truoc
void AddHead(LIST &l, NODE*p)
{
    if(l.pHead==NULL)
    {
        l.pHead=l.pTail=p;
    }
    else
    {
        p->pNext=l.pHead;
        l.pHead=p;
    }
}
//Them vao cuoi node nao nhap sau chen vao sau node nhap truoc
void AddTail(LIST &l, NODE*p)
{
    if(l.pHead==NULL)
    {
        l.pHead=l.pTail=p;
    }
    else
    {
        l.pTail->pNext=p;
        l.pTail=p;
    }
}
// Tao danh sach Lien ket
void GetData(LIST &l)
{
    init(l);
    int n;
    cout << "Ban muon nhap bao nhieu sinh vien: ";
    cin >>n;
    cin.ignore();
    for(int i=0;i<n;i++)
    {
        int n;
        SINHVIEN x;
        NhapSinhVien(x);
        NODE*p = GetNode(x);
        AddTail(l,p);

    }
}
// Xuat danh sach
void Print(LIST &l)
{
    int i=1;
    for(NODE*p=l.pHead;p;p=p->pNext)
    {
    cout<<"\t"<<i;
    i++;
    XuatSinhVien(p->Data);
    }
}

// Them cuoi
void themCuoi(LIST &l, NODE* p)
{
    l.pTail->pNext=p;
    l.pTail=p;

}
//Them dau
void themDau(LIST &l, NODE *p)
{
    p->pNext=l.pHead;
    l.pHead=p;
}
void themviTri(LIST &l,int i,NODE *p)
{
    if(i==1)
    {
        themDau(l,p);
        return;
    }
    int dem=0;
    for(NODE*k=l.pHead;k;k=k->pNext)
    dem++;
    if(i==dem)
    {
    themCuoi(l,p);
    return;
    }
    int kt=1;
    NODE *temp;
    for(NODE*k=l.pHead;k!=l.pTail;k=k->pNext)
    {
        if(kt==i)
        {
            temp->pNext=p;
            p->pNext=k;
            return;
        }
        else
        {
            kt++;
            temp=k;
        }
    }


}
// xoa node dau
void xoaDau(LIST &l)
{
    NODE*p = l.pHead;
    l.pHead = l.pHead->pNext;
    delete p;
}
//Xoa node cuoi
void xoaCuoi(LIST &l)
{
    NODE*p;
    for(NODE*k=l.pHead;k!=NULL;k=k->pNext)
    {
        if(k==l.pTail)
        {
            l.pTail=p;
            p->pNext=NULL;
            delete k;
            return;
        }
        p=k;
    }

}
void SuaNodeBatKi(LIST &l, int i)
{    if(i==1)
    {
       cout << "Ten sua la: ";
       getline(cin,l.pHead->Data.Hoten);
       cout <<"Tuoi sua la: ";
       cin>>l.pHead->Data.tuoi;
       cout <<"Diem sua la: ";
       cin>>l.pHead->Data.diem_TB;
        return ;
    }
    int dem=0;
    for(NODE*k=l.pHead;k;k=k->pNext)
    dem++;
    if(i==dem)
    {
      cout << "Ten sua la: ";
       getline(cin,l.pTail->Data.Hoten);
       cout <<"Tuoi sua la: ";
       cin>>l.pTail->Data.tuoi;
       cout <<"Diem sua la: ";
       cin>>l.pTail->Data.diem_TB;;
    return;
    }
    int kt=1;
    for(NODE*k=l.pHead;k;k=k->pNext)
    {
        if(kt==i)
        {
        cout << "Ten sua la: ";
       getline(cin,k->Data.Hoten);
       cout <<"Tuoi sua la: ";
       cin>>k->Data.tuoi;
       cout <<"Diem sua la: ";
       cin>>k->Data.diem_TB;
            return;
        }

    }

}
void XoaNodeBatKi(LIST &l, int i)
{    if(i==1)
    {
       xoaDau(l);
        return ;
    }
    int dem=0;
    for(NODE*k=l.pHead;k;k=k->pNext)
    dem++;
    if(i==dem)
    {
    xoaCuoi(l);
    return;
    }
    int kt=1;
    NODE*temp;
    for(NODE*k=l.pHead;k;k=k->pNext)
    {
        if(kt==i)
        {
            NODE*g = k->pNext;
            temp->pNext=g;
            delete k;
            return;
        }
        else{
        temp=k;
        kt++;
        }
    }

}

void Rescue(LIST &l)      // Giai phong Danh sach
{
    NODE* p;
    while(l.pHead!=NULL)
    {
        p=l.pHead;
        l.pHead=p->pNext;
        delete(p);
    }
}
int main() {
    LIST l;
    int choose;
    cout <<"     ==============================\n";
    cout << "\t\tMENU\n";
    cout <<"     ==============================\n";
    cout <<"     1.Tao danh sach Sinh Vien\n     2.Hien Thi danh sach sinh vien\n     3.Chen them sinh vien\n     4.Xoa mot sinh vien\n     5.Sua mot sinh vien\n     6.Ket thuc\n";
    cout <<"     ==============================\n";
    do
    {
        cout << "Xin moi ban chon chuc nang: ";
        cin>>choose;
        cin.ignore();
        switch(choose)
        {
            case 6:
            {
            cout << "Ban chon Ket thuc!!\n";
            break;
            }
            case 1:
            {
            GetData(l);
            break;
            }
            case 2:
           {
            cout <<"\t\t DANH SACH SINH VIEN\n";
            cout <<"\tSTT\t\tHo ten\t\tTuoi\t\tDiemTB\n";
            Print(l);
            break;
           }
            case 3:
            {
                   SINHVIEN x;
                   NhapSinhVien(x);
                   NODE* P=GetNode(x);
                   int vitri;
                   cout <<"Them vao vi tri sinh vien thu: ";
                   cin >>vitri;
                   themviTri(l,vitri,P);
                   break;
            }
            case 4:
            {
            int vt;
            cout <<"Xoa sinh vien thu: ";
            cin >>vt;
            XoaNodeBatKi(l,vt);
            break;
            }
            case 5:
            {
            int vt;
            cout <<"Sua sinh vien thu: ";
            cin >>vt;
            cin.ignore();
            SuaNodeBatKi(l,vt);
            break;
            }
            default:
            {
            cout<< "chon dung chuc nang!!!\n";
            break;
            }
        }
//       cout << "Ban con muon chon them chuc nang nao khong:?? 1 la co 0 la khong: ";
//       cin >> kt;
//       cin.ignore();
//       while((kt!=1 and kt!=0))
//       {
//       cout << "Xin ban nhap so 1 hoac 0\n";
//       cout << "Ban con muon chon them chuc nang nao khong:?? 1 la co 0 la khong: ";
//       cin >> kt;
//       cin.ignore();
//       }
    }while(choose!=6);
    Rescue(l);
	return 0;
}
