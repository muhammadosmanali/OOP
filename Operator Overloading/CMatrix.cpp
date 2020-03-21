#include <iostream> 
#include "CMatrix.h"

CMatrix::CMatrix() {
	for(int a = 0; a <= 2; a++) {
		for(int b = 0; b <= 2; b++) {
			m[a][b] = 0;
		}
	}
}

CMatrix::CMatrix(CMatrix &mat) {
	for(int a = 0; a <= 2; a++) {
		for(int b = 0; b <= 2; b++) {
			m[a][b] = mat.m[a][b];
		}
	}
}

bool CMatrix::operator ==(const CMatrix &mat)const {
	for(int a = 0; a <= 2; a++) {
		for(int b = 0; b <= 2; b++) {
			if(m[a][b] == mat.m[a][b]) {
				return true;
			}
		}
	}
	return false;
}

bool CMatrix::operator !() const{
	for(int a = 0; a <= 2; a++) {
		for(int b = 0; b <= 2; b++) {
			if(a == b) {
				if(m[a][b] == 1) {
					return true;
				}
			}
			if(a != b) {
				if(m[a][b] == 0) {
					return true;
				}
			}
		}
	}
	return false;
}

void CMatrix::operator =(const CMatrix &mat) {
	for(int a = 0; a <= 2; a++) {
		for(int b = 0; b <= 2; b++) {
			m[a][b] = mat.m[a][b];
		}
    }
}

CMatrix CMatrix::operator *(const CMatrix &mat) {
	CMatrix mul;
	for(int a = 0; a <= 2; a++) {
		for(int b = 0; b <= 2; b++) {
			mul.m[a][b] += m[a][b] * mat.m[a][b];
		}
    }
    return mul;
}

CMatrix CMatrix::operator +(const CMatrix &mat) {
	CMatrix add;
	for(int a = 0; a <= 2; a++) {
		for(int b = 0; b <= 2; b++) {
			add.m[a][b] = m[a][b] + mat.m[a][b];
		}
    }
    return add;
} 

CMatrix CMatrix::operator -(const CMatrix &mat) {
	CMatrix sub;
	for(int a = 0; a <= 2; a++) {
		for(int b = 0; b <= 2; b++) {
			sub.m[a][b] = m[a][b] - mat.m[a][b];
		}
    }
}
