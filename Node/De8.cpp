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

void hienThi(NodePtr L){
    if(L==NULL) return;
    NodePtr Q=L;
    bool found = false;
    while(Q!=NULL){
        if(2025-Q->infor.namSinh>20){
            found = true;
            cout <<Q->infor.maCB<<" | "<<Q->infor.tenCB<<" | "<<Q->infor.gioiTinh<<" | "<<Q->infor.namSinh<<endl;
        }Q=Q->next;
    }if(!found) cout <<"Khong co cb!";
}

void chenVt5(NodePtr &L, CanBo newCB){
    NodePtr P = new Node;
    P->infor = newCB;
    P->next = NULL;

    NodePtr Q = L;
    int dem = 1;
    while(Q!=NULL&&dem<4){
        dem++;
        Q=Q->next;
    }if(Q==NULL){
        cout <<"Vi tri khong hop le!";
        return;
    }P->next = Q->next;
    Q->next = P;
}

void xoaCH(NodePtr &L){
    if(L==NULL) return;

    NodePtr tmp, Q=L;
    while(Q->next!=NULL&&Q->next->infor.namSinh!=2018){
        Q=Q->next;
    }if(Q->next==NULL){
        cout <<"Khong co hop le!";
        return;
    }tmp = Q->next;
    Q->next = tmp->next;
    delete tmp;

}

void chenCH(NodePtr &L, CanBo newCB){
    if(L==NULL) return;
    NodePtr P = new Node;
    P->infor = newCB;
    P->next = NULL;

    if(L->infor.maCB==1){
        P->next = L;
        L=P;
        return;
    }
    NodePtr Q = L;
    while (Q->next!=NULL&&Q->next->infor.maCB!=1){
        Q=Q->next;
    }
    if(Q->next==NULL){
        cout <<"Khong co hop le!";
        return;
    }P->next = Q->next;
    Q->next = P;
    
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
    // hienThi(L);
    // chenVt5(L, newS1);
    // xoaCH(L);
    chenCH(L, newS4);
    showAll(L);
}    