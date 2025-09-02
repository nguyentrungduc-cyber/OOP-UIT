#include "CoMoi.h"

#include <cmath>

CoMoi::CoMoi() : TraderID(0), HoaHong(0) { Type = 2; }

void CoMoi::Nhap(int id, int type)
{
    std::cin >> TraderID;
    ID = id;
    type = Type;
}

void CoMoi::Xuat() const
{
    std::cout << ID << " " << Type << " " << TraderID << "\n";
}

int CoMoi::getTraderID() const
{
    return TraderID;
}

// hưởng 1% giá trị giao dịch của trader mà họ giới thiệu, bất kể trader thắng hay thua
void CoMoi::themHoaHong(double tienCuoc)
{
    // làm tròn chữ số
    HoaHong += floor(tienCuoc * 0.01 * 100) / 100;
}

double CoMoi::getHoaHong() const
{
    return HoaHong;
}
