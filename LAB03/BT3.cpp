#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

class cPhanSo {
public:
    int tu, mau;
    cPhanSo(int t = 0, int m = 1) : tu(t), mau(m) { rutGon(); }

    void rutGon() {
        if (mau == 0) return;
        int common = gcd(abs(tu), abs(mau));
        tu /= common;
        mau /= common;
        if (mau < 0) { tu = -tu; mau = -mau; }
    }

    double giaTri() const { return (double)tu / mau; }

    void xuat() const { cout << tu << "/" << mau; }
};

class cDSPhanSo {
private:
    vector<cPhanSo> ds;

public:
    void nhap() {
        int n;
        cout << "Nhap so luong phan so: "; cin >> n;
        for (int i = 0; i < n; i++) {
            int t, m;
            cout << "Nhap PS thu " << i + 1 << " (tu mau): ";
            cin >> t >> m;
            ds.push_back(cPhanSo(t, m));
        }
    }

    cPhanSo tinhTong() {
        cPhanSo tong(0, 1);
        for (const auto& ps : ds) {
            tong = cPhanSo(tong.tu * ps.mau + ps.tu * tong.mau, tong.mau * ps.mau);
        }
        return tong;
    }

    cPhanSo timMax() {
        return *max_element(ds.begin(), ds.end(), [](cPhanSo a, cPhanSo b) { return a.giaTri() < b.giaTri(); });
    }

    cPhanSo timMin() {
        return *min_element(ds.begin(), ds.end(), [](cPhanSo a, cPhanSo b) { return a.giaTri() < b.giaTri(); });
    }

    cPhanSo timPhanSoTuNguyenToMax() {
        cPhanSo maxPS(0, 1);
        bool found = false;
        for (const auto& ps : ds) {
            if (isPrime(ps.tu)) {
                if (!found || ps.tu > maxPS.tu) {
                    maxPS = ps;
                    found = true;
                }
            }
        }
        return maxPS;
    }

    void sapXepTang() {
        sort(ds.begin(), ds.end(), [](cPhanSo a, cPhanSo b) { return a.giaTri() < b.giaTri(); });
    }

    void sapXepGiam() {
        sort(ds.begin(), ds.end(), [](cPhanSo a, cPhanSo b) { return a.giaTri() > b.giaTri(); });
    }

    void xuat() {
        for (const auto& ps : ds) { ps.xuat(); cout << " "; }
        cout << endl;
    }
};

int main() {
    cDSPhanSo list;
    list.nhap();

    cout << "\nTong cac phan so: "; list.tinhTong().xuat();
    cout << "\nPhan so lon nhat: "; list.timMax().xuat();
    cout << "\nPhan so nho nhat: "; list.timMin().xuat();

    cout << "\nPhan so co tu la SNT lon nhat: ";
    list.timPhanSoTuNguyenToMax().xuat();

    cout << "\nSap xep tang dan: ";
    list.sapXepTang(); list.xuat();

    cout << "Sap xep giam dan: ";
    list.sapXepGiam(); list.xuat();

    return 0;
}
