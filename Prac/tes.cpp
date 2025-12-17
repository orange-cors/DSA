#include <iostream>
#include <vector>
using namespace std;

struct CanBo{
	string MaCB;
	string Ten;
	int namSinh;
	double heSoLuong;
};

void displayList(vector<CanBo> &ls){
	cout <<"Danh sach can bo cua ban la:\n";
	for(int i = 0;i<ls.size();i++){
		cout <<"STT "<<i+1<<" | "<<ls[i].MaCB<<" | "<<ls[i].Ten<<" | "<<ls[i].namSinh<<" | "<<ls[i].heSoLuong<<endl;
	}
}

void insertionSort(vector<CanBo> &ls){
	cout <<"\nSau khi sap xep theo chieu tang dan cua he so luong!\n";
	for(int i = 1;i<ls.size();i++){
		CanBo tmp = ls[i];
		int j = i - 1;
		while(j>=0&&ls[j].heSoLuong>tmp.heSoLuong){
			ls[j+1] = ls[j];
			j--;
		}ls[j+1] = tmp;
	}
}

int deleteSecond(vector<CanBo> &ls, int delIndex){
	if(delIndex<0||delIndex>=ls.size()) return 0;
	for(int i = delIndex;i<ls.size()-1;i++){
		ls[i] = ls[i+1];
	}ls.pop_back();
	return 1;
}

int addByIndex(vector<CanBo> &ls, int addIndex, CanBo newCB){
	if(addIndex<0||addIndex>ls.size()) return 0;
	ls.push_back(CanBo());
	for(int i = ls.size()-1;i>addIndex;i--){
		ls[i] = ls[i-1];
	}ls[addIndex] = newCB;
	return 1;
}

int deleteCB(vector<CanBo> &ls, double avr){
	int check = 0;
	
	for(int i = 0;i<ls.size();){
		if(ls[i].namSinh<1995&&ls[i].heSoLuong>avr){
			check = 1;
			for(int j = i; j<ls.size()-1;j++){
				ls[j] = ls[j+1];
			}ls.pop_back();
		}else i++;
	}
	return check;
}

int main(){
	vector<CanBo> ls = {
		{"10011", "Binh", 1986, 6.5},
		{"10012", "Minh", 1992, 4.0},
		{"10013", "An", 1994, 5.1},
		{"10014", "Chung", 1995, 4.4},
		{"10015", "Thanh", 1996, 3.67}
	};
	
	displayList(ls);
	insertionSort(ls);
	displayList(ls);
	
	
	int delIndex;
	cout <<"\nNhap vi tri can xoa: ";
	cin >>delIndex;
	if(deleteSecond(ls, delIndex)==1){
		cout <<"\nDa xoa thanh cong phan tu thu 2!\n";
		displayList(ls);
	}else cout <<"\nVi tri xoa ngoai pham vi!";
	
	CanBo newCB = {"1016", "Hieu", 2000, 2.67};
	int addIndex;
	cout <<"\nNhap vi tri can chen: ";
	cin >>addIndex;
	if(addByIndex(ls, addIndex, newCB)==1){
		cout <<"\nDa chen thanh cong vao vi tri 4!\n";
		displayList(ls);
	}else cout <<"\nVi tri chen ngoai pham vi!";
	

	double sum = 0;
	for(int i = 0;i<ls.size();i++){
		sum += ls[i].heSoLuong;
	}
	
	double avr = sum/ls.size();

	
	if(deleteCB(ls, avr)==1){
		cout <<"\nDa xoa thanh cong!\n";
		displayList(ls);
	}else cout <<"\nKhong tim thay can bo nao hop le!";
}
	
