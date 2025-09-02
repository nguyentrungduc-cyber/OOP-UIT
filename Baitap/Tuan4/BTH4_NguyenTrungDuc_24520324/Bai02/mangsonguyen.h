#ifndef MANGSONGUYEN_H
#define MANGSONGUYEN_H

#include <iostream>
using namespace std;

class MangSoNguyen {
private:
    int* dulieu;
    int kichthuoc;

public:
    MangSoNguyen();
    MangSoNguyen(int n);
    MangSoNguyen(const MangSoNguyen& mang);
    ~MangSoNguyen();

    MangSoNguyen operator=(const MangSoNguyen& mang);
    MangSoNguyen operator+(const MangSoNguyen& mang);

    MangSoNguyen operator++();
    MangSoNguyen operator++(int);

    friend ostream& operator<<(ostream& os, const MangSoNguyen& mang);
    friend istream& operator>>(istream& is, MangSoNguyen& mang);
};

#endif
