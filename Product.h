#pragma once
#include "header.h"
class mathang
{
    friend class hoadon;

private:
    wstring mahang;
    wstring tenhang;
    wstring nhacc;
    int manhacc;
    int soluong;
    int sldaban;
    long int gia;
    static int tongsohang;        // tong so hang
    static mathang *cachang[100]; // danh sach luu tru cac mat hang
    static const char *tephang;

public:
    mathang(wstring ma, wstring ten, int manhacc, wstring listnhacc[], int sl, int sldb, long int g)
    {
        this->mahang = ma;
        this->tenhang = ten;
        this->soluong = sl;
        this->sldaban = sldb;
        this->manhacc = manhacc;
        this->nhacc = listnhacc[this->manhacc];
        this->gia = g;
    }
    static void themhang();   // them mat hang
    static void timhang();    // tim mat hang theo ma
    static void lietkehang(); // liet ke mat hang
    static void nhaphang();   // nhap them lam tang so luong cua mat hang
    static void suahang();    // sua thong tin ve mat hang
    static void xoahang();    // xoa mot mat hang
    static void sapxephang(); // sap xep hang theo id
    void hienmothang();       // hien thi mot mat hang (la 1 phan cua liet ke mat hang)
    static void ghihang();    // ghi mat hang vao tep
    static void dochang();    // doc mat hang tu tep ra
};
wstring listnhacc[20] = {
    L"Nike",
    L"Adidas",
    L"Puma",
    L"Biti's",
    L"Converse",
    L"Vans",
    L"Ananas",
    L"Balenciaga",
    L"Louis Vuiton",
    L"New Balance",
    L"Asics",
    L"Reebok ",
};
const char *mathang::tephang = "hang.txt";
int mathang::tongsohang = 0;
mathang *mathang::cachang[100];
wchar_t *NhapChuoiNumber(const int k)
{
    wchar_t *kq = new wchar_t[k + 1];
    int n, index = 0;
    do
    {
    loop:;
        n = getch();
        if (((n >= '0' && n <= '9') || (n >= 'A' && n <= 'Z')) && index < k)
        {
            wcout << wchar_t(n);
            kq[index++] = n;
        }
        else if (n == '\b' && index > 0)
        {
            wcout << L"\b \b";
            kq[--index] = 0;
        }
        if (n == 13 && index == 0)
            goto loop;
    } while (n != 13);

    kq[index] = 0;
    wcout << endl;
    return kq;
}
void mathang::themhang()
{
    wstring ma;
    wstring ten;
    int manhacc;
    int sl;
    int sldb = 0;
    int somau;
    long g;
    wcout << L"Nhập mã mẫu giày: ";
    ma = NhapChuoiNumber(4);
    wcout << L"Nhập tên mẫu giày: ";
    fflush(stdin);
    getline(wcin, ten);
    wcout << L"Nhập mã nhà cung cấp: ";
    wcin >> manhacc;
    wcout << L"Nhập số lượng: ";
    wcin >> sl;
    wcout << L"Nhập giá: ";
    wcin >> g;
    int dem = 0;
    for (int i = 0; i < tongsohang; i++)
    {
        if (cachang[i]->mahang == ma)
            dem++;
    }
    if (dem != 0)
        wcout << L"\nTrùng mã giày, nhập lại mã khác!\n\n";
    else
    {
        cachang[tongsohang] = new mathang(ma, ten, manhacc, listnhacc, sl, sldb, g);
        tongsohang++;
        wcout << L"\nMẫu giày đã được thêm !\n\n";
    }
}
void mathang::sapxephang()
{
	for (int i = 0; i < tongsohang; i++)
	{
		for (int j = i + 1; j < tongsohang; j++)
		{
			if (cachang[i]->mahang > cachang[j]->mahang)
			{
				swap(cachang[j],cachang[i]);
			}
		}
	}
}
void mathang::suahang()
{
    wstring ma;
    wstring masua;
    int manhacc;
    wstring ten;
    int somau;
    int sl, j;
    long g;
    wcout << L"Nhập mã mẫu giày cần sửa: ";
    fflush(stdin);
    ma = NhapChuoiNumber(4);
    for (int j = 0; j < tongsohang; j++)
    {
        if (cachang[j]->mahang == ma)
        {
            wcout << L"Sửa mã giày: ";
            masua = NhapChuoiNumber(4);
            wcout << L"Sửa tên giày: ";
            fflush(stdin);
            getline(wcin, ten);
            wcout << L"Sửa mã nhà cung cấp: ";
            wcin >> manhacc;
            wcout << L"Sửa số lượng: ";
            wcin >> sl;
            wcout << L"Sửa giá: ";
            wcin >> g;
            for (int i = 0; i < tongsohang; i++)
            {
                if (cachang[i]->mahang == ma)
                {
                    cachang[i]->mahang = masua;
                    cachang[i]->tenhang = ten;
                    cachang[i]->nhacc = listnhacc[manhacc];
                    cachang[i]->soluong = sl;
                    cachang[i]->gia = g;
                    wcout << L"Bạn đã sửa xong !";
                    break;
                }
            }
        }
        if (j == tongsohang)
            wcout << L"Mã giày không tồn tại!";
    }
}

