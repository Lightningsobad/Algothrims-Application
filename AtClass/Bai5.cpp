#include<bits/stdc++.h>

using namespace std;


int count = 0;
struct CongViec
{
    char MaCV[10];
    double time_start;
    double time_work;

};

struct NhanVien
{
    char ten[10];
};

CongViec cv[7] {
    {"CV001", 7, 2.5}, 
    {"CV002", 5, 0.25}, 
    {"CV003", 6, 12}, 
    {"CV004", 8, 5}, 
    {"CV005", 17, 0.3}, 
    {"CV006", 19, 6}, 
    {"CV007", 18, 6}
};

NhanVien nv[7] {
    {"An"}, {"Binh"}, {"Cuong"}, {"Dung"},
    {"Giang"}, {"Hai"}, {"Kien"}
};



void inTieuDe(){
    printf("|%-20s|%-20s|%-20s|\n", "MA CONG VIEC", "THOI GIAN BAT DAU", "THOI GIAN CAN THIET");
}




//Thiết kế thuật toán A1 để hiển thị ra màn hình tất cả các công việc trong danh 
//sách c theo thứ tự ngược lại bằng phương pháp đệ quy. 
void A1(CongViec cv[], int n){
    if(n > 0){
        printf("|%-20s|%-20.1f|%-20.1f|\n", cv[n - 1].MaCV, cv[n - 1].time_start, cv[n - 1].time_work);
        A1(cv, n - 1);
    }
}
// Thiết kế thuật toán A2 để đếm và trả về số công việc có thời gian thực hiện không 
// quá 30 phút (hoặc 0.5 giờ) trong danh sách b bằng chiến lược chia để trị. 
void A2(CongViec cv[], int l, int r){
    if(l == r){
        if(cv[l].time_work <= 0.5){
            ::count++;
            printf("|%-20s|%-20.1f|%-20.1f|\n", cv[l].MaCV, cv[l].time_start, cv[l].time_work);          
        }
    }
        else{
            int mid = (l + r) / 2;
            A2(cv, l, mid);
            A2(cv, mid + 1, r);
        }
 }

 //Thiết kế thuật toán A3 để liệt kê tất cả các phương án khác nhau để giao n công 
 //việc trong danh sách b cho n nhân viên trong danh sách L bằng phương pháp 
 //quay lui. 

void showResult(CongViec* cv_result, NhanVien nv[]){
    for(int i = 0; i < 7; i++){
        cout << cv_result[i].MaCV << " - " << nv[i].ten << endl;
    }
    cout << "-------------------------------------------" << endl;
}

void A3(CongViec cv[], NhanVien nv[], CongViec cv_result[], bool* flag, int n, int k){
    for (int i = 0; i < n; i++)
    {
        if(flag[i] == false){
            strcpy(cv_result[k].MaCV, cv[i].MaCV);
            cv_result[k].time_start = cv[i].time_start;
            cv_result[k].time_work = cv[i].time_work;
            if(k == n - 1){
                showResult(cv_result, nv);
            }
            else{
                flag[i] = true;
                A3(cv, nv, cv_result, flag, n, k + 1);
                flag[i] = false;
            }
        }
    }
    

}
int main(){
    int n = 7;
    cout << "DANH DACH CONG VIEC THEO THU TU NGUOC LAI: " << endl;
    inTieuDe();
    A1(cv, n);
    cout << "DANH SACH CAC CONG VIEC CO THOI GIAN CAN THIET KHONG QUA 30 PHUT:" << endl;
    inTieuDe();
    A2(cv, 0, n - 1);
    cout << "So cong viec: " << ::count << endl;
    CongViec* cv_result = new CongViec[n];
    bool* flag = new bool[n];
    for (int i = 0; i < n; i++)
    {
        flag[i] = false;
    }
    cout << "DANH SACH CONG VIEC - NHAN VIEN TUONG UNG: " << endl;
    A3(cv, nv, cv_result, flag, n, 0);
    return 0;
}