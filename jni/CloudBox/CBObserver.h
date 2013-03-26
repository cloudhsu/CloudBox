/*
 *  CBObserver.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/03/14.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#ifndef __CBOBSERVER_H__
#define __CBOBSERVER_H__

template<class TSubjectObject>
class CBObserver
{
protected:
    int m_id;
public:
    CBObserver() {}
    virtual ~CBObserver() {}

    inline int getId() const { return m_id; }
    inline void setId(int val) { m_id = val; }

    virtual void update(TSubjectObject object) = 0;
};

#endif