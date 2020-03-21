#include <iostream>
#include <string.h>
#include "CName.h"
using namespace std;



CName::CName() {
	this->first = new char[1];
	this->first[0] = '\0';
	this->mid = new char[1];
	this->mid[0] = '\0';
	this->last = new char[1];
	this->last[0] = '\0';
}
 
CName::CName(const char *first, const char *mid, const char *last) {
	this->first = new char[strlen(first) + 1];
	strcpy(this->first, first);
	this->mid = new char[strlen(mid) + 1];
	strcpy(this->mid, mid);
	this->last = new char[strlen(last) + 1];
	strcpy(this->last, last);
}

CName::CName(const CName &name) {
	this->first = new char[strlen(name.first) + 1];
	strcpy(this->first, name.first);
	this->mid = new char[strlen(name.mid) + 1];
	strcpy(this->mid, name.mid);
	this->last = new char[strlen(name.last) + 1];
	strcpy(this->last, name.last);
}
  
CName::~CName() {
	delete [] this->first;
	delete [] this->mid;
	delete [] this->last;
}


CName & CName::operator =(const CName &name) {
	delete [] this->first;
	this->first = new char[strlen(name.first) + 1];
	strcpy(this->first, name.first);
	delete [] this->mid;
	this->mid = new char[strlen(name.mid) + 1];
	strcpy(this->mid, name.mid);
	delete [] this->last;
	this->last = new char[strlen(name.last) + 1];
	strcpy(this->last, name.last);
	return *this;
}

CName& CName::setName(const char *first, const char *mid, const char *last) {
	delete [] this->first;
	this->first = new char[strlen(first) + 1];
	strcpy(this->first, first);
	delete [] this->mid;
	this->mid = new char[strlen(mid) + 1];
	strcpy(this->mid, mid);
	delete [] this->last;
	this->last = new char[strlen(last) + 1];
	strcpy(this->last, last);
	return *this;
}

char* CName::getfirst() const {
	char * tmp = new char[strlen(this->first) + 1];
	strcpy(tmp, this->first);
	return tmp;
}

char* CName::getmid() const {
	char * tmp = new char[strlen(this->mid) + 1];
	strcpy(tmp, this->mid);
	return tmp;
}

char* CName::getlast() const {
	char * tmp = new char[strlen(this->last) + 1];
	strcpy(tmp, this->last);
	return tmp;
}

void CName::usrinput() {
	cout << "Please Enter your Name as (First Middle Last): ";
	cin >> first >> mid >> last;
}

void CName::Display() {
	cout << "\r\r\nName: " << this->first << " " << this->mid << " " << this->last;
}



