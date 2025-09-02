#ifndef PHANSO_H
#define PHANSO_H

#include <iostream>
using namespace std;

class PhanSo {
private:
    int* TuSo;
    int* MauSo;

public:
    PhanSo();
    PhanSo(int tu, int mau);
    PhanSo(const PhanSo& ps);
    ~PhanSo();

    void rutGon();

    PhanSo operator=(const PhanSo& ps);

    PhanSo operator+(const PhanSo& ps);
    PhanSo operator-(const PhanSo& ps);
    PhanSo operator*(const PhanSo& ps);
    PhanSo operator/(const PhanSo& ps);

    PhanSo operator+=(const PhanSo& ps);
    PhanSo operator-=(const PhanSo& ps);
    PhanSo operator*=(const PhanSo& ps);
    PhanSo operator/=(const PhanSo& ps);

    bool operator==(const PhanSo& ps);
    bool operator!=(const PhanSo& ps);
    bool operator<(const PhanSo& ps);
    bool operator<=(const PhanSo& ps);
    bool operator>(const PhanSo& ps);
    bool operator>=(const PhanSo& ps);

    PhanSo operator++();     
    PhanSo operator++(int);  
    PhanSo operator--();     
    PhanSo operator--(int);  

    friend istream& operator>>(istream& is, PhanSo& ps);
    friend ostream& operator<<(ostream& os, PhanSo ps);
};

#endif
