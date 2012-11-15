/*
 *  CBDelegateImpl.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/8/14.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 *
 */

#if (PARAMETER_COUNT == 0)
// ,typename T0, typename T1, typename t2
#define PARAMETERS_TEMPLATE
// ,T0, T1, T2
#define PARAMETERS_TEMPLATE_PARAMETER
// T0, T1, T2
#define PARAMETERS_TEMPLATE_ARGS
// T0 t0, T1 t1, T2 t2
#define PARAMETERS_FUNCTION
// t0,t1,t2
#define PARAMETERS_FUNCTION_ARGS
#endif

#if (PARAMETER_COUNT == 1)
// ,typename T0, typename T1, typename t2
#define PARAMETERS_TEMPLATE , typename T0
// ,T0, T1, T2
#define PARAMETERS_TEMPLATE_PARAMETER ,T0
// T0, T1, T2
#define PARAMETERS_TEMPLATE_ARGS T0
// T0 t0, T1 t1, T2 t2
#define PARAMETERS_FUNCTION T0 t0
// t0,t1,t2
#define PARAMETERS_FUNCTION_ARGS t0
#endif

#if (PARAMETER_COUNT == 2)
// ,typename T0, typename T1, typename t2
#define PARAMETERS_TEMPLATE , typename T0, typename T1
// ,T0, T1, T2
#define PARAMETERS_TEMPLATE_PARAMETER ,T0, T1
// T0, T1, T2
#define PARAMETERS_TEMPLATE_ARGS T0,T1
// T0 t0, T1 t1, T2 t2
#define PARAMETERS_FUNCTION T0 t0, T1 t1
// t0,t1,t2
#define PARAMETERS_FUNCTION_ARGS t0, t1
#endif

#if (PARAMETER_COUNT == 3)
// ,typename T0, typename T1, typename t2
#define PARAMETERS_TEMPLATE , typename T0, typename T1, typename T2
// ,T0, T1, T2
#define PARAMETERS_TEMPLATE_PARAMETER ,T0, T1, T2
// T0, T1, T2
#define PARAMETERS_TEMPLATE_ARGS T0,T1,T2
// T0 t0, T1 t1, T2 t2
#define PARAMETERS_FUNCTION T0 t0, T1 t1, T2 t2
// t0,t1,t2
#define PARAMETERS_FUNCTION_ARGS t0, t1, t2
#endif

#if (PARAMETER_COUNT == 4)
// ,typename T0, typename T1, typename t2
#define PARAMETERS_TEMPLATE , typename T0, typename T1, typename T2, typename T3
// ,T0, T1, T2
#define PARAMETERS_TEMPLATE_PARAMETER ,T0, T1, T2, T3
// T0, T1, T2
#define PARAMETERS_TEMPLATE_ARGS T0,T1,T2,T3
// T0 t0, T1 t1, T2 t2
#define PARAMETERS_FUNCTION T0 t0, T1 t1, T2 t2, T3 t3
// t0,t1,t2
#define PARAMETERS_FUNCTION_ARGS t0, t1, t2, t3
#endif

#if (PARAMETER_COUNT == 5)
// ,typename T0, typename T1, typename t2
#define PARAMETERS_TEMPLATE , typename T0, typename T1, typename T2, typename T3, typename T4
// ,T0, T1, T2
#define PARAMETERS_TEMPLATE_PARAMETER ,T0, T1, T2, T3, T4
// T0, T1, T2
#define PARAMETERS_TEMPLATE_ARGS T0,T1,T2,T3,T4
// T0 t0, T1 t1, T2 t2
#define PARAMETERS_FUNCTION T0 t0, T1 t1, T2 t2, T3 t3, T4 t4
// t0,t1,t2
#define PARAMETERS_FUNCTION_ARGS t0, t1, t2, t3, t4
#endif


template<typename RVALUE PARAMETERS_TEMPLATE>
class CBDelegate< RVALUE (PARAMETERS_TEMPLATE_ARGS) >
{
private:
    class DelegateBase
    {
    public:
        DelegateBase() {}
        virtual ~DelegateBase() {}
        virtual RVALUE invoke(PARAMETERS_FUNCTION) = 0;
    };

    class DelegateFunc : public DelegateBase
    {
    private:
        typedef RVALUE (*FUNC)(PARAMETERS_TEMPLATE_ARGS);
        FUNC m_func;
    public:
        DelegateFunc(FUNC func)
        {
            m_func = func;
        }
        RVALUE invoke(PARAMETERS_FUNCTION)
        {
            return m_func(PARAMETERS_FUNCTION_ARGS);
        }
    };

    template<typename TInstance>
    class DelegateClass : public DelegateBase
    {
    private:
        TInstance* m_instance;
        typedef RVALUE (TInstance::*FUNC)(PARAMETERS_TEMPLATE_ARGS);
        FUNC m_func;
    public:
        DelegateClass(TInstance* instance,FUNC func)
        {
            m_instance = instance;
            m_func = func;
        }
        RVALUE invoke(PARAMETERS_FUNCTION)
        {
            return (m_instance->*m_func)(PARAMETERS_FUNCTION_ARGS);
        }
    };

private:
    DelegateBase* m_delegate;
public:
    CBDelegate(){}
    virtual ~CBDelegate(){ delete m_delegate; }

    void initDelegate(RVALUE (*Func)(PARAMETERS_TEMPLATE_ARGS))
    {
        m_delegate = new DelegateFunc(Func);
    }

    template<typename TInstance>
    void initDelegate(TInstance* instance,RVALUE (TInstance::*Func)(PARAMETERS_TEMPLATE_ARGS))
    {
        m_delegate = new DelegateClass<TInstance>(instance,Func);
    }
    RVALUE invoke(PARAMETERS_FUNCTION)
    {
        return m_delegate->invoke(PARAMETERS_FUNCTION_ARGS);
    }
public:
    CBDelegate* operator*()
    {
        return this;
    }
    //operator
    CBDelegate* operator=(CBDelegate* d)
    {
        if (this == d)
            return this;
        return d;
    }

    CBDelegate* operator->()
    {
        return this;
    }
};


#undef PARAMETERS_TEMPLATE
#undef PARAMETERS_TEMPLATE_PARAMETER
#undef PARAMETERS_TEMPLATE_ARGS
#undef PARAMETERS_FUNCTION
#undef PARAMETERS_FUNCTION_ARGS