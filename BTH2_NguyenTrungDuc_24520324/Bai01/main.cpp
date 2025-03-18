#include "nhanvien.h"
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int SoSV; // nhập số lượng sinh viên đi
    cout << "Nhap so sinh vien: ";
    cin >> SoSV;

    NhanVien *nv2 = new NhanVien[SoSV];
    nv2->NhapN(nv2, SoSV);
    nv2->XuatN(nv2, SoSV);

    delete[] nv2;

    // NhanVien sv2;

    // nv2.set_HoTen();
    // nv2.set_SoNgay();

    // cout << nv2.get_HoTen();
    // cout << nv2.get_SoNgay();
    // cout << nv2.get_MaSo();
    // cout << nv2.get_ChucDanh();
    // cout << fixed << setprecision(1) << nv2.get_HeSoLuong();

    // NhanVien nv1 = nv2;

    // cout << endl
    //      << nv1.get_SoNgay();
    // cout << nv1.get_ChucDanh();
    // cout << fixed << setprecision(1) << nv1.get_HeSoLuong();

    return 0;
}
