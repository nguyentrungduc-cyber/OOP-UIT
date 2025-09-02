#ifndef MANG_H
#define MANG_H

using namespace std;

#define NUMBER_ARRAY 100

class MangMotChieu
{
private:
    int Mang[NUMBER_ARRAY];
    int KichThuoc;

public:
    MangMotChieu();
    MangMotChieu(int Arr[], int n);
    void Nhap();
    void Xuat();
    void Random();
    void Dem();
    bool KiemTra();
    void SoLe();
    bool SoNguyenTo(int Phantu);
    void SoNguyenToLonNhat();
    ~MangMotChieu();
};

#endif
