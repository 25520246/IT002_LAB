#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Date {
    int ngay, thang, nam;
};

class cCandidate {
private:
    string ma, ten;
    Date ns;
    float diemToan, diemVan, diemAnh;

public:
    void nhap() {
        cout << "Nhap ma: "; cin >> ma;
        cin.ignore();
        cout << "Nhap ten: "; getline(cin, ten);

        cout << "Nhap ngay sinh (ngay thang nam): ";
        cin >> ns.ngay >> ns.thang >> ns.nam;

        cout << "Nhap diem Toan, Van, Anh: ";
        cin >> diemToan >> diemVan >> diemAnh;
    }

    void xuat() const {
        cout << left << setw(10) << ma
             << setw(20) << ten
             << setw(12) << (to_string(ns.ngay) + "/" + to_string(ns.thang) + "/" + to_string(ns.nam))
             << setw(8) << diemToan << setw(8) << diemVan << setw(8) << diemAnh
             << setw(10) << getTongDiem() << endl;
    }

    float getTongDiem() const {
        return diemToan + diemVan + diemAnh;
    }
};

class cListCandidate {
private:
    vector<cCandidate> danhSach;

public:
    void nhapDS(int n) {
        for (int i = 0; i < n; i++) {
            cout << "\nNhap thi sinh thu " << i + 1 << endl;
            cCandidate c;
            c.nhap();
            danhSach.push_back(c);
        }
    }

    void xuatDiemLonHon15() {
        cout << "\nDanh sach thi sinh co tong diem > 15" << endl;
        bool found = false;
        for (const auto& c : danhSach) {
            if (c.getTongDiem() > 15) {
                c.xuat();
                found = true;
            }
        }
        if (!found) cout << "Khong co thi sinh nao du dieu kien." << endl;
    }

    void timMax() {
        if (danhSach.empty()) return;
        float maxDiem = danhSach[0].getTongDiem();
        for (const auto& c : danhSach) {
            if (c.getTongDiem() > maxDiem) maxDiem = c.getTongDiem();
        }

        cout << "\nThi sinh co diem cao nhat (" << maxDiem << ")" << endl;
        for (const auto& c : danhSach) {
            if (c.getTongDiem() == maxDiem) {
                c.xuat();
            }
        }
    }

    void sapXepGiamDan() {
        sort(danhSach.begin(), danhSach.end(), [](const cCandidate& a, const cCandidate& b) {
            return a.getTongDiem() > b.getTongDiem();
        });
        cout << "\nDanh sach sau khi sap xep giam dan theo tong diem" << endl;
        for (const auto& c : danhSach) {
            c.xuat();
        }
    }
};

int main() {
    cListCandidate ds;
    int n;

    cout << "Nhap so luong thi sinh n: ";
    cin >> n;

    ds.nhapDS(n);
    ds.xuatDiemLonHon15();
    ds.timMax();
    ds.sapXepGiamDan();

    return 0;
}
