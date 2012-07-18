//
//  CBiOSAudioManager.h
//  CloudBox Cross-Platform Framework Project
//
//  Created by Hsu Cloud on 2012/6/24.
//  Copyright 2012 Orz. All rights reserved.
//

#ifndef _CBIOSAUDIOMANAGER_H_
#define _CBIOSAUDIOMANAGER_H_

#import "CBAudioBase.h"

class CBiOSAudioManager : public CBAudioBase
{
public:
    CBiOSAudioManager();
    ~CBiOSAudioManager();
    void loadMusic(const string fileName);
    void releaseMusic();
    void playMusic();
    void stopMusic();
    void pauseMusic();
    void resumeMusic();
    
    float getVolume();
    void setVolume(float volume);
};

#endif