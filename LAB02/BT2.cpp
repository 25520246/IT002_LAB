#include <iostream>
#include <cmath>

using namespace std;

class PhanSo {
private:
    int iTu, iMau;

    int timUSCLN(int a, int b) {
        a = abs(a); b = abs(b);
        if (a == 0 || b == 0) return a + b;
        while (a != b) {
            if (a > b) a -= b;
            else b -= a;
        }
        return a;
    }

public:
    void Nhap() {
        cout << "Nhap tu so: "; cin >> iTu;
        do {
            cout << "Nhap mau so: "; cin >> iMau;
            if (iMau == 0) cout << "Mau so khong hop le, nhap lai.\n";
        } while (iMau == 0);
    }

    void Xuat() {
        if (iMau < 0) { iTu = -iTu; iMau = -iMau; }
        if (iTu == 0) cout << 0;
        else if (iMau == 1) cout << iTu;
        else cout << iTu << "/" << iMau;
    }

    void RutGon() {
        int uoc = timUSCLN(iTu, iMau);
        iTu /= uoc;
        iMau /= uoc;
    }

    PhanSo Tong(PhanSo b) {
        PhanSo kq;
        kq.iTu = iTu * b.iMau + b.iTu * iMau;
        kq.iMau = iMau * b.iMau;
        kq.RutGon();
        return kq;
    }

    PhanSo Hieu(PhanSo b) {
        PhanSo kq;
        kq.iTu = iTu * b.iMau - b.iTu * iMau;
        kq.iMau = iMau * b.iMau;
        kq.RutGon();
        return kq;
    }

    PhanSo Tich(PhanSo b) {
        PhanSo kq;
        kq.iTu = iTu * b.iTu;
        kq.iMau = iMau * b.iMau;
        kq.RutGon();
        return kq;
    }

    PhanSo Thuong(PhanSo b) {
        PhanSo kq;
        kq.iTu = iTu * b.iMau;
        kq.iMau = iMau * b.iTu;
        kq.RutGon();
        return kq;
    }

    int SoSanh(PhanSo b) {
        int veTrai = iTu * b.iMau;
        int vePhai = b.iTu * iMau;

        if (veTrai > vePhai) return 1;
        if (veTrai < vePhai) return -1;
        return 0;
    }
};

int main() {
    PhanSo ps1, ps2, ketQua;

    cout << "Phan so 1:\n";
    ps1.Nhap();
    cout << "Phan so 2\n";
    ps2.Nhap();

    ps1.RutGon();
    cout << "Phan so 1 sau khi rut gon: ";
    ps1.Xuat();
    cout << endl;

    ps2.RutGon();
    cout << "Phan so 2 sau khi rut gon: ";
    ps2.Xuat();
    cout << endl;

    cout << "Tong: ";
    ketQua = ps1.Tong(ps2);
    ketQua.Xuat(); cout << endl;

    cout << "Hieu: ";
    ketQua = ps1.Hieu(ps2);
    ketQua.Xuat(); cout << endl;

    cout << "Tich: ";
    ketQua = ps1.Tich(ps2);
    ketQua.Xuat(); cout << endl;

    cout << "Thuong: ";
    ketQua = ps1.Thuong(ps2);
    ketQua.Xuat(); cout << endl;

    cout << "So sanh: ";
    int ss = ps1.SoSanh(ps2);
    if (ss == 1) cout << "PS1 > PS2";
    else if (ss == -1) cout << "PS1 < PS2";
    else cout << "PS1 = PS2";

    cout << endl;
    return 0;
}
