#ifndef COMOI_H
#define COMOI_H

#include "DoiTuong.h"

class CoMoi : public DoiTuong
{

private:
    int TraderID;
    double HoaHong;

public:
    CoMoi();
    void Nhap(int, int) override;
    void Xuat() const override;
    int getTraderID() const;
    void themHoaHong(double);
    double getHoaHong() const;
};

#endif