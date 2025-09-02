#include "SanGiaoDich.h"
#include <fstream>
#include <algorithm>

SanGiaoDich::~SanGiaoDich()
{
    for (DoiTuong *obj : DSDoiTuong)
        delete obj;
    DSDoiTuong.clear();
}

void SanGiaoDich::Nhap()
{
    int n, m;
    std::cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int id, loai;
        std::cin >> id >> loai;
        DoiTuong *obj = nullptr;
        if (loai == 1)
        {
            obj = new NhaCai();
            nhaCai = dynamic_cast<NhaCai *>(obj);
        }
        else if (loai == 2)
            obj = new CoMoi();
        else if (loai == 3)
            obj = new Trader();
        obj->Nhap(id, loai);
        DSDoiTuong.push_back(obj);
    }

    bool ketThuc = false;
    for (int i = 1; i <= m && !ketThuc; i++)
    {
        XuLyLuot(i, ketThuc);
    }
    if (!ketThuc)
        XuatFile();
}

void SanGiaoDich::Xuat() const
{
    for (const DoiTuong *obj : DSDoiTuong)
        obj->Xuat();
}

Trader *SanGiaoDich::TimTrader(int id)
{
    for (DoiTuong *Dt : DSDoiTuong)
    {
        if (Dt->getID() == id && Dt->getType() == 3)
            return dynamic_cast<Trader *>(Dt);
    }
    return nullptr;
}

CoMoi *SanGiaoDich::TimCoMoi(int traderId)
{
    for (DoiTuong *Dt : DSDoiTuong)
    {
        if (Dt->getType() == 2)
        {
            CoMoi *Cm = dynamic_cast<CoMoi *>(Dt);
            if (Cm->getTraderID() == traderId)
                return Cm;
        }
    }
    return nullptr;
}

void SanGiaoDich::XuLyLuot(int luot, bool &ketThucSom)
{
    std::vector<Lenh> LenhHopLe;
    std::vector<Lenh> LenhKhongHopLe;
    Lenh lenh;

    do
    {
        lenh.Nhap();
        if (lenh.TraderID == -1)
            break;

        Trader *trader = TimTrader(lenh.TraderID);
        if (trader && trader->datCuoc(lenh.tienCuoc))
        {
            LenhHopLe.push_back(lenh);
            trader->capNhatSoDu(-lenh.tienCuoc);
            nhaCai->capNhatSoDu(lenh.tienCuoc); // Cộng tiền cược vào Nhà Cái
            nhaCai->capNhatSoDu(-(floor(lenh.tienCuoc * 0.01 * 100) / 100));
        }
        else
        {
            LenhKhongHopLe.push_back(lenh);
        }
    } while (lenh.TraderID != -1);

    if (LenhHopLe.empty() && LenhKhongHopLe.empty())
        return;

    static bool ketQuaTruocLaUp = false;

    double loiNhuanUp = 0, loiNhuanDown = 0;
    for (const Lenh &l : LenhHopLe) // Lệnh hợp lệ là khác nullprt và có đủ tiền cược
    {
        double tienLoi = (l.LoaiLenh == 0) ? l.tienCuoc : l.tienCuoc * 1.5;

        // Kiểm tra trường hợp Up, Down
        // Giả sử, up thắng
        bool thangUp = (l.LoaiLenh == 0 && l.lenh == 1) ||
                       (l.LoaiLenh == 1 && l.lenh == 1 && luot > 1 && !ketQuaTruocLaUp) ||
                       (l.LoaiLenh == 1 && l.lenh == 0 && luot > 1 && ketQuaTruocLaUp);

        // Giả sử, down thắng
        bool thangDown = (l.LoaiLenh == 0 && l.lenh == 0) ||
                         (l.LoaiLenh == 1 && l.lenh == -1 && luot > 1 && ketQuaTruocLaUp) ||
                         (l.LoaiLenh == 1 && l.lenh == 0 && luot > 1 && !ketQuaTruocLaUp);

        if (thangUp)

            // Úp thắng, nhà cái mất
            loiNhuanUp -= (l.tienCuoc + tienLoi - (floor(tienLoi * 0.01 * 100) / 100));
        else

            // còn không, bị thu, mất trắng
            loiNhuanUp += l.tienCuoc;

        if (thangDown)
            loiNhuanDown -= (l.tienCuoc + tienLoi - (floor(tienLoi * 0.01 * 100) / 100));
        else
            loiNhuanDown += l.tienCuoc;
    }

    bool ketQuaUp = loiNhuanUp > loiNhuanDown;

    int TongLoiNhuanUpDown = loiNhuanDown + loiNhuanUp;

    // chọn giữa 2 trường hợp để tối đa hóa lợi nhuận
    double loiNhuan = ketQuaUp ? loiNhuanUp : loiNhuanDown;

    // kiểm tra xem số dư nhà cái có âm không sẽ phá sản hay tiếp tục
    if ((nhaCai->getSoDu() + loiNhuan) < 0)
    {
        XuatFile();
        ketThucSom = true;
        return;
    }

    double tongPhi = 0;
    for (const Lenh &l : LenhHopLe)
    {
        Trader *trader = TimTrader(l.TraderID);
        CoMoi *coMoi = TimCoMoi(l.TraderID);
        double tienLoi = ((l.LoaiLenh == 0) ? l.tienCuoc : l.tienCuoc * 1.5);
        bool thang = ketQuaUp ? ((l.LoaiLenh == 0 && l.lenh == 1) ||
                                 (l.LoaiLenh == 1 && l.lenh == 1 && luot > 1 && !ketQuaTruocLaUp) ||
                                 (l.LoaiLenh == 1 && l.lenh == 0 && luot > 1 && ketQuaTruocLaUp))
                              : ((l.LoaiLenh == 0 && l.lenh == 0) ||
                                 (l.LoaiLenh == 1 && l.lenh == -1 && luot > 1 && ketQuaTruocLaUp) ||
                                 (l.LoaiLenh == 1 && l.lenh == 0 && luot > 1 && !ketQuaTruocLaUp));
        if (trader)
        {
            if (thang)
            {
                double phiSan = floor(tienLoi * 0.01 * 100) / 100;
                trader->capNhatSoDu(tienLoi + l.tienCuoc - phiSan);
                tongPhi += phiSan;
                nhaCai->capNhatSoDu(-(tienLoi + l.tienCuoc));
            }
            else
            {
            }
        }
        if (coMoi)
        {
            coMoi->themHoaHong(l.tienCuoc);
        }
    }

    nhaCai->capNhatSoDu(tongPhi);

    ketQuaTruocLaUp = ketQuaUp;
}

void SanGiaoDich::XuatFile()
{
    std::sort(DSDoiTuong.begin(), DSDoiTuong.end(), [](DoiTuong *a, DoiTuong *b)
              { return a->getID() < b->getID(); });
    std::ofstream out("RESULT.TXT");
    for (DoiTuong *tv : DSDoiTuong)
    {
        out << tv->getID() << " " << std::fixed << std::setprecision(1);
        if (tv->getType() == 1)
            out << dynamic_cast<NhaCai *>(tv)->getSoDu();
        else if (tv->getType() == 3)
            out << dynamic_cast<Trader *>(tv)->getSoDu();
        else if (tv->getType() == 2)
            out << dynamic_cast<CoMoi *>(tv)->getHoaHong();
        out << "\n";
    }
    out.close();
}