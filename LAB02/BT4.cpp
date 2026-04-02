#include <iostream>

using namespace std;

class ThoiGian {
private:
    int iGio, iPhut, iGiay;

public:
    void Nhap() {
        do {
            cout << "Nhap gio: "; cin >> iGio;
            cout << "Nhap phut: "; cin >> iPhut;
            cout << "Nhap giay: "; cin >> iGiay;

            if (iGio < 0 || iGio > 23 || iPhut < 0 || iPhut > 59 || iGiay < 0 || iGiay > 59) {
                cout << "Thoi gian khong hop le, nhap lai.\n";
            } else {
                break;
            }
        } while (true);
    }

    void Xuat() {
        if (iGio < 10) cout << "0";
        cout << iGio << ":";

        if (iPhut < 10) cout << "0";
        cout << iPhut << ":";

        if (iGiay < 10) cout << "0";
        cout << iGiay << endl;
    }

    void TinhCongThemMotGiay() {
        iGiay++;
        if (iGiay >= 60) {
            iGiay = 0;
            iPhut++;
            if (iPhut >= 60) {
                iPhut = 0;
                iGio++;
                if (iGio >= 24) {
                    iGio = 0;
                }
            }
        }
    }
};

int main() {
    ThoiGian tg;

    cout << "Nhap thoi gian\n";
    tg.Nhap();

    cout << "Thoi gian hien tai: ";
    tg.Xuat();

    tg.TinhCongThemMotGiay();

    cout << "Thoi gian sau khi +1 giay: ";
    tg.Xuat();

    return 0;
}
