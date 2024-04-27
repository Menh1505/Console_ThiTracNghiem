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

void CauHoiTN::Enter_Question(istream &in)
{
	if (&in == &cin)
	{
		cout << "\nNoi dung: ";
		getline(in, content);

		cout << "So luong dap an: ";
		in >> n_answer;
		in.ignore();

		answer = new string[n_answer];
		for (int i = 0; i < n_answer; ++i)
		{
			cout << "Noi dung dap an " << (char)(i + 'a') << ": ";
			getline(in, answer[i]);
		}

		cout << "Dap an dung: ";
		in >> correct_Answer;

		cout << "Muc diem (1|2|3): ";
		in >> diff;
		cin.ignore();
	}
	else
	{
		in.ignore();
		getline(in, content);
		in >> n_answer;
		in.ignore();
		answer = new string[n_answer];
		for (int i = 0; i < n_answer; ++i)
		{
			getline(in, answer[i]);
		}
		in >> correct_Answer;
		in >> diff;
	}
}

void CauHoiTN::Print_Question(ostream &out)
{
	if (&out == &cout)
	{
		out << content << endl;
		for (int i = 0; i < n_answer; ++i)
		{
			out << (char)(i + 'a') << ". " << answer[i] << endl;
		}
	}
	else
	{
		out << content << endl;
		out << n_answer << endl;
		for (int i = 0; i < n_answer; ++i)
		{
			out << answer[i] << endl;
		}
		out << correct_Answer << endl;
		out << diff << endl;
	}
}

int CauHoiTN::examine(char yourAnswer)
{
	if (yourAnswer == correct_Answer)
		return diff;
	else
		return 0;
}

bool CompareQuestion(CauHoiTN cau1, CauHoiTN cau2)
{
	if (cau1.content == cau2.content)
		return false;
	else
		return true;
}
