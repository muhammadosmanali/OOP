#include <iostream>
#include "Time.h"
using namespace std;

CTime::CTime() : hr(0), min(0), sec(0) {
	//no-op
}

CTime::CTime(int hr, int min, int sec) {
	this->hr = hr;
	this->min = min;
	this->sec = sec; 
} 

CTime::CTime(const CTime &time) {
	this->hr = time.hr;
	this->min = time.min;
	this->sec = time.sec;
}

CTime::~CTime() {
	//no-op
}

void CTime::Display() {
	cout << "H: " << hr << "  M: " << min << "  S: " << sec << endl;
}

CTime CTime::operator ++ () {
	++sec;
	if(sec >= 60) {
		++min;
		sec -= 60;
	}
	if(min >= 60) {
		++hr;
		min -= 60;
	}
	return CTime(hr, min, sec);
}

CTime CTime::operator -- () {
	sec--;
	if(sec <= 0) {
		min--;
		sec += 60;
	}
	if(min <= 0) {
		hr--;
		min += 60;
	}
	return CTime(hr, min, sec);
}

bool CTime::operator ==(const CTime &time) const {
	if(this->hr != time.hr) {
		return false;
	}
	if(this->min != time.min) {
		return false;
	}
	if(this->sec != time.sec) {
		return false;
	}
	return true;
}

CTime CTime::operator -(const CTime &time)const {
	CTime t;
	t.hr = hr - time.hr;
	t.min = min - time.min;
	t.sec = sec - time.sec;
	return t;
}

bool CTime::operator <(const CTime &time) const {
	if(this->hr < time.hr) {
		return true;
	}
	if(this->hr > time.hr) {
		return false;
	}
	if(this->min < time.min) {
		return true;
	}
	if(this->min > time.min) {
		return false;
	}
	if(this->sec < time.sec) {
		return true;
	}
	return false;
}

bool CTime::operator >(const CTime &time)const {
	if(this->hr > time.hr) {
		return true;
	}
	if(this->hr < time.hr) {
		return false;
	}
	if(this->min > time.min) {
		return true;
	}
	if(this->min < time.min) {
		return false;
	}
	if(this->sec > time.sec) {
		return true;
	}
	return false;
}


