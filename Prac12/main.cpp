#include <iostream>
#include <cstring>
using namespace std;

struct Student
{
    int id;
    char surName[20];
    char firstName[20];
    char gender[10];
    int birthYear;
    float finalScore;
};

struct Node
{
    Student infor;
    Node* next;
};

typedef Node* List;

void createEmpty(List &L){
    L=NULL;
}

void deleteFirstNode(List &L){
    if(L==NULL) return;
    Node* P=L;
    L=L->next;
    delete P;
}

void insertStudent(List &L, int index, Student newStudent){
    List P=new Node;
    P->infor=newStudent;
    P->next=NULL;

    if(L==NULL) L=P;
    Node* Q=L;
    for(int i=0;i<index&&Q!=NULL;i++)
        Q=Q->next;

    if(Q!=NULL&&Q->next!=NULL){
        P->next=Q->next;
        Q->next=P;   
    }return;
}

void selectionSort(List &L){
    for(Node* Q=L;Q!=NULL;Q->next){
        Node* minNode=Q;
        for(Node* R=L;R!=NULL;R->next)
            if(R->infor.firstName<minNode->infor.firstName)
                minNode=R;
        Student temp=minNode->infor;
        minNode->infor=Q->infor;
        Q->infor=temp;        
    }
}

void showList(List L){
    if(L==NULL) return;
    Node* Q=L;
    while(Q!=NULL){
        cout<<Q->infor.id<<" "<<Q->infor.surName<<endl;

        Q=Q->next;
    }
}    

int main(){
    List L;
    createEmpty(L);

    Student s1={1,"Nguyen","Anh","Male",2000,8.5};

    insertStudent(L,0,s1);

}