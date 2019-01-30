#include <iostream>

//Cho n thành phố đánh số từ 1 đến n và m tuyến đường giao thông hai chiều giữa chúng, mạng lưới
//giao thông này được cho bởi bảng C cấp nxn, ở đây C ij = C ji = Chi phí đi đoạn đường trực tiếp từ
//thành phố i đến thành phố j. Giả thiết rằng C ii = 0 với ∀i, C ij = +∞ nếu không có đường trực tiếp từ
//thành phố i đến thành phố j.
//Một người du lịch xuất phát từ thành phố 1, muốn đi thăm tất cả các thành phố còn lại mỗi thành
//phố đúng 1 lần và cuối cùng quay lại thành phố 1. Hãy chỉ ra cho người đó hành trình với chi phí ít
//nhất. Bài toán đó gọi là bài toán người du lịch hay bài toán hành trình của một thương gia
//(Traveling Salesman)
using namespace std;
const int MAX=20;
const int MAXS = 20*100;
int C[MAX][MAX];    // mảng giá tiền
int A[MAX],B[MAX];  // Mảng thử nghiệm đi thành phố và mảng  đường đi tối ưu nhất
bool choice[MAX];   // Đánh dấu thành phố đã đi qua
int T[MAX+1];       // Mảng tiền khi đi đến thành phố thứ i
int n,m,minspending;
void khoitao()      // Tạo mảng giá tiền cho chuyến đi từ thành phố này sang thành phố khác
{
    cin >>n >>m;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        if(i==j)
        {
        C[i][j]=0;
        }
        else
        {
        C[i][j]=MAXS;   // Nếu khoog có đường trực tiếp thì bằng vô cùng giá tiền
        };

    for(int k=1;k<=m;k++)
    {
        int i,j;
        cin >>i>>j;
        cin >>C[i][j];
        C[j][i]=C[i][j];
    }
}
void valueStart()
{
    for(int i=1;i<=n;i++)
    choice[i]=true;     // Đánh dấu các thành phố là chưa ddi qua hay là bắt đầu đi
    choice[1]=false;    // Bắt đầu từ thành phố 1 nên coi như đã đi qua
    T[1]=0;             // Tổnng tiền lúc đầu
    A[1]=1;             // thành phố đầu tiên
    minspending = MAXS; // khởi tạo số tiền nhỏ nhất = vô cùng
}
void Xuli(int i)
{
    int j;
    for(j=2;j<=n;j++)   // Bắt đầu từ thanh phố 2
    {
        if(choice[j])   // Nếu mà chưa đi qua
        {
            A[i]=j;     // Thử đi
            T[i]=T[i-1]+C[A[i-1]][j]; // Tính tiền khi đi qua
            if(T[i]<minspending)      //  nếu tiền nhỏ hơn lần đi trước thì đi
            {
                if(i<n)
                {
                    choice[j]=false; // Đánh dấu đã đi qua
                    Xuli(i+1);       // Chọn tiếp thành phố kế bằng đệ quy
                    choice[j]=true;// Khi chọn xong 1 đường đi thì --> cách 2
                }
                else
                {
                if((T[n]+C[A[n]][1])<minspending)// Khi đến thành phố cuối mà tổng tiền khi đi về từ thành phố đó tới 1 nhỏ hơn cách trước thì chọn cách này
                {
                    for(i=1;i<=n;i++)
                    B[i]=A[i];                  // Gansn vào cách đi tối ưu nhất
                    minspending=T[n]+C[A[n]][1];
                }
                }
            }
        }
    }

}
void INKQ() // IN kết quả đường đi và số tiền
{

    if(minspending==MAXS)
    {
        cout << "NOT FIND ";
    }
    else
    {
    for(int i=1;i<=n;i++)
    cout << B[i] <<"-->";
    cout << "1" <<endl;
    cout <<"Money: "<<minspending;
    }
}
int main() {
    khoitao();
    valueStart();
    Xuli(2);
    INKQ();
	return 0;
}
