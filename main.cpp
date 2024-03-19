#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <ctime>
	using namespace std;

class Student
{
public:
	Student()
	{

	}
	void setfam(string fam) 
	{
		this->fam = fam;
	}
	void setmath(int math) 
	{
		this->math = math;
	}
	void setphys(int phys) 
	{
		this->phys = phys;
	}
	void setstip(int stip)
	{
		this->stip = stip;
	}
	string getfam() 
	{
		return fam;
	}
	int getmath() 
	{
		return math;
	}
	int getphys() 
	{
		return phys;
	}
	int getstip()
	{
		return stip;
	}
	

	Student(string fam, int math, int phys, int stip)
	{
		this->fam = fam;
		this->math = math;
		this->phys = phys;
		this->stip = stip;
	}

private:
	string fam;
	int math;
	int phys;
	int stip;
};
unsigned long seed = 1;
//  у тех у кого 5 5 делаем стипендию 10к у кого 4/5 или 5/4 ставим 8к и у кого 4 4 ставим 5к у всех остальных ставим рандомную стипендию до 4к 

int main()
{
	srand(time(NULL));
	Student student[30];
	setlocale(LC_CTYPE, "Rus");
	SetConsoleCP(1251);
	fstream file("DataBase.txt");
	if (!file.is_open()) 
	{
		std::cout << "Not find file!" << endl;
		exit(1);
	}
	for (int i = 0; i < 30; ++i)
	{
		std::string fam;
		int math;
		int phys;
		file >> fam;
		file >> math;
		file >> phys;
		student[i].setfam(fam);
		student[i].setphys(phys);
		student[i].setmath(math);
		
		if ( math == 5 && phys == 5)
		{
			student[i].setstip(10000);
			std::cout << fam << " " << math << " " << phys << " "  << "стипендия студента: " << student[i].getstip() << endl;
		}
		else if (math == 4 && phys == 5 || math == 5 && phys == 4)
		{
			student[i].setstip(8000);
			std::cout << fam << " " << math << " " << phys << " " << " стипендия студента: " << student[i].getstip() << endl;
		}
		else if (math == 4 && phys == 4)
		{
			student[i].setstip(5000);
			std::cout << fam << " " << math << " " << phys << " " << " стипендия студента: " << student[i].getstip() << endl;
		}
		else
		{
			student[i].setstip(rand()%5000);
			std::cout << fam << " " << math << " " << phys << " " << " стипедния студента: " << student[i].getstip() << endl;
		}
		
	}
	return 0;
}
