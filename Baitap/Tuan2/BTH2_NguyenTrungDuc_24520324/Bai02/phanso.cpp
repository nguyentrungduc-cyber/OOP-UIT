#include "phanso.h"
#include <bits/stdc++.h>

PhanSo::PhanSo()
{
    TuSo = 0;
    MauSo = 1;
}

PhanSo::PhanSo(int tuSo, int mauSo)
{
    this->TuSo = tuSo;
    this->MauSo = mauSo;
    RutGon();
}

void PhanSo::Nhap()
{
    cout << "Nhap tu so: ";
    cin >> TuSo;

    cout << "Nhap mau so: ";
    cin >> MauSo;
}

void PhanSo::Xuat()
{
    cout << TuSo << "/" << MauSo;
}

void PhanSo::NhapN(PhanSo p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Phan so thu " << i + 1 << endl;
        p[i].Nhap();
        cout << endl;
    }
}

void PhanSo::XuatN(PhanSo p[], int n)
{
    cout << "\n==========Danh sach phan so==========\n";

    for (int j = 0; j < n; j++)
    {
        cout << "Gia tri phan so thu " << j + 1 << " : ";
        p[j].Xuat();
        cout << endl;
    }
}

PhanSo PhanSo::Tong(PhanSo p[], int n)
{
    PhanSo tong(0, 1);
    for (int i = 0; i < n; i++)
    {
        int msc = lcm(tong.MauSo, p[i].MauSo);
        int tuMoi = (tong.TuSo * (msc / tong.MauSo)) + (p[i].TuSo * (msc / p[i].MauSo));
        tong = PhanSo(tuMoi, msc);
    }
    return tong;
}

void PhanSo::RutGon()
{
    int ucln = std::gcd(TuSo, MauSo);
    TuSo /= ucln;
    MauSo /= ucln;
}

void PhanSo::SapXep(PhanSo p[], int n, bool Hoi)
{
    if (Hoi == 1) // be -> lon
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((p[i].TuSo * p[j].MauSo) > (p[j].TuSo * p[i].MauSo))
                {
                    swap(p[i], p[j]);
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((p[i].TuSo * p[j].MauSo) < (p[j].TuSo * p[i].MauSo))
                {
                    swap(p[i], p[j]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        p[i].RutGon();
    }
}
