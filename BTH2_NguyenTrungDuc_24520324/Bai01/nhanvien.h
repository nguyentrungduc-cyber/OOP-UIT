#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <string>

using namespace std;

class HoTen
{
public:
    string Ho;
    string Ten;

    HoTen() {}
    HoTen(string ho, string ten) : Ho(ho), Ten(ten) {}
};

class NhanVien
{
private:
    HoTen HoTenNhanVien;
    string MaSo, ChucDanh;
    int SoNgay;
    float HeSoLuong;

public:
    NhanVien();
    NhanVien(HoTen hoTen, int soNgay, string maSo, string chucDanh, float hesoLuong);
    NhanVien(HoTen hoTen, int soNgay);
    NhanVien(const NhanVien &temp);

    void set_HoTen();
    void set_SoNgay();

    string get_HoTen();
    int get_SoNgay();
    string get_MaSo();
    string get_ChucDanh();
    float get_HeSoLuong();

    void Nhap();
    void Xuat();
    void NhapN(NhanVien nv[], int n);
    void XuatN(NhanVien nv[], int n);

    ~NhanVien();
};

#endif
