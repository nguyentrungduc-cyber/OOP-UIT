#ifndef SANGIAODICH_H
#define SANGIAODICH_H

#include "NhaCai.h"
#include "CoMoi.h"
#include "Trader.h"
#include "Lenh.h"
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

class SanGiaoDich
{
private:
    std::vector<DoiTuong *> DSDoiTuong;
    NhaCai *nhaCai;

    Trader *TimTrader(int ID);
    CoMoi *TimCoMoi(int traderID);

public:
    SanGiaoDich() : nhaCai(nullptr) {}
    ~SanGiaoDich();
    void Nhap();
    void Xuat() const;
    void XuLyLuot(int luot, bool &ketThucSom);
    void XuatFile();
};

#endif