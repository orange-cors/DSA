#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct DienThoai{
    int id;
    string nhanHieu;
    int kichThuoc;
    int gia;
};

string hang[] = {
    "iPhone",
    "Samsung",
    "Xiaomi",
    "Oppo",
    "Vivo",
    "Nokia"
};

int sizeList[] = {5, 6, 7, 8};

int n, s;

int f[100][100] = {0};

void khoiTao(DienThoai d[]){

    for(int i = 0; i < n; i++){

        d[i].id = i + 1;

        d[i].nhanHieu = hang[rand() % 6];

        d[i].kichThuoc = sizeList[rand() % 4];

        d[i].gia =
            (1LL * rand() * rand()) % 500000 + 100000;
    }
}

void hienThi(DienThoai d[]){

    cout << "\nDanh sach dien thoai:\n\n";

    for(int i = 0; i < n; i++){

        cout << "SP "
             << d[i].id
             << " | "
             << d[i].nhanHieu
             << " | Size: "
             << d[i].kichThuoc
             << " | Gia: "
             << d[i].gia
             << endl;
    }

    cout << endl;
}

void sortGreedy(DienThoai d[]){

    for(int i = 0; i < n - 1; i++){

        for(int j = 0; j < n - i - 1; j++){

            double r1 =
                (double)d[j].gia / d[j].kichThuoc;

            double r2 =
                (double)d[j+1].gia / d[j+1].kichThuoc;

            if(r1 < r2){

                DienThoai tmp = d[j];
                d[j] = d[j+1];
                d[j+1] = tmp;
            }
        }
    }
}

void greedy(DienThoai d[]){

    sortGreedy(d);

    int tongGia = 0;

    int tongSize = 0;

    int soLuong = 0;

    cout << "\nGreedy chon:\n\n";

    for(int i = 0; i < n; i++){

        if(tongSize + d[i].kichThuoc <= s){

            cout << "SP "
                 << d[i].id
                 << " | "
                 << d[i].nhanHieu
                 << " | "
                 << d[i].kichThuoc
                 << " | "
                 << d[i].gia
                 << endl;

            tongSize += d[i].kichThuoc;

            tongGia += d[i].gia;

            soLuong++;
        }
    }

    cout << "\nSo dien thoai lay duoc: "
         << soLuong
         << endl;

    cout << "Tong gia lon nhat (Greedy): "
         << tongGia
         << endl;
}

void dp(DienThoai d[]){

    for(int i = 1; i <= n; i++){

        for(int j = 0; j <= s; j++){

            f[i][j] = f[i-1][j];

            if(d[i-1].kichThuoc <= j){

                int tmp =
                    d[i-1].gia
                    + f[i-1][j-d[i-1].kichThuoc];

                if(tmp > f[i][j]){

                    f[i][j] = tmp;
                }
            }
        }
    }
}

void hienThiBangPA(){
    for(int i = 0;i<=n;i++){
        for(int j=0;j<=s;j++){
            cout <<f[i][j]<<"\t";
        }cout <<endl;
    }cout <<endl;
}

void truyVet(DienThoai d[]){

    int i = n;

    int j = s;

    int soLuong = 0;

    cout << "\nDP chon:\n\n";

    while(i > 0 && j > 0){

        if(f[i][j] != f[i-1][j]){

            cout << "SP "
                 << d[i-1].id
                 << " | "
                 << d[i-1].nhanHieu
                 << " | "
                 << d[i-1].kichThuoc
                 << " | "
                 << d[i-1].gia
                 << endl;

            j -= d[i-1].kichThuoc;

            soLuong++;
        }

        i--;
    }

    cout <<"Bang phuong an:\n";
    hienThiBangPA();

    cout << "\nSo dien thoai lay duoc: "
         << soLuong
         << endl;

    cout << "Tong gia lon nhat (DP): "
         << f[n][s]
         << endl;
}

int main(){

    srand(time(0));

    do{
        cout << "Nhap n (5 <= n <= 10): ";
        cin >> n;
    }while(n < 5 || n > 10);

    do{
        cout << "Nhap kich thuoc tui s: ";
        cin >> s;
    }while(s <= 0);

    DienThoai d[20];

    khoiTao(d);

    hienThi(d);

    greedy(d);

    dp(d);

    truyVet(d);

    return 0;
}