#include "hocsinh.h"

int main()
{
    LopHoc lop;
    lop.NhapN();
    lop.XuatN();

    std::cout << "\nThem mot hoc sinh:\n";
    lop.ThemHocSinh();
    lop.XuatN();

    std::string maso;
    std::cout << "\nNhap MSSV hoc sinh can xoa: ";
    std::cin >> maso;
    lop.XoaHocSinh(maso);

    std::cout << "\nDanh sach hoc sinh sau khi xoa:\n";
    lop.XuatN();

    return 0;
}
