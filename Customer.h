#pragma once
#include "header.h"
class khachhang
{
	friend class hoadon;

private:
	wstring makhach;
	wstring tenkhach;
	wstring dtkhach;
	static int tongsokhach;			 // tong so khach
	static khachhang *cackhach[100]; // danh sach luu tru cac khach
	static const char *tepkhach;

public:
	khachhang(wstring ma, wstring ten, wstring dt)
	{
		this->makhach = ma;
		this->tenkhach = ten;
		this->dtkhach = dt;
	}
	static void themkhach();   // phuong thuc them khach hang
	static void lietkekhach(); // phuong thuc liet ke khach hang
	static void timkhach();	   // tim mot khach hang theo ma
	static void sapxepkhach(); // sap xep khach hang theo id 
	static void suakhach();	   // sua thong tin khach
	static void xoakhach();	   // xoa mot khach hang
	void hienmotkhach();	   // hien thi mot khach (la 1 phan cua liet ke khach hang)
	static void ghikhach();	   // ghi khach hang vao tep
	static void dockhach();	   // doc khach hang tu teo ra
};

const char *khachhang::tepkhach = "khach.txt";
int khachhang::tongsokhach = 0;
khachhang *khachhang::cackhach[100];

void khachhang::themkhach()
{
	wstring ma;
	wstring ten;
	wstring dt;
	wcout << L"Nhập vào mã khách hàng :";
	ma = NhapChuoiNumber(4);

	wcout << L"Nhập vào tên khách hàng: ";
	fflush(stdin);
	getline(wcin, ten);
	wcout << L"Nhập SĐT khách hàng: ";
	dt = NhapChuoiNumber(10);

	int dem = 0;
	for (int i = 0; i < tongsokhach; i++)
	{
		if (cackhach[i]->makhach == ma)
			dem++;
	}
	if (dem != 0)
		wcout << L"\nMã khách đã tồn tại, mời nhập mã khác!\n\n";

	else
	{
		cackhach[tongsokhach] = new khachhang(ma, ten, dt);
		tongsokhach++;
		wcout << L"\nĐã thêm khách hàng này vào !\n\n";
	}
}
void khachhang::sapxepkhach()
{
	for (int i = 0; i < tongsokhach; i++)
	{
		for (int j = i + 1; j < tongsokhach; j++)
		{
			if (cackhach[i]->makhach > cackhach[j]->makhach)
			{
				swap(cackhach[j],cackhach[i]);
			}
		}
	}
}
void khachhang::suakhach()
{
	wstring ma;
	wstring masua;
	wstring ten;
	wstring dt;
	wcout << L"Nhập mã khách hàng cần sửa: ";
	ma = NhapChuoiNumber(4);

	for (int j = 0; j < tongsokhach; j++)
	{
		if (cackhach[j]->makhach == ma)
		{
			wcout << L"Mã mới: ";
			masua = NhapChuoiNumber(4);

			wcout << L"Tên mới: ";
			fflush(stdin);
			getline(wcin, ten);
			wcout << L"SĐT mới: ";
			dt = NhapChuoiNumber(10);

			for (int i = 0; i < tongsokhach; i++)
				if (cackhach[i]->makhach == ma)
				{
					cackhach[i]->makhach = masua;
					cackhach[i]->tenkhach = ten;
					cackhach[i]->dtkhach = dt;
					break;
				}
			wcout << L"Đã sửa xong !";
			break;
		}
		if (j == tongsokhach)
		{
			wcout << L"Không tìm thấy khách hàng này!";
		}
	}
}

void khachhang::xoakhach()
{
	wstring ma;
	int x;
	int i;
	wcout << L"Nhập mã khách hàng cần xóa :";
	ma = NhapChuoiNumber(4);

	for (i = 0; i < tongsokhach; i++)
		if (cackhach[i]->makhach == ma)
			{
			x = i;
			break;
			}
		if (i == tongsokhach)
			wcout << L"Không tìm thấy khách hàng!\n\n";
		else
		{
			for (i = x; i < tongsokhach; i++)
			{
				cackhach[i] = cackhach[i + 1];
			}
			delete cackhach[tongsokhach - 1];
			wcout << L"Đã xóa khách hàng có mã " << ma << L"\n\n";
			tongsokhach--;
	}
}

void khachhang::lietkekhach()
{
	sapxepkhach();
	wcout.setf(ios::left);
	wcout.width(10);
	wcout << L"";
	wcout << L"DANH SÁCH CÁC KHÁCH HÀNG\n\n";
	wcout.width(15);
	wcout << L"Mã khách";
	wcout.width(25);
	wcout << L"Tên khách";
	wcout << L"SĐT    \n";
	for (int i = 0; i < tongsokhach; i++)
	{
		cackhach[i]->hienmotkhach();
		wcout << endl;
	}
}

void khachhang::hienmotkhach()
{
	wcout.setf(ios::left);
	wcout.width(15);
	wcout << makhach;
	wcout.width(25);
	wcout << tenkhach;
	wcout << dtkhach;
}

void khachhang::timkhach()
{
	int i, dem = 0;
	wstring ma;
	wcout << L"\nNhap vao ma khach hang can tim: ";
	ma = NhapChuoiNumber(4);

	for (i = 0; i < tongsokhach; i++)
	{
		if (ma == cackhach[i]->makhach)
			dem++;
	}
	if (dem == 0)
		wcout << L"Khong co khach hang co ma so nay!\n\n";
	for (i = 0; i < tongsokhach; i++)
	{
		if (ma == cackhach[i]->makhach)
		{
			wcout.setf(ios::left);
			wcout.width(15);
			wcout << L"Mã khách";
			wcout.width(25);
			wcout << L"Tên khách";
			wcout << L"SĐT    \n";
			cackhach[i]->hienmotkhach();
			wcout << endl;
		}
	}
}

locale loc(locale(), new codecvt_utf8<wchar_t>); // UTF-8

void khachhang::dockhach()
{

	wifstream is(tepkhach, ios::in);
	is.imbue(loc);
	while (is.eof() == 0)
	{
		wstring ma;
		wstring ten;
		wstring dt;
		getline(is, ma);
		getline(is, ten);
		getline(is, dt);
		if(is.eof() == 1)
		{
			is.ignore();
			break;
		}
		cackhach[tongsokhach++] = new khachhang(ma, ten, dt);
	}
	is.close();
}

void khachhang::ghikhach()
{
	wofstream os(tepkhach, ios::out);
	os.imbue(loc);
	for (int i = 0; i < tongsokhach; i++)
	{
		os << cackhach[i]->makhach << endl;
		os << cackhach[i]->tenkhach << endl;
		os << cackhach[i]->dtkhach << endl;
	}
	os.close();
}
