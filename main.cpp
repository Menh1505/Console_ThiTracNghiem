#include "cauHoiTN.h"

/* istream& operator>>(istream& in, CauHoiTN a)
{
    cin.ignore();
    cout << "Nhap noi dung cau hoi: ";
    getline(in, a.noiDung);
    cout << "Nhap noi dung dap an A: ";
    getline(in, a.dapAn1);
    cout << "Nhap noi dung dap an B: ";
    getline(in, a.dapAn2);
    cout << "Nhap dap an dung (A/B): ";
    in >> a.dapAnDung;
    return in;
}

ostream& operator<<(ostream& out, CauHoiTN a)
{
    out << a.noiDung << endl;
    out << a.dapAn1 << endl;
    out << a.dapAn2 << endl;
    return out;
}
 */
void docFile(ifstream &f, vector<string> &cauHoi)
{
    if (f.is_open())
    {
        string s;
        while (std::getline(f, s))
        {
            s.erase(s.find_last_not_of(" \n") + 1);
            if (!s.empty())
            {
                cauHoi.push_back(s);
            }
        }
        cout << "\nDa ghi thanh cong!\n"
             << endl;
        f.close();
    }
    else
    {
        cout << "\nKhong the mo file!\n"
             << endl;
    }
}

void ghiFile(ofstream &f, const vector<std::string> &cauHoi)
{
    if (f.is_open())
    {
        for (const string &question : cauHoi)
        {
            f << question << std::endl;
        }
        f.close();
        std::cout << "\nDa ghi cau hoi!\n"
                  << std::endl;
    }
    else
    {
        cout << "\nKhong the mo tep!\n"
             << std::endl;
    }
}

bool giongNhau(CauHoiTN cau1, CauHoiTN cau2)
{
    if (cau1.content == cau2.content)
        return false;
    else
        return true;
}

char Menu()
{
    cout << "\n1. Nhap cau hoi";
    cout << "\n2. In cau hoi";
    cout << "\n3. Doc cau hoi tu file";
    cout << "\n4. Ghi cau hoi vao file";
    cout << "\n5. Kiem tra";
    cout << "\n0. Thoat";
    cout << "\nNhap lua chon: ";

    string c;
    cin >> c;

    return c[0];
}

char Enter_Quest_Menu()
{
}

vector<CauHoiTN> Ques;
vector<CauHoiTN> Ez_Q;
vector<CauHoiTN> Med_Q;
vector<CauHoiTN> Har_Q;
int main()
{
    string file_path_in = "cauhoi.txt";
    string file_path_out = "inCauHoi.txt";
    ifstream file_in;
    ofstream file_out;
    int n;
    /*int count = 0;*/
    int choice;
    do
    {
        choice = Menu();
        switch (choice)
        {
        case 1:
            
            break;
        case 2:
            
            break;
        case 3:
         
            break;
        case 4:
        {
            break;
        }
        case 5:
            // kiem tra
            break;
        case 0:
            cout << "Thoat chuong trinh." << endl;
            break;
        default:
            cout << "Lua chon khong hop le!" << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}