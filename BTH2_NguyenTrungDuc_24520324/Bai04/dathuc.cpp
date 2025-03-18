
#include "daThuc.h"
#include <cmath>

DaThuc::DaThuc() : bac(0), heSo(1, 0) {} // khai báo constructor Đa thức KHÔNG bậc với Bậc = 0 và Hệ số có 1 cái với giá trị không

DaThuc::DaThuc(int n) : bac(n), heSo(n + 1, 0) {} // khai báo constructor Đa thức n bậc

void DaThuc::nhap()
{

    // std::cout << "Nhập bậc của đa thức: ";
    std::cin >> bac;
    heSo.resize(bac + 1); // đảm bảo vector có đúng "Bậc + 1" phần tử, nếu nhiều hơn thì cắt bớt và ít hơn thì mặc định Hệ số = 0

    for (int i = bac; i >= 0; --i) // khai báo Hệ số bằng số bậc, vì có thêm hệ số tự do = 0(do giả thuyết Hệ số = Bậc)
    {
        heSo[i] = i;
    }
}

void DaThuc::nhapN(DaThuc dt1[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "Nhap bac cho da thuc " << i + 1 << " : ";
        dt1[i].nhap(); // ✅ Sửa thành dt1[i].nhap()
        // std::cout << std::endl;
    }
}

void DaThuc::xuat() const // "const" đảm bảo hàm xuất không làm thay đổi giá trị nào
{
    for (int i = bac; i >= 0; --i)
    {
        std::cout << heSo[i] << "x^" << i;
        if (i > 0)
            std::cout << " + ";
    }
    std::cout << std::endl;
}

void DaThuc::xuatN(DaThuc dt1[], int n) const
{
    std::cout << "\n========Danh sach da thuc==========\n";

    for (int i = 0; i < n; i++)
    {
        std::cout << "Da thuc " << i + 1 << " : ";
        dt1[i].xuat();
    }
}

double DaThuc::tinhGiaTri(double x) const // "const" đảm bảo hàm xuất không làm thay đổi giá trị nào
{
    double result = 0;
    for (int i = 0; i <= bac; ++i)
    {
        result += heSo[i] * std::pow(x, i);
    }
    return result;
}

// khai báo hàm có kiểu dữ liệu DaThuc và thuộc lớp DaThuc, "operator+" toán tử + được nạp chồng giúp không cần [Tên hàm](...) mà ...=...+..., "other" đầu giúp other không bị thay đỏi
DaThuc DaThuc::operator+(const DaThuc &other) const
{
    int maxBac = std::max(bac, other.bac); // Lấy bậc lớn nhất của hai đa thức để xác định bậc của đa thức kết quả
    DaThuc sum(maxBac);                    // Tạo một đối tượng Sum mới có bậc maxBac và hệ số = maxBac + 1
    for (int i = 0; i <= maxBac; ++i)
    {
        double h1 = (i <= bac) ? heSo[i] : 0; // nếu i <= bậc thì lấy hệ số[i] còn lại = 0 do không có bậc đó
        double h2 = (i <= other.bac) ? other.heSo[i] : 0;
        sum.heSo[i] = h1 + h2;
    }
    return sum;
}

DaThuc DaThuc::operator-(const DaThuc &other) const
{
    int maxBac = std::max(bac, other.bac);
    DaThuc diff(maxBac);
    for (int i = 0; i <= maxBac; ++i)
    {
        double h1 = (i <= bac) ? heSo[i] : 0;
        double h2 = (i <= other.bac) ? other.heSo[i] : 0;
        diff.heSo[i] = h1 - h2;
    }
    return diff;
}

DaThuc tinhTong(const DaThuc dt1[], int n)
{
    if (n == 0)
        return DaThuc(); // Trả về đa thức rỗng nếu không có đa thức nào

    DaThuc sum = dt1[0]; // Bắt đầu từ đa thức đầu tiên
    for (int i = 1; i < n; i++)
    {
        sum = sum + dt1[i]; // Cộng từng đa thức vào sum
    }
    return sum;
}

DaThuc tinhHieu(const DaThuc dt1[], int n)
{
    if (n == 0)
        return DaThuc(); // Trả về đa thức rỗng nếu không có đa thức nào

    DaThuc diff = dt1[0]; // Bắt đầu từ đa thức đầu tiên
    for (int i = 1; i < n; i++)
    {
        diff = diff - dt1[i]; // Trừ từng đa thức vào diff
    }
    return diff;
}