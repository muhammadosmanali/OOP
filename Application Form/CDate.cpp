#include <iostream>
#include "CDate.h"
using namespace std;

//dayofmonth contain the total number of days of every month.
int CDate::dayofmonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

//strofmonth contain the short form of months and their length is not greater than 4.
//"JAN" contain only 3 characters and the given length is 4 it is because the 4rth one is null character.
char CDate::strofmonth[12][4] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};

//stringofcharacter contain the full name of months in the form of strings and their length is not grater than 10.
char CDate::stringofmonth[12][10] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST",
 "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};


//Null Constructor
CDate::CDate() {
	this->day = 14;
	this->month = 8;
	this->year = 1997;
	this->validate();
}

//Initialization Constructor
CDate::CDate(int D, int M, int Y) {
	this->day = D;
	this->month = M;
	this->year = Y;
	this->validate();
}

//Validate function check the date is valid or not and also check that if year is leap year than february
// is of 29 days otherwise it is of 28 days.
void CDate::validate() {
	if(month < 1 || 12 < month) {
		this->day = -1;
	}
	else {
		if(isleapyear()) {
			this->dayofmonth[1] = 29;
		}
		else {
			this->dayofmonth[1] = 28;
		}
	}
	if(day < 1|| day > dayofmonth[month - 1]) {
		this->day = -1;
	}
}

//isleapyear check that the year is leap year is not.
bool CDate::isleapyear() {
	if(year % 4) {
		return false;
	}
	else {
		return true;
	}
}

//Print the date in three different formats.
void CDate::print(int opt = 0)const {
	if(opt == 2) {
		cout << "                        Date of Birth: " << stringofmonth[month - 1] << " " << day << " " << year << endl; 
	}
	else if(opt == 1) {
		cout << day << "-" << strofmonth[month - 1] << "-" << year << endl;
	}
	else {
		cout << day << "/" << month << "/" << year << endl;
	}
}

//This function takes the input of date.
void CDate::ReadfromKB() {
	do {
		cout << "Enter your date of birth as dd mm yyyy: ";
		cin >> day >> month >> year;
		cout << endl;
		validate();
	}while(day == -1);
}

//This function also used to comparison between dates.
int CDate::Comparewithdate(const CDate& date) {
	if(year < date.year) {
		return -1;
	}
	if(year > date.year) {
		return +1;
	}
	if(month < date.month) {
		return -1;
	}
	if(month > date.month) {
		return +1;
	}
	if(day < date.day) {
		return -1;
	}
	if(day > date.day) {
		return +1;
	}
	return 0;
}

// All are operators used to comparison between dates.
bool CDate::operator <(const CDate date)const {
    if(this->year < date.year) {
    	return true;
	}
	if(this->year > date.year) {
    	return false;
	}
	if(this->month < date.month) {
    	return true;
	}
	if(this->month > date.month) {
    	return false;
	}
	if(this->day < date.day) {
    	return true;
	}
	return false;
}

bool CDate::operator >(const CDate date)const {
    if(this->year > date.year) {
    	return true;
	}
	if(this->year < date.year) {
    	return false;
	}
	if(this->month > date.month) {
    	return true;
	}
	if(this->month < date.month) {
    	return false;
	}
	if(this->day > date.day) {
    	return true;
	}
	return false;
}

bool CDate::operator <=(const CDate date)const {
    if(this->year <= date.year) {
    	return true;
	}
	if(this->year > date.year) {
    	return false;
	}
	if(this->month <= date.month) {
    	return true;
	}
	if(this->month > date.month) {
    	return false;
	}
	if(this->day <= date.day) {
    	return true;
	}
	return false;
}

bool CDate::operator >=(const CDate date)const {
    if(this->year >= date.year) {
    	return true;
	}
	if(this->year < date.year) {
    	return false;
	}
	if(this->month >= date.month) {
    	return true;
	}
	if(this->month < date.month) {
    	return false;
	}
	if(this->day >= date.day) {
    	return true;
	}
	return false;
}

bool CDate::operator ==(const CDate date)const {
    if(this->year != date.year) {
    	return false;
	}
	if(this->month != date.month) {
    	return false;
	}
	if(this->day != date.day) {
    	return false;
	}
	return true;
}

bool CDate::operator !=(const CDate date)const {
    if(this->year == date.year) {
    	return false;
	}
	if(this->month == date.month) {
    	return false;
	}
	if(this->day == date.day) {
    	return false;
	}
	return true;
}

CDate CDate::operator ++() {
	day++;
	if(day > dayofmonth[month - 1]) {
		month++;
		day = 1;
	}
	if(month > 12) {
		year++;
		month = 1;
	}
	return CDate(day, month, year);
}

CDate CDate::operator --() {
	day--;
	if(day <= 0) {
		month--;
		day = dayofmonth[month - 1];
	}
	if(month <= 0) {
		year--;
		month = 12;
	}
	return CDate(day, month, year);
}

//In setdate (setter) here user can set the values of date, month and year.
CDate& CDate::setDate(int D, int M, int Y) {
	this->day = D;
	this->month = M;
	this->year = Y;
	this->validate();
	return *this;
}

//User can set the value of day.
CDate& CDate::setDay(int D) {
	this->day = D;
	this->validate();
	return *this;
}

//User can set the value of month.
CDate& CDate::setMonth(int M) {
	this->month = M;
	this->validate();
	return *this;
}

//User can set the value of year.
CDate& CDate::setYear(int Y) {
	this->year = Y;
	this->validate();
	return *this;
}

//In getday user can get day from date.
int CDate::getDay()const {
    return day;
}

//user can get month from date
int CDate::getMonth()const {
    return month;
}

//user can get year from date.
int CDate::getYear()const {
    return year;
}


