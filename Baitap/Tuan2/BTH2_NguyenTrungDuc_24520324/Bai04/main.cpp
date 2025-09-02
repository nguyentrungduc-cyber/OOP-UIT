#include "daThuc.h"
#include <iostream>

int main()
{
    int SoLuong;
    std::cout << "Nhap so luong da thuc: ";
    std::cin >> SoLuong;

    DaThuc *dt1 = new DaThuc[SoLuong];
    dt1[0].nhapN(dt1, SoLuong);
    dt1[0].xuatN(dt1, SoLuong);

    double x;
    std::cout << "\nNhap gia tri x: ";
    std::cin >> x;
    std::cout << "P1(" << x << ") = " << dt1[0].tinhGiaTri(x) << std::endl;

    DaThuc sum = tinhTong(dt1, SoLuong);
    std::cout << "Tong: ";
    sum.xuat();

    DaThuc diff = tinhHieu(dt1, SoLuong);
    std::cout << "Hieu ";
    diff.xuat();

    delete[] dt1;

    return 0;
}
