#include "hocsinh.h"
#include <iostream>

using namespace std;

HocSinh::HocSinh() : HoTen("NULL"), MaSo("NULL"), SoDT("NULL"), DTB(0.0) {}

HocSinh::HocSinh(string hoten, string maso, string sodt, float dtb)
    : HoTen(hoten), MaSo(maso), SoDT(sodt), DTB(dtb) {}

void HocSinh::KiemTraHoTen()
{
    string KetQua;
    while (true)
    {
        KetQua = "";
        for (char KiemTra : HoTen)
        {
            if (((KiemTra >= 'A') && (KiemTra <= 'Z')) ||
                ((KiemTra >= 'a') && (KiemTra <= 'z')) ||
                (KiemTra == ' '))
            {
                KetQua += KiemTra;
            }
        }
        if (!KetQua.empty())
            break;
        cout << "Ho ten khong hop le! Nhap lai: ";
        // cin.ignore();
        getline(cin, HoTen);
    }
    HoTen = KetQua;
    cout << "Ho ten sau khi kiem tra: " << HoTen << endl;
}

void HocSinh::KiemTraMSSV()
{
    while (true)
    {
        string KetQua = "";
        for (char KiemTra : MaSo)
        {
            if (KiemTra >= '0' && KiemTra <= '9')
            {
                KetQua += KiemTra;
            }
        }
        if (KetQua.length() == 8)
        {
            MaSo = KetQua;
            cout << "Ma so sau khi kiem tra: " << MaSo << endl;
            break;
        }
        cout << "MSSV khong hop le! Nhap lai (8 chu so): ";
        cin.ignore();
        getline(cin, MaSo);
    }
}

void HocSinh::KiemTraSDT()
{
    while (true)
    {
        string KetQua = "";
        for (char KiemTra : SoDT)
        {
            if (KiemTra >= '0' && KiemTra <= '9')
            {
                KetQua += KiemTra;
            }
        }
        if (KetQua.length() >= 9 && KetQua.length() <= 11)
        {
            SoDT = KetQua;
            cout << "So dien thoai sau khi kiem tra: " << SoDT << endl;
            break;
        }
        cout << "So dien thoai khong hop le! Nhap lai (9-11 chu so): ";
        // cin.ignore();
        getline(cin, SoDT);
    }
}

void HocSinh::KiemTraDTB()
{
    while (DTB < 0 || DTB > 10)
    {
        cout << "DTB khong hop le! Nhap lai (0-10): ";
        cin >> DTB;
    }
    cout << "Diem trung binh sau khi kiem tra: " << DTB << endl;
}

void HocSinh::Nhap()
{
    cout << "Nhap ho ten hoc sinh: ";
    getline(cin, HoTen);
    // KiemTraHoTen();

    cout << "Nhap ma so hoc sinh: ";
    // cin.ignore();
    getline(cin, MaSo);
    // KiemTraMSSV();

    cout << "Nhap so dien thoai: ";
    // cin.ignore();
    getline(cin, SoDT);
    // KiemTraSDT();

    cout << "Nhap diem trung binh: ";
    cin >> DTB;
    // KiemTraDTB();
}
