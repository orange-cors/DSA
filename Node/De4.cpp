#include <iostream>
#include <string>
using namespace std;

struct Sach{
    int id;
    string tenSach;
    string tenTg;
    int namXb;
};

struct Node{
    Sach infor;
    Node* next;
};

typedef Node* NodePtr;

void createEmpty(NodePtr &L){
    L=NULL;
}

void insertLast(NodePtr &L, Sach newSach){
    NodePtr P = new Node;
    P->infor = newSach;
    P->next = NULL;

    if(L==NULL){
        L=P;
        return;
    }
    NodePtr Q = L;
    while(Q->next!=NULL){
        Q=Q->next;
    }
    Q->next = P;
}

void nhapDuLieu(NodePtr &L, int n){
    for(int i = 0 ;i<n;i++){
        Sach x;
        cout <<"Nhap id: ";
        cin >> x.id;
        cin.ignore();

        cout <<"Nhap tenSach: ";        
        getline(cin, x.tenSach);

        cout <<"Nhap tenTg: ";
        getline(cin, x.tenTg);

        cout <<"Nhap namXb: ";
        cin >> x.namXb;
        cin.ignore();

        insertLast(L, x);
    }
}

void hienThi(NodePtr L){
    if(L==NULL) return;
    bool found =false;
    NodePtr Q = L;
    while(Q!=NULL){
        if(Q->infor.tenTg=="Quách Tuấn Ngọc"){
            found = true;
            cout <<Q->infor.id<<endl;
        }
        Q=Q->next;
    }if(!found) cout <<"Khong tim thay!";
}

int main(){
    NodePtr L;
    createEmpty(L);
    Sach newS1 = {500110, "Conan1", "Pham Giang", 2007};
    Sach newS2 = {500111, "Conan2", "Quách Tuấn Ngọc", 2006};
    Sach newS3 = {500112, "Conan3", "Pham Giang2", 2005};
    Sach newS4 = {500113, "Conan4", "Quách Tuấn Ngọc", 2004};
    Sach newS5 = {500114, "Conan5", "Pham Giang4", 2003};
    Sach newS6 = {500115, "Conan6", "Pham Giang", 2002};
    Sach newS7 = {500116, "Conan7", "Pham Giang5", 2001};

    cout << "=== List ===\n";
    insertLast(L, newS1);
    insertLast(L, newS2);
    insertLast(L, newS3);
    insertLast(L, newS4);
    insertLast(L, newS5);
    insertLast(L, newS6);
    insertLast(L, newS7);
    // showBook(L);
    // hienThiSach(L);
    // chenSach(L, newS2);
    // xoa(L);
    // showBook(L);
    // nhapDuLieu(L, 3);
    hienThi(L);
    
}