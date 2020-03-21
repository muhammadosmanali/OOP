#include <iostream>
#include <cstring>
#include <fstream>
#include "CName.h"
#include "CDate.h"
using namespace std;

class CMCQ {
	protected:
	    static char options[13][2];
	public:
		CMCQ();
		~CMCQ();
		void openfile();
		void line();
		void start();
};

char CMCQ::options[13][2] = {"b", "a", "d", "b", "a", "c", "d", "a", "a", "b", "c", "b", "d"};

CMCQ::CMCQ() {
	//no-op
}


CMCQ::~CMCQ() {
	//no-op
}

void CMCQ::openfile() {
    line();
	cout << "     Please select from option a, b, c, d. Every question worth 4 points.\n" << "     There is negative marking of -1.\n" << endl;
    line();
}

void CMCQ::line() {
	for(int i = 0; i < 80; i++) {
		cout << "-";
    }
}

void CMCQ::start() {
	line();
	line();
	cout << "                               QUIZ OF C++ LANGUAGE " << endl;
	line();                               
	line();
	cout << "\nUser Please Enter Your Name";
}



class CTestQuestion : public CMCQ {
	protected:
	    string mcq[50]; 
		string userinput;
		int i;
		int score;
		int count;
		int corrAns;
		int wrgAns;
	public:
		CTestQuestion();
		~CTestQuestion();
		ifstream& checkMCQ(ifstream &infile);
};

CTestQuestion::CTestQuestion() : score(0), count(0), corrAns(0), wrgAns(0) {
	//no-op
}

CTestQuestion::~CTestQuestion() {
	//no-op
}

ifstream& CTestQuestion::checkMCQ(ifstream &infile) {
	while(count < 13) {
		for(i = 0; i < 13; i++) {
			getline(infile, mcq[i], '\n');
		    if(i == count) {
		    	cout << "\nQ # ";
		    	cout << mcq[i] << endl;
		    	cout << "Your option: " ;
		        cin >> userinput;	
			}
	    }
	    if(userinput == options[count]) {
            cout << "-----------\n";
	    	cout << "\nCorrect\n" << endl;
            cout << "-----------\n";
	    	score = score + 4;
	    	corrAns++;
		}
		else {
            cout << "-----------\n";
			cout << "\nWrong\n" << endl;
            cout << "-----------\n";
			score = score - 5;
			wrgAns++;
		}
		count++;
    }
    return infile;
}
	

class CTest : public CTestQuestion {
	protected:
		CDate date;
		CName name;
	public:
		CTest();
		CTest(CDate d, CName n);
		~CTest();
		void inp_name_date();
		void PrintResult();
		ofstream& PrintResult(ofstream &outfile);
};


CTest::CTest() {
	//no-op
}

CTest::CTest(CDate d, CName n) : date(d), name(n) {
    //no-op
}


CTest::~CTest() {
	//no-op
}

void CTest::inp_name_date() {
	name.usrinput();
	date.ReadfromKB();
}

void CTest::PrintResult() {
	cout << "\n\n";
	line();
	cout << "\r\nName: ";
	name.Display();
	cout << "                                  Date: ";
	date.print(2);
	cout << "\r\n";
	line();
	cout << "\r\nResult: \r\n";
	line();
	cout << "\r\nCorrect Attempts: " << corrAns << "                          " << "Wrong Attempts: " << wrgAns << endl << endl;
	cout << "\r\n                          Final Score: " << score <<  "\r\n"; 
	line();
}

ofstream& CTest::PrintResult(ofstream &outfile) {
	freopen("Result.txt", "w", stdout);
	PrintResult();
	outfile.close();
	return outfile;
}


int main() {
	ifstream infile;
	ofstream outfile;
	CTest obj1;
    obj1.start();
	obj1.inp_name_date();
	obj1.openfile();
	infile.open("MCQ.txt", ios::in);
	obj1.checkMCQ(infile);
	obj1.PrintResult();
	obj1.PrintResult(outfile);
}
