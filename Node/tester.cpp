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

void insertLast(List &L, Student newStudent){
    Node* P=new Node;
    P->infor=newStudent;
    P->next=NULL;

    if(L == NULL){
        L = P;
    }
    else{
    	Node* Q =L;
    	while(Q->next!=NULL)
    		Q=Q->next;
    	Q->next=P;	
	}
}

void insertAt3(List &L, Student newStudent){
	Node* P = new Node;
	P->infor=newStudent;
	P->next=NULL;
	
	int idx =1;
	Node* Q = L;
	Node* S;
	while(Q!=NULL&&idx<3){
		S=Q;
		idx++;
		Q=Q->next;
	}
	P->next=S->next;              
	S->next=P;
}

void chenViTriThu3(List &L, Student newStudent)
{
	int d=1;
	List M, Q = L;
	
	while(Q!=NULL && d<3)
	{
		M= Q;
		Q = Q->next;
		d++;
	}
	if(Q==NULL)
	{
		cout << "Vi tri khong thich  hop!";
		return;
	}
	
	
	Node* P = new Node;
	P->infor=newStudent;
	P->next=NULL;
	
	P->next = M->next;
	M->next = P;
	
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
        cout<<Q->infor.id<<" | "<<Q->infor.surName<<" | "<<Q->infor.firstName<<" | "<<Q->infor.gender<<" | "<<Q->infor.birthYear<<" | "<<Q->infor.finalScore<<endl;
        Q=Q->next;
    }
}

int main(){
    List L;
    createEmpty(L);

    Student s1;
    s1.id=01;
    strcpy(s1.surName, "Nguyen Van");
    strcpy(s1.firstName, "Binh");
    strcpy(s1.gender, "Nam");
    s1.birthYear=2005;
    s1.finalScore=9.2;
    
    Student s2;
    s2.id=02;
    strcpy(s2.surName, "Nguyen Duc");
    strcpy(s2.firstName, "Anh");
    strcpy(s2.gender, "Nam");
    s2.birthYear=2006;
    s2.finalScore=9.8;
    
    Student s3;
    s3.id=03;
    strcpy(s3.surName, "Le Thi Anh");
    strcpy(s3.firstName, "Duong");
    strcpy(s3.gender, "Nu");
    s3.birthYear=2006;
    s3.finalScore=9.9;
    
    Student s4;
    s4.id=04;
    strcpy(s4.surName, "Le Quynh");
    strcpy(s4.firstName, "Anh");
    strcpy(s4.gender, "Nu");
    s4.birthYear=2006;
    s4.finalScore=8.9;

    insertLast(L,s1);
    insertLast(L,s2);
    insertLast(L,s3);
    insertLast(L,s4);
//  selectionSort(L);
	insertAt3(L, s1);
	showList(L);
//	chenViTriThu3(L, s1);
//    showList(L);

}