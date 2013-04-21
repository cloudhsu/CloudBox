/*
 *  CBSubjectMediator.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/03/14.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#ifndef __CBSUBJECTMEDIATOR_H__
#define __CBSUBJECTMEDIATOR_H__

#include "CBLibrary.h"
#include "CBObserver.h"
#include <vector>
using namespace std;

template <class TSubjectObject>
class CBSubjectMediator
{
public:
    typedef TSubjectObject* TSubjectObjectPtr;
protected:
    vector<CBObserver<TSubjectObjectPtr>* > m_observers;
public:
    CBSubjectMediator() {}

    virtual ~CBSubjectMediator()
    {
        for (int i = 0; i < m_observers.size(); i++) {
            CBDELETE(m_observers[i]);
        }
        m_observers.clear();
    }

    void attachObserver(CBObserver<TSubjectObjectPtr>* observer)
    {
        m_observers.push_back(observer);
    }
    void detachObserver(CBObserver<TSubjectObjectPtr>* observer)
    {
        CBObserver<TSubjectObjectPtr>* removeObserver = NULL;
        for (int i = 0; i < m_observers.size(); i++) {
            removeObserver = m_observers[i];
            if(removeObserver->getId() == observer->getId())
            {
                m_observers.erase(m_observers.begin() + i);
                break;
            }
        }
    }

    void notify(TSubjectObjectPtr object)
    {
        for (int i = 0; i < m_observers.size(); i++) {
            m_observers[i]->update(object);
        }
    }
};

#endif