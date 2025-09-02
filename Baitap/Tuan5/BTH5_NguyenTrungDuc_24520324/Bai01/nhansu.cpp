#include "nhansu.h"

// ========== Nhan Su ==========
void NhanSu::Nhap()
{
    cout << "Nhap ho ten: ";
    getline(cin, sHoTen);

    cout << "Nhap ngay thang nam sinh (dd/mm/yy): ";
    getline(cin, sSinhNhat);

    cout << "Nhap ma so nhan su: ";
    cin >> iMaSo;

    cin.ignore(); // avoid getline in another function
}

void NhanSu::Xuat()
{
    cout << "Ho Ten: " << sHoTen << endl;
    cout << "Ngay thang nam sinh (dd/mm/yy): " << sSinhNhat << endl;
    cout << "Ma so: " << iMaSo << endl;
}

// ========== Giang Vien ==========
void GiaoVien::vNhap()
{
    NhanSu::Nhap();

    cout << "Nhap hoc ham: ";
    getline(cin, sHocHam);

    cout << "Nhap hoc vi: ";
    getline(cin, sHocVi);

    cout << "So nam giang day: ";
    cin >> iNamGiangDay;
    cin.ignore();

    int SoLuong;
    cout << "Nhap so luong mon hoc: ";
    cin >> SoLuong;
    cin.ignore();

    vDanhSachMonGiangDay.resize(SoLuong);
    cout << "\n========Thong tin mon giang day========" << endl;
    for (int i = 0; i < SoLuong; i++)
    {
        cout << "Nhap mon hoc thu " << i + 1 << " : ";
        getline(cin, vDanhSachMonGiangDay[i]); // type of data is string
    }
}

void GiaoVien::vXuat()
{
    NhanSu::Xuat();

    cout << "Hoc ham: " << sHocHam << endl;
    cout << "Hoc vi: " << sHocVi << endl;
    for (auto &MonGV : vDanhSachMonGiangDay)
    {
        cout << "Mon giang day: " << MonGV << endl;
    }
    cout << "Luong giao vien: " << dLuongGV() << endl;
}

double GiaoVien::dLuongGV()
{
    return ((vDanhSachMonGiangDay.size() * iNamGiangDay * 0.12) * 20000);
}

void DSGiaoVien::NhapDS()
{
    cout << "Nhap so luong giao vien: ";
    cin >> iSoLuongGV;
    cin.ignore();
    cout << "\n========Danh sach thong tin giao vien========" << endl;
    for (int i = 0; i < iSoLuongGV; i++)
    {
        cout << "Nhap thong tin giao vien thu " << i + 1 << endl;
        GiaoVien *DanhSach = new GiaoVien();
        DanhSach->vNhap();
        vDanhSachGV.push_back(DanhSach);
        cout << endl;
    }
}

void DSGiaoVien::XuatDS()
{
    cout << "\n========Danh sach thong tin giao vien========" << endl;
    for (int i = 0; i < iSoLuongGV; i++)
    {
        cout << "Thong tin giao vien thu " << i + 1 << " : ";
        vDanhSachGV[i]->vXuat();
        cout << endl;
    }
}

DSGiaoVien::~DSGiaoVien()
{
    for (auto &Gv : vDanhSachGV)
    {
        delete Gv;
    }
    vDanhSachGV.clear();
}

double DSGiaoVien::dLuongGV()
{
    double Tong = 0.0;
    for (auto &Gv : vDanhSachGV)
    {
        Tong += Gv->dLuongGV();
    }
    return Tong;
}

// ========== Tro Giang ==========
void TroGiang::Nhap()
{
    NhanSu::Nhap();

    int iSoLuongMonTrogiang;
    cout << "Nhap so luong mon tro giang:  ";
    cin >> iSoLuongMonTrogiang;
    cin.ignore();
    vDanhSachMonTroGiang.resize(iSoLuongMonTrogiang);

    cout << "\n========Thong tin mon tro giang========" << endl;
    for (int i = 0; i < iSoLuongMonTrogiang; i++)
    {
        cout << "Nhap mon thu " << i + 1 << " : ";
        getline(cin, vDanhSachMonTroGiang[i]);
    }
}

