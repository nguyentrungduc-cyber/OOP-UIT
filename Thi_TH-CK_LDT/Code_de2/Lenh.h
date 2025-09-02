#ifndef LENH_H
#define LENH_H

#include <iostream>

class Lenh
{
public:
    int TraderID, LoaiLenh, lenh;
    double tienCuoc;

    // ID của trader - Trực tiếp (0)/ phái sinh(1) - Up(1)/ Down(0)
    Lenh();
    void Nhap();
    void Xuat() const;
};

#endif