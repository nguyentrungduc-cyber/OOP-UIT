#ifndef HOCSINH_H
#define HOCSINH_H

#include <string>
#include <iostream>

using namespace std;

class HocSinh
{
private:
    string HoTen, MaSo, SoDT;
    float DTB;

public:
    HocSinh();
    HocSinh(string, string, string, float);

    void Nhap();
    void KiemTraHoTen();
    void KiemTraMSSV();
    void KiemTraSDT();
    void KiemTraDTB();
};

#endif