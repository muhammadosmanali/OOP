#include <iostream>
#include <string.h>
#include <fstream> 
#include "CDate.h"
#include "CName.h"
#include "Address.h"
#include "Contact.h"
#include "Continfo.h"
using namespace std;

class Form {
	CDate date;
	CName name;
	Address add;
	Contact con;
	ContInfo info;
	public:
		Form();
		Form(CDate d, CName n, Address a, Contact ct,  ContInfo c);
		~Form();
		void line();
		void userinput();
		void printfom();
		ofstream& printform(ofstream & outfile);
};

Form::Form() {
	//no-op
}

Form::Form(CDate d, CName n, Address a, Contact ct, ContInfo c) : date(d), name(n), add(a), con(ct), info(c) {
	//no-op
}

Form::~Form() {
	//no-op
}

void Form::line() {
	cout << "\r\n";
	for(int i = 0; i < 80; i++) {
		cout << "-";
	}
	cout << "\r\n";
}

void Form::userinput() {
	name.usrinput();
	date.ReadfromKB();
	info.input1();
	con.input();
	add.input();
}

void Form::printfom() {
	cout << "                                 APPLICATION FORM\n\r";
	line();
	name.Display();
	date.print(2);
	line();
	info.Display();
	line();
	con.display();
	line();
	add.print();
	line();
}

ofstream & Form::printform(ofstream & outfile) {
	freopen("Application Form.txt", "w", stdout);
	printfom();
	outfile.close();
	return outfile;
}

int main() {
	ofstream outfile;
	Form obj;
	obj.userinput();
	obj.printfom();
	obj.printform(outfile);
}
