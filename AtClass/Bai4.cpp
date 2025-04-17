#include<bits/stdc++.h> 

using namespace std;

#define MAX 100

struct ChuyenBay
{
	char soHieu[8];
	double giave;
	int soghe;
};

ChuyenBay x[7] = {
	{"VN001", 700000, 1}, 
	{"VN002", 800000, 9},
	{"VN003", 750000, 10},
	{"VN004", 600000, 23},
	{"VN005", 500000, 88},
	{"VN006", 300000, 102},
	{"VN007", 900000, 36},
};


void inTieuDe(){
	cout << "------------------------------------------" << endl;
	printf("|%-10s|%-10s|%-10s|\n", "SO HIEU", "GIA VE", "SO GHE");
}


void inDanhSach(ChuyenBay x[], int n){
	if(n == 0)
		return;
	inDanhSach(x, n - 1);
	printf("|%-10s|%-10.1f|%-10d|\n", x[n - 1].soHieu, x[n - 1].giave, x[n - 1].soghe);

}

//Thiết kế thuật toán A1 để hiển thị ra màn hình tất cả các chuyến bay có giá vé 
//trên 700000 bằng phương pháp đệ quy

void A1(ChuyenBay x[], int l, int r){
	if(l == r){
		if(x[l].giave > 700000){
			printf("|%-10s|%-10.1f|%-10d|\n", x[l].soHieu, x[l].giave, x[l].soghe);
		}
	}
	else {
		int mid = (l + r) / 2;
		A1(x, l, mid);
		A1(x, mid + 1, r);
	}

}

//Thiết kế thuật toán A2 để tìm và trả về chuyến bay có giá vé thấp nhất trong danh 
//sách b bằng chiến lược chia để trị. 
ChuyenBay A2(ChuyenBay x[], int l, int r){
	if(l == r)
		return x[l];
	int mid = (l + r) / 2;
	ChuyenBay x1 = A2(x, l, mid);
	ChuyenBay x2 = A2(x, mid + 1, r);
	return x1.giave < x2.giave ? x1:x2;
}

//Thiết kế thuật toán A3 để liệt kê tất cả các phương án khác nhau để chọn ra 4 
//chuyến bay từ danh sách b bằng phương pháp quay lui. 

void showResultA3(ChuyenBay* x){
	for(int i = 0; i < 4; i++){
		cout << x[i].soHieu << " - " << x[i].soghe << endl;
	}
	cout << "---------------------------------------" << endl;
}

void A3(ChuyenBay x[], ChuyenBay* x_result, bool* flag, int n, int k){
	for(int i = 0; i < n; i++){
		if(flag[i] == false){
			strcpy((x_result[k]).soHieu, x[i].soHieu);
			x_result[k].giave = x[i].giave;
			x_result[k].soghe = x[i].soghe;
			if(k == 3){
				showResultA3(x_result);
			}
			else{
				flag[i] = true;
				A3(x, x_result, flag, n, k + 1);
				flag[i] = false;
			}

		}
	}
}

// void A3(ChuyenBay x[], ChuyenBay* x_result, int n, int k){
// 	for(int i = 0; i < n; i++){
// 		strcpy((x_result[k]).soHieu, x[i].soHieu);
// 		x_result[k].giave = x[i].giave;
// 		x_result[k].soghe = x[i].soghe;
// 		if(k == 4)
// 			showResultA3(x_result);
// 		else
// 			A3(x, x_result, flag, n, k + 1);
// 	}
// }




int main() {
	int n = 7;
	inTieuDe();
	inDanhSach(x, n);
	cout << "Danh sach chuyen bay co gia ve lon hon 700000:" << endl;
	inTieuDe();
	A1(x, 0, n -  1);
	cout << "Chuyen bay co gia ve nho nhat: " << endl;
	inTieuDe();
	printf("|%-10s|%-10.1f|%-10d|\n", A2(x, 0, n - 1).soHieu, A2(x, 0, n - 1).giave, A2(x, 0, n - 1).soghe);
	cout << "Tap hop phuong an chon ra 4 chuyen bay tu danh sach cac chuyen bay tren" << endl;
	ChuyenBay* x_result = new ChuyenBay[4];
	bool* flag = new bool[4];
	for(int i = 0; i < 4; i++)
		flag[i] = false;
	A3(x, x_result, flag, n, 0);
	return 0;
	
	
}