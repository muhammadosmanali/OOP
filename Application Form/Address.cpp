#include <iostream>
#include <string.h>
#include "Address.h"
using namespace std;

Address::Address() {
	this->street = new char[1];
	this->street[0] = '\0';
	this->city = new char[1];
	this->city[0] = '\0';
	this->state = new char[1];
	this->state[0] = '\0';
	this->country = new char[1];
	this->country[0] = '\0';
	this->zip_code = new char[1];
	this->zip_code[0] = '\0';
}

Address::Address(char* s, char* c, char* s1, char* c1, char* z) {
	this->street = new char[strlen(street) + 1];
	strcpy(this->street, s);
	this->city = new char[strlen(city) + 1];
	strcpy(this->city, c);
	this->state = new char[strlen(state) + 1];
	strcpy(this->state, s1);
	this->country = new char[strlen(country) + 1];
	strcpy(this->country, c1);
	this->zip_code = new char[strlen(zip_code) + 1];
	strcpy(this->zip_code, z);
}

Address::~Address() {
	delete[] street;
	delete[] city;
	delete[] state;
	delete[] country;
	delete[] zip_code;
}

Address::Address(const Address & src) {
	this->street = new char[strlen(src.street) + 1];
	strcpy(this->street, src.street);
	this->city = new char[strlen(src.city) + 1];
	strcpy(this->city, src.city);
	this->state = new char[strlen(src.state) + 1];
	strcpy(this->state, src.state);
	this->country = new char[strlen(src.country) + 1];
	strcpy(this->country, src.country);
	this->zip_code = new char[strlen(src.zip_code) + 1];
	strcpy(this->zip_code, src.zip_code);
}

Address & Address::operator =(Address & src) {
	delete[] street;
	this->street = new char[strlen(src.street) + 1];
	strcpy(this->street, src.street);
	delete[] city;
	this->city = new char[strlen(src.city) + 1];
	strcpy(this->city, src.city);
	delete[] state;
	this->state = new char[strlen(src.state) + 1];
	strcpy(this->state, src.state);
	delete[] country;
	this->country = new char[strlen(src.country) + 1];
	strcpy(this->country, src.country);
	delete[] zip_code;
	this->zip_code = new char[strlen(src.zip_code) + 1];
	strcpy(this->zip_code, src.zip_code);
	return *this;
}

Address & Address::setAddress(char* s, char* c, char* s1, char* c1, char*z) {
	delete[] street;
	this->street = new char[strlen(street) + 1];
	strcpy(this->street, s);
	delete[] city;
	this->city = new char[strlen(city) + 1];
	strcpy(this->city, c);
	delete[] state;
	this->state = new char[strlen(state) + 1];
	strcpy(this->state, s1);
	delete[] country;
	this->country = new char[strlen(country) + 1];
	strcpy(this->country, c1);
	delete[] zip_code;
	this->zip_code = new char[strlen(zip_code) + 1];
	strcpy(this->zip_code, z);
}

char* Address::getcity()const {
    char* temp = new char[strlen(city) + 1];
    strcpy(temp, city);
    return temp;
}

char* Address::getstreet()const {
    char* temp = new char[strlen(street) + 1];
    strcpy(temp, street);
    return temp;
}

char* Address::getstate()const {
    char* temp = new char[strlen(state) + 1];
    strcpy(temp, state);
    return temp;
}

char* Address::getcountry()const {
    char* temp = new char[strlen(country) + 1];
    strcpy(temp, country);
    return temp;
}

char* Address::getzip()const {
    char* temp = new char[strlen(zip_code) + 1];
    strcpy(temp, zip_code);
    return temp;
}

void Address::input() {
	cout << "Enter the street Number and Colony Name(e.g 10-Garden-Town): ";
	cin >> street;
	cout << "Enter the Name of city: ";
	cin >> city;
	cout << "Enter the Zip code of city: ";
	cin >> zip_code;
	cout << "Enter the Name of State: ";
	cin >> state;
	cout << "Enter the Name of Country: ";
	cin >> country;
}

void Address::print() {
	cout << "\r\nADDRESS INFO\r\n\n";
	cout << "\r\nStreet # " << street << " " << city << ", " << state << ", " << country << "              Postal Code: " << zip_code << endl;
}
