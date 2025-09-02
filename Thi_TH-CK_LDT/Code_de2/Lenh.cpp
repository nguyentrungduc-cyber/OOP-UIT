#include "Lenh.h"

Lenh::Lenh() : TraderID(0), LoaiLenh(0), lenh(0), tienCuoc(0) {}

void Lenh::Nhap()
{
    std::cin >> TraderID;
    if (TraderID == -1)
        return;

    std::cin >> LoaiLenh >> lenh >> tienCuoc;
}

void Lenh::Xuat() const
{
    if (TraderID == -1)
        return;
    std::cout << TraderID << " " << LoaiLenh << " " << lenh << " " << tienCuoc << "\n";
}