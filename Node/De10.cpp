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
    P->infor=newSach;
    P->next=NULL;
    if(L==NULL){
        L=P;
        return;
    }NodePtr Q = L;
    while (Q->next!=NULL){
        Q=Q->next;
    }Q->next=P;
}

void hienThi(NodePtr L){
    if(L==NULL) return;
    NodePtr Q =L;
    bool found = false;
    while (Q!=NULL)
    {
        if(Q->infor.tenTg=="Pham Giang"){
            found = true;
            cout <<Q->infor.maSach<<" | "<<Q->infor.tenSach<<" | "<<Q->infor.tenTg<<" | "<<Q->infor.namXb<<endl;
        }Q=Q->next;
    }if(!found) cout <<"Khong tim thay sach";
}

void chenSau(NodePtr &L, Sach newSach){
    if(L==NULL) return;
    NodePtr P = new Node;
    P->infor=newSach;
    P->next=NULL;

    NodePtr Q = L;
    while (Q!=NULL&&Q->infor.maSach!=500112)
    {
        Q=Q->next;
    }if(Q==NULL){
        cout <<"Ko ton tai Sach!";
        return;
    }
    P->next=Q->next;
    Q->next=P;
}

void xoaSach(NodePtr &L){
    if(L==NULL) return;
    NodePtr Q = L;
    int dem=1;
    while (Q->next!=NULL&&dem<5)
    {
        dem++;
        Q=Q->next;
    }
    if(Q->next==NULL){
        cout <<"Vi tri ko hop le!";
        return;
    }
    NodePtr tmp = Q->next;
    Q->next = tmp->next;
    delete tmp;
}
void showBook(NodePtr L){
    if(L==NULL) return;
    NodePtr Q =L;
    while (Q!=NULL)
    {
        cout <<Q->infor.maSach<<" | "<<Q->infor.tenSach<<" | "<<Q->infor.tenTg<<" | "<<Q->infor.namXb<<endl;
        Q=Q->next;
    }
}

int main(){
    NodePtr L;
    createEmpty(L);
    Sach newS1 = {500110, "Conan1", "Pham Giang", 2007};
    Sach newS2 = {500111, "Conan2", "Pham Giang1", 2006};
    Sach newS3 = {500112, "Conan3", "Pham Giang2", 2005};
    Sach newS4 = {500113, "Conan4", "Pham Giang3", 2004};
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
    showBook(L);
    cout <<endl;
    hienThi(L);
    cout <<endl;
    // chenSau(L, newS2);
    // showBook(L);
    cout <<endl;
    xoaSach(L);
    showBook(L);
    
}