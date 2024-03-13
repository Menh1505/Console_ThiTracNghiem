#ifndef CAUHOITN_H
#define CAUHOITN_H

#include <string>
#include <vector>
#include <fstream>

using namespace std;

class CauhoiTN
{
private:
    string cauhoi;
    char cauTLdung;
    string cauTL[3];
    bool daTraLoiDung;

public:
    CauhoiTN();
    void nhap();
    void docfile(ifstream& f);
    void ghifile(ofstream& f);
    void kiemtra();
    void xuat();
    bool get_daTraLoiDung();
    string get_cauhoi();
    friend bool giongnhau(CauhoiTN cau1, CauhoiTN cau2);
};

#endif