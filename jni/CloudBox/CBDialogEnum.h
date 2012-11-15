/*
 *  CBDialogEnum.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/10/13.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef __CBDIALOGENUM__
#define __CBDIALOGENUM__

enum DialogResult
{
    DialogResultNone = 0,
    DialogResultOK = 1,
    DialogResultCancel = 2,
    DialogResultYes = 3,
    DialogResultNo = 4,
    DialogResultAbort = 5,
    DialogResultRetry = 6,
    DialogResultIgnore = 7,
    DialogResultRateMe = 8,
    DialogResultRateCancel = 9,
    DialogResultRateNever = 10
};

enum DialogType
{
    DialogTypeClose = 0,
    DialogTypeOK = 1,
    DialogTypeCancel = 2,
    DialogTypeOKCancel = 3,
    DialogTypeYesNo = 4,
    DialogTypeRate = 5
};

#endif