void mathang::xoahang()
{
    wstring ma;
    int x;
    int i;
    wcout << L"Nhập mã mẫu giày muốn xóa :";
    ma = NhapChuoiNumber(4);
    for (i = 0; i < tongsohang; i++)
    {
        if (cachang[i]->mahang == ma)
        {
            x = i;
            break;
        }
    }
    if (i == tongsohang)
        wcout << L"Mã mẫu giày không tồn tại!\n\n";
    else
    {
        for (i = x; i < tongsohang; i++)
            cachang[i] = cachang[i + 1];
        delete cachang[tongsohang - 1];
        wcout << L"Mã xóa mẫu giày có mã: " << ma << L"\n\n";
        tongsohang--;
    }
}

void mathang::nhaphang()
{
    int x;
    wstring ma;
    wcout << L"Nhập mã mẫu giày cần thêm số lượng: ";
    ma = NhapChuoiNumber(4);
    wcout << L"Nhập số lượng thêm vào mã giày " << ma << L" :";
    wcin >> x;
    for (int i = 0; i < tongsohang; i++)
    {
        if (cachang[i]->mahang == ma)
        {
            cachang[i]->soluong += x;
            wcout << L"Đã nhập thêm xong !\n\n";
            break;
        }
    }
}

void mathang::lietkehang()
{
    sapxephang();
    wcout.setf(ios::left);
    wcout.width(10);
    wcout << L"";
    wcout << L"DANH SÁCH CÁC MẪU GIÀY\n\n";
    wcout.width(20);
    wcout << L"Mã giày";
    wcout.width(20);
    wcout << L"Tên giày";
    wcout.width(20);
    wcout << L"Tên nhà cung cấp";
    wcout.width(20);
    wcout << L"Tồn kho";
    wcout.width(20);
    wcout << L"Đã bán";
    wcout << L"Giá";
    wcout << endl;
    for (int i = 0; i < tongsohang; i++)
    {
        cachang[i]->hienmothang();
        wcout << endl;
    }
}

void mathang::hienmothang()
{
    wcout.setf(ios::left);
    wcout.width(20);
    wcout << mahang;
    wcout.width(20);
    wcout << tenhang;
    wcout.width(20);
    wcout << nhacc;
    wcout.width(20);
    wcout << soluong;
    wcout.width(20);
    wcout << sldaban;
    wcout << gia << L"vnd";
}
void mathang::timhang()
{
    int i, dem = 0;
    wstring ma;
    wcout << L"\nNhập mã mẫu giày cần tìm: ";
    ma = NhapChuoiNumber(4);
    for (i = 0; i < tongsohang; i++)
    {
        if (cachang[i]->mahang == ma)
            dem++;
    }
    if (dem == 0)
        wcout << L"Không có mẫu giày này !\n\n";
    for (i = 0; i < tongsohang; i++)
    {
        if (ma == cachang[i]->mahang)
        {
            wcout.setf(ios::left);
            wcout.width(10);
            wcout << L"";
            wcout << L"DANH SÁCH CÁC MẪU GIÀY\n\n";
            wcout.width(20);
            wcout << L"Mã giày";
            wcout.width(20);
            wcout << L"Tên giày";
            wcout.width(20);
            wcout << L"Tên nhà cung cấp";
            wcout.width(20);
            wcout << L"Tồn kho";
            wcout.width(20);
            wcout << L"Đã bán";
            wcout << L"Giá";
            cachang[i]->hienmothang();
            wcout << endl;
        }
    }
}
int chuyenchuoithanhso(wstring s)
{
    return _wtoi(s.c_str());
}
void mathang::dochang()
{
    wifstream is(tephang, ios::in);
    while (is.eof() == 0)
    {
        int sl, sldb;
        int macc;
        long g;
        wstring ma;
        wstring ten;
        wstring temp;
        getline(is, ma);
        getline(is, ten);
        getline(is, temp);
        macc = chuyenchuoithanhso(temp);
        getline(is, temp);
        sl = chuyenchuoithanhso(temp);
        getline(is, temp);
        sldb = chuyenchuoithanhso(temp);
        getline(is, temp);
        g = chuyenchuoithanhso(temp);
        if (is.eof() == 1)
        {
            is.ignore();
            break;
        }
        cachang[tongsohang++] = new mathang(ma, ten, macc, listnhacc, sl, sldb, g);
    }
    is.close();
}

void mathang::ghihang()
{
    wofstream os(tephang, ios::out);
    for (int i = 0; i < tongsohang; i++)
    {
        os << cachang[i]->mahang << endl;
        os << cachang[i]->tenhang << endl;
        os << cachang[i]->manhacc << endl;
        os << cachang[i]->soluong << endl;
        os << cachang[i]->sldaban << endl;
        os << cachang[i]->gia << endl;
    }
    os.close();
}
