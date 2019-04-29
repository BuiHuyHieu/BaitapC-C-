#include<iostream>
#include<sstream>
#include<string>
#include<conio.h>
#include<windows.h>

using namespace std;

struct hoa_don
{
	string ten_hang;
	int so_luong;
	int tien_ban;

};
struct thu_nhap
{
	struct hoa_don hoadon[1000];
	int tong_tien;
};
typedef struct thu_nhap tn;

class ban_Hang
{
private:
	tn THUNHAP;
	int i;
public:
	ban_Hang() {
		i = 1;
		THUNHAP.hoadon[i].ten_hang = "Update";
		THUNHAP.hoadon[i].so_luong = 0;
		THUNHAP.hoadon[i].tien_ban = 0;
		THUNHAP.tong_tien = 0;
	}
	void tao_don()
	{
		cout << "Nhap don thu " << i << endl;
		fflush(stdin);
		cout << "Nhap ten hang thu " << i << " : ";
		getline(cin, THUNHAP.hoadon[i].ten_hang);
		cout << "Nhap so luong hang: ";
		cin >> THUNHAP.hoadon[i].so_luong;
		cout << "Nhap so tien ban: ";
		cin >> THUNHAP.hoadon[i].tien_ban;
		cout << "\n";
		fflush(stdin);
	}
	void xuat_don()
	{
		if(i==1) cout <<"Da het don hang!" ;else
		{
		for(int k=1;k<i;k++)
		{
		cout << "Don thu: " << k << endl;
		cout << " Ten hang: " << THUNHAP.hoadon[k].ten_hang << "\n so luong: " << THUNHAP.hoadon[k].so_luong << "\n Gia ban: " << THUNHAP.hoadon[k].tien_ban;
		cout <<"\n\n";
	    }
		}
	}
	void huy_don(int index)
	{
		for(int k=index;k<i;k++)
		{
			THUNHAP.hoadon[k]=THUNHAP.hoadon[k+1];
		}
		this->i--;
	}
	int tiep()
	{
		return this->i++;
	}
	int tong_hoa_don() 
	{
		int k=i;
		return --k;
	}
	int tong_tien_nhan()
	{
		THUNHAP.tong_tien=0;
		for(int k=1;k<=i;k++)
		THUNHAP.tong_tien+=THUNHAP.hoadon[k].so_luong*THUNHAP.hoadon[k].tien_ban;
		
		return THUNHAP.tong_tien;
	}
	void thay_gia(int index)
	{
		int value;
		cout <<"Nhap gia can thay: ";
		cin >> value;
		THUNHAP.hoadon[index].tien_ban=value;
	}
			
};
int main()
{
	char start;
	cout <<"\t\t\t\t===== DAY LA PHAN MEM BAN HANG=====\n\n";
	cout <<"\t\t\t\tNhan 1 de bat dau nhan 0 de thoat ";
	if(!kbhit())
	{
		start = getch();
		  switch(start)
		  {
		  	case '1': goto software;break;
		  	case '0': cout<<"Nho quay lai !!";break;
		  }
			
	}
	software: 
		system("cls");
		int s=20;
		for(int i=1;i<=5;i++)
		{
			cout<<"LOADING";
					for(int i=1;i<7;i++)
					{
						cout<<".";
						Sleep(200);
					}
			cout << s <<"%";
			s+=20;
			Sleep(500);
			system("cls");
		}
	    system("cls");	
	    ban_Hang doanhthu;
		int input;
		do
		{
		cout<<"\t \t \t MENU\n";
		cout <<" ==============================================================\n";
		cout<<"|  1: Tao cac don hang                                         |\n";
		cout<<"|  2: Huy mot don hang                                         |\n";
		cout<<"|  3: Tong so don hang                                         |\n";
		cout<<"|  4: Tong so tien nhan duoc                                   |\n";
		cout<<"|  5: Thay doi gia don hang                                    |\n";
		cout<<"|  6: Xuat nhung don hang                                      |\n";
		cout<<"|  7: Thoat                                                    |\n";
		cout<<" ===============================================================\n";
		cout <<"\nNhap chuc nang: ";
		cin >> input;
		switch(input)
		{
				case 1: 
				{
						int ktra;
						do
						{
							doanhthu.tao_don();
							doanhthu.tiep();
							cout << "Nhap tiep thi nhan 1 khong thi nhan 0!: ";
							cin >> ktra;
	   					 }while(ktra==1);
	   					 break;
				}
				case 2: 
				{
					int vitri;
					cout << "Huy don hang so: ";
					cin>>vitri;
					doanhthu.huy_don(vitri);
					break;
				}
				case 3:
					{
						cout << "Tong so hoa don:  "<<doanhthu.tong_hoa_don()<<endl;
						break;
					}
				case 4:
					{
						cout <<"Tong tien thu duoc la: "<<doanhthu.tong_tien_nhan()<<endl;
						break;
					}
				case 6:
					{
						cout <<"Nhung don hang da ban la: \n";
						doanhthu.xuat_don();
						break;
					}
				case 5:
					{
						int vitri;
						cout << "Thay doi gia don vi tri so: ";
						cin >> vitri;
						doanhthu.thay_gia(vitri);
						break;
					}
				case 7:
					{
						cout <<"Lan sau nho ghe qua! <3";
						break;
					}
		}
			
		}while(input!=7);

	return 0;
}

