// Trường đại học này có đội ngũ gồm: giảng viên, trợ giảng, nghiên cứu viên và chuyên
// viên. Tất cả đội ngũ nhân sự đều có thông tin về họ tên, ngày tháng năm sinh, mã số
// nhân sự. Mỗi vai trò cần phải được cung cấp thêm thông tin và có cách tính lương dựa
// trên tính chất công việc, cụ thể:
// • Giảng viên cần phải được cung cấp thông tin về học hàm, học vị, số năm giảng
// dạy và danh sách tên tất cả các môn học đang giảng dạy. Trợ giảng cần cung cấp
// thông tin về số môn trợ giảng. Giảng viên và trợ giảng được tính lương theo công
// thức:
// o Lương giảng viên = (số môn giảng dạy * số năm giảng dạy * 0.12) * 20000
// o Lương trợ giảng = (số môn trợ giảng * 0.3) * 18000
// • Nghiên cứu viên được cung cấp thông tin về danh sách tất cả mã dự án nghiên cứu
// đang tham gia, và chuyên viên phải cung cấp thông tin về danh sách tất cả mã dự
// án giáo dục đã hoàn thành. Mỗi dự án đều có mã dự án bắt đầu bằng một chữ cái
// kèm theo 2 chữ số, ví dụ một số mã dự án: M01, X92, ... và nghiên cứu viên còn
// có thêm thông tin về số năm kinh nghiệm nghiên cứu, chuyên viên có thông tin về
// số năm kinh nghiệm làm việc. Nghiên cứu viên và chuyên viên được tính lương
// theo công thức:
// o Lương nghiên cứu viên = (số năm kinh nghiệm nghiên cứu * 2 + số dự án
// bắt đầu bằng chữ D) * 20000
// o Lương chuyên viên = (số năm kinh nghiệm làm việc * 4 + số dự án bắt
// đầu bằng chữ T) * 18000

#ifndef NHANSU_H
#define NHANSU_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class NhanSu
{
private:
    string sHoTen, sSinhNhat;
    int iMaSo;

public:
    void Nhap();
    void Xuat();
};

class GiaoVien : public NhanSu
{
private:
    string sHocHam, sHocVi;
    int iNamGiangDay;
    vector<string> vDanhSachMonGiangDay;

public:
    void vNhap();
    void vXuat();
    double dLuongGV();
};

class DSGiaoVien
{
private:
    vector<GiaoVien *> vDanhSachGV;
    int iSoLuongGV;

public:
    ~DSGiaoVien();
    void NhapDS();
    void XuatDS();
    double dLuongGV();
};

class TroGiang : public NhanSu
{
private:
    vector<string> vDanhSachMonTroGiang;

public:
    void Nhap();
    void Xuat();
    double dLuongTG();
};

class DSTroGiang
{
private:
    vector<TroGiang *> vDanhSachTG;
    int iSoLuongTG;

public:
    ~DSTroGiang();
    void NhapDS();
    void XuatDS();
    double dLuongTG();
};

class NghienCuuVien : public NhanSu
{
private:
    vector<string> vDanhSachMaDuAnNghienCuu;
    int iNamNghienCuu;

public:
    void Nhap();
    void Xuat();
    double dLuongNCV();
};

class DSNghienCuuVien
{
private:
    vector<NghienCuuVien *> vDanhSachNCV;
    int iSoLuongNCV;

public:
    ~DSNghienCuuVien();
    void NhapDS();
    void XuatDS();
    double dLuongNCV();
};

class ChuyenVien : public NhanSu
{
private:
    vector<string> vDanhSachMaDuAnGiaoDuc;
    int iNamKinhNghiem;

public:
    void Nhap();
    void Xuat();
    double dLuongCV();
};

class DSChuyenVien
{
private:
    vector<ChuyenVien *> vDanhSachCV;
    int iSoLuongCV;

public:
    ~DSChuyenVien();
    void NhapDS();
    void XuatDS();
    double dLuongCV();
};

#endif