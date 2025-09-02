#include <iostream>
#include "PhanSo.h"
using namespace std;

int main() {
    PhanSo a, b;

    cout << "Nhap phan so thu nhat:\n";
    cin >> a;

    cout << "Nhap phan so thu hai:\n";
    cin >> b;

    cout << "\nPhan so a: " << a << endl;
    cout << "Phan so b: " << b << endl;

    PhanSo tong = a + b;
    PhanSo hieu = a - b;
    PhanSo tich = a * b;
    PhanSo thuong = a / b;

    cout << "\na + b = " << tong << endl;
    cout << "a - b = " << hieu << endl;
    cout << "a * b = " << tich << endl;
    cout << "a / b = " << thuong << endl;

    PhanSo c;
    c = a;
    c += b;
    cout << "\nc = a; c += b; => c = " << c << endl;

    c = a;
    c -= b;
    cout << "c = a; c -= b; => c = " << c << endl;

    c = a;
    c *= b;
    cout << "c = a; c *= b; => c = " << c << endl;

    c = a;
    c /= b;
    cout << "c = a; c /= b; => c = " << c << endl;

    cout << "\nSo sanh:\n";
    cout << "a == b: " << (a == b) << endl;
    cout << "a != b: " << (a != b) << endl;
    cout << "a < b: "  << (a < b)  << endl;
    cout << "a <= b: " << (a <= b) << endl;
    cout << "a > b: "  << (a > b)  << endl;
    cout << "a >= b: " << (a >= b) << endl;

    cout << "\nToan tu tien to, hau to:\n";
    cout << "++a = " << ++a << endl;
    cout << "a++ = " << a++ << endl;

    cout << "--b = " << --b << endl;
    cout << "b-- = " << b-- << endl;

    return 0;
}
