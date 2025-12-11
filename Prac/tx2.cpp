#include <iostream>
#include <vector>
using namespace std;

struct Student {
    string id;
    string name;
    int birthYear;
    double gpa;
};

// a) Nhập + hiển thị danh sách
void inputList(vector<Student> &ls, int n){
    for(int i = 0; i < n; i++){
        Student st;
        cout << "Nhap MaSV: ";
        cin >> st.id;

        cout << "Nhap Ten: ";
        cin >> st.name;

        cout << "Nhap Nam Sinh: ";
        cin >> st.birthYear;

        cout << "Nhap DTB: ";
        cin >> st.gpa;

        ls.push_back(st);
    }
}

void displayList(const vector<Student> &ls){
    cout << "\n===== DANH SACH SINH VIEN =====\n";
    for(int i = 0; i < ls.size(); i++){
        cout << i+1 << ". " 
             << ls[i].id << " | "
             << ls[i].name << " | "
             << ls[i].birthYear << " | "
             << ls[i].gpa << endl;
    }
}

// b) Selection Sort theo tên
void selectionSortByName(vector<Student> &ls){
    int n = ls.size();
    for(int i = 0; i < n - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(ls[j].name < ls[minIndex].name){
                minIndex = j;
            }
        }
        if(minIndex != i){
            Student temp = ls[i];
            ls[i] = ls[minIndex];
            ls[minIndex] = temp;
        }
    }
}

// c) Xóa phần tử thứ 2 (index = 1)
int deleteSecond(vector<Student> &ls){
    if(ls.size() < 2) return -1;

    for(int i = 1; i < ls.size() - 1; i++){
        ls[i] = ls[i + 1];
    }
    ls.pop_back();
    return 1;
}

// d) Chèn vào vị trí thứ 4 (index = 3)
int insertAtFourth(vector<Student> &ls, Student x){
    int index = 3;
    if(index < 0 || index > ls.size()) return -1;

    ls.push_back(Student()); // mở rộng
    for(int i = ls.size() - 1; i > index; i--){
        ls[i] = ls[i - 1];
    }
    ls[index] = x;
    return 1;
}

// e) Xóa SV có GPA < 7.5 và sinh > 2005
void deleteByCondition(vector<Student> &ls){
    for(int i = 0; i < ls.size(); ){
        if(ls[i].gpa < 7.5 && ls[i].birthYear > 2005){
            for(int j = i; j < ls.size() - 1; j++){
                ls[j] = ls[j + 1];
            }
            ls.pop_back();
        } else {
            i++;
        }
    }
}

int main(){
    vector<Student> ls;
    int n = 7;

    // a
    inputList(ls, n);
    displayList(ls);

    // b
    cout << "\n-- Sap xep theo ten (Selection Sort) --\n";
    selectionSortByName(ls);
    displayList(ls);

    // c
    cout << "\n-- Xoa phan tu thu 2 --\n";
    deleteSecond(ls);
    displayList(ls);

    // d
    cout << "\n-- Chen sinh vien vao vi tri thu 4 --\n";
    Student newSt = {"1006", "Doan", 2005, 7.6};
    insertAtFourth(ls, newSt);
    displayList(ls);

    // e
    cout << "\n-- Xoa cac SV GPA < 7.5 va nam sinh > 2005 --\n";
    deleteByCondition(ls);
    displayList(ls);

    return 0;
}
