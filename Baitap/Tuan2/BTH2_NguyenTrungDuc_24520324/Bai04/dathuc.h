#ifndef DATHUC_H
#define DATHUC_H

#include <vector>
#include <iostream>

class DaThuc
{
private:
    int bac;
    std::vector<double> heSo;

public:
    DaThuc();
    DaThuc(int n);

    void nhap();
    void nhapN(DaThuc dt1[], int n);

    void xuat() const;
    void xuatN(DaThuc dt1[], int n) const;

    double tinhGiaTri(double x) const;

    DaThuc operator+(const DaThuc &other) const;

    DaThuc operator-(const DaThuc &other) const;
};
DaThuc tinhHieu(const DaThuc dt1[], int n);
DaThuc tinhTong(const DaThuc dt1[], int n);
#endif
