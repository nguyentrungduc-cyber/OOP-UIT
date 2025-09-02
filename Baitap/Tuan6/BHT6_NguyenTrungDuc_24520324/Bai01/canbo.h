#pragma once

#include <bits/stdc++.h>

using namespace std;

class CanBo
{
private:
    string sMaSo, sHoTen, sSinhNhat;

public:
    virtual void Nhap() = 0;
    virtual void Xuat() = 0;
    virtual long lLuong() = 0;
};

class CanBoBienChe : public CanBo
{
private:
    long lLuongCoBan;
    int iHeSoLuong, iHeSoLuongPhuCap;

public:
    void Nhap() override;
    void Xuat() override;
    long lLuong() override;
};

class CanBoHopDong : public CanBo
{
private:
    long lTienCong;
    int iHeSoVuotGio, iNgayCong;

public:
    void Nhap() override;
    void Xuat() override;
    long lLuong() override;
};

class DanhSachCanBo
{
private:
    vector<CanBo *> vDanhSach;
    int iSoLuongCanBo;

public:
    ~DanhSachCanBo();
    void NhapDS();
};