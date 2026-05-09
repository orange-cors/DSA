#include <iostream>
#include <string>
using namespace std;

struct MonHoc{
    string maMH;
    string tenMH;
    int soDVHT;
    float diem;
};

#define MAX 20

struct DanhSach{
    MonHoc e[MAX];
    int n;
};

void nhapDuLieu(DanhSach &ds){
    for(int i = 0;i<ds.n;i++){
        cout <<"Nhap maMH: ";
        getline(cin, ds.e[i].maMH);

        cout <<"Nhap tenMH: ";        
        getline(cin, ds.e[i].tenMH);

        cout <<"Nhap soDV: ";
        cin >> ds.e[i].soDVHT;

        cout <<"Nhap diem: ";
        cin >> ds.e[i].diem;
        cin.ignore();
    }
}

void showAll(DanhSach ds){
    for(int i =0 ;i<ds.n;i++){
        cout <<ds.e[i].maMH<<" | "<<ds.e[i].tenMH<<" | "<<ds.e[i].soDVHT<<" | "<<ds.e[i].diem<<endl;
    }
}

int main(){
    DanhSach ds;
    ds.n = 3;
    // MonHoc mh1 = {"MH01", "Toan", 300, 8.5};
    // MonHoc mh2 = {"MH02", "Ly",   3, 7.0};
    // MonHoc mh3 = {"456f", "Hoa",  2, 6.5};
    // MonHoc mh4 = {"MH04", "Anh",  209, 9.0};
    // MonHoc mh5 = {"MH05", "Tin",  3, 8.0};

    // ds.e[0] = mh1;
    // ds.e[1] = mh2;
    // ds.e[2] = mh3;
    // ds.e[3] = mh4;
    // ds.e[4] = mh5;

    // xoaCB456(ds);
    // hienThi(ds);
    // showAll(ds);
    nhapDuLieu(ds);
    showAll(ds);

}