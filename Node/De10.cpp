#include <iostream>
#include <cstring>
using namespace std;

struct Sach{
    int id;
    char tenSach[50];
    char tenTg[30];
    int namXb;
};

struct Node{
    Sach infor;
    Node* next;
};

typedef Node* List;

Node* createNode(Sach x){
    Node* P = new Node;
    P->infor = x;
    P->next = NULL;
    return P;
}

void insertAfter(List &L, List Q, Sach newBook){
    List P = new Node;
    P->infor=newBook;
    if(L==NULL) L=P;
    else{
        P->next=Q->next;
        Q->next=P;
    }
}

void showNode(List L){
    if(L==NULL) return;
    Node* Q = L;
    while(Q!=NULL){
        cout << Q->infor.id << " | "
            << Q->infor.tenSach << " | "
            << Q->infor.tenTg << " | "
            << Q->infor.namXb << endl;
            Q=Q->next;
    }

}

void showBook(List L){
    Node* Q = L;
    while(Q!=NULL){
        if(!strcmp(Q->infor.tenTg, "Pham Giang")){
            cout << Q->infor.id << " | "
            << Q->infor.tenSach << " | "
            << Q->infor.tenTg << " | "
            << Q->infor.namXb << endl;
        }
        Q=Q->next;
    }
}

void insertBook(List &L, Sach newBook){
    Node* P = new Node;
    P->infor=newBook;
    P->next=NULL;
    if(L==NULL) return;
    Node* Q = L;
    while(Q!=NULL){
        if(Q->infor.id==500112){
            P->next=Q->next;
            Q->next=P;
            return;
        }
        Q=Q->next;
    }
}

void deleteBook(List L, int n){
    if(L==NULL) return;
    Node* Q = L;
    for(int i =1;i<n-1&&Q!=NULL;i++){
        Q=Q->next;
    }
    if(Q!=NULL&&Q->next!=NULL){
        Node* tmp = Q->next;
        Q->next=tmp->next;
        delete tmp;
    }
}

int main(){
    List L = NULL;
    Sach newSv1;
    newSv1.id = 500112;
    strcpy(newSv1.tenSach, "Conan");
    strcpy(newSv1.tenTg, "Pham Giang");
    newSv1.namXb = 2000;

    Sach newSv2;
    newSv2.id = 500113;
    strcpy(newSv2.tenSach, "Doraemon");
    strcpy(newSv2.tenTg, "Nguyen Van Muoi");
    newSv2.namXb = 2009;

    Sach newSv3;
    newSv3.id = 500114;
    strcpy(newSv3.tenSach, "One Thief");
    strcpy(newSv3.tenTg, "Pham Giang");
    newSv3.namXb = 1990;

    Sach newSv4;
    newSv4.id = 500115;
    strcpy(newSv4.tenSach, "Demon Blood");
    strcpy(newSv4.tenTg, "Terry David");
    newSv4.namXb = 1992;

    L=createNode(newSv1);
    insertAfter(L,L,newSv3);
    insertAfter(L,L,newSv2);
    insertAfter(L,L,newSv3);
    insertAfter(L,L,newSv2);
    insertAfter(L,L,newSv3);
    insertAfter(L,L,newSv2);
    cout << "=== List ===\n";
    // showNode(L);
    // showBook(L);
    insertBook(L, newSv4);
    deleteBook(L, 6);
    showNode(L);
}