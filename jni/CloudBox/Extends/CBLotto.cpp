//
//  CBLotto.cpp
//  CloudBox Cross-Platform Framework Project
//
//  Created by Cloud on 2011/1/16.
//  Copyright 2011 Cloud Hsu. All rights reserved.
//

#include <stdlib.h>
#include <time.h>
#include "CBLotto.h"

CBLotto::CBLotto()
{
	// constructor
	m_showBalls = 6;
	m_lottoTpye = TW_WILI;
}

CBLotto::~CBLotto()
{
	// Deconstructor
}

void CBLotto::setLottoType(LottoType lottoType)
{
	m_lottoTpye = lottoType;
}

LottoType CBLotto::getLottoType()
{
	return m_lottoTpye;
}

int CBLotto::random()
{
	return rand();
}

void CBLotto::SortLotto(int* lotto,int length)
{
	for(int i = length; i >= 0 ;i--)
	{
		for(int j = 0 ; j < i-1 ; j++)
		{
			if(lotto[j] > lotto[j+1])
			{
				int temp = lotto[j];
				lotto[j] = lotto[j+1];
				lotto[j+1] = temp;
			}
		}
	}
}

void CBLotto::RandmonLoto(int* lotto,int max,int length)
{
	srand(time(NULL));
	for(int i = 0; i < length ;)
	{
		bool isNew = true;
		int number = random()% max + 1;
		for(int j = 0; j < i ; j++)
		{
			if(number == lotto[j])
			{
				isNew = false;
				break;
			}
		}
		if(isNew)
		{
			lotto[i] = number;
			i++;
		}
	}
	SortLotto(lotto,length);
}

int* CBLotto::TW_Wili()
{
	m_showBalls = 7;
	m_showBalls1 = 6;
	int* lotto = new int[7];
	RandmonLoto(lotto,38,6);
	lotto[6] = random()% 8 + 1;
	return lotto;
}
int* CBLotto::TW_Big()
{
	m_showBalls = 6;
	m_showBalls1 = 6;
	int* lotto = new int[6];
	RandmonLoto(lotto,49,6);
	return lotto;
}
int* CBLotto::USA_Mega()
{
	m_showBalls = 6;
	m_showBalls1 = 5;
	int* lotto = new int[6];
	RandmonLoto(lotto,56,5);
	lotto[5] = random()% 46 + 1;
	return lotto;
}
int* CBLotto::USA_Power()
{
	m_showBalls = 6;
	m_showBalls1 = 5;
	int* lotto = new int[6];
	RandmonLoto(lotto,59,5);
	lotto[5] = random()% 39 + 1;
	return lotto;
}
int* CBLotto::JP_Mini()
{
	m_showBalls = 5;
	m_showBalls1 = 5;
	int* lotto = new int[5];
	RandmonLoto(lotto,31,5);
	return lotto;
}
int* CBLotto::JP_SIX()
{
	m_showBalls = 6;
	m_showBalls1 = 5;
	int* lotto = new int[6];
	RandmonLoto(lotto,43,6);
	return lotto;
}

int* CBLotto::CN_Double()
{
	m_showBalls = 7;
	m_showBalls1 = 6;
	int* lotto = new int[7];
	RandmonLoto(lotto,33,6);
	lotto[6] = random()% 16 + 1;
	return lotto;
}

int* CBLotto::CN_Lotto()
{
	m_showBalls = 7;
	m_showBalls1 = 5;
	int* lotto = new int[7];
	RandmonLoto(lotto,35,5);
	RandmonLoto(&lotto[5],12,2);
	return lotto;
}

int* CBLotto::getLotto()
{
	return getLotto(m_lottoTpye);
}

int* CBLotto::getLotto(LottoType lottoType)
{
	int* lotto;
	switch (lottoType) {
		case TW_WILI:
			lotto = TW_Wili();
			break;
		case TW_BIG:
			lotto = TW_Big();
			break;
		case USA_MEGA:
			lotto = USA_Mega();
			break;
		case USA_POWER:
			lotto = USA_Power();
			break;
		case JP_MINI:
			lotto = JP_Mini();
			break;
		case JP_LOTO6:
			lotto = JP_SIX();
			break;
		case CN_DOUBLE:
			lotto = CN_Double();
			break;
		case CN_LOTTO:
			lotto = CN_Lotto();
			break;
		default:
			break;
	}
	return lotto;
}
