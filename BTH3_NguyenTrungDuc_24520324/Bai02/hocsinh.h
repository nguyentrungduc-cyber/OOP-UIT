#ifndef HOCSINH_H
#define HOCSINH_H

#include <iostream>
#include <string>
#include <vector>

class HocSinh {
public:
    std::string HoTen;
    std::string MaSo;
    int Tuoi;
    float DTB;

    HocSinh();
    HocSinh(std::string hoten, std::string maso, int tuoi, float dtb);
    void Nhap();
    void Xuat();
    static std::vector<HocSinh*> NhapTuFile(const std::string& filename);
};

class LopHoc {
private:
    std::vector<HocSinh*> DanhSach;

public:
    LopHoc();
    ~LopHoc();
    void NhapN();
    void XuatN();
    void ThemHocSinh();
    void XoaHocSinh(const std::string& maso);
    void C();
};

#endif
