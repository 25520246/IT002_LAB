#include <iostream>
#include <cmath>
using namespace std;

class SoPhuc {
private:
    double iThuc, iAo;

public:
    void Nhap() {
        cout << "Nhap phan thuc: "; cin >> iThuc;
        cout << "Nhap phan ao: "; cin >> iAo;
    }

    void Xuat() {
        if (iAo >= 0) cout << iThuc << " + " << iAo << "i";
        else cout << iThuc << " - " << abs(iAo) << "i";
        cout << endl;
    }

    SoPhuc Tong(SoPhuc b) {
        SoPhuc kq;
        kq.iThuc = iThuc + b.iThuc;
        kq.iAo = iAo + b.iAo;
        return kq;
    }

    SoPhuc Hieu(SoPhuc b) {
        SoPhuc kq;
        kq.iThuc = iThuc - b.iThuc;
        kq.iAo = iAo - b.iAo;
        return kq;
    }

    SoPhuc Tich(SoPhuc b) {
        SoPhuc kq;
        kq.iThuc = iThuc * b.iThuc - iAo * b.iAo;
        kq.iAo = iThuc * b.iAo + iAo * b.iThuc;
        return kq;
    }

    SoPhuc Thuong(SoPhuc b) {
        SoPhuc kq;
        double mau = b.iThuc * b.iThuc + b.iAo * b.iAo;
        if (mau == 0) {
            cout << "Khong the chia cho so phuc 0" << endl;
            return kq;
        }
        kq.iThuc = (iThuc * b.iThuc + iAo * b.iAo) / mau;
        kq.iAo = (iAo * b.iThuc - iThuc * b.iAo) / mau;
        return kq;
    }
};

int main() {
    SoPhuc sp1, sp2, kq;
    cout << "So phuc 1:\n"; sp1.Nhap();
    cout << "So phuc 2:\n"; sp2.Nhap();

    cout << "\nKet qua:";
    cout << "\nTong: "; (kq = sp1.Tong(sp2)).Xuat();
    cout << "Hieu: "; (kq = sp1.Hieu(sp2)).Xuat();
    cout << "Tich: "; (kq = sp1.Tich(sp2)).Xuat();
    cout << "Thuong: "; (kq = sp1.Thuong(sp2)).Xuat();

    return 0;
}
