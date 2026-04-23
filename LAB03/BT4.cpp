#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>

using namespace std;

class cArray {
private:
    vector<int> data;

    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0) return false;
        return true;
    }

public:
    void taoNgauNhien(int n) {
        data.clear();
        srand(time(0));
        for (int i = 0; i < n; i++) {
            data.push_back(rand() % 100);
        }
    }

    void xuat() {
        for (int x : data) cout << x << " ";
        cout << endl;
    }

    int demX(int x) {
        int count = 0;
        for (int val : data) if (val == x) count++;
        return count;
    }

    bool kiemTraTang() {
        return is_sorted(data.begin(), data.end());
    }

    int timLeNhoNhat() {
        int minLe = -1;
        bool found = false;
        for (int x : data) {
            if (x % 2 != 0) {
                if (!found || x < minLe) {
                    minLe = x;
                    found = true;
                }
            }
        }
        return minLe;
    }

    int timSTNLonNhat() {
        int maxSNT = -1;
        for (int x : data) {
            if (isPrime(x)) {
                if (x > maxSNT) maxSNT = x;
            }
        }
        return maxSNT;
    }

    void sapXep(bool tang) {
        if (tang) sort(data.begin(), data.end());
        else sort(data.begin(), data.end(), greater<int>());
    }
};

int main() {
    cArray arr;
    int n, x;

    cout << "Nhap so luong phan tu n: "; cin >> n;
    arr.taoNgauNhien(n);

    cout << "Mang vua tao: "; arr.xuat();

    cout << "Nhap gia tri x can dem: "; cin >> x;
    cout << "So lan xuat hien cua " << x << ": " << arr.demX(x) << endl;

    cout << "Mang tang dan? " << (arr.kiemTraTang() ? "Co" : "Khong") << endl;

    int leMin = arr.timLeNhoNhat();
    if (leMin != -1) cout << "So le nho nhat: " << leMin << endl;
    else cout << "Khong co so le trong mang." << endl;

    int sntMax = arr.timSTNLonNhat();
    if (sntMax != -1) cout << "So nguyen to lon nhat: " << sntMax << endl;
    else cout << "Khong co so nguyen to." << endl;

    cout << "Sap xep tang dan: ";
    arr.sapXep(true); arr.xuat();

    return 0;
}
