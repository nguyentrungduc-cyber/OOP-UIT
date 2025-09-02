#include "DoiTuong.h"

DoiTuong::DoiTuong() : ID(0), Type(0) {}

DoiTuong::~DoiTuong() {}

int DoiTuong::getID() const
{
    return ID;
}

int DoiTuong::getType() const
{
    return Type;
}