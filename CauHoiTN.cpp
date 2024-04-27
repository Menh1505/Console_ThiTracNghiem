#include "cauHoiTN.h"

CauHoiTN::CauHoiTN()
{
	content = "";
	n_answer = 0;
	answer = nullptr;
	correct_Answer = ' ';
	diff = 0;
}

CauHoiTN::CauHoiTN(string _content, int _n_answer, string *_answer, char _correct_Answer, int _diff)
{
	content = _content;
	n_answer = _n_answer;
	answer = _answer;
	correct_Answer = _correct_Answer;
	diff = _diff;
}

CauHoiTN::~CauHoiTN()
{
	delete[] answer;
	cout << "Da xoa cau hoi" << endl;
}

void CauHoiTN::Enter_Question(istream &in)
{
	cout << "\nNoi dung: ";
	getline(in, content);

	cout << "\nSo luong dap an: ";
	in >> n_answer;
	in.ignore();

	answer = new string[n_answer];
	for (int i = 0; i < n_answer; ++i)
	{
		cout << "Noi dung dap an " << (char)(i + 'a') << ": ";
		in >> answer[i];
	}

	cout << "\nDap an dung: ";
	in >> correct_Answer;

	cout << "\nMuc diem (1|2|3): ";
	in >> diff;
}

void CauHoiTN::Print_Question(ostream &out)
{
	out << content << endl;
	for (int i = 0; i < n_answer; ++i)
	{
		out << (char)(i + 'a') << ". " << answer[i] << endl;
	}
}

int CauHoiTN::examine(char yourAnswer)
{
	if (yourAnswer == correct_Answer)
		return diff;
	else
		return 0;
}