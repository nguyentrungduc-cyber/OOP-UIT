#include "hocsinh.h"
#include <fstream>
#include <sstream>

HocSinh::HocSinh() : HoTen("NULL"), MaSo("NULL"), Tuoi(0), DTB(0.0) {}

HocSinh::HocSinh(std::string hoten, std::string maso, int tuoi, float dtb)
    : HoTen(hoten), MaSo(maso), Tuoi(tuoi), DTB(dtb) {}

void HocSinh::Nhap()
{
    std::cin.ignore(); 
    std::cout << "Ten: ";
    std::getline(std::cin, HoTen);

    std::cout << "MSSV: ";
    std::getline(std::cin, MaSo);

    std::cout << "Tuoi: ";
    std::cin >> Tuoi;
    std::cin.ignore(); 

    std::cout << "DTB: ";
    std::cin >> DTB;
    std::cin.ignore(); 
}

void HocSinh::Xuat()
{
    std::cout << "Ten: " << HoTen << "\n";
    std::cout << "MSSV: " << MaSo << "\n";
    std::cout << "Tuoi: " << Tuoi << "\n";
    std::cout << "DTB: " << DTB << "\n";
}


std::vector<HocSinh*> HocSinh::NhapTuFile(const std::string& filename)
{
    std::vector<HocSinh*> danhSachHocSinh;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Khong the mo file " << filename << std::endl;
        return danhSachHocSinh;
    }

    int n;
    file >> n;  
    file.ignore(); 

    for (int i = 0; i < n; i++)
    {
        std::string hoten, maso;
        int tuoi;
        float dtb;

        std::getline(file, hoten);  
        std::getline(file, maso);   
        file >> tuoi;               
        file >> dtb;                
        file.ignore();              

        HocSinh* hs = new HocSinh(hoten, maso, tuoi, dtb);
        danhSachHocSinh.push_back(hs);
    }

    file.close();
    return danhSachHocSinh;
}

LopHoc::LopHoc() {}

LopHoc::~LopHoc()
{
    for (HocSinh* hs : DanhSach)
    {
        delete hs;
    }
}

void LopHoc::NhapN()
{
    std::vector<HocSinh*> danhSachHocSinh = HocSinh::NhapTuFile("LopHoc.txt");

    for (HocSinh* hs : danhSachHocSinh)
    {
        DanhSach.push_back(hs);
    }
}

void LopHoc::XuatN()
{
    if (DanhSach.empty())
    {
        std::cout << "Danh sach hoc sinh dang trong!\n";
        return;
    }

    for (HocSinh* hs : DanhSach)
    {
        hs->Xuat();
    }
}

void LopHoc::ThemHocSinh()
{
    HocSinh* hs = new HocSinh();
    hs->Nhap();

    
    for (const auto& h : DanhSach)
    {
        if (h->MaSo == hs->MaSo)
        {
            std::cout << "Hoc sinh voi MSSV " << hs->MaSo << " da ton tai!\n";
            delete hs;
            return;
        }
    }

    for (const auto& h : DanhSach)
    {
        if (h->HoTen == hs->HoTen)
        {
            std::cout << "Hoc sinh voi ten " << hs->HoTen << " da ton tai!\n";
            delete hs;
            return;
        }
    }

    DanhSach.push_back(hs);
    std::cout << "Them hoc sinh thanh cong!\n";
}

void LopHoc::XoaHocSinh(const std::string& maso)
{
    if (DanhSach.empty())
    {
        std::cout << "Danh sach dang trong, khong the xoa!\n";
        return;
    }

    for (auto it = DanhSach.begin(); it != DanhSach.end(); ++it)
    {
        if ((*it)->MaSo == maso)
        {
            delete *it;
            DanhSach.erase(it);
            std::cout << "Hoc sinh voi MSSV " << maso << " da bi xoa!\n";
            return;
        }
    }
    std::cout << "Khong tim thay hoc sinh voi MSSV: " << maso << "\n";
}
