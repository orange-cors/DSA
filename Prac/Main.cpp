#include <iostream>
#include <vector>
using namespace std;

struct Employee{
    string id;
    string surName;
    string firstName;
    string gender;
    int yearOfBirth;
    double basicSalary;
};

void displayList(vector<Employee> ls){
    cout <<"\nDanh sach nhan vien cua ban la: \n";
    for(int i = 0;i<ls.size();i++){
        cout <<"STT "<<i+1<<" | "<<ls[i].id<<" | "<<ls[i].surName<<" | "<<ls[i].firstName<<" | "<<ls[i].gender<<" | "<<ls[i].yearOfBirth<<" | "<<ls[i].basicSalary<<endl;
    }
}

int binarySearch(vector<Employee> &ls, int left, int right, string keyName){
    if(left>right) return -1;
    else{
        int mid = (left+right)/2;
        if(ls[mid].firstName==keyName) return mid;
        else if(ls[mid].firstName>keyName) return binarySearch(ls, left, mid-1, keyName);
        else return binarySearch(ls, mid+1, right, keyName);
    }
}

void sortByFirstName(vector<Employee> &ls){
    cout <<"\nSap xep theo ten bang selection sort!\n";
    for(int i = 1;i<ls.size();i++){
        Employee key = ls[i];
        int j = i -1;
        while(j>=0&&ls[j].firstName>key.firstName){
            ls[j+1] = ls[j];
            j--;
        }ls[j+1] = key;
    }
}

int delEmployeeByIndex(vector<Employee> &ls, int index){
    if(index<0||index>ls.size()) return -1;
    for(int j = index;j<ls.size()-1;j++){
        ls[j] = ls[j+1];
    }ls.pop_back();
    return 1;
}


int addEmployee(vector<Employee> &ls, int index, Employee news){
    if(index < 0 || index > ls.size()) return -1;
    ls.push_back(Employee());
    for(int i = ls.size() - 1; i > index; i--){
        ls[i] = ls[i - 1];
    }
    ls[index] = news;
    return 1;
}

int delEmployee(vector<Employee> &ls){
    int check = -1;
    for(int i = 0;i<ls.size();){
        if(2025-(ls[i].yearOfBirth)>30&&ls[i].basicSalary>15){
            check = 1;
            for(int j = i;j<ls.size()-1;j++){
                ls[j] = ls[j+1];
            }ls.pop_back();
        }else i++;
    }return check;
}

int main(){
    string keyName;
    int index;
    vector<Employee> ls = {
        {"NV1001", "Trần Văn", "Bình", "Nam", 1996, 12},
        {"NV1002", "Trần Mai", "Hương", "Nữ", 1995, 13.5},
        {"NV1003", "Nguyễn Thành", "Trung", "Nam", 1994, 14},
        {"NV1004", "Lê Thanh", "Hà", "Nữ", 1998, 10},
        {"NV1005", "Phan Đức", "Anh", "Nam", 1992, 15.5},
        {"NV1006", "Dương Bình", "Minh", "Nam", 2000, 8.5}
    };

    displayList(ls);

    sortByFirstName(ls);
    displayList(ls);
    cout <<"\nNhap ten nhan vien can tim: ";
    cin >>keyName;
    int result = binarySearch(ls, 0, ls.size()-1, keyName);
    if(result!=-1){
        cout <<"\nTim thay o vi tri: "<< result<<endl;
        cout <<ls[result].id<<" | "<<ls[result].surName<<" | "<<ls[result].firstName<<" | "<<ls[result].gender<<" | "<<ls[result].yearOfBirth<<" | "<<ls[result].basicSalary<<endl;
    }else cout <<"\nKhong tim thay NV!";
cout <<"\nNhap vi tri can chen: ";
    cin >>index;
    if(delEmployeeByIndex(ls, index)==1){
        cout <<"\nDa xoa nhan vien!";
        displayList(ls);
    }else cout <<"\nVi tri xoa ko hop le!\n";

    // Employee news = {"1007", "Đinh Thu", "Hòa" , "Nữ", 1998, 11.6};
    // cout <<"\nNhap vi tri can chen: ";
    // cin >>index;
    // if(addEmployee(ls, index, news)==1){
    //     cout <<"\nChen nhan vien vao vi tri "<<index<<" thanh cong!\n";
    //     displayList(ls);
    // }else cout <<"\nLoi vi tri can chen!";

    // if(delEmployee(ls)==1){
    //     cout <<"\nDa xoa nhan vien!";
    //     displayList(ls);
    // }else cout <<"\nKhong co nhan vien nao hop le!\n";
}