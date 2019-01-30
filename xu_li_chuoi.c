#include<stdio.h>
#include<string.h>
#include<stdlib.h>
        // Các thao tác xử lí xâu cần nhớ do Hiệu biên soạn
//Nhap chuoi co chua ki tu i
int main(){
    char chuoi[50],temp[50];
    gets(chuoi);
    printf("Do dai chuoi %d:\n",strlen(chuoi)); // Lay do dai chuoi
    char *s=(char*)malloc(50*sizeof(char)); // Cap phat bo nho cho con tro s
    strcpy(s,chuoi);                        // copy chuoi vao s
    printf("chuoi copy la :%s\n",s);
    strncpy(temp,chuoi,3);                 // copy vao chuoi temp tu chuoi bat dau o vi tri i(doi so la chuoi+i=i) cuoi cung la so pha tu
    printf("chuoi copy bat ki la %s\n",temp);
    strcat(temp,chuoi);                     // ghep chuoi chuoi vao chuoi temp;
    printf("Chuoi ghep la: %s\n",temp);
    char *chuoiTrich;
    chuoiTrich = strchr(chuoi,'i');             // Trich chuoi tu vi tri co ki tu i toi het ( thay i bat ki) tuong tu la ham strstr chi thay ki tu la tu 1 chuoi nao do
    printf("Chuoi trich la: %s\n",chuoiTrich);
    char so[10];
    printf("Nhap chuoi chuyen thanh so: ");
    fflush(stdin);
    gets(so);
    int SO = atoi(so);                          // chuyn chuoi thanh so sang dang int con l thi la atol(s) va thuc la stof(s)
    printf("Chuyen thanh cong so do la: %d\n",SO);
    char MEMS[10]="";                           // Khoi tao chuoi rong de dat ki tu
    memset(MEMS,'H',3);                         // Khoi tao trong chuoi rong MEMS 3 ki tu dau tien la H(tong quat thay H la ki tu bat ki va 3 la so luong bat ki)
    printf("Dat thanh cong va chuoi la: %s\n",MEMS);
    char kt, kt1;
    scanf("%c%c",&kt,&kt1);
    kt=toupper(kt);                            //doi ki tu thuong thanh hoa ap dung vao bai doi chuoi thuong thanh hoa
    kt1=tolower(kt1);                         // doi ki tu hoa thanh thuong ap dung bai doi chuoi hoa thanh thuong
    printf("%c%c",kt,kt1);
    //strcmp(s1,s2) so sanh chuoi s1 va s2 co phan biet thuong hoa con stricmp(s1,s2) la khong phan biet
    free(s);            // Dung con tro xong nho giai phong
    free(chuoiTrich);
    return 0;
}
