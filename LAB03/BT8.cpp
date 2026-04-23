#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

class cNhanVienSX {
private:
    string maNV, hoTen;
    int ngay, thang, nam;
    int soSanPham;
    double donGia;

public:
    cNhanVienSX() : maNV(""), hoTen(""), ngay(1), thang(1), nam(1990), soSanPham(0), donGia(0) {}

    void nhap() {
        cout << "Ma NV: "; cin >> maNV;
        cin.ignore();
        cout << "Ho ten: "; getline(cin, hoTen);
        cout << "Ngay sinh (dd mm yyyy): "; cin >> ngay >> thang >> nam;
        cout << "So san pham: "; cin >> soSanPham;
        cout << "Don gia/san pham: "; cin >> donGia;
    }

    double tinhLuong() const {
        return (double)soSanPham * donGia;
    }

    void xuat() const {
        cout << left << setw(10) << maNV
             << setw(20) << hoTen
             << setw(15) << (to_string(ngay) + "/" + to_string(thang) + "/" + to_string(nam))
             << setw(15) << soSanPham
             << setw(15) << donGia
             << setw(15) << tinhLuong() << endl;
    }

    bool isOlderThan(const cNhanVienSX& other) const {
        if (nam != other.nam) return nam < other.nam;
        if (thang != other.thang) return thang < other.thang;
        return ngay < other.ngay;
    }

    string getHoTen() const { return hoTen; }
};

class cListNhanVienSX {
private:
    vector<cNhanVienSX> danhSach;

public:
    void nhapDS(int n) {
        for (int i = 0; i < n; i++) {
            cout << "\nNhap NV thu " << i + 1 << endl;
            cNhanVienSX nv;
            nv.nhap();
            danhSach.push_back(nv);
        }
    }

    void xuatDS() {
        cout << "\nDANH SACH NHAN VIEN SAN XUAT" << endl;
        cout << left << setw(10) << "Ma" << setw(20) << "Ho Ten" << setw(15) << "Ngay Sinh"
             << setw(15) << "So SP" << setw(15) << "Don gia" << setw(15) << "Luong" << endl;
        for (const auto& nv : danhSach) nv.xuat();
    }

    void timNVLuongThapNhat() {
        if (danhSach.empty()) return;
        auto minNV = min_element(danhSach.begin(), danhSach.end(), [](const cNhanVienSX& a, const cNhanVienSX& b) {
            return a.tinhLuong() < b.tinhLuong();
        });
        cout << "\nNhan vien co luong thap nhat: " << minNV->getHoTen() << " (" << minNV->tinhLuong() << ")" << endl;
    }

    double tinhTongLuongCongTy() {
        double tong = 0;
        for (const auto& nv : danhSach) tong += nv.tinhLuong();
        return tong;
    }

    void timNVLonTuoiNhat() {
        if (danhSach.empty()) return;
        const cNhanVienSX* oldest = &danhSach[0];
        for (const auto& nv : danhSach) {
            if (nv.isOlderThan(*oldest)) {
                oldest = &nv;
            }
        }
        cout << "\nNhan vien lon tuoi nhat: " << oldest->getHoTen() << endl;
    }

    void sapXepTangDanLuong() {
        sort(danhSach.begin(), danhSach.end(), [](const cNhanVienSX& a, const cNhanVienSX& b) {
            return a.tinhLuong() < b.tinhLuong();
        });
        cout << "\nDa sap xep danh sach tang dan theo luong." << endl;
    }
};

int main() {
    cListNhanVienSX cty;
    int n;

    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    cty.nhapDS(n);
    cty.xuatDS();
    cty.timNVLuongThapNhat();
    cout << "Tong luong cong ty phai tra: " << cty.tinhTongLuongCongTy() << endl;
    cty.timNVLonTuoiNhat();
    cty.sapXepTangDanLuong();
    cty.xuatDS();

    return 0;
}
