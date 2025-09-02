#include "canbo.h"

// ========== Can Bo ==========
void CanBo::Nhap()
{
    cout << "Nhap ho ten: ";
    getline(cin, sHoTen);

    cout << "Nhap ngay thang nam sinh (dd/mm/yy): ";
    getline(cin, sSinhNhat);

    cout << "Nhap ma so can bo: ";
    cin >> sMaSo;

    cin.ignore(); // avoid getline in another function
}

void CanBo::Xuat()
{
    cout << "Ho Ten: " << sHoTen << endl;
    cout << "Ngay thang nam sinh (dd/mm/yy): " << sSinhNhat << endl;
    cout << "Ma so: " << sMaSo << endl;
}

// ========== Can Bo Bien Che ==========
void CanBoBienChe::Nhap()
{
    cout << "Nhap thong tin can bo bien che: " << endl;

    CanBo::Nhap();

    cout << "Nhap luong co ban: ";
    cin >> lLuongCoBan;

    cout << "Nhap he so luong phu cap: ";
    cin >> iHeSoLuongPhuCap;

    cout << "Nhap he so luong: ";
    cin >> iHeSoLuong;
    cin.ignore();
}

void CanBoBienChe::Xuat()
{
    cout << "Thong tin cac bo bien che: " << endl;

    CanBo::Xuat();

    cout << "Luong co ban: " << lLuongCoBan << endl;
    cout << "He so luong phu cap: " << iHeSoLuongPhuCap << endl;
    cout << "He so luong: " << iHeSoLuong << endl;
    cout << "Luong cua can bo bien che: " << lLuong() << endl;
}

long CanBoBienChe::lLuong()
{
    return lLuongCoBan * iHeSoLuongPhuCap * iHeSoLuong;
}

// ========== Can Bo ==========
void CanBoHopDong::Nhap()
{
    cout << "Nhap thong tin can bo hop dong: " << endl;

    CanBo::Nhap();

    cout << "Nhap tien cong: ";
    cin >> lTienCong;

    cout << "Nhap he so vuot gio: ";
    cin >> iHeSoVuotGio;

    cout << "Nhap ngay cong: ";
    cin >> iNgayCong;

    cin.ignore();
}

void CanBoHopDong::Xuat()
{
    cout << "Thong tin can bo hop dong: " << endl;

    CanBo::Xuat();

    cout << "Tien cong: " << lTienCong << endl;
    cout << "He so vuot gio: " << iHeSoVuotGio << endl;
    cout << "Ngay cong: " << iNgayCong << endl;
    cout << "Luong: " << lLuong() << endl;
}

long CanBoHopDong::lLuong()
{
    return lTienCong * iHeSoVuotGio * iNgayCong;
}
// ========== Danh Sach Can Bo ==========
void DanhSachCanBo::NhapDS()
{
    int iSoLuongCanBoBienChe;
    cout << "Nhap so luong can bo bien che nha nuoc: ";
    cin >> iSoLuongCanBoBienChe;

    int iSoLuongCanBoHopDong;
    cout << "Nhap so luong can ba hop dong: ";
    cin >> iSoLuongCanBoHopDong;

    cin.ignore();

    iSoLuongCanBo = iSoLuongCanBoBienChe + iSoLuongCanBoHopDong;

    vDanhSach.resize(iSoLuongCanBo);

    for (int i = 0; i < iSoLuongCanBoBienChe; i++)
    {
        vDanhSach[i] = new CanBoBienChe();
    }

    for (int i = iSoLuongCanBoBienChe; i < iSoLuongCanBo; i++)
    {
        vDanhSach[i] = new CanBoHopDong;
    }
    cout << "\n======== IN PUT ========\n " << endl;
    for (int i = 0; i < iSoLuongCanBo; i++)
    {
        vDanhSach[i]->Nhap();
    }

    cout << "\n======== OUT PUT ========\n " << endl;
    for (int i = 0; i < iSoLuongCanBo; i++)
    {
        vDanhSach[i]->Xuat();
    }

    int iTongLuongCanBo = 0; // khong co "= 0" dan den gia tri rac;
    for (int i = 0; i < iSoLuongCanBo; i++)
    {
        iTongLuongCanBo += vDanhSach[i]->lLuong();
    }
    cout << "So tien luong phai tra cho toan bo can bo: " << iTongLuongCanBo << endl;
}

DanhSachCanBo::~DanhSachCanBo()
{
    for (auto &Cb : vDanhSach)
    {
        delete Cb;
    }
    vDanhSach.clear();
}
