#ifndef TRADER_H
#define TRADER_H

#include "DoiTuong.h"

class Trader : public DoiTuong
{
private:
    double SoDu;

public:
    Trader();
    void Nhap(int, int) override;
    void Xuat() const override;
    double getSoDu() const;
    void capNhatSoDu(double);
    bool datCuoc(double tienCuoc) const;
};

#endif