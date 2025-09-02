#pragma once

#include <iostream>
#include <vector>

using namespace std;

class GiaSuc
{
protected:
    int iLoai; // dung de cho cac loai gia suc : bo, de, cuu

public:
    GiaSuc();
    virtual ~GiaSuc();

    virtual void TiengKeu() = 0;
    virtual int iSinhCon() = 0;
    virtual int iChoSua() = 0;
    virtual int igetLoai();
};

class Bo : public GiaSuc
{

public:
    Bo();
    ~Bo();
    void TiengKeu() override;
    int iSinhCon() override;
    int iChoSua() override;
};

class Cuu : public GiaSuc
{
public:
    Cuu();
    ~Cuu();
    void TiengKeu() override;
    int iSinhCon() override;
    int iChoSua() override;
};

class De : public GiaSuc
{
public:
    De();
    ~De();
    void TiengKeu() override;
    int iSinhCon() override;
    int iChoSua() override;
};

class DSGiaSuc
{
private:
    vector<GiaSuc *> vDanhSach;
    int iSoLuongGiaSuc;

public:
    ~DSGiaSuc();
    void NhapDS();
};
