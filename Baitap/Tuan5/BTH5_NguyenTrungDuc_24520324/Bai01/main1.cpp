#include "nhansu.h"

int main()
{
    DSGiaoVien Gv;
    DSTroGiang Tg;
    DSNghienCuuVien Ncv;
    DSChuyenVien Cv;

    cout << "======== IN PUT ========" << endl;
    Gv.NhapDS();
    Tg.NhapDS();
    Ncv.NhapDS();
    Cv.NhapDS();

    cout << "======== OUT PUT ========" << endl;
    Gv.XuatDS();
    Tg.XuatDS();
    Ncv.XuatDS();
    Cv.XuatDS();

    double TongLuong = 0.0;
    TongLuong = Gv.dLuongGV() + Tg.dLuongTG() + Ncv.dLuongNCV() + Cv.dLuongCV();
    cout << "Tong luong phai tra cho nhan su: " << TongLuong;

    return 0;
}