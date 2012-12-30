//
//  CBLotto.h
//  CloudBox Cross-Platform Framework Project
//
//  Created by Cloud on 2011/1/16.
//  Copyright 2011 Cloud Hsu. All rights reserved.
//

#ifndef _CBLOTTO_H_
#define _CBLOTTO_H_

#ifdef __CBBLACKBERRY__
#include "../CBSingleton.h"
#else
#include "CBSingleton.h"
#endif

enum LottoType
{
	TW_WILI = 1,
	TW_BIG = 2,
	USA_MEGA = 3,
	USA_POWER = 4,
	JP_LOTO6 = 5,
	JP_MINI = 6,
	CN_DOUBLE = 7,
	CN_LOTTO = 8
};

class CBLotto : public CBSingleton<CBLotto>
{
private:
	LottoType m_lottoTpye;
	int m_showBalls;
	int m_showBalls1;
	// --- Add private member --- //
	void SortLotto(int* lotto,int length);

	int* TW_Wili();
	int* TW_Big();
	int* USA_Mega();
	int* USA_Power();
	int* JP_Mini();
	int* JP_SIX();
	int* CN_Double();
	int* CN_Lotto();

	int random();

	void RandmonLoto(int* lotto,int max,int length);
public:
	// --- Add public member --- //
	CBLotto();
	~CBLotto();
	
	int getBallNum() { return m_showBalls; }
	int getBall1Num() { return m_showBalls1; }
	int* getLotto();
	int* getLotto(LottoType lottoType);
	void setLottoType(LottoType lottoType);
	LottoType getLottoType();
};

#define SLotto CBLotto::instance()

#endif
