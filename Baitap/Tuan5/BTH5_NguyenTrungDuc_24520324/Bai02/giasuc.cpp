// #pragma one
#include "giasuc.h"
#include <string>
#include <algorithm>

// ============= Gia Suc =============

int GiaSuc::igetLoai()
{
    return iLoai;
}

GiaSuc::GiaSuc() {}

GiaSuc::~GiaSuc() {}

enum LoaiGiaSuc
{
    LOAI_BO = 1,
    LOAI_CUU = 2,
    LOAI_DE = 3
};

// ============= Bo =============
Bo::Bo()
{
    iLoai = LOAI_BO;
}

Bo::~Bo() {}

void Bo::TiengKeu()
{
    cout << "Um booooo!" << endl;
}

int Bo::iSinhCon()
{
    return rand() % 12; // Vậy tối đa một con bò cái có thể sinh khoảng 8–12 con trong đời (về lý thuyết)
}

int Bo::iChoSua()
{
    return rand() % 20;
}

// ============= Cuu =============
Cuu::Cuu()
{
    iLoai = LOAI_CUU;
}

Cuu::~Cuu() {}

void Cuu::TiengKeu()
{
    cout << "Me meeeee!" << endl;
}

int Cuu::iSinhCon()
{
    return rand() % 15; // một con cừu cái có thể sinh từ 6 đến 15 con hoặc hơn
}

int Cuu::iChoSua()
{
    return rand() % 5;
}

// ============= Cuu =============
De::De()
{
    iLoai = LOAI_DE;
}

De::~De() {}

void De::TiengKeu()
{
    cout << "Be Beeeee!" << endl;
}

int De::iSinhCon()
{
    return rand() % 6; // Dê có thể sinh tối đa 4 đến 6 con trong một lứa
}

int De::iChoSua()
{
    return rand() % 10;
}

// ============= Danh Sach Gia Suc =============
void DSGiaSuc::NhapDS()
{
    // So luong bo
    int iSoLuongBo;
    cout << "Nhap so luong bo: ";
    cin >> iSoLuongBo;

    // So luong cuu
    int iSoLuongCuu;
    cout << "So luong cuu: ";
    cin >> iSoLuongCuu;

    // So luong de
    int iSoLuongDe;
    cout << "Nhap so luong de: ";
    cin >> iSoLuongDe;

    // So luong gia suc
    iSoLuongGiaSuc = iSoLuongBo + iSoLuongCuu + iSoLuongDe;

    // Nap kich thuoc cho "vDanhSach" de cap phat dong gia suc
    vDanhSach.resize(iSoLuongGiaSuc);

    // Cap phap dong cho cac loai gia suc
    // Bo
    for (int i = 0; i < iSoLuongBo; i++) // nap du lieu vao danh sach, bat dau tu Bo
    {
        vDanhSach[i] = new Bo; // co "()" cung dung ma khong co cung dung neu Contructor khong co tham so
    }
    // Cuu
    for (int i = iSoLuongBo; i < (iSoLuongCuu + iSoLuongBo); i++) // nap tiep du lieu Cuu vao danh sach
    {
        vDanhSach[i] = new Cuu();
    }
    // De
    for (int i = (iSoLuongBo + iSoLuongCuu); i < iSoLuongGiaSuc; i++) // nap tiep du lieu De vao danh sach
    {
        vDanhSach[i] = new De;
    }

    // Doi bung -> Keu
    string sKiemTra;
    cout << "Chu nong trai co o nha khong? (Yes/No) : ";
    cin.ignore();
    getline(cin, sKiemTra);
    while (true)
    {
        if (sKiemTra != "")
        {
            // Tao ban sao cho bien KiemTra
            string sTemp;
            sTemp = sKiemTra;

            transform(sTemp.begin(), sTemp.end(), sTemp.begin(), ::tolower);
            if (sTemp == "no")
            {
                for (int i = 0; i < iSoLuongGiaSuc; i++)
                {

                    vDanhSach[i]->TiengKeu(); // Dung, vi da khai bao "vDanhSach[i] = new Bo();" o tren
                }
            }
            else
            {
                cout << "Khong co gi! Bye." << endl;
            }
            break;
        }
        else
        {
            cout << "Ban chua tra loi cau hoi! Vui long tra loi cau hoi!" << endl;
            cout << "Chu nong trai co o nha khong? (Yes/No) : ";
            getline(cin, sKiemTra);
        }
    }

    // TINH TONG MOI LOAI GIA SUC CHAN NUOI
    int TongGiaSuc = 0, TongBoCon = 0, TongCuuCon = 0, TongDeCon = 0;
    for (int i = 0; i < iSoLuongGiaSuc; i++)
    {
        // Tong bo con
        if (vDanhSach[i]->igetLoai() == LOAI_BO)
            TongBoCon += vDanhSach[i]->iSinhCon();

        // Tong cuu con
        if (vDanhSach[i]->igetLoai() == LOAI_CUU)
            TongCuuCon += vDanhSach[i]->iSinhCon();

        // Tong de con
        if (vDanhSach[i]->igetLoai() == LOAI_DE)
            TongDeCon += vDanhSach[i]->iSinhCon();
    }
    TongGiaSuc = (iSoLuongBo + TongBoCon) + (iSoLuongCuu + TongCuuCon) + (iSoLuongDe + TongDeCon);
    cout << "Chuc mung ban! Co tong cong " << TongGiaSuc << " gia suc trong nong trai!" << endl;

    // TINH TONG SUA MOI LOAI GIA SUC SAN XUAT
    int TongSua = 0;
    for (int i = 0; i < iSoLuongGiaSuc; i++)
    {
        TongSua += vDanhSach[i]->iChoSua();
    }
    cout << "Wow! Gia suc ban nuoi san xuat duoc tong " << TongSua << " (lit) sua lan do!" << endl;
}

DSGiaSuc::~DSGiaSuc()
{
    for (auto &Gs : vDanhSach)
    {
        delete Gs;
    }
    vDanhSach.clear();
}