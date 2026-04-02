#include <iostream>
using namespace std;

class NgayThangNam {
private:
    int iNgay, iThang, iNam;

    bool laNamNhuan(int n) {
        return (n % 400 == 0) || (n % 4 == 0 && n % 100 != 0);
    }

    int tinhSoNgayTrongThang(int t, int n) {
        switch (t) {
            case 4: case 6: case 9: case 11: return 30;
            case 2: return laNamNhuan(n) ? 29 : 28;
            default: return 31;
        }
    }

public:
    void Nhap() {
        do {
            cout << "Nhap ngay, thang, nam: ";
            cin >> iNgay >> iThang >> iNam;
            if (iThang < 1 || iThang > 12 || iNgay < 1 || iNgay > tinhSoNgayTrongThang(iThang, iNam)) {
                cout << "Du lieu khong hop le, nhap lai";
            } else break;
        } while (true);
    }

    void Xuat() {
        cout << iNgay << '/' << iThang << '/' << iNam << '\n';
    }

    void NgayThangNamTiepTheo() {
        int ngayKe = iNgay;
        int thangKe = iThang;
        int namKe = iNam;

        if (ngayKe < tinhSoNgayTrongThang(thangKe, namKe)) {
            ngayKe++;
        } else {
            ngayKe = 1;
            if (thangKe < 12) {
                thangKe++;
            } else {
                thangKe = 1;
                namKe++;
            }
        }
        cout << "Ngay tiep theo la: ";
        cout << ngayKe << '/' << thangKe << '/' << namKe;
    }
};

int main() {
    NgayThangNam dt;

    dt.Nhap();

    cout << "Ngay da nhap: ";
    dt.Xuat();

    dt.NgayThangNamTiepTheo();

    return 0;
}
