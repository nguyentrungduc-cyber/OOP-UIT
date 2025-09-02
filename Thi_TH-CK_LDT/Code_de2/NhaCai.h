#ifndef NHACAI_H
#define NHACAI_H

#include "DoiTuong.h"

class NhaCai : public DoiTuong
{
private:
    double SoDu; // Thu trader, trả kèo trader, hoa hồng cò

public:
    NhaCai();
    void Nhap(int, int) override;
    void Xuat() const override;
    double getSoDu() const;
    void capNhatSoDu(double);
};

#endif