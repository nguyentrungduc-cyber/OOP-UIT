#include "PhanSo.h"
#include <numeric>

PhanSo::PhanSo()
{
    TuSo = new int(0);
    MauSo = new int(1);
}

PhanSo::PhanSo(int tu, int mau)
{
    TuSo = new int(tu);
    MauSo = new int(mau == 0 ? 1 : mau);
    rutGon();
}

PhanSo::PhanSo(const PhanSo& ps)
{
    TuSo = new int(*ps.TuSo);
    MauSo = new int(*ps.MauSo);
}

PhanSo::~PhanSo()
{
    delete TuSo;
    delete MauSo;
}

void PhanSo::rutGon()
{
    int ucln = gcd(*TuSo, *MauSo); 
    *TuSo /= ucln;
    *MauSo /= ucln;

    if (*MauSo < 0) {
        *TuSo *= -1;
        *MauSo *= -1;
    }
}

PhanSo PhanSo::operator=(const PhanSo& ps)
{
    if (this != &ps) {
        *TuSo = *ps.TuSo;
        *MauSo = *ps.MauSo;
    }
    return *this;
}

PhanSo PhanSo::operator+(const PhanSo& ps)
{
    int tu = (*TuSo) * (*ps.MauSo) + (*ps.TuSo) * (*MauSo);
    int mau = (*MauSo) * (*ps.MauSo);
    return PhanSo(tu, mau);
}

PhanSo PhanSo::operator-(const PhanSo& ps)
{
    int tu = (*TuSo) * (*ps.MauSo) - (*ps.TuSo) * (*MauSo);
    int mau = (*MauSo) * (*ps.MauSo);
    return PhanSo(tu, mau);
}

PhanSo PhanSo::operator*(const PhanSo& ps)
{
    int tu = (*TuSo) * (*ps.TuSo);
    int mau = (*MauSo) * (*ps.MauSo);
    return PhanSo(tu, mau);
}

PhanSo PhanSo::operator/(const PhanSo& ps)
{
    int tu = (*TuSo) * (*ps.MauSo);
    int mau = (*MauSo) * (*ps.TuSo);
    return PhanSo(tu, mau);
}

PhanSo PhanSo::operator+=(const PhanSo& ps)
{
    *this = *this + ps;
    return *this;
}

PhanSo PhanSo::operator-=(const PhanSo& ps)
{
    *this = *this - ps;
    return *this;
}

PhanSo PhanSo::operator*=(const PhanSo& ps)
{
    *this = *this * ps;
    return *this;
}

PhanSo PhanSo::operator/=(const PhanSo& ps)
{
    *this = *this / ps;
    return *this;
}

bool PhanSo::operator==(const PhanSo& ps)
{
    return (*TuSo) * (*ps.MauSo) == (*ps.TuSo) * (*MauSo);
}

bool PhanSo::operator!=(const PhanSo& ps)
{
    return !(*this == ps);
}

bool PhanSo::operator<(const PhanSo& ps)
{
    return (*TuSo) * (*ps.MauSo) < (*ps.TuSo) * (*MauSo);
}

bool PhanSo::operator<=(const PhanSo& ps)
{
    return (*this < ps) || (*this == ps);
}

bool PhanSo::operator>(const PhanSo& ps)
{
    return !(*this <= ps);
}

bool PhanSo::operator>=(const PhanSo& ps)
{
    return !(*this < ps);
}

PhanSo PhanSo::operator++()
{
    *TuSo += *MauSo;
    return *this;
}

PhanSo PhanSo::operator++(int)
{
    PhanSo temp = *this;
    ++(*this);
    return temp;
}

PhanSo PhanSo::operator--()
{
    *TuSo -= *MauSo;
    return *this;
}

PhanSo PhanSo::operator--(int)
{
    PhanSo temp = *this;
    --(*this);
    return temp;
}

istream& operator>>(istream& is, PhanSo& ps)
{
    cout << "Tu so: ";
    is >> *ps.TuSo;
    cout << "Mau so: ";
    is >> *ps.MauSo;
    if (*ps.MauSo == 0)
        *ps.MauSo = 1;
    ps.rutGon();
    return is;
}

ostream& operator<<(ostream& os, PhanSo ps)
{
    os << *ps.TuSo << "/" << *ps.MauSo;
    return os;
}
