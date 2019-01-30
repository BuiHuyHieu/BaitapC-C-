#include<bits/stdc++.h>

//Đề: xóa các số ở vị chẵn trước sau đó đến lẻ , cứ liên tục sao cho đến chỉ còn 1 số
//    số ban đầu được tạo thành bởi ghi liên tiếp các số từ 1 tới n. Ví dụ : n=5 thì số là 12345(từ 1 tới 5)
//                                                                           n=13 thì số là 112345678910111213..
//    vị trí đầu tiên là vị trí 1,... cho đến hết
//    ví dụ: n=5 12345 xóa lần 1 còn 135 xóa lần 2 còn 3;

using namespace std;
string Co(int n)
{
    string p="";
    for(int i=1;i<=n;i++)
    {
        ostringstream convert;
        convert << i;
        string temp = convert.str();
        p+=temp;
    }
     return p;

}
int main()
{
    int n;
    cin >> n;
    string so=Co(n);
    if (n==1) cout << "Ket qua: " <<n;      // Neu chi co 1 so thi in luon kqua
    else
    {
    while(1)
    {
    // do phan tu dau la vi tri 0 ma de bai mac dinh la vi tri 1 o dau nen chuyen bai toan thanh xoa le truoc
    so.erase(1,1);                          // Xoa phan tu le dau tien
    for(int i=2;i<so.size();i++)            // li do chay tu 2 vi khi bi xoa 1 phan thi so luong -1 va i tang 1 thi coi nhu vi tri i tiep theo se la i+2 phu hop vs tinh chat chan le
    so.erase(i,1);                          // Xoa phan tu i
    if(so.size()==1) break;                 // neu con lai 1nn thi thoat
    //tuong tu phan tren
    so.erase(0,1);
    for(int i=1;i<so.size();i++)
    so.erase(i,1);
    if(so.size()==1) break;
    }
    cout <<"Ket qua: " << so;
    }
    return 0;
}
