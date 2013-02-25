/*
 *  CBNumber.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/8/19.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#include "CBNumber.h"
#include "CBString.h"
#include "CBImage.h"

CBNumber::CBNumber()
:CBView()
{
	m_numberFill = NumberFillNone;
	m_maxNumbers = MAX_NUMBERS;
	m_text = "0";
	m_fontSize = 14;
	initialNumber();
}

CBNumber::CBNumber(int fontSize)
:m_number(0),CBView()
{
	m_numberFill = NumberFillNone;
	m_maxNumbers = MAX_NUMBERS;
	m_fontSize = fontSize;
	initialNumber();
}

CBNumber::CBNumber(int number,int fontSize)
{
	m_numberFill = NumberFillNone;
	m_maxNumbers = MAX_NUMBERS;
	m_fontSize = fontSize;
	setNumber(number);
	initialNumber();
}

CBNumber::CBNumber(const string& preFileNmae)
{
	m_numberFill = NumberFillNone;
	m_maxNumbers = MAX_NUMBERS;
    initialNumber(preFileNmae);
}

CBNumber::~CBNumber()
{
	for(int i = 0; i <= 9 ; i++)
		CBDELETE(m_numbers[i]);
}

int CBNumber::getNumber()
{
	return m_number;
}
void CBNumber::setNumber(const int number)
{
	m_number = number;
	string s;
	stringstream ss(s);
	ss << m_number;
	m_text = ss.str();
}

void CBNumber::initialNumber()
{
	for(int i = 0; i <= 9 ; i++)
	{
		string s;
		stringstream ss(s);
		ss << i;
		m_numbers[i] = new CBString(ss.str(),m_fontSize);
	}
}

void CBNumber::initialNumber(const string& preFileNmae)
{
	for(int i = 0; i <= 9 ; i++)
	{
		string s;
		stringstream ss(s);
		ss << preFileNmae << i << ".png";
		m_numbers[i] = new CBImage(ss.str());
	}
}

void CBNumber::draw()
{
	if(!this->getVisible())
		return;
	int index;
	float x = this->getX();
	float y = this->getY();
	if(m_numberFill == NumberFillZero)
	{
		for(int i = 0, j = 0 ; i < m_maxNumbers ; i++)
		{
			if((m_maxNumbers - i) <= m_text.size())
			{
				index = m_text[j++] - ASCII_INT_0;
			}
			else
			{
				index = 0;
			}
			m_numbers[index]->setColor(m_color.r, m_color.g, m_color.b, m_color.a);
			m_numbers[index]->moveToAbsolute(x, y);
			m_numbers[index]->visit();
			x += m_numbers[index]->getWidth();
		}
	}
	else
	{
		for(int i = 0 ; i < m_text.size() ; i++)
		{
			index = m_text[i] - ASCII_INT_0;
			m_numbers[index]->setColor(m_color.r, m_color.g, m_color.b, m_color.a);
			m_numbers[index]->moveToAbsolute(x, y);
			m_numbers[index]->visit();
			x += m_numbers[index]->getWidth();
		}
	}
}
