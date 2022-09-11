#include "header.h"
#include "Product.h"
#include "Customer.h"
#include "Bill.h"
//***************DOC GHI DU LIEU***************

//*** doc du lieu ***
void docdl()
{
  mathang::dochang();
  khachhang::dockhach();
  hoadon::dochoadon();
}

//*** ghi du lieu ***
void ghidl()
{
  mathang::ghihang();
  khachhang::ghikhach();
  hoadon::ghihoadon();
}


int menu()
{
  system("cls");

  wcout << L"******************CHƯƠNG TRÌNH QUẢN LÝ CỬA HÀNG BÁN GIÀY****************\n";
  wcout << L"========================================================================\n";
  wcout << L"**                1.DANH SÁCH CÁC MẪU GIÀY                            **\n";
  wcout << L"**                2.NHẬP THÊM MẪU GIÀY MỚI                            **\n";
  wcout << L"**                3.TÌM MẪU GIÀY THEO MÃ                              **\n";
  wcout << L"**                4.THÊM SỐ LƯỢNG CHO MẪU GIÀY                        **\n";
  wcout << L"**                5.ĐIỀU CHỈNH THÔNG TIN MẪU GIÀY                     **\n";
  wcout << L"**                6.XÓA MỘT MẪU GIÀY TRONG KHO                        **\n";
  wcout << L"========================================================================\n";
  wcout << L"**                7.DANH SÁCH KHÁCH MUA GIÀY                          **\n";
  wcout << L"**                8.NHẬP THÊM KHÁCH HÀNG MỚI                          **\n";
  wcout << L"**                9.TÌM KHÁCH HÀNG THEO MÃ                            **\n";
  wcout << L"**                10.ĐIỀU CHỈNH THÔNG TIN KHÁCH HÀNG                  **\n";
  wcout << L"**                11.XÓA MỘT KHÁCH HÀNG                               **\n";
  wcout << L"========================================================================\n";
  wcout << L"**                12.DANH SÁCH HÓA ĐƠN                                **\n";
  wcout << L"**                13.TẠO HÓA ĐƠN MUA HÀNG MỚI                         **\n";
  wcout << L"**                14.SỬA HÓA ĐƠN MUA HÀNG                             **\n";
  wcout << L"**                15.TÌM HÓA ĐƠN MUA HÀNG                             **\n";
  wcout << L"**                16.TÌM HÓA ĐƠN BẰNG MÃ KHÁCH HÀNG                   **\n";
  wcout << L"**                17.XÓA HÓA ĐƠN                                      **\n";
  wcout << L"**                0.THOÁT                                             **\n";
  wcout << L"************************************************************************\n";
  wcout << L"**     DESIGN BY: ĐÀO DUY QUÂN - NGUYỄN MINH THÔNG - ĐỖ THẾ HIỆP      **\n";
  wcout << L"**                  19119123         19119137         19119086        **\n";
  wcout << L"************************************************************************\n";
  wcout << L"                  MỜI BẠN CHỌN CHỨC NĂNG: ";

  int chon;
  wcin >> chon;
  return chon;
}
//*** main ***
int main()
{
    _setmode(_fileno(stdin), 0x00010000);
    _setmode(_fileno(stdout), 0x00010000);
  docdl();

  int chon;
  while (1)
  {
    chon = menu();
    switch (chon)
    {
    case 1:
      system("cls");
      mathang::lietkehang();
      break;
    case 2:
      system("cls");
      mathang::themhang();
      break;
    case 3:
      system("cls");
      mathang::timhang();
      break;
    case 4:
      system("cls");
      mathang::nhaphang();
      break;
    case 5:
      system("cls");
      mathang::suahang();
      break;
    case 6:
      system("cls");
      mathang::xoahang();
      break;
    case 7:
      system("cls");
      khachhang::lietkekhach();
      break;
    case 8:
      system("cls");
      khachhang::themkhach();
      break;
    case 9:
      system("cls");
      khachhang::timkhach();
      break;
    case 10:
      system("cls");
      khachhang::suakhach();
      break;
    case 11:
      system("cls");
      khachhang::xoakhach();
      break;
    case 12:
      system("cls");
      hoadon::danhsachcachoadon();
      break;
    case 13:
      system("cls");
      hoadon::laphoadon();
      break;
    case 14:
      system("cls");
      hoadon::suahoadon();
      break;
    case 15:
      system("cls");
      hoadon::timhoadon();
      break;
    case 17:
      system("cls");
      hoadon::xoahoadon();
      break;
    case 16:
      system("cls");
      hoadon::timhoadonbangmakh();
      break;
    }
    if (chon == 0)
      break;
    getch();
  }
  ghidl();
}
