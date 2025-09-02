#include "phanso.h"
#include <bits/stdc++.h>

int main()
{
    int SoLuong;
    cout << "Nhap so luong: ";
    cin >> SoLuong;

    int Hoi;
    cout << "Tang dan(1) hay Giam dan(0): ";
    cin >> Hoi;

    PhanSo *ps1 = new PhanSo[SoLuong];
    ps1[0].NhapN(ps1, SoLuong);
    ps1[0].XuatN(ps1, SoLuong);

    PhanSo Tong = PhanSo::Tong(ps1, SoLuong);
    cout << "\nTong cac phan so: ";
    Tong.Xuat();

    PhanSo ps;
    ps.SapXep(ps1, SoLuong, Hoi);
    cout << endl
         << "Danh sach phan so sau khi sap xep" << endl;
    ps.XuatN(ps1, SoLuong);

    delete[] ps1;

    return 0;
}