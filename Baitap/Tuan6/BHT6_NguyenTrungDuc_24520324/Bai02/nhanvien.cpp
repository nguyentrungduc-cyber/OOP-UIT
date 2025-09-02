#include "nhanvien.h"

NhanVien::~NhanVien() {}

void NhanVien::Nhap()
{
    cout << "Nhap ma so: ";
    getline(cin, sMaSo);

    cout << "Nhap ho ten: ";
    getline(cin, sHoTen);

    cout << "Nhap ngay thang nam sinh (dd/mm/yyyy): ";
    getline(cin, sSinhNhat);
}

void NhanVien::Xuat()
{
    cout << "Ma so: " << sMaSo << endl;
    cout << "Ho ten: " << sHoTen << endl;
    cout << "Ngay thang nam sinh: " << sSinhNhat << endl;
}

void GiaoVien::Nhap()
{
    cout << "======== Nhap thong tin cho giao vien ========\n";

    NhanVien::Nhap();

    cout << "Nhap so tiet giang day: ";
    cin >> iTietHoc;

    cout << "Nhap so khoa luan huong dan: ";
    cin >> iKhoaLuan;

    cin.ignore();
}

void GiaoVien::Xuat()
{
    cout << "======== Thong tin cho giao vien ========\n";

    NhanVien::Xuat();

    cout << "So tiet giang day: " << iTietHoc << endl;
    cout << "So khoa luan huong dan: " << iKhoaLuan << endl;
}

bool GiaoVien::LaoDongTienTien()
{
    return ((iTietHoc >= 300) && (iKhoaLuan >= 5));
}

void NghienCuuVien::Nhap()
{
    cout << "======== Nhap thong tin cho nghien cuu vien ========\n";

    NhanVien::Nhap();

    cout << "Nhap so de tai nghien cuu: ";
    cin >> iDeTai;

    cout << "Nhap so bai bao khoa hoc (tac gia hoac dong gia): ";
    cin >> iBaiBao;

    cin.ignore();
}

void NghienCuuVien::Xuat()
{
    cout << "======== Thong tin cho nghien cuu vien ========\n";

    NhanVien::Xuat();

    cout << "So de tai nghien cuu: " << iDeTai << endl;
    cout << "So so bai bao khoa hoc (tac gia hoac dong gia): " << iBaiBao << endl;
}

bool NghienCuuVien::LaoDongTienTien()
{
    return ((iDeTai >= 1) && (iBaiBao >= 2));
}

void NhanVienVanPhong::Nhap()
{
    cout << "======== Nhap thong tin cho nhan vien van phong ========\n";

    NhanVien::Nhap();

    cout << "Nhap so lop boi duong da tham gia: ";
    cin >> iLopBoiDuong;

    cout << "Nhap so gio lao dong cong ich: ";
    cin >> fThoiGianLaoDongCongIch;

    cin.ignore();
}

void NhanVienVanPhong::Xuat()
{
    cout << "======== Thong tin cho nhan vien van phong ========\n";

    NhanVien::Xuat();

    cout << "So lop boi duong da tham gia: " << iLopBoiDuong << endl;
    cout << "So gio lao dong cong ich: " << fThoiGianLaoDongCongIch << endl;
}

bool NhanVienVanPhong::LaoDongTienTien()
{
    return ((iLopBoiDuong >= 1) && (fThoiGianLaoDongCongIch >= 20));
}

void QLNV::NhapDS()
{
    int iSoLuongGiaoVien;
    cout << "Nhap so luong giao vien: ";
    cin >> iSoLuongGiaoVien;

    int iSoLuongNghienCuuVien;
    cout << "Nhap so luong nghien cuu vien: ";
    cin >> iSoLuongNghienCuuVien;

    int iSoLuongNhanVienVanPhong;
    cout << "Nhap so luong nhan vien van phong: ";
    cin >> iSoLuongNhanVienVanPhong;

    cin.ignore();

    iSoLuongNhanVien = iSoLuongGiaoVien + iSoLuongNghienCuuVien + iSoLuongNhanVienVanPhong;

    vDanhSach.resize(iSoLuongNhanVien);

    for (int i = 0; i < iSoLuongGiaoVien; i++)
    {
        vDanhSach[i] = new GiaoVien();
    }

    for (int i = iSoLuongGiaoVien; i < (iSoLuongNhanVien - iSoLuongNhanVienVanPhong); i++)
    {
        vDanhSach[i] = new NghienCuuVien;
    }

    for (int i = (iSoLuongNhanVien - iSoLuongNhanVienVanPhong); i < iSoLuongNhanVien; i++)
    {
        vDanhSach[i] = new NhanVienVanPhong();
    }

    cout << "\n======== INPUT ========\n"
         << endl;
    for (int i = 0; i < iSoLuongNhanVien; i++)
    {
        vDanhSach[i]->Nhap();
    }
}

QLNV::~QLNV()
{
    for (auto &Nv : vDanhSach)
    {
        delete Nv;
    }
    vDanhSach.clear();
}

istream &operator>>(istream &is, QLNV &qlnv)
{
    qlnv.NhapDS();
    return is;
}

ostream &operator<<(ostream &os, const QLNV &qlnv)
{
    os << "\n======== OUTPUT ========\n";
    for (int i = 0; i < qlnv.iSoLuongNhanVien; i++)
    {
        if (qlnv.vDanhSach[i]->LaoDongTienTien())
        {
            qlnv.vDanhSach[i]->Xuat();
        }
    }
    return os;
}