void TroGiang::Xuat()
{
    NhanSu::Xuat();

    for (auto &MonTG : vDanhSachMonTroGiang)
    {
        cout << "Mon tro giang: " << MonTG << endl;
    }
    cout << "Luong tro giang: " << dLuongTG() << endl;
}

double TroGiang::dLuongTG()
{
    return (vDanhSachMonTroGiang.size() * 0.3) * 18000;
}

void DSTroGiang::NhapDS()
{
    cout << "Nhap so luong tro giang: ";
    cin >> iSoLuongTG;
    cin.ignore();

    cout << "\n===========Danh sach tro giang===========" << endl;
    for (int i = 0; i < iSoLuongTG; i++)
    {
        cout << "Nhap thong tin tro giang thu " << i + 1 << endl;
        TroGiang *Tg = new TroGiang();
        Tg->Nhap();
        vDanhSachTG.push_back(Tg);
        cout << endl;
    }
}

void DSTroGiang::XuatDS()
{
    cout << "\n===========Thong tin danh sach tro giang===========" << endl;
    for (int i = 0; i < iSoLuongTG; i++)
    {
        cout << "Thong tin tro giang thu " << i + 1 << endl;
        vDanhSachTG[i]->Xuat();
        cout << endl;
    }
}

DSTroGiang::~DSTroGiang()
{
    for (auto &Tg : vDanhSachTG)
    {
        delete Tg;
    }
    vDanhSachTG.clear();
}

double DSTroGiang::dLuongTG()
{
    double Tong = 0.0;
    for (auto &Gv : vDanhSachTG)
    {
        Tong += Gv->dLuongTG();
    }
    return Tong;
}

// ========== Nghien Cuu Vien ==========
void NghienCuuVien::Nhap()
{
    NhanSu::Nhap();

    cout << "Nhap so nam kinh nghiem nghien cuu: ";
    cin >> iNamNghienCuu;
    cin.ignore();

    int iSoLuongDuAnNghienCuu;
    cout << "Nhap so luong du an nghien cuu: ";
    cin >> iSoLuongDuAnNghienCuu;
    cin.ignore();

    vDanhSachMaDuAnNghienCuu.resize(iSoLuongDuAnNghienCuu);
    cout << "\n========Thong tin du an nghien cuu========" << endl;
    for (int i = 0; i < iSoLuongDuAnNghienCuu; i++)
    {
        string KiemTra;
        while (true)
        {
            cout << "Nhap du an nghien cuu thu " << i + 1 << " : ";
            getline(cin, KiemTra);

            if ((((KiemTra[0] >= 'a') && (KiemTra[0] <= 'z')) || ((KiemTra[0] >= 'A') && (KiemTra[0] <= 'Z'))) &&
                (KiemTra.length() == 3) &&
                ((KiemTra[1] >= '1') && (KiemTra[1] <= '9')) && ((KiemTra[2] >= '1') && (KiemTra[2] <= '9')))
            {
                vDanhSachMaDuAnNghienCuu[i] = KiemTra;
                break;
            }
            else
            {
                cout << "Ma khong hop le! Vui long nhap lai (1 chu cai + 2 chu so)! Xin cam on!" << endl;
            }
        }
    }
}

void NghienCuuVien::Xuat()
{
    NhanSu::Xuat();

    for (auto &MaDuAn : vDanhSachMaDuAnNghienCuu)
    {
        cout << "Ma du an nghien cuu: " << MaDuAn << endl;
    }
    cout << "Luong nghien cuu vien: " << dLuongNCV() << endl;
}

double NghienCuuVien::dLuongNCV()
{
    int Dem = 0;
    for (auto &MaDuAn : vDanhSachMaDuAnNghienCuu)
    {
        if (MaDuAn[0] == 'D')
            Dem++;
    }
    return (iNamNghienCuu * 2 + Dem) * 20000;
}

void DSNghienCuuVien::NhapDS()
{
    cout << "Nhap so luong nghien cuu vien: ";
    cin >> iSoLuongNCV;
    cin.ignore();

    cout << "\n===========Danh sach nghien cuu vien===========" << endl;
    for (int i = 0; i < iSoLuongNCV; i++)
    {
        cout << "Nhap thong tin nghien cuu vien thu " << i + 1 << endl;
        NghienCuuVien *Ncv = new NghienCuuVien();
        Ncv->Nhap();
        vDanhSachNCV.push_back(Ncv);
        cout << endl;
    }
}

