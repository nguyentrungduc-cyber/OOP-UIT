#include "MangSoNguyen.h"
#include <iostream>
using namespace std;

int main()
{
    MangSoNguyen a, b;

    cout << "Nhap mang a:\n";
    cin >> a;

    cout << "Nhap mang b:\n";
    cin >> b;

    cout << "\nMang a: " << a << endl;
    cout << "Mang b: " << b << endl;

    MangSoNguyen tong = a + b;
    cout << "Mang a + b = " << tong << endl;
    cout << "Mang b + a = " << b + a << endl;

    cout << "\nTien to ++a: " << ++a << endl;
    cout << "Hau to a++: " << a++ << endl;

    return 0;
}
