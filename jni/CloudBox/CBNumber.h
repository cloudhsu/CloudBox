/*
 *  CBNumber.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/8/19.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBNUMBER_H_
#define _CBNUMBER_H_

#define CHAR_COUNT		10
#define TEXTURE_SIZE	256
#define MAX_NUMBERS 6
#define ASCII_INT_0 48

#include <string>
#include <sstream>
#include "CBView.h"
using namespace std;

enum NumberFill
{
	NumberFillNone,
	NumberFillZero
};


class CBNumber : public CBView
{
private:
	int m_number;
	CBView *m_numbers[10];
	string m_text;
	int m_fontSize;
	NumberFill m_numberFill;
	int m_maxNumbers;
	CBNumber();
	void initialNumber();
	void initialNumber(const string& preFileNmae);
protected:
	void draw();
public:
	CBNumber(int fontSize);
	CBNumber(int number,int fontSize);
	CBNumber(const string& preFileNmae);
	~CBNumber();
	
	int getNumber();
	void setNumber(const int number);
	
	inline NumberFill getNumberFill() { return m_numberFill; }
	inline void setNumberFill(NumberFill numberFill) { m_numberFill = numberFill; }
	
	inline int getMaxNumbers() { return m_maxNumbers; }
	inline void setMaxNumbers(int maxNumbers) { m_maxNumbers = maxNumbers; }
};

#endif