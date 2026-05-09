#include <iostream>
#include <string>
using namespace std;

struct MonHoc{
    string id;
    string tenMH;
    int soDVHT;
    float diemSo;
};

#define MAX 10

struct DanhSach{
    MonHoc e[MAX];
    int n;
};

void themCuoi(DanhSach &ds, MonHoc newMH){
    if(ds.n>=MAX){
        cout <<"Ds day!";
        return;
    }
    ds.e[ds.n]=newMH;
    ds.n++;
}

void xoaPt2(DanhSach &ds){
    for(int i = 2;i<ds.n-1;i++){
        ds.e[i] = ds.e[i+1];
    }ds.n--;
}

void showAll(DanhSach ds){
    for(int i =0 ;i<ds.n;i++){
        cout <<ds.e[i].id<<" | "<<ds.e[i].tenMH<<" | "<<ds.e[i].soDVHT<<" | "<<ds.e[i].diemSo<<endl;
    }
}

int main(){
    DanhSach ds;
    ds.n = 5;
    MonHoc mh1 = {"MH01", "Toan", 3, 8.5};
    MonHoc mh2 = {"MH02", "Ly",   3, 7.0};
    MonHoc mh3 = {"MH03", "Hoa",  2, 6.5};
    MonHoc mh4 = {"MH04", "Anh",  2, 9.0};
    MonHoc mh5 = {"MH05", "Tin",  3, 8.0};

    ds.e[0] = mh1;
    ds.e[1] = mh2;
    ds.e[2] = mh3;
    ds.e[3] = mh4;
    ds.e[4] = mh5;

    themCuoi(ds, mh1);
    xoaPt2(ds);
    showAll(ds);

}