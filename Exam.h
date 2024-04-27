#include "QuestionList.h"
#include <ctime>
#include <cstdlib>
class Exam
{
private:
    string ID;
    int n_Question;
    QuestionList exam;

public:
    Exam()
    {
        ID = "";
        n_Question = 0;
    }

    void Build(CauHoiTN* ez, int n_ez, CauHoiTN* med, int n_med, CauHoiTN* hard, int n_hard)
    {
        srand(unsigned(time(0)));
        cout << "\nNhap ma de: ";
        getline(cin, ID);

    LOOP:
        int max_question = n_ez + n_med + n_hard;
        cout << "\nNhap so luong cau hoi" << "(toi da" << max_question << ") cau hoi: ";
        cin >> n_Question;
        if (n_Question < 1 || n_Question > max_question)
        {
            cout << "\nSo luong khong hop le, moi nhap lai!";
            goto LOOP;
        }

        cout << "\nTinh nang chon so luong cau hoi dang xay dung nen lay mac dinh so luong cau hoi la 10 :D";
        n_Question = 10;
        exam.Set_n_Question(10);

        int n = 0;
        CauHoiTN *tmp = new CauHoiTN[10];
        for (int i = 0; i < 5; ++i, ++n)
        {
            tmp[n] = ez[i];
        }
        for (int i = 0; i < 3; ++i, ++n)
        {
            tmp[n] = med[i];
        }
        for (int i = 0; i < 2; ++i, ++n)
        {
            tmp[n] = hard[i];
        }

        cout << "\nXay dung thanh cong";
        exam.Set_list(tmp);
    }

    void Print()
    {
        exam.Output();
    }

    void Test()
    {
        int record = 0;
        int correct_count = 0;

        char answer;
        int tmp_point;
        for (int i = 0; i < n_Question; ++i)
        {
            cout << "\nCau " << i + 1 << ": ";
            exam.Get_list()[i].Print_Question(cout);
            cin >> answer;
            tmp_point = exam.Get_list()[i].examine(answer);
            if (tmp_point != 0)
            {
                record += tmp_point;
                correct_count++;
            }
        }

        cout << "\nChuc mung ban hoan thanh bai kiem tra";
        cout << "\nSo luong cau dung: " << correct_count;
        cout << "\nSo diem: " << record;
    }
    ~Exam()
    {
    }
};
