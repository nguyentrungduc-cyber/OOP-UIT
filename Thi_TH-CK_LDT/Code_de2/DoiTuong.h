#ifndef DOiTUONG_H
#define DOiTUONG_H

#include <iostream>

class DoiTuong
{
protected:
    int ID, Type;

public:
    DoiTuong();
    virtual ~DoiTuong();
    virtual void Nhap(int, int) = 0;
    virtual void Xuat() const = 0;
    int getID() const;
    int getType() const;
};

#endif