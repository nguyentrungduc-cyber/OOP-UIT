#include "NhaCai.h"

NhaCai::NhaCai() : SoDu(0) { Type = 1; }

void NhaCai::Nhap(int id, int type)
{
    std::cin >> SoDu;
    ID = id;
    Type = type;
}

void NhaCai::Xuat() const
{
    std::cout << ID << " " << Type << " " << SoDu << "\n";
}

double NhaCai::getSoDu() const
{
    return SoDu;
}

void NhaCai::capNhatSoDu(double LoiNhuan)
{
    SoDu += LoiNhuan;
}
