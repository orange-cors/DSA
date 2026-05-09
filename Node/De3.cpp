#include <iostream>
#include <string>
using namespace std;

struct CanBo{
    string maCB;
    string tenCB;
    int tuoi;
    float luong;
};

#define MAX 100

struct DanhSach{
    CanBo e[MAX];
    int n;
};

void xoaCB456(DanhSach &ds){
    int found = -1;
    for(int i = 0;i<ds.n;i++){
        if(ds.e[i].maCB=="456"){
            found = i;
            break;
        }
    }if(found==-1){
        cout <<"Khong tim thay!\n";
        return;
    }
    for(int j = found;j<ds.n-1;j++){
        ds.e[j] = ds.e[j+1];
    }ds.n--;
}

void hienThi(DanhSach ds){
    bool found = false;
    for(int i = 0;i<ds.n;i++){
        if(ds.e[i].tuoi<40){
            found = true;
            cout <<ds.e[i].maCB<<" | "<<ds.e[i].tenCB<<" | "<<ds.e[i].tuoi<<" | "<<ds.e[i].luong<<endl;
        }
    }if(!found) cout <<"Khong co cb nao!\n";
}

void showAll(DanhSach ds){
    for(int i =0 ;i<ds.n;i++){
        cout <<ds.e[i].maCB<<" | "<<ds.e[i].tenCB<<" | "<<ds.e[i].tuoi<<" | "<<ds.e[i].luong<<endl;
    }
}

int main(){
    DanhSach ds;
    ds.n = 5;
    CanBo mh1 = {"MH01", "Toan", 300, 8.5};
    CanBo mh2 = {"MH02", "Ly",   3, 7.0};
    CanBo mh3 = {"456f", "Hoa",  2, 6.5};
    CanBo mh4 = {"MH04", "Anh",  209, 9.0};
    CanBo mh5 = {"MH05", "Tin",  3, 8.0};

    ds.e[0] = mh1;
    ds.e[1] = mh2;
    ds.e[2] = mh3;
    ds.e[3] = mh4;
    ds.e[4] = mh5;

    // xoaCB456(ds);
    hienThi(ds);
    // showAll(ds);

}