#include "nhanvien.h"
#include <bits/stdc++.h>

NhanVien::NhanVien()
{
    HoTenNhanVien.Ho = "null";
    HoTenNhanVien.Ten = "null";
    SoNgay = 0;
    MaSo = "null";
    ChucDanh = "null";
    HeSoLuong = 0;
}

NhanVien::NhanVien(HoTen hoTen, int soNgay, string maSo, string chucDanh, float hesoLuong)
{
    this->HoTenNhanVien = hoTen;
    this->SoNgay = soNgay;
    this->MaSo = maSo;
    this->ChucDanh = chucDanh;
    this->HeSoLuong = hesoLuong;
}

NhanVien::NhanVien(const NhanVien &temp)
{
    SoNgay = temp.SoNgay;
    ChucDanh = temp.ChucDanh;
    HeSoLuong = temp.HeSoLuong;
}

void NhanVien::set_HoTen()
{
    cout << "Nhap ho: ";
    getline(cin, HoTenNhanVien.Ho);

    cout << "Nhap ten: ";
    getline(cin, HoTenNhanVien.Ten);
}

void NhanVien::set_SoNgay()
{
    cout << "Nhap so ngay: ";
    cin >> SoNgay;
}

string NhanVien::get_HoTen()
{
    cout << "\n=========Danh sach sinh vien=========\n";
    cout << "Ho ten sinh vien: ";
    return HoTenNhanVien.Ho + " " + HoTenNhanVien.Ten;
}

int NhanVien::get_SoNgay()
{
    cout << "\nSo ngay lam viec: ";
    return SoNgay;
}

string NhanVien::get_MaSo()
{
    cout << "\nMa so nhan vien: ";
    return to_string(SoNgay) + HoTenNhanVien.Ten;
}

string NhanVien::get_ChucDanh()
{
    cout << "\nChuc danh nhan vien: ";
    if ((SoNgay >= 0) && (SoNgay < 365))
    {
        ChucDanh = "Nhan vien";
    }
    else if ((SoNgay >= 365) && (SoNgay < 730))
    {
        ChucDanh = "Quan ly";
    }
    else if ((SoNgay >= 730) && (SoNgay < 1460))
    {
        ChucDanh = "Truong phong";
    }
    else
    {
        ChucDanh = "Truong ban quan ly";
    }

    return ChucDanh;
}

float NhanVien::get_HeSoLuong()
{
    cout << "\nHe so luong nhan vien: ";
    if (ChucDanh == "Nhan vien")
    {
        HeSoLuong = 1.0;
    }
    else if (ChucDanh == "Quan ly")
    {
        HeSoLuong = 1.5;
    }
    else if (ChucDanh == "Truong phong")
    {
        HeSoLuong = 2.25;
    }
    else
    {
        HeSoLuong = 4.0;
    }

    return HeSoLuong;
}

void NhanVien::Nhap()
{
    cout << "Nhap ho nhan vien: ";
    cin.ignore();
    getline(cin, HoTenNhanVien.Ho);

    cout << "Nhap ten nhan vien: ";
    getline(cin, HoTenNhanVien.Ten);

    cout << "Nhap ngay lam viec: ";
    cin >> SoNgay;

    MaSo = get_MaSo();
    ChucDanh = get_ChucDanh();
    HeSoLuong = get_HeSoLuong();
}

void NhanVien::Xuat()
{
    cout << left << setw(19) << (HoTenNhanVien.Ho + " " + HoTenNhanVien.Ten)
         << setw(20) << SoNgay
         << setw(18) << MaSo
         << setw(22) << ChucDanh
         << setw(14) << fixed << setprecision(1) << HeSoLuong << endl;
}

void NhanVien::NhapN(NhanVien nv[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nhan vien thu " << i + 1 << endl;
        nv[i].Nhap();
        cout << endl;
    }
}

void NhanVien::XuatN(NhanVien nv[], int n)
{
    cout << "\n=========Danh sach nhan vien=========00\n";
    cout << left << setw(19) << "Ho ten nhan vien"
         << setw(20) << "So ngay lam viec"
         << setw(18) << "Ma so nhan vien"
         << setw(22) << "Chuc danh nhan vien"
         << setw(14) << "He so luong" << endl;

    for (int j = 0; j < n; j++)
    {
        nv[j].Xuat();
    }
}

NhanVien::~NhanVien() {}
