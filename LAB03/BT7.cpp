#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

class cNhanVienVP {
private:
    string maNV, hoTen;
    int ngay, thang, nam;
    double luong;

public:
    cNhanVienVP() : maNV(""), hoTen(""), ngay(1), thang(1), nam(0), luong(0) {}

    void nhap() {
        cout << "Ma NV: "; cin >> maNV;
        cin.ignore();
        cout << "Ho ten: "; getline(cin, hoTen);
        cout << "Ngay sinh (dd mm yyyy): "; cin >> ngay >> thang >> nam;
        cout << "Luong: "; cin >> luong;
    }

    void xuat() const {
        cout << left << setw(10) << maNV
             << setw(20) << hoTen
             << setw(15) << (to_string(ngay) + "/" + to_string(thang) + "/" + to_string(nam))
             << setw(15) << luong << endl;
    }

    double getLuong() const { return luong; }

    bool isOlderThan(const cNhanVienVP& other) const {
        if (nam != other.nam) return nam < other.nam;
        if (thang != other.thang) return thang < other.thang;
        return ngay < other.ngay;
    }

    string getHoTen() const { return hoTen; }
};

class cListNhanVien {
private:
    vector<cNhanVienVP> danhSach;

public:
    void nhapDS(int n) {
        for (int i = 0; i < n; i++) {
            cout << "\nNhap thong tin NV thu " << i + 1 << endl;
            cNhanVienVP nv;
            nv.nhap();
            danhSach.push_back(nv);
        }
    }

    void xuatDS() {
        cout << "\nDANH SACH NHAN VIEN" << endl;
        cout << left << setw(10) << "Ma" << setw(20) << "Ho Ten" << setw(15) << "Ngay Sinh" << setw(15) << "Luong" << endl;
        for (const auto& nv : danhSach) nv.xuat();
    }

    void timNVLuongMax() {
        if (danhSach.empty()) return;
        auto maxNV = max_element(danhSach.begin(), danhSach.end(), [](const cNhanVienVP& a, const cNhanVienVP& b) {
            return a.getLuong() < b.getLuong();
        });
        cout << "\nNhan vien luong cao nhat: " << maxNV->getHoTen() << " (" << maxNV->getLuong() << ")" << endl;
    }

    double tinhTongLuong() {
        double tong = 0;
        for (const auto& nv : danhSach) tong += nv.getLuong();
        return tong;
    }

    void timNhanVienLonTuoiNhat() {
        if (danhSach.empty()) return;
        const cNhanVienVP* oldest = &danhSach[0];
        for (const auto& nv : danhSach) {
            if (nv.isOlderThan(*oldest)) {
                oldest = &nv;
            }
        }
        cout << "\nNhan vien lon tuoi nhat: " << oldest->getHoTen() << endl;
    }

    void sapXepTangDanLuong() {
        sort(danhSach.begin(), danhSach.end(), [](const cNhanVienVP& a, const cNhanVienVP& b) {
            return a.getLuong() < b.getLuong();
        });
        cout << "\nDa sap xep danh sach tang dan theo luong." << endl;
    }
};

int main() {
    cListNhanVien cty;
    int n;

    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    cty.nhapDS(n);
    cty.xuatDS();
    cty.timNVLuongMax();
    cout << "Tong luong cong ty phai tra: " << cty.tinhTongLuong() << endl;
    cty.timNhanVienLonTuoiNhat();
    cty.sapXepTangDanLuong();
    cty.xuatDS();

    return 0;
}
