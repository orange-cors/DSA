#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct NhanVien {
    int maSV;
    string hoDem;
    string ten;
    string gioiTinh;
    int namSinh;
    double luong;
};

void nhapDS(vector<NhanVien> &ds) {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    ds.resize(n);
    for(int i = 0; i < n; i++) {
        cout << "\nEmployee " << i + 1 << endl;
        cout << "ID: "; cin >> ds[i].maSV;
        cout << "Last+Mid name: ";
        cin.ignore();
        getline(cin, ds[i].hoDem);
        cout << "First name: ";
        getline(cin, ds[i].ten);
        cout << "Gender: ";
        cin >> ds[i].gioiTinh;
        cout << "Birth year: ";
        cin >> ds[i].namSinh;
        cout << "Salary: ";
        cin >> ds[i].luong;
    }
}

void hienDS(const vector<NhanVien> &ds) {
    cout << "\n===== EMPLOYEE LIST =====\n";
    for (auto &x : ds) {
        cout << x.maSV << " | " << x.hoDem << " " << x.ten
             << " | " << x.gioiTinh
             << " | " << x.namSinh
             << " | " << x.luong << endl;
    }
}

void timTenAnh(const vector<NhanVien> &ds) {
    cout << "\nPeople with first name 'Anh':\n";
    bool found = false;
    for (auto &x : ds) {
        if (x.ten == "Anh") {
            cout << x.maSV << " | " << x.hoDem << " " << x.ten << endl;
            found = true;
        }
    }
    if (!found) cout << "No one found.\n";
}

bool cmpName(const NhanVien &a, const NhanVien &b) {
    return a.ten < b.ten;
}

void themNhanVien(vector<NhanVien> &ds) {
    NhanVien x;
    x.maSV = 1007;
    x.hoDem = "Dinh Thu";
    x.ten = "Hoa";
    x.gioiTinh = "Nu";
    x.namSinh = 1998;
    x.luong = 11.6;

    // chèn vào vị trí thứ 3 (index = 2)
    ds.insert(ds.begin() + 2, x);
}

void xoaNguoiLonHon30Luong15(vector<NhanVien> &ds) {
    ds.erase(
        remove_if(
            ds.begin(),
            ds.end(),
            [](const NhanVien &x) {
                int age = 2025 - x.namSinh;
                return age > 30 && x.luong > 15;
            }
        ),
        ds.end()
    );
}

int main() {
    vector<NhanVien> ds;

    // Bước 1: Nhập danh sách
    nhapDS(ds);

    cout << "\n--- Initial list ---\n";
    hienDS(ds);

    // Bước 2: Tìm người tên Anh
    timTenAnh(ds);

    // Bước 3: Sort theo tên
    sort(ds.begin(), ds.end(), cmpName);
    cout << "\n--- Sorted by first name ---\n";
    hienDS(ds);

    // Bước 4: Thêm nhân viên mới ở vị trí 3
    themNhanVien(ds);
    cout << "\n--- After inserting employee ---\n";
    hienDS(ds);

    // Bước 5: Xoá nhân viên >30 tuổi và lương >15
    xoaNguoiLonHon30Luong15(ds);
    cout << "\n--- After deleting employees (age>30 && salary>15) ---\n";
    hienDS(ds);

    return 0;
}
