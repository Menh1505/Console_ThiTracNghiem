#include "QuestionList.h"

QuestionList::QuestionList()
{
    n_Question = 0;
    list = nullptr;
}
QuestionList::QuestionList(int _n_Question, CauHoiTN *_list)
{
    n_Question = _n_Question;
    list = _list;
}

QuestionList::~QuestionList()
{
    delete[] list;
}

void QuestionList::Input()
{
LOOP:
    cout << "\n1. Nhap cau hoi tu ban phim";
    cout << "\n2. Nhap cau hoi tu file";
    cout << "\nLua chon: ";

    int choice;
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
    case 1:
    {
        cout << "\nNhap so luong cau hoi: ";
        cin >> n_Question;
        cin.ignore();

        list = new CauHoiTN[n_Question];

        for (int i = 0; i < n_Question; ++i)
        {
            cout << "\nCau " << i + 1;
            list[i].Enter_Question(cin);
        }
        break;
    }
    case 2:
    {
        string fileName;
        cout << "\nNhap ten file (kem duoi mo rong): ";
        getline(cin, fileName);

        fstream fin(fileName, ios_base::in);
        fin >> n_Question;
        list = new CauHoiTN[n_Question];

        for (int i = 0; i < n_Question; ++i)
        {
            list[i].Enter_Question(fin);
        }
        fin.close();
        cout << "\nDa nhap xong";
        break;
    }
    default:
        cout << "\nKhong hop le, xin chon lai";
        goto LOOP;
        break;
    }
}

void QuestionList::Output()
{
LOOP:
    cout << "\n1. In ra man hinh";
    cout << "\n2. In ra file";
    cout << "\n3. Quay lai";
    cout << "\nLua chon: ";

    int choice;
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
    case 1:
    {
        for (int i = 0; i < n_Question; ++i)
        {
            cout << "\nCau " << i + 1 << ": ";
            list[i].Print_Question(cout);
        }
        break;
    }
    case 2:
    {
        string fileName;
        cout << "\nNhap ten file (kem duoi mo rong): ";
        getline(cin, fileName);

        fstream fout(fileName, ios_base::out);
        fout << n_Question << endl;
        for (int i = 0; i < n_Question; ++i)
        {
            list[i].Print_Question(fout);
        }
        fout.close();
        break;
    }
    case 3:
    {
        return;
    }
    default:
        cout << "\nKhong hop le, xin chon lai";
        goto LOOP;
        break;
    }
}