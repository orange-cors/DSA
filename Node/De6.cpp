#include <iostream>
#include <string>
using namespace std;

struct Sach{
    int maSach;
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
    while(Q->next!=NULL)
        Q=Q->next;
    Q->next = P;    
}

void hienThi(NodePtr L){
    if(L==NULL) return;
    NodePtr Q = L;
    while(Q!=NULL){
        if(Q->infor.namXb==2018){
            cout <<Q->infor.maSach<<" | "<<Q->infor.tenSach<<" | "<<Q->infor.tenTg<<" | "<<Q->infor.namXb<<endl;
        }
        Q=Q->next;
    }
}

void showBook(NodePtr L){
    if(L==NULL) return;
    NodePtr Q = L;
    while(Q!=NULL){
        cout <<Q->infor.maSach<<" | "<<Q->infor.tenSach<<" | "<<Q->infor.tenTg<<" | "<<Q->infor.namXb<<endl;
        Q=Q->next;
    }
}

void chenSach(NodePtr &L, int n, Sach newSach){
    NodePtr P = new Node;
    P->infor = newSach;
    P->next = NULL;

    if(n==1){
        P->next=L;
        L=P;
        return;
    }
    int dem = 1;
    NodePtr Q = L;
    while(Q!=NULL&&dem<n-1){
        dem++;
        Q=Q->next;
    }
    if(Q==NULL){
        cout <<"Vi tri khong hop le!";
        return;
    }
    P->next=Q->next;
    Q->next=P;
}

void xoaSach(NodePtr &L){
    if(L==NULL) return;
    NodePtr tmp;
    if(L->infor.maSach==9){
        tmp = L;
        L=L->next;
        delete tmp;
        return;
    }
    NodePtr Q = L;
    while(Q->next!=NULL&&Q->next->infor.maSach!=9){
        Q=Q->next;
    }
    if(Q->next == NULL){
        cout << "Khong tim thay!";
        return;
    }

    tmp = Q->next;
    Q->next = tmp->next;
    delete tmp;
}

int main(){
    NodePtr L;
    createEmpty(L);
    Sach newS1 = {1, "Conan1", "Pham Giang", 2007};
    Sach newS2 = {2, "Conan2", "Pham Giang1", 2018};
    Sach newS3 = {3, "Conan3", "Pham Giang2", 2005};
    Sach newS4 = {4, "Conan4", "Pham Giang3", 2004};
    Sach newS5 = {5, "Conan5", "Pham Giang4", 2018};
    Sach newS6 = {6, "Conan6", "Pham Giang", 2002};
    Sach newS7 = {7, "Conan7", "Pham Giang5", 2001};

    cout << "=== List ===\n";
    insertLast(L, newS1);
    insertLast(L, newS2);
    insertLast(L, newS3);
    insertLast(L, newS4);
    insertLast(L, newS5);
    insertLast(L, newS6);
    insertLast(L, newS7);
    showBook(L);
    cout <<endl;
    hienThi(L);
    // chenSach(L, 3, newS7);
    cout <<endl;
    showBook(L);
    cout <<endl;
    xoaSach(L);
    showBook(L);
    // insertFirst(L, newS7);
    // showBook(L);
    // // chenViTri3(L, newS1);
    // // cout <<endl;
    // // showBook(L);
    // cout <<endl;
    // // xoaSach(L);
    // showBook(L);

    
}