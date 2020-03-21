#include <iostream>
#include <string.h>
#include "Continfo.h"
using namespace std;

ContInfo::ContInfo() {
	
	this->relegion = new char[1];
	this->relegion[0] = '\0';
	this->status = new char[1];
	this->status[0] = '\0';
	this->sex = new char[1];
	this->sex[0] = '\0';
	this->citizen = new char[1];
	this->citizen[0] = '\0';
	this->cnic = new char[1];
	this->cnic[0] = '\0';
	this->domicile = new char[1];
	this->domicile[0] = '\0';
}

ContInfo::ContInfo(char* r, char* s, char* s1, char* c, char* c1, char* d) {
	
	this->relegion = new char[strlen(this->relegion) + 1];
	strcpy(this->relegion, r);
	this->status = new char[strlen(this->status) + 1];
	strcpy(this->status, s);
	this->sex = new char[strlen(this->sex) + 1];
	strcpy(this->sex, s1);
	this->citizen = new char[strlen(this->citizen) + 1];
	strcpy(this->citizen, c);
	this->cnic = new char[strlen(this->cnic) + 1];
	strcpy(this->cnic, c1);
	this->domicile = new char[strlen(this->domicile) + 1];
	strcpy(this->domicile, d);
}

ContInfo::~ContInfo() {
	
	delete[] this->relegion;
	delete[] this->status;
	delete[] this->sex;
	delete[] this->citizen;
	delete[] this->cnic;
	delete[] this->domicile;
}

ContInfo::ContInfo(const ContInfo & src) {
	
	this->relegion = new char[strlen(src.relegion) + 1];
	strcpy(this->relegion, src.relegion);
	this->status = new char[strlen(src.status) + 1];
	strcpy(this->status, src.status);
	this->sex = new char[strlen(src.sex) + 1];
	strcpy(this->sex, src.sex);
	this->citizen = new char[strlen(src.citizen) + 1];
	strcpy(this->citizen, src.citizen);
	this->cnic = new char[strlen(src.cnic) + 1];
	strcpy(this->cnic, src.cnic);
	this->domicile = new char[strlen(src.domicile) + 1];
	strcpy(this->domicile, src.domicile);
}

ContInfo & ContInfo::operator = (ContInfo & src) {
	
	delete[] this->relegion;
	this->relegion = new char[strlen(src.relegion) + 1];
	strcpy(this->relegion, src.relegion);
	delete[] this->status;
	this->status = new char[strlen(src.status) + 1];
	strcpy(this->status, src.status);
	delete[] this->sex;
	this->sex = new char[strlen(src.sex) + 1];
	strcpy(this->sex, src.sex);
	delete[] this->citizen;
	this->citizen = new char[strlen(src.citizen) + 1];
	strcpy(this->citizen, src.citizen);
	delete[] this->cnic;
	this->cnic = new char[strlen(src.cnic) + 1];
	strcpy(this->cnic, src.cnic);
	delete[] this->domicile;
	this->domicile = new char[strlen(src.domicile) + 1];
	strcpy(this->domicile, src.domicile);
}

ContInfo & ContInfo::setCont(char* r, char* s, char* s1, char* c, char* c1, char* d) {
	delete[] this->relegion;
	this->relegion = new char[strlen(this->relegion) + 1];
	strcpy(this->relegion, r);
	delete[] this->status;
	this->status = new char[strlen(this->status) + 1];
	strcpy(this->status, s);
	delete[] this->sex;
	this->sex = new char[strlen(this->sex) + 1];
	strcpy(this->sex, s1);
	delete[] this->citizen;
	this->citizen = new char[strlen(this->citizen) + 1];
	strcpy(this->citizen, c);
	delete[] this->cnic;
	this->cnic = new char[strlen(this->cnic) + 1];
	strcpy(this->cnic, c1);
	delete[] this->domicile;
	this->domicile = new char[strlen(this->domicile) + 1];
	strcpy(this->domicile, d);
}


char* ContInfo::getrelegion()const {
    char* temp = new char[strlen(this->relegion) + 1];
    strcpy(temp, this->relegion);
    return temp;
}

char* ContInfo::getstatus()const {
    char* temp = new char[strlen(this->status) + 1];
    strcpy(temp, this->status);
    return temp;
}

char* ContInfo::getsex()const {
    char* temp = new char[strlen(this->sex) + 1];
    strcpy(temp, this->sex);
    return temp;
}

char* ContInfo::getcitizen()const {
    char* temp = new char[strlen(this->citizen) + 1];
    strcpy(temp, this->citizen);
    return temp;
}

char* ContInfo::getcnic()const {
    char* temp = new char[strlen(this->cnic) + 1];
    strcpy(temp, this->cnic);
    return temp;
}

char* ContInfo::getdomicile()const {
    char* temp = new char[strlen(this->domicile) + 1];
    strcpy(temp, this->domicile);
    return temp;
}

void ContInfo::input1() {
	cout << "Please Enter your CNIC Number: ";
	cin >> cnic;
	cout << "Please Enter your Relegion: ";
	cin >> relegion;
	cout << "Please Enter your Sex(Male or Female): ";
	cin >> sex;
	cout << "Please Enter your Marital Status(Single/Marries): ";
	cin >> status;
	cout << "Please Enter your Domicile City: ";
	cin >> domicile;
	cout << "Please Enter the name of Country which you hold Nationality: ";
	cin >> citizen;
}


void ContInfo::Display() {
	cout << "\r\r\nCNIC: " << cnic << "                      Relegion:" << relegion;
	cout << "\r\r\nMarital Status: " << status << "                      Sex: " << sex;
	cout << "\r\r\nDomicile: " << domicile << "                      Nationality: " << citizen << endl;
	
	
}


