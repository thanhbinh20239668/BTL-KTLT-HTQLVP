#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct date{
    int ngay;
    int thang;
    int nam;
};
struct benhnhan{
    int maso;
    char ten[50];
    char gioitinh[5];
    date ngaySinh;
    date ngaynhapvien;
    date ngayxuatvien;
    int ngaynamvien;
    int tienthuoc;
    float bhyt;
    int vienphi;
};
typedef benhnhan BN;
void Menu();
void xoaXuongDong(char x[]);
void nhapBenhnhan(BN &bn);
void inDon(BN bn);
void tinhsongaynamvien(BN *bn);
void tongvienphi(BN *bn);
void themBenhnhan(BN &bn);
void nhapDanhsachbenhnhan(BN ds[],int &n);
void xuatDanhsachbenhnhan(BN ds[],int n);
int main(){
   int chon =0;
   struct benhnhan ds[1000];
   int n=0;
   do
   {
    Menu();
    printf("\nNhap lua chon: ");
    scanf("%d", &chon);
    switch (chon)
    {
    case 0:
        {
        printf("\nThoat chuong trinh!\n");
        break;
        }
    case 1:
        {
            nhapDanhsachbenhnhan(ds,n);
            break;
        }
    case 2:
        {
            xuatDanhsachbenhnhan(ds,n);
            break;
        }
    case 3:
        {
            int ma;
            printf ("Nhap vao ma benh nhan can cap nhat: "); scanf ("%d", &ma);  
            //capnhat(ds,n,ma); 
            break;
        }
    case 4:
        {   
            int ma;
            printf ("Nhap vao ma benh nhan can xoa: "); scanf ("%d", &ma);
            //xoahoadon(ds,n,ma);
            n=n-1;
            break;
        }
    case 5:
        {
            int ma;
            printf ("Nhap vao ma benh nhan can tim: "); scanf ("%d", &ma);
            //timkiem(ds,n,ma);
            break;
        }
    case 6:
        {
            //themmothoadon(ds,n);
            n=n+1;
            break;
        }
    case 7:
        {
            xuatDanhsachbenhnhan(ds,n);
            //tinhtongdon(ds,n);
            break;
        }
    case 8:
        {
            //nhaptuFile(ds,n);
            break;
        }
    case 9:
        {
            //xuatvaoFile(ds,n);
            break;
        }
    default:
        {
        printf("\nLua chon khong hop le vui long nhap lai lua chon!\n");
            break;
        }
    }
   }while(chon != 0);
}
void xoaXuongDong(char x[]){
    size_t len = strlen(x);
    if(x[len-1]=='\n'){
        x[len-1]='\0';
    }
}
void nhapBenhnhan(BN &bn){
   printf ("\nMa so:"); scanf("%d", &bn.maso);
   printf("\nHo Ten:");getchar(); fflush(stdin);fgets(bn.ten, sizeof(bn.ten), stdin); xoaXuongDong(bn.ten);
   printf("\nGioi Tinh: "); fflush(stdin);fgets(bn.gioitinh, sizeof(bn.gioitinh), stdin); xoaXuongDong(bn.gioitinh);
   printf("\nNgay Sinh: "); scanf("%d/%d/%d", &bn.ngaySinh.ngay, &bn.ngaySinh.thang, &bn.ngaySinh.nam);
   printf("\nNgay nhap vien: "); scanf("%d/%d/%d", &bn.ngaynhapvien.ngay, &bn.ngaynhapvien.thang, &bn.ngaynhapvien.nam);
   printf("\nNgay xuat vien: "); scanf("%d/%d/%d", &bn.ngayxuatvien.ngay, &bn.ngayxuatvien.thang, &bn.ngayxuatvien.nam);
   printf("\nBao hiem y te chi tra %: "); scanf("%f", &bn.bhyt);
   printf("\nTien thuoc: "); scanf("%d", &bn.tienthuoc);
}
void inDon(BN bn){
    printf ("\n%6s \t %20s \t %10s \t %10s \t %10s \t %4s \t %5s \t %8s \t %8s","Ma so","Ten","Gioi tinh","Ngay sinh","Nhap vien","Ngay benh","BHYT%","Thuoc","Don");
    printf("\n%6d \t %20s \t %10s \t %d/%d/%d \t %d/%d/%d \t %4d \t %8.2f% \t %8d \t %8d", bn.maso, bn.ten, bn.gioitinh, bn.ngaySinh.ngay, bn.ngaySinh.thang, bn.ngaySinh.nam, bn.ngaynhapvien.ngay,bn.ngaynhapvien.thang,bn.ngaynhapvien.nam,bn.ngaynamvien,bn.bhyt,bn.tienthuoc,bn.vienphi);
}
void tinhsongaynamvien(BN *bn){
   int dem=0;
    if(bn->ngayxuatvien.nam==bn->ngaynhapvien.nam){
     if ((( bn->ngaynhapvien.nam % 4 == 0) && (bn->ngaynhapvien.nam % 100!= 0)) || (bn->ngaynhapvien.nam %400 == 0)){
        if(bn->ngayxuatvien.thang==bn->ngaynhapvien.thang){
            dem=bn->ngayxuatvien.ngay-bn->ngaynhapvien.ngay+1;}
        if(bn->ngayxuatvien.thang!=bn->ngaynhapvien.thang){
            if (bn->ngaynhapvien.thang==1,3,5,7,8,10,12) dem=(31-(bn->ngaynhapvien.ngay))+bn->ngayxuatvien.ngay + 1;
            if (bn->ngaynhapvien.thang==4,6,9,11) dem=(30-(bn->ngaynhapvien.ngay))+bn->ngayxuatvien.ngay + 1;
            else dem=(29-(bn->ngaynhapvien.ngay))+bn->ngayxuatvien.ngay + 1;}
     }
     else {
        if(bn->ngayxuatvien.thang==bn->ngaynhapvien.thang){
            dem=bn->ngayxuatvien.ngay-bn->ngaynhapvien.ngay +1 ;}
        if(bn->ngayxuatvien.thang!=bn->ngaynhapvien.thang){
            if (bn->ngaynhapvien.thang==1,3,5,7,8,10,12) dem=(31-(bn->ngaynhapvien.ngay))+bn->ngayxuatvien.ngay + 1;
            if (bn->ngaynhapvien.thang==4,6,9,11) dem=(30-(bn->ngaynhapvien.ngay))+bn->ngayxuatvien.ngay + 1;
            else dem=(28-(bn->ngaynhapvien.ngay))+bn->ngayxuatvien.ngay + 1;}
     }
    }
    else dem = 365*(bn->ngayxuatvien.nam - bn->ngaynhapvien.nam);
    bn->ngaynamvien=dem;
}
void tongvienphi(BN *bn){
    bn->vienphi = (bn->tienthuoc + bn->ngaynamvien*200000)*(1-(bn->bhyt)/100);
}
void themBenhnhan(BN &bn){
    nhapBenhnhan(bn);
    tinhsongaynamvien(&bn);
    tongvienphi(&bn);
    inDon(bn); 
}
void nhapDanhsachbenhnhan(BN ds[], int &n){
    system("cls");
    do{
        printf("\nNhap so luong benh nhan: "); scanf("%d", &n);}
        while(n<=0);
    for(int i=0; i<n; i++){
        printf("\nBenh nhan thu %d", i+1);
        themBenhnhan(ds[i]);
    }
}
void xuatDanhsachbenhnhan(BN ds[],int n){
    system("cls");
    for (int i=0; i<n; i++){
        inDon(ds[i]);
        printf("\n");
    }
}
void Menu(){
    printf("\n====================HE THONG QUAN LY VIEN PHI====================\n");
    printf("                      0. Thoat chuong trinh\n");
    printf("                      1. Nhap danh sach benh nhan\n");
    printf("                      2. Xuat danh sach benh nhan\n");
    printf("                      3. Cap nhat hoa don\n");
    printf("                      4. Xoa benh nhan\n");
    printf("                      5. Tim kiem hoa don theo ma so\n");
    printf("                      6. Them mot hoa don\n");
    printf("                      7. Tinh tong hoa don\n");
    printf("                      8. Nhap danh sach hoa don tu file\n");
    printf("                      9. Xuat danh sach hoa don vao file\n");
    printf("=================================================================\n");
}