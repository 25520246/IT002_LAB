#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

class cDaThuc {
private:
    int n;
    vector<double> a;

public:
    cDaThuc(int n = 0) : n(n) {
        a.resize(n + 1, 0);
    }

    void nhap() {
        cout << "Nhap bac cua da thuc: "; cin >> n;
        a.resize(n + 1);
        cout << "Nhap cac he so (tu bac " << n << " ve 0):" << endl;
        for (int i = 0; i <= n; i++) {
            cout << "He so x^" << n - i << ": ";
            cin >> a[i];
        }
    }

    void xuat() {
        for (int i = 0; i <= n; i++) {
            if (a[i] == 0) continue;
            if (i > 0 && a[i] > 0) cout << " + ";
            if (a[i] < 0) cout << " - ";
            cout << abs(a[i]);
            if (n - i > 0) cout << "x";
            if (n - i > 1) cout << "^" << n - i;
        }
        cout << endl;
    }

    double tinhGiaTri(double x) {
        double p = a[0];
        for (int i = 1; i <= n; i++)
            p = p * x + a[i];
        return p;
    }

    cDaThuc cong(cDaThuc other) {
        int maxN = max(this->n, other.n);
        cDaThuc res(maxN);
        for (int i = 0; i <= maxN; i++) {
            double val1 = (i >= maxN - this->n) ? this->a[i - (maxN - this->n)] : 0;
            double val2 = (i >= maxN - other.n) ? other.a[i - (maxN - other.n)] : 0;
            res.a[i] = val1 + val2;
        }
        return res;
    }

    cDaThuc tru(cDaThuc other) {
        int maxN = max(this->n, other.n);
        cDaThuc res(maxN);
        for (int i = 0; i <= maxN; i++) {
            double val1 = (i >= maxN - this->n) ? this->a[i - (maxN - this->n)] : 0;
            double val2 = (i >= maxN - other.n) ? other.a[i - (maxN - other.n)] : 0;
            res.a[i] = val1 - val2;
        }
        return res;
    }
};

int main() {
    cDaThuc P, Q;

    cout << "Nhap da thuc P" << endl;
    P.nhap();
    cout << "Da thuc P: "; P.xuat();

    cout << "\nNhap da thuc Q" << endl;
    Q.nhap();
    cout << "Da thuc Q: "; Q.xuat();

    double x;
    cout << "\nNhap gia tri x de tinh P(x): "; cin >> x;
    cout << "P(" << x << ") = " << P.tinhGiaTri(x) << endl;

    cout << "\nP + Q = ";
    P.cong(Q).xuat();

    cout << "P - Q = ";
    P.tru(Q).xuat();

    return 0;
}
