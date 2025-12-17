#include <iostream>
using namespace std;

struct SinhVien{
    int id;
    char hoTen[30];
    int tuoi;
    float diemTk;
};

struct Node{
    SinhVien infor;
    Node *next;
};

typedef Node *TRO;

TRO L;


void createEmpty(TRO &L){
    L=NULL;
}

bool checkEmpty(TRO L){
    return L==NULL;
}

void travel(TRO L){
    TRO Q;
    if(!checkEmpty(L)){
        Q=L;
        while(Q!=NULL){
            cout << Q->infor.id << " | "
             << Q->infor.hoTen << " | "
             << Q->infor.tuoi << " | "
             << Q->infor.diemTk << endl;
             Q=Q->next;
        }
    }else return;
}

TRO searchNode(TRO L, int id){
    TRO Q = L;
    while(Q != NULL && Q->infor.id != id)
        Q = Q->next;
    return Q;
}


void insertFirst(TRO &L, SinhVien newSv){
    TRO P = new Node;
    P->infor = newSv;
    P->next=L;
    L=P;
}

void insertLast(TRO &L, SinhVien newSv2){
    TRO P = new Node;
    P->infor = newSv2;
    P->next = NULL;

    if(checkEmpty(L)) L=P;
    else{
        TRO Q;
        Q=L;
        while(Q->next!=NULL)
            Q=Q->next;
        Q->next = P;
    }    
}

void insertByQ(TRO &L, TRO Q, SinhVien newSv3){
    TRO P = new Node;
    P->infor = newSv3;

    if(L == NULL){
        P->next = NULL;
        L = P;
    }
    else if(Q == NULL){
        P->next = L;
        L = P;
    }
    else{
        P->next = Q->next;
        Q->next = P;
    }
}

void deleteFirst(TRO &L){
    if(L == NULL) return;
    TRO Q = L;
    L=L->next;
    delete Q;
}

void deleteByM(TRO &L, TRO M){
    if(M == NULL || M->next == NULL) return;
    TRO Q=M->next;
    M->next=Q->next;
    delete Q;
}


int main(){
    createEmpty(L);

    // cout <<checkEmpty(L);
    SinhVien newSv = {6, "Pham Giang", 19, 9.5};
    SinhVien newSv2 = {7, "Nguyen Van D", 12, 8.5};
      SinhVien newSv3 = {8, "Nguyen Van E", 15, 6.5};
    cout << "=== Test insertFirst ===\n";
    insertFirst(L, newSv);
    // travel(L);

    // TRO S = searchNode(L, 6);
    // travel(S);

    cout << "=== Test insertLast ===\n";
    insertLast(L, newSv2);

    insertByQ(L, L, newSv3);
    
    // deleteFirst(L);
    deleteByM(L, L);
    travel(L);
}