#include "Exam.h"

int Menu()
{
    cout << "\n1. Nhap cau hoi";
    cout << "\n2. In cau hoi";
    cout << "\n3. Xay dung de kiem tra";
    cout << "\n4. In de kiem tra";
    cout << "\n5. Kiem tra";
    cout << "\n0. Thoat";
    cout << "\nNhap lua chon: ";

    int c;
    cin >> c;

    return (int)c;
}

char Input()
{
    cout << "\na. Nhap cau hoi de";
    cout << "\nb. Nhap cau hoi trung binh";
    cout << "\nc. Nhap cau hoi kho";
    cout << "\nd. Quay lai";
    cout << "\nLua chon: ";

    char c;
    cin >> c;
    return c;
}

char Output()
{
    cout << "\na. In cau hoi de";
    cout << "\nb. In cau hoi trung binh";
    cout << "\nc. In cau hoi kho";
    cout << "\nd. In tat ca";
    cout << "\ne. Quay lai";
    cout << "\nLua chon: ";

    char c;
    cin >> c;
    return c;
}


int main()
{
    QuestionList Ez, Med, Hard;
    Exam test1;
    int choice;
    do
    {
        choice = Menu();
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            bool loop = true;
            while (loop)
            {
                switch (Input())
                {
                case 'a':
                {
                    Ez.Input();
                    break;
                }
                case 'b':
                {
                    Med.Input();
                    break;
                }
                case 'c':
                {
                    Hard.Input();
                    break;
                }
                case 'd':
                {
                    loop = false;
                    break;
                }
                default:
                    cout << "\nKhong hop le!";
                    break;
                }
            }
            break;
        }
        case 2:
        {
            bool loop = true;
            while (loop)
            {
                switch (Output())
                {
                case 'a':
                {
                    Ez.Output();
                    break;
                }
                case 'b':
                {
                    Med.Output();
                    break;
                }
                case 'c':
                {
                    Hard.Output();
                    break;
                }
                case 'd':
                {
                    Ez.Output();        
                    Med.Output();
                    Hard.Output();
                    break;
                }
                case 'e':
                {
                    loop = false;
                    break;
                }
                default:
                    cout << "\nKhong hop le!";
                    break;
                }
            }
            break;
        }
        case 3:
            test1.Build(Ez.Get_list(), Ez.Get_n_Question(), Med.Get_list(), Med.Get_n_Question(), Hard.Get_list(), Hard.Get_n_Question());
            break;
        case 4:
        {
            test1.Print();
            break;
        }
        case 5:
            test1.Test();
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