#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Diem {
    double x, y;
};

class cDaGiac {
private:
    int n;
    vector<Diem> vertices;

public:
    cDaGiac() : n(0) {}

    void nhap() {
        do {
            cout << "Nhap so dinh (n >= 3): ";
            cin >> n;
        } while (n < 3);

        vertices.resize(n);
        for (int i = 0; i < n; i++) {
            cout << "Dinh " << i + 1 << " (x y): ";
            cin >> vertices[i].x >> vertices[i].y;
        }
    }

    void xuat() {
        cout << "Da giac co " << n << " dinh: ";
        for (const auto& p : vertices) {
            cout << "(" << p.x << ", " << p.y << ") ";
        }
        cout << endl;
    }

    double tinhChuVi() {
        double chuVi = 0;
        for (int i = 0; i < n; i++) {
            Diem p1 = vertices[i];
            Diem p2 = vertices[(i + 1) % n];
            chuVi += sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
        }
        return chuVi;
    }

    double tinhDienTich() {
        double dienTich = 0;
        for (int i = 0; i < n; i++) {
            Diem p1 = vertices[i];
            Diem p2 = vertices[(i + 1) % n];
            dienTich += (p1.x * p2.y - p2.x * p1.y);
        }
        return abs(dienTich) / 2.0;
    }

    void tinhTien(double dx, double dy) {
        for (auto& p : vertices) {
            p.x += dx;
            p.y += dy;
        }
    }

    void phongToThuNho(double k) {
        for (auto& p : vertices) {
            p.x *= k;
            p.y *= k;
        }
    }

    void quay(double alpha) {
        double rad = alpha * M_PI / 180.0;
        double s = sin(rad);
        double c = cos(rad);
        for (auto& p : vertices) {
            double x_new = p.x * c - p.y * s;
            double y_new = p.x * s + p.y * c;
            p.x = x_new; p.y = y_new;
        }
    }
};

int main() {
    cDaGiac dg;

    dg.nhap();
    dg.xuat();

    cout << "Chu vi: " << dg.tinhChuVi() << endl;
    cout << "Dien tich: " << dg.tinhDienTich() << endl;

    double a,b;

    cout << "Nhap vector tinh tien(x,y): ";
    cin >> a >> b;
    dg.tinhTien(a, b);
    cout << "Da giac sau khi tinh tien: \n";
    dg.xuat();

    cout << "Nhap do phong to/thu nho: ";
    cin >> a;
    dg.phongToThuNho(a);
    cout << "Da giac sau khi phong to/thu nho:\n";
    dg.xuat();

    cout << "Nhap goc quay: ";
    cin >> a;
    dg.quay(a);
    cout << "Da giac sau khi quay:\n";
    dg.xuat();

    return 0;
}
