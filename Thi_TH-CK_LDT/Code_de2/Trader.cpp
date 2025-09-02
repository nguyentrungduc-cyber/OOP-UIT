#include "Trader.h"

Trader::Trader() : SoDu(0) { Type = 3; }

void Trader::Nhap(int id, int type)
{
    std::cin >> SoDu;
    ID = id;
    Type = type;
}

void Trader::Xuat() const
{
    std::cout << ID << " " << Type << " " << SoDu << "\n";
}

double Trader::getSoDu() const
{
    return SoDu;
}

void Trader::capNhatSoDu(double TienLoi)
{
    SoDu += TienLoi;
}

bool Trader::datCuoc(double tienCuoc) const
{
    return tienCuoc <= SoDu;
}
