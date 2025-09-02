#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class NhanVien
{
protected:
    string sMaSo, sHoTen, sSinhNhat;

public:
    virtual ~NhanVien();
    virtual void Nhap();
    virtual void Xuat();
    virtual bool LaoDongTienTien() = 0;
};

class GiaoVien : public NhanVien
{
private:
    int iTietHoc, iKhoaLuan;

public:
    void Nhap() override;
    void Xuat() override;
    bool LaoDongTienTien() override;
};

class NghienCuuVien : public NhanVien
{
private:
    int iDeTai, iBaiBao;

public:
    void Nhap() override;
    void Xuat() override;
    bool LaoDongTienTien() override;
};

class NhanVienVanPhong : public NhanVien
{
private:
    int iLopBoiDuong;
    float fThoiGianLaoDongCongIch;

public:
    void Nhap() override;
    void Xuat() override;
    bool LaoDongTienTien() override;
};

class QLNV
{
private:
    vector<NhanVien *> vDanhSach;
    int iSoLuongNhanVien;

public:
    ~QLNV();
    void NhapDS();
    friend istream &operator>>(istream &is, QLNV &qlnv);
    friend ostream &operator<<(ostream &os, const QLNV &qlnv);
};