void DSNghienCuuVien::XuatDS()
{
    cout << "\n===========Thong tin danh sach nghien cuu vien===========" << endl;
    for (int i = 0; i < iSoLuongNCV; i++)
    {
        cout << "Thong tin tro giang thu " << i + 1 << endl;
        vDanhSachNCV[i]->Xuat();
        cout << endl;
    }
}

DSNghienCuuVien::~DSNghienCuuVien()
{
    for (auto &Ncv : vDanhSachNCV)
    {
        delete Ncv;
    }
    vDanhSachNCV.clear();
}

double DSNghienCuuVien::dLuongNCV()
{
    double Tong = 0.0;
    for (auto &Gv : vDanhSachNCV)
    {
        Tong += Gv->dLuongNCV();
    }
    return Tong;
}

// ========== Chuyen Vien ==========
void ChuyenVien::Nhap()
{
    NhanSu ::Nhap();

    cout << "Nhap so nam kinh nghiem lam viec: ";
    cin >> iNamKinhNghiem;
    cin.ignore();

    int iSoLuongDuAnGiaoDuc;
    cout << "Nhap so luong du an giao duc hoan thanh: ";
    cin >> iSoLuongDuAnGiaoDuc;
    cin.ignore();

    vDanhSachMaDuAnGiaoDuc.resize(iSoLuongDuAnGiaoDuc);
    for (int i = 0; i < iSoLuongDuAnGiaoDuc; i++)
    {
        string KiemTra;
        while (true)
        {
            cout << "Nhap du an nghien cuu thu " << i + 1 << " : ";
            getline(cin, KiemTra);

            if ((((KiemTra[0] >= 'a') && (KiemTra[0] <= 'z')) || ((KiemTra[0] >= 'A') && (KiemTra[0] <= 'Z'))) &&
                (KiemTra.length() == 3) &&
                ((KiemTra[1] >= '1') && (KiemTra[1] <= '9')) && ((KiemTra[2] >= '1') && (KiemTra[2] <= '9')))
            {
                vDanhSachMaDuAnGiaoDuc[i] = KiemTra;
                break;
            }
            else
            {
                cout << "Ma khong hop le! Vui long nhap lai (1 chu cai + 2 chu so)! Xin cam on!" << endl;
            }
        }
    }
}

void ChuyenVien::Xuat()
{
    NhanSu::Xuat();

    for (int i = 0; i < vDanhSachMaDuAnGiaoDuc.size(); i++)
    {
        cout << "Ma du an giao duc hoan thanh thu " << i + 1 << " : " << vDanhSachMaDuAnGiaoDuc[i] << endl;
    }
    cout << "Luong chuyen vien: " << dLuongCV() << endl;
}

double ChuyenVien::dLuongCV()
{
    int Dem = 0;
    for (auto &MaDuAn : vDanhSachMaDuAnGiaoDuc)
    {
        if (MaDuAn[0] == 'T')
            Dem++;
    }
    return (iNamKinhNghiem * 4 + Dem) * 18000;
}

void DSChuyenVien::NhapDS()
{
    cout << "Nhap so luong chuyen vien: ";
    cin >> iSoLuongCV;
    cin.ignore();

    cout << "\n===========Danh sach chuyen vien===========" << endl;
    for (int i = 0; i < iSoLuongCV; i++)
    {
        cout << "Nhap thong tin chuyen thu " << i + 1 << endl;
        ChuyenVien *Cv = new ChuyenVien();
        Cv->Nhap();
        vDanhSachCV.push_back(Cv);
        cout << endl;
    }
}

void DSChuyenVien::XuatDS()
{
    cout << "\n===========Thong tin danh sach chuyen vien===========" << endl;
    for (int i = 0; i < iSoLuongCV; i++)
    {
        cout << "Thong tin chuyen vien thu " << i + 1 << endl;
        vDanhSachCV[i]->Xuat();
        cout << endl;
    }
}

DSChuyenVien::~DSChuyenVien()
{
    for (auto &Cv : vDanhSachCV)
    {
        delete Cv;
    }
    vDanhSachCV.clear();
}

double DSChuyenVien::dLuongCV()
{
    double Tong = 0.0;
    for (auto &Gv : vDanhSachCV)
    {
        Tong += Gv->dLuongCV();
    }
    return Tong;
}