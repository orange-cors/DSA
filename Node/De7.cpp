#include <iostream>
#include <string>
using namespace std;

struct CanBo{
    int maCB;
    string tenCB;
    string gioiTinh;
    int namSinh;
};

struct Node{
    CanBo infor;
    Node* next;
};

typedef Node* NodePtr;

void createEmpty(NodePtr &L){
    L=NULL;
}

void insertLast(NodePtr &L, CanBo newCB){
    NodePtr P = new Node;
    P->infor = newCB;
    P->next = NULL;
    if(L==NULL){
        L=P;
        return;
    }

    NodePtr Q = L;
    while(Q->next!=NULL){
        Q=Q->next;
    }Q->next=P;
}

void showAll(NodePtr L){
    if(L==NULL){
        return;
    }
    NodePtr Q = L;
    while(Q!=NULL){
        cout <<Q->infor.maCB<<" | "<<Q->infor.tenCB<<" | "<<Q->infor.gioiTinh<<" | "<<Q->infor.namSinh<<endl;
        Q=Q->next;
    }
}

void xoaCB(NodePtr &L){
    if(L==NULL) return;

    NodePtr Q = L;
    int dem = 1;
    while(Q->next!=NULL&&dem<4){
        dem++;
        Q=Q->next;
    }

    if(Q->next==NULL){
        cout <<"Vi tri khong hop le!";
        return;
    }
    NodePtr tmp = Q->next;
    Q->next=tmp->next;
    delete tmp;
}

void hienThi(NodePtr L){
    if(L==NULL) return;
    bool found = false;
    NodePtr Q = L;
    while(Q!=NULL){
        if(Q->infor.gioiTinh=="Nam"){
            found = true;
            cout <<Q->infor.maCB<<" | "<<Q->infor.tenCB<<" | "<<Q->infor.gioiTinh<<" | "<<Q->infor.namSinh<<endl;
        }Q=Q->next;
    }
    if(!found)
        cout <<"Khong co CB nam!";
}

void chenSau100122(NodePtr &L, CanBo newCB){
    NodePtr P = new Node;
    P->infor = newCB;
    P->next = NULL;
    if(L==NULL) return;

    NodePtr Q = L;
    while(Q!=NULL&&Q->infor.maCB!=8){
        Q=Q->next;
    }if(Q==NULL){
        cout <<"Khong co CB phu hop!";
        return;
    }P->next=Q->next;
    Q->next=P;
}
int main(){
    NodePtr L;
    createEmpty(L);
    CanBo newS1 = {1, "Conan1", "Nam", 2007};
    CanBo newS2 = {2, "Conan2", "Nam", 2018};
    CanBo newS3 = {3, "Conan3", "Nữ", 2005};
    CanBo newS4 = {4, "Conan4", "Nam", 2004};
    CanBo newS5 = {5, "Conan5", "Nam", 2018};
    CanBo newS6 = {6, "Conan6", "Nữ", 2002};
    CanBo newS7 = {7, "Conan7", "Nam", 2001};

    cout << "=== List ===\n";
    insertLast(L, newS1);
    insertLast(L, newS2);
    insertLast(L, newS3);
    insertLast(L, newS4);
    insertLast(L, newS5);
    insertLast(L, newS6);
    insertLast(L, newS7);
    

    showAll(L);
    cout <<endl;
    xoaCB(L);
    // chenSau100122(L, newS1);
    showAll(L);
    // hienThi(L);
}    