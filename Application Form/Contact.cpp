#include <iostream>
#include <string.h>
#include "Contact.h"
using namespace std;

Contact::Contact() {
	this->mobile = new char[1];
	this->mobile[0] = '\0';
	this->tele = new char[1];
	this->tele[0] = '\0';
	this->mail = new char[1];
	this->mail[0] = '\0';
}

Contact::Contact(char* m, char* t, char* m1) {
	this->mobile = new char[strlen(this->mobile) + 1];
	strcpy(this->mobile, m);
	this->tele = new char[strlen(this->tele) + 1];
	strcpy(this->tele, t);
	this->mail = new char[strlen(this->mail) + 1];
	strcpy(this->mail, m1);
}

Contact::~Contact() {
	delete[] this->mobile;
	delete[] this->tele;
	delete[] this->mail;
}

Contact::Contact(const Contact & src) {
	this->mobile = new char[strlen(src.mobile) + 1];
	strcpy(this->mobile, src.mobile);
	this->tele = new char[strlen(src.tele) + 1];
	strcpy(this->tele, src.tele);
	this->mail = new char[strlen(src.mail) + 1];
	strcpy(this->mail, src.mail);
}

Contact & Contact::operator =(Contact & src) {
	delete[] this->mobile;
	this->mobile = new char[strlen(src.mobile) + 1];
	strcpy(this->mobile, src.mobile);
	delete[] this->tele;
	this->tele = new char[strlen(src.tele) + 1];
	strcpy(this->tele, src.tele);
	delete[] this->mail;
	this->mail = new char[strlen(src.mail) + 1];
	strcpy(this->mail, src.mail);
}

Contact & Contact::setcontact(char* m, char* t, char* m1) {
	delete[] this->mobile;
	this->mobile = new char[strlen(this->mobile) + 1];
	strcpy(this->mobile, m);
	delete[] this->tele;
	this->tele = new char[strlen(this->tele) + 1];
	strcpy(this->tele, t);
	delete[] this->mail;
	this->mail = new char[strlen(this->mail) + 1];
	strcpy(this->mail, m1);
}

char* Contact::getmobile()const {
    char* temp = new char[strlen(this->mobile) + 1];
    strcpy(temp, this->mobile);
    return temp;
}

char* Contact::gettele()const {
    char* temp = new char[strlen(this->tele) + 1];
    strcpy(temp, this->tele);
    return temp;
}

char* Contact::getmail()const {
    char* temp = new char[strlen(this->mail) + 1];
    strcpy(temp, this->mail);
    return temp;
}

void Contact::input() {
	cout << "Please Enter your Contact Number(+923xx-xxxxxxx): ";
	cin >> mobile;
	cout << "Please Enter your Telephone Number(055-3xx-xxxx) if not then write(NULL): ";
	cin >> tele;
	cout << "Please Enter your Email(if not write NULL): ";
	cin >> mail;
}

void Contact::display() {
	cout << "\r\nCONTACT INFO\r\r\n";
	cout << "Contact Number: " << mobile << "                      Telephone Number: " << tele << endl;
	cout << "\r\r\nEmail: " << mail << endl;
}

