#ifndef PHANSO_H
#define PHANSO_H

#include <bits/stdc++.h>

using namespace std;

class PhanSo
{
private:
    int TuSo;
    int MauSo;

public:
    PhanSo();

    PhanSo(int, int);

    void Nhap();
    void NhapN(PhanSo p[], int n);

    static PhanSo Tong(PhanSo p[], int n);
    void RutGon();

    void SapXep(PhanSo p[], int n, bool Hoi);

    void Xuat();
    void XuatN(PhanSo p[], int n);
};

#endif
