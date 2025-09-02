#include "MangSoNguyen.h"
#include <iostream>
using namespace std;

MangSoNguyen::MangSoNguyen()
{
    kichthuoc = 0;
    dulieu = nullptr;
}

MangSoNguyen::MangSoNguyen(int n)
{
    kichthuoc = n;
    dulieu = new int[kichthuoc] {};
}

MangSoNguyen::MangSoNguyen(const MangSoNguyen& mang)
{
    kichthuoc = mang.kichthuoc;
    dulieu = new int[kichthuoc];
    for (int i = 0; i < kichthuoc; ++i)
        dulieu[i] = mang.dulieu[i];
}

MangSoNguyen::~MangSoNguyen()
{
    delete[] dulieu;
}

MangSoNguyen MangSoNguyen::operator=(const MangSoNguyen& mang)
{
    if (this != &mang) {
        delete[] dulieu;
        kichthuoc = mang.kichthuoc;
        dulieu = new int[kichthuoc];
        for (int i = 0; i < kichthuoc; ++i)
            dulieu[i] = mang.dulieu[i];
    }
    return *this;
}

MangSoNguyen MangSoNguyen::operator+(const MangSoNguyen& mang)
{
    int max = (kichthuoc > mang.kichthuoc) ? kichthuoc : mang.kichthuoc;
    MangSoNguyen tong(max);
    for (int i = 0; i < max; ++i) {
        int x = (i < kichthuoc) ? dulieu[i] : 0;
        int y = (i < mang.kichthuoc) ? mang.dulieu[i] : 0;
        tong.dulieu[i] = x + y;
    }
    return tong;
}

MangSoNguyen MangSoNguyen::operator++()
{
    for (int i = 0; i < kichthuoc; ++i)
        ++dulieu[i];
    return *this;
}

MangSoNguyen MangSoNguyen::operator++(int)
{
    MangSoNguyen tam(*this);
    ++(*this);
    return tam;
}

istream& operator>>(istream& is, MangSoNguyen& mang)
{
    cout << "Nhap kich thuoc mang: ";
    is >> mang.kichthuoc;

    delete[] mang.dulieu;
    mang.dulieu = new int[mang.kichthuoc];

    for (int i = 0; i < mang.kichthuoc; ++i) {
        cout << "dulieu[" << i << "] = ";
        is >> mang.dulieu[i];
    }
    return is;
}

ostream& operator<<(ostream& os, const MangSoNguyen& mang)
{
    for (int i = 0; i < mang.kichthuoc; ++i)
        os << mang.dulieu[i] << " ";
    return os;
}
