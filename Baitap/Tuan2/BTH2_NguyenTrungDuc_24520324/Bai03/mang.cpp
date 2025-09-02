#include "mang.h"
#include <iostream> // Để sử dụng cout, cin
#include <cstdlib>  // Để sử dụng rand(), srand()
#include <ctime>    // Để sử dụng time()

MangMotChieu::MangMotChieu() : KichThuoc(0) {}

// dung trong TH Mang co san
MangMotChieu::MangMotChieu(int Arr[], int n)
{
    KichThuoc = n;
    for (int i = 0; i < n; i++)
    {
        Mang[i] = Arr[i];
    }
}

void MangMotChieu::Nhap()
{
    cout << "Nhap so luong phan tu: ";
    cin >> KichThuoc;
    for (int i = 0; i < KichThuoc; i++)
    {
        cout << "Nhap gia tri thu " << i + 1 << ": ";
        cin >> Mang[i];
    }
}

void MangMotChieu::Xuat()
{
    cout << "Mang da nhap: ";
    for (int i = 0; i < KichThuoc; i++)
    {
        cout << Mang[i] << " ";
    }
    cout << endl;
}

void MangMotChieu::Random()
{
    cout << "Cau A, B" << endl;
    int SoNhoNhat, SoLonNhat;
    cout << "Nhap so luong phan tu: ";
    cin >> this->KichThuoc;

    cout << "Ban muon random tu a den b ([a, b])" << endl;
    cout << "Hay nhap a : ";
    cin >> SoNhoNhat;
    cout << "Hay nhap b : ";
    cin >> SoLonNhat;

    srand(time(0));

    for (int i = 0; i < this->KichThuoc; i++)
    {
        this->Mang[i] = SoNhoNhat + rand() % (SoLonNhat - SoNhoNhat + 1);
    }

    cout << "\n=======Danh sach cac phan tu random========\n";
    for (int j = 0; j < this->KichThuoc; j++)
    {
        cout << "Phan tu thu " << j + 1 << " : " << this->Mang[j] << endl;
    }
}

void MangMotChieu::Dem()
{
    cout << "Cau C" << endl;
    int GiaTriCanTim;
    cout << "Ban muon dem phan tu nao?" << endl;
    cout << "Tui muon dem phan tu ";
    cin >> GiaTriCanTim;

    int Dem = 0;
    for (int i = 0; i < KichThuoc; i++)
    {
        if (GiaTriCanTim == Mang[i])
        {
            Dem++;
        }
    }
    cout << "Vang, phan tu " << GiaTriCanTim << " xuat hien " << Dem << " lan a!";
}

bool MangMotChieu::KiemTra()
{
    cout << "\nCau D" << endl;
    for (int i = 0; i < (KichThuoc - 1); i++)
    {
        if (Mang[i] >= Mang[i + 1])
        {
            cout << "Damn it! Mang khong tang dan." << endl;
            return false;
        }
    }

    cout << "\nMay qua! Mang tang dan." << endl;
    return true;
}

void MangMotChieu::SoLe()
{
    cout << "Cau E" << endl;
    cout << "=======Danh sach cac phan tu so le========\n";
    int LeNhoNhat = Mang[0];
    for (int i = 0; i < KichThuoc; i++)
    {
        if (Mang[i] % 2 != 0)
        {
            cout << "Phan tu so le thu " << i + 1 << " : ";
            cout << Mang[i];
            cout << endl;

            if (LeNhoNhat > Mang[i])
            {
                LeNhoNhat = Mang[i];
            }
        }
    }
    cout << "So le nho nhat: " << LeNhoNhat;
}

bool MangMotChieu::SoNguyenTo(int PhanTu)
{
    if (PhanTu < 2)
        return false;
    for (int i = 2; i * i <= PhanTu; i++)
    {
        if (PhanTu % i == 0)
            return false;
    }
    return true;
}

void MangMotChieu::SoNguyenToLonNhat()
{
    cout << "\nCau F";
    int maxPrime = Mang[0];
    for (int i = 0; i < KichThuoc; i++)
    {
        if (SoNguyenTo(Mang[i]) && Mang[i] > maxPrime)
        {
            maxPrime = Mang[i];
        }
    }

    cout << "\nSo nguyen to lon nhat: " << maxPrime;
}

MangMotChieu::~MangMotChieu() {}