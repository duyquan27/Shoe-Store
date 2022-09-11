#pragma once
#include "header.h"
#include "Product.h"
#include "Customer.h"

class hoadon
{
    friend class mathang;
    friend class khachhang;

private:
    wstring mahoadon;
    wstring mamathang;
    wstring makhachhang;
    int soluong;
    long thanhtien;
    static int sohoadon;           // tong so hoa don
    static hoadon *cachoadon[100]; // danh sach cac hoa don
    static const char *tephoadon;

public:
    hoadon(wstring ma0, wstring ma1, wstring ma2, int sl, long tien)
    {
        this->mahoadon = ma0;
        this->mamathang = ma1;
        this->makhachhang = ma2;
        this->soluong = sl;
        this->thanhtien = tien;
    }
    static void laphoadon();         // tao 1 hoa don moi
    void hienhoadon();               // hien 1 hoa don (la 1 phan cua danh sach hoa don)
    static void danhsachcachoadon(); // hien tat ca hoa don
    static void suahoadon();         // sua hoa don
    static void xoahoadon();         // xoa hoa don
    static void timhoadon();         // tim hoa don
    static void sapxephoadon();      // sap xep hoa don theo id
    static void timhoadonbangmakh(); // tim hoa don bang ma khach hang
    static void dochoadon();         // doc hoa don tu tep
    static void ghihoadon();         // ghi hoa don vao tep
};

const char *hoadon::tephoadon = "hoadon.txt";
hoadon *hoadon::cachoadon[100];
int hoadon::sohoadon = 0;

void hoadon::laphoadon()
{
    wstring mahoadon;
    wstring mamathang;
    wstring makhachhang;
    int soluong;
    long thanhtien = 0;
    int i, dem1 = 0, dem2 = 0, dem3 = 0, count = 1;
    wcout << L"\nNhập vào mã hóa đơn: ";
    mahoadon = NhapChuoiNumber(4);
    for (i = 0; i < sohoadon; i++)
    {
        if (mahoadon == hoadon::cachoadon[i]->mahoadon)
        {
            dem3++;
            break;
        }
    }
    if (dem3 != 0)
    {
        wcout << L"Mã hóa đơn đã tồn tại, mời nhập mã khác";
    }
    else
    {
        wcout << L"Nhập mã mặt hàng cần bán: ";
        mamathang = NhapChuoiNumber(4);

        /*dung bien j de khong bi trung bien i, giup xac dinh
    vi tri mat hang thu j de san sang thay doi so luong,
    duoc lam ngay ben duoi */
        for (int j = 0; j < mathang::tongsohang; j++)
        {
            if (mamathang == mathang::cachang[j]->mahang)
            {
                dem1++;
                break;
            }
        }
        if (dem1 == 0)
        {
            wcout << L"\nKhông có hàng!";
            count = 0;
        }
        else
        {
            wcout << L"Nhập mã khách cần mua: ";
            makhachhang = NhapChuoiNumber(4);

            for (i = 0; i < khachhang::tongsokhach; i++)
            {
                if (makhachhang == khachhang::cackhach[i]->makhach)
                {
                    dem2++;
                    break;
                }
            }
            if (dem2 == 0)
            {
                wcout << L"\nKhông tìm thấy khách, mời tạo khách mới!";
                count = 0;
            }
            else
            {
                if ((dem1 != 0) && (dem2 != 0))
                {
                    wcout << L"Nhập số lượng cần bán: ";
                    wcin >> soluong;
                    /*lay gia tri j de xac dinh mat hang thu may*/
                    for (int j = 0; j < mathang::tongsohang; j++)
                    {
                        if ((mathang::cachang[j]->soluong) >= soluong && mathang::cachang[j]->mahang == mamathang)
                        {
                            mathang::cachang[j]->sldaban += soluong;
                            mathang::cachang[j]->soluong -= soluong;
                            thanhtien = (mathang::cachang[j]->gia) * soluong;
                        }
                        else if ((mathang::cachang[j]->soluong) <= 0)
                        {
                            wcout << L"Hết hàng, vui lòng chọn mẫu khác !";
                            count = 0;
                        }
                    }
                }
                if (count == 1)
                {
                    cachoadon[sohoadon] = new hoadon(mahoadon, mamathang, makhachhang, soluong, thanhtien);

                    sohoadon++;
                    wcout << L"\nMã Giày: " << mamathang;
                    wcout << L"\nMã Khách: " << makhachhang;
                    wcout << L"\nSố lượng: " << soluong;
                    wcout << L"\nTổng thu: " << thanhtien;
                    wcout << L"\nLưu hóa đơn có mã " << mahoadon << L" thành công!";
                }
            }
        }
    }
}
void hoadon::sapxephoadon()
{
	for (int i = 0; i < sohoadon; i++)
	{
		for (int j = i + 1; j < sohoadon; j++)
		{
			if (cachoadon[i]->mahoadon > cachoadon[j]->mahoadon)
			{
				swap(cachoadon[j],cachoadon[i]);
			}
		}
	}
}
void hoadon::suahoadon()
{
    wstring mahoadon;
    wstring mahoadonsua;
    wstring makhachhang;
    wstring mamathang;
    int soluong, x;
    long thanhtien;
    wcout << L"Nhập mã hóa đơn cần sửa: ";
    mahoadon = NhapChuoiNumber(4);

    for (int j = 0; j < sohoadon; j++)
    {
        if (cachoadon[j]->mahoadon == mahoadon)
        {
            for (int i = 0; i < sohoadon; i++)
            {
                if (cachoadon[i]->mahoadon == mahoadon)
                {
                    x = cachoadon[i]->soluong;
                    break;
                }
            }
            wcout << L"Sửa mã hóa đơn: ";
            mahoadonsua = NhapChuoiNumber(4);

            wcout << L"Sửa mã giày: ";
            mamathang = NhapChuoiNumber(4);

            wcout << L"Sửa mã khách: ";
            makhachhang = NhapChuoiNumber(4);

            wcout << L"Sửa số lượng hàng mua:";
            wcin >> soluong;
            for (int k = 0; k < mathang::tongsohang; k++)
            {
                if (cachoadon[k]->mamathang == mathang::cachang[k]->mahang)
                {
                    mathang::cachang[k]->soluong += x;
                }
            }
            for (int j = 0; j < sohoadon; j++)
            {
                if ((mathang::cachang[j]->soluong) >= soluong)
                {
                    mathang::cachang[j]->soluong -= soluong;
                    thanhtien = (mathang::cachang[j]->gia) * soluong;
                }
            }
            for (int i = 0; i < sohoadon; i++)
            {
                if (cachoadon[i]->mahoadon == mahoadon)
                {
                    cachoadon[i]->mahoadon = mahoadonsua;
                    cachoadon[i]->makhachhang = makhachhang;
                    cachoadon[i]->mamathang = mamathang;
                    cachoadon[i]->soluong = soluong;
                    cachoadon[i]->thanhtien = thanhtien;
                    break;
                }
            }
            wcout << L"Sửa thành công !";
            break;
        }
        if (j == sohoadon)
        {
            wcout << L"Không thấy mã hóa đơn này!";
        }
    }
}

void hoadon::hienhoadon()
{
    wcout.setf(ios::left);
    wcout.width(15);
    wcout << mahoadon;
    wcout.width(15);
    wcout << mamathang;
    wcout.width(15);
    wcout << makhachhang;
    wcout.width(15);
    wcout << soluong;
    wcout.width(20);
    wcout << thanhtien;
}

void hoadon::danhsachcachoadon()
{
    sapxephoadon();
    wcout.setf(ios::left);
    wcout.width(10);
    wcout << L"";
    wcout << L"DANH SÁCH CÁC HÓA ĐƠN\n\n";
    wcout.width(15);
    wcout << L"Mã hóa đơn";
    wcout.width(15);
    wcout << L"Mã mẫu giày";
    wcout.width(15);
    wcout << L"Mã khách";
    wcout.width(15);
    wcout << L"Số lượng";
    wcout << L"Thành tiền\n";
    for (int i = 0; i < sohoadon; i++)
    {
        cachoadon[i]->hienhoadon();
        wcout << endl;
    }
}

void hoadon::xoahoadon()
{
    wstring mahoadon;
    int x;
    int i;
    wcout << L"Nhập vào mã hóa đơn cần xóa:";
    mahoadon = NhapChuoiNumber(4);

    for (i = 0; i < sohoadon; i++)
    {
        if (cachoadon[i]->mahoadon == mahoadon)
        {
            x = i;
            break;
        }
    }
    if (i == sohoadon)
        wcout << L"Không thấy mã hóa đơn !\n\n";
    else
    {
        for (i = x; i < sohoadon; i++)
            cachoadon[i] = cachoadon[i + 1];
        delete cachoadon[sohoadon - 1];
        wcout << L"Đã xóa hóa đơn có mã: " << mahoadon << L"\n\n";
        sohoadon--;
    }
}

void hoadon::timhoadon()
{
    int i, dem = 0;
    wstring mahoadon;
    wcout << L"\nNhập mã mẫu hóa đơn cần tìm: ";
    mahoadon = NhapChuoiNumber(4);

    for (i = 0; i < sohoadon; i++)
    {
        if (mahoadon == cachoadon[i]->mahoadon)
            dem++;
    }
    if (dem == 0)
        wcout << L"Không tìm thấy mã hóa đơn!\n\n";
    for (i = 0; i < sohoadon; i++)
    {
        if (mahoadon == cachoadon[i]->mahoadon)
        {

            wcout.width(15);
            wcout << L"Mã hóa đơn";
            wcout.width(15);
            wcout << L"Mã mẫu giày";
            wcout.width(15);
            wcout << L"Mã khách";
            wcout.width(15);
            wcout << L"Số lượng";
            wcout << L"Thành tiền\n";
            cachoadon[i]->hienhoadon();
            wcout << endl;
        }
    }
}
void hoadon::timhoadonbangmakh()
{
    int i, dem = 0;
    long tongthu = 0;
    wstring makh;
    wcout << L"\nNhập mã khách hàng cần tìm hóa đơn: ";
    makh = NhapChuoiNumber(4);

    for (i = 0; i < sohoadon; i++)
    {
        if (makh == cachoadon[i]->makhachhang)
        {
            tongthu += (cachoadon[i]->thanhtien);
            dem++;
        }
    }
    if (dem == 0)
    {
        wcout << L"Không tìm thấy mã hóa đơn nào của khách này!\n\n";
    }
    else if (dem != 0)
    {
        wcout.setf(ios::left);
        wcout.width(15);
        wcout << L"Mã hóa đơn";
        wcout.width(15);
        wcout << L"Mã mẫu giày";
        wcout.width(15);
        wcout << L"Mã khách";
        wcout.width(15);
        wcout << L"Số lượng";
        wcout << L"Thành tiền\n";
        for (i = 0; i < sohoadon; i++)
        {
            if (makh == cachoadon[i]->makhachhang)
            {
                cachoadon[i]->hienhoadon();
                wcout << endl;
            }
        }
        wcout << L"Tổng tiền khách đã chi ra là: " << tongthu << endl;
    }
}
void hoadon::dochoadon()
{
    wifstream is(tephoadon, ios::in);
    while (is.eof() == 0)
    {
        wchar_t mahoadon[10];
        is.getline(mahoadon, sizeof(mahoadon));
        wchar_t mamathang[15];
        is.getline(mamathang, sizeof(mamathang));
        wchar_t makhachhang[15];
        is.getline(makhachhang, sizeof(makhachhang));
        int soluong;
        long thanhtien;
        is >> soluong >> thanhtien;
        is.ignore();
        if (is.eof() == 1)
        {
            is.ignore();
            break;
        }
        cachoadon[sohoadon++] = new hoadon(mahoadon, mamathang, makhachhang, soluong, thanhtien);
    }
}

void hoadon::ghihoadon()
{
    wofstream os(tephoadon, ios::out);
    for (int i = 0; i < sohoadon; i++)
    {
        os << cachoadon[i]->mahoadon << endl;
        os << cachoadon[i]->mamathang << endl;
        os << cachoadon[i]->makhachhang << endl;
        os << cachoadon[i]->soluong << setw(15) << cachoadon[i]->thanhtien << endl;
    }
}
