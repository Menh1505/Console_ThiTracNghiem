#include <iostream>
#include <vector>
#include "CauhoiTN.h"

using namespace std;

int main()
{
    vector<CauhoiTN> danhSachCauHoi;
    int chon;
    // Tạo menu
    do
    {
        cout << "1. Nhap cau hoi" << endl;
        cout << "2. Doc cau hoi tu file" << endl;
        cout << "3. Ghi cau hoi vao file" << endl;
        cout << "4. Thi" << endl;
        cout << "5. Xuat cau hoi" << endl;
        cout << "6. Kiem tra hai cau hoi co trung nhau hay khong" << endl;
        cout << "7. Thoat" << endl;
        cout << "Chon chuc nang: ";
        cin >> chon;
        switch (chon)
        {
        case 1:
            {
                CauhoiTN cauhoi;
                cauhoi.nhap();
                danhSachCauHoi.push_back(cauhoi);
                break;
            }
        case 2:
            // Doc cau hoi tu file
            {
                ifstream doc("cauhoi.txt");
                if (doc.is_open())
                {

                    CauhoiTN cauhoi;
                    cauhoi.docfile(doc);

                    danhSachCauHoi.push_back(cauhoi);
                    doc.close();
                }
                else
                {
                    cout << "Khong mo duoc file cauhoi.txt\n";
                }
                break;
            }
        case 3:
            // Ghi cau hoi vao file
            {
                ofstream ghi("cauhoi.txt", ios_base::app);
                if (ghi.is_open())
                {
                    for (auto cauhoi : danhSachCauHoi)
                    {
                        cauhoi.ghifile(ghi);
                    }
                    ghi.close();
                }
                else
                {
                    cout << "Khong mo duoc file cauhoi.txt\n";
                }
            }
            break;
        case 4:
            {
                int soThuTu = 1;
                int socaudung = 0;
                for (auto cauhoi : danhSachCauHoi)
                {
                    cout << "\nCau hoi thu " << soThuTu++;
                    cauhoi.kiemtra();
                    if(cauhoi.get_daTraLoiDung())
                        socaudung++;
                }
                cout << "\nDiem cua ban la: " << socaudung;
                break;
            }
        case 5:
        {
            int soThuTu = 1;
            for (auto cauhoi : danhSachCauHoi)
            {
                cout << "1) ";
                cauhoi.xuat();
            }
            break;
        }
        case 6:
        {
            cout << "\nSo cau hoi dang co la: " << danhSachCauHoi.size();
            cout << "\nChon thu tu cua 2 cau hoi de so sanh (cauhoi1, cauhoi2): ";
            int cauhoi1, cauhoi2;
            cin >> cauhoi1 >> cauhoi2;
            if (giongnhau(danhSachCauHoi[cauhoi1], danhSachCauHoi[cauhoi2]))
            {
                cout << "\nHai cau hoi tren giong nhau";
            }
            else
            {
                cout << "\nHai cau hoi tren khong giong nhau";
            }

            break;
        }
        case 7:
        {
            break;
        }
        default:
        {
            cout << "Chuc nang khong hop le\n";
        }
        }
    } while (chon != 7);

    return 0;
}