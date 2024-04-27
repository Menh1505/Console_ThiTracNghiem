#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class CauHoiTN
{
private:
	string content;
	int n_answer;
	string* answer;
	char correct_Answer;
	int diff; //1: easy, 2: medium, 3: hard
public:
	CauHoiTN();
	CauHoiTN(string, int, string*, char, int);
	~CauHoiTN()
	{
		delete answer;
	}
	void Enter_Question(istream&);
	void Print_Question(ostream&);
	int examine(char); //return your point
	friend bool CompareQuestion(CauHoiTN cau1, CauHoiTN cau2); //compare content of two ques

	int Get_Diff() {return diff;}
};