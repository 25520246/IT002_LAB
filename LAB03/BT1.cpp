#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct diem {
    double x,y;
};

class cTamGiac {
private:
    diem A,B,C;

    double AB,AC,BC;

    void updatecanh() {
        AB = sqrt(pow((A.x - B.x),2) + pow((A.y - B.y),2));
        AC = sqrt(pow((A.x - C.x),2) + pow((A.y - C.y),2));
        BC = sqrt(pow((B.x - C.x),2) + pow((B.y - C.y),2));
    }

public:
    cTamGiac() {
        A = {0,0};
        B = {0,0};
        C = {0,0};
        updatecanh();
    }

    ~cTamGiac(){}

    void nhap() {
        cout << "Nhap toa do A(x,y): ";
        cin >> A.x >> A.y;
        cout << "Nhap toa do B(x,y): ";
        cin >> B.x >> B.y;
        cout << "Nhap toa do C(x,y): ";
        cin >> C.x >> C.y;
        updatecanh();
    }

    void xuat() {
        cout << "Tam giac co 3 diem:";
        cout << " A(" << A.x << ',' << A.y << ')' << '\n';
        cout << " B(" << B.x << ',' << B.y << ')' << '\n';
        cout << " C(" << C.x << ',' << C.y << ')' << '\n';
    }

    void kiemTraLoai() {
        double eps = 1e-6;

        if (abs(AB - BC) < eps && abs(BC - AC) < eps)
            cout << "Tam giac deu\n";
        else if (abs(AB - BC) < eps || abs(BC - AC) < eps || abs(AC - AB) < eps)
            cout << "Tam giac can\n";
        else if (abs(pow(AB, 2) + pow(BC, 2) - pow(AC, 2)) < eps ||
                 abs(pow(BC, 2) + pow(AC, 2) - pow(AB, 2)) < eps ||
                 abs(pow(AC, 2) + pow(AB, 2) - pow(BC, 2)) < eps)
            cout << "Tam giac vuong." << '\n';
        else
            cout << "Tam giac thuong." << '\n';
    }

    double tinhChuVi() {
        return AB + AC + BC;
    }

    double tinhDienTich() {
        double p = (AB + AC + BC) / 2;
        return sqrt(p * (p - AB) * (p - AC) * (p - BC));
    }

    void tinhTien(double dx, double dy) {
        A.x += dx; A.y += dy;
        B.x += dx; B.y += dy;
        C.x += dx; C.y += dy;
        updatecanh();
    }

    void quay(double alpha) {
        double rad = alpha * M_PI / 180.0;
        double s = sin(rad);
        double c = cos(rad);

        diem points[3] = {A, B, C};
        for(int i = 0; i < 3; i++) {
            double x_new = points[i].x * c - points[i].y * s;
            double y_new = points[i].x * s + points[i].y * c;
            points[i] = {x_new, y_new};
        }
        A = points[0]; B = points[1]; C = points[2];
    }

    void phongToThuNho(double k) {
        A.x *= k; A.y *= k;
        B.x *= k; B.y *= k;
        C.x *= k; C.y *= k;
        updatecanh();
    }
};

int main() {
    cTamGiac tg;
    tg.nhap();
    tg.xuat();

    cout << "Chu vi: " << tg.tinhChuVi() << '\n';
    cout << "Dien tich: " << tg.tinhDienTich() << '\n';
    cout << "Loai: "; tg.kiemTraLoai();

    double a,b;
    cout << "Nhap vector tinh tien(x,y): ";
    cin >> a >> b;
    tg.tinhTien(a, b);
    cout << "Sau khi tinh tien :\n";
    tg.xuat();

    cout << "Nhap goc quay: ";
    cin >> a;
    tg.quay(a);
    cout << "Sau khi quay:\n";
    tg.xuat();

    cout << "Nhap he so phong to: ";
    cin >> a;
    tg.phongToThuNho(a);
    if(a < 1) {cout << "Sau khi thu nho:\n"; tg.xuat();}
    else if(a > 1) {cout << "Sau khi phong to:\n"; tg.xuat();}
    else cout << "Khong co thay doi";



    return 0;
}
