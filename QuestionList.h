#include "cauHoiTN.h"

class QuestionList
{
private:
    int n_Question;
    CauHoiTN* list;
public:
    QuestionList();
    QuestionList(int, CauHoiTN*);
    ~QuestionList();
    void Input();
    void Output();
    int Get_n_Question() {return n_Question;}
    void Set_n_Question(int val) {n_Question = val;}
    CauHoiTN* Get_list() {return list;}
    void Set_list(CauHoiTN* val) {list = val;}
};

