#include "CauhoiTN.h"
#include <iostream>
using namespace std;
CauhoiTN::CauhoiTN()
{
    daTraLoiDung = false;
}

void CauhoiTN::nhap()
{
    cin.ignore();
    cout << "\nNhap cau hoi: ";
    getline(cin, cauhoi);
    cout << "\nNhap cau A: ";
    getline(cin, cauTL[0]);
    cout << "\nNhap cau B: ";
    getline(cin, cauTL[1]);
    cout << "\nNhap dap an dung: ";
    cin >> cauTLdung;
}

void CauhoiTN::docfile(ifstream& f)
{
    getline(f, cauhoi);
    getline(f,cauTL[0]);
    getline(f,cauTL[1]);
    f >> cauTLdung;

     string xoaBoNhoDem;
    getline(f, xoaBoNhoDem);
}

void CauhoiTN::ghifile(ofstream& f)
{
    f << cauhoi << endl;
    f << cauTL[0] << endl;
    f << cauTL[1] << endl;
    f << cauTLdung << endl;
}

void CauhoiTN::kiemtra()
{
    cout << cauhoi << endl;
    cout << "a)" << cauTL[0] << endl;
    cout << "b)" << cauTL[1] << endl;
    cout << "\nNhap dap an cua ban (A,B): ";
    char res;
    cin >> res;
    if(res == cauTLdung || res == (cauTLdung - 32) || res == (cauTLdung + 32))
    {
        daTraLoiDung = true;
    } 
}

void CauhoiTN::xuat()
{
    cout << cauhoi << endl;
    cout << "Dap an: ";
    if(cauTLdung == 'A' || cauTLdung == 'a')
    {
        cout << cauTL[0] << endl;
    }
    if(cauTLdung == 'B' || cauTLdung == 'b')
    {
        cout << cauTL[1] << endl;
    }
}
bool CauhoiTN::get_daTraLoiDung()
{
    return daTraLoiDung;
}

string CauhoiTN::get_cauhoi()
{
    return cauhoi;
}
bool giongnhau(CauhoiTN cau1, CauhoiTN cau2)
{
    return cau1.cauhoi == cau2.cauhoi;
}