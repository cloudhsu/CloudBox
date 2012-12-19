/*
 *  CBEffectManager.java
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2012/7/11.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

package com.clouddevelop.cloudbox;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

import android.content.Context;
import android.media.AudioManager;
import android.media.SoundPool;
import android.util.Log;


public class CBEffectManager
{
	private Context mContext;
	private SoundPool mSoundPool;
	private float mLeftVolume;
	private float mRightVolume;
	
	// sound id and stream id map
	private HashMap<Integer,Integer> mSoundIdStreamIdMap;
	// sound path and sound id map
	private HashMap<String,Integer> mPathSoundIDMap;
	
	private static final String TAG = "cloudbox-app";
	private static final int MAX_SIMULTANEOUS_STREAMS_DEFAULT = 10;
	private static final float SOUND_RATE = 1.0f;
	private static final int SOUND_PRIORITY = 1;
	private static final int SOUND_QUALITY = 5;
	
	private final int INVALID_SOUND_ID = -1;
	private final int INVALID_STREAM_ID = -1;
	
	public CBEffectManager()
	{
		mContext = CBUtility.getMainActivity();
	}
	
	public void initialEffect()
	{
		this.mSoundIdStreamIdMap = new HashMap<Integer,Integer>();
		mSoundPool = new SoundPool(MAX_SIMULTANEOUS_STREAMS_DEFAULT, AudioManager.STREAM_MUSIC, SOUND_QUALITY);
		mPathSoundIDMap = new HashMap<String,Integer>();
		
		this.mLeftVolume = 0.5f;
		this.mRightVolume = 0.5f;
		Log.i("cloudbox-app", "initialEffect succeed.");
	}
	
	public int createSoundIdFromAsset(String fileName){
		int soundId = INVALID_SOUND_ID;
		
		try {
			soundId = mSoundPool.load(mContext.getAssets().openFd(fileName), 0);
		} catch(Exception e){
			 Log.e(TAG, "error: " + e.getMessage(), e);
		}
		
		return soundId;
	}
	
    // using wave file.
	public void loadEffect(String fileName)
    {
		if(fileName.length() == 0)
			return;
		if(mSoundIdStreamIdMap == null)
		{
			initialEffect();
		}
		int soundId = INVALID_SOUND_ID;
		
		// if the sound is preloaded, pass it
		if (this.mPathSoundIDMap.get(fileName) == null){
			soundId = createSoundIdFromAsset(fileName);
			
			if (soundId != INVALID_SOUND_ID){
				// the sound is loaded but has not been played
				this.mSoundIdStreamIdMap.put(soundId, INVALID_STREAM_ID);
				
				// record path and sound id map
				this.mPathSoundIDMap.put(fileName, soundId);
			}
		}
    }
	
	public void releaseAllEffect()
    {
		if (mSoundPool != null){
			mSoundPool.release();
			mSoundPool = null;
		}
		if (mPathSoundIDMap != null){
			mPathSoundIDMap.clear();
			mPathSoundIDMap = null;
		}
		if (mSoundIdStreamIdMap != null){
			mSoundIdStreamIdMap.clear();
			mSoundIdStreamIdMap = null;
		}
    }
	public void playEffect(String fileName)
    {
		if(fileName == null)
			return;
		if(mPathSoundIDMap == null)
		{
			Log.i("cloudbox-app", "mPathSoundIDMap is null.");
			return;
		}
		Integer soundId = this.mPathSoundIDMap.get(fileName);
		
		if (soundId != null){
			// the sound is preloaded, stop it first
			
			this.mSoundPool.stop(soundId);
			
			// play sound
			int streamId = this.mSoundPool.play(soundId.intValue(), this.mLeftVolume, 
					this.mRightVolume, SOUND_PRIORITY, 0, SOUND_RATE);
			
			// record sound id and stream id map
			this.mSoundIdStreamIdMap.put(soundId, streamId);
		}
		else
		{
			loadEffect(fileName);
			playEffect(fileName);
		}
    }
	public void stopEffect(String fileName)
    {
		Integer soundId = this.mPathSoundIDMap.get(fileName);
		
		if (soundId != null){
			this.stopEffect(soundId);
		}
    }
	
	private void stopEffect(int soundId){
        Integer streamId = this.mSoundIdStreamIdMap.get(soundId);
        
        if (streamId != null && streamId.intValue() != INVALID_STREAM_ID){
        	this.mSoundPool.stop(streamId.intValue());
        	this.mPathSoundIDMap.remove(soundId);
        }
	}
    
	public float getVolume()
    {
    	return (this.mLeftVolume + this.mRightVolume) / 2;
    }
	public void setVolume(float volume)
    {
		if (volume < 0){
			volume = 0;
		}	
		if (volume > 1){
			volume = 1;
		}
		
		this.mLeftVolume = this.mRightVolume = volume;
		
		// change the volume of playing sounds
		Iterator<?> iter = this.mSoundIdStreamIdMap.entrySet().iterator();
		while (iter.hasNext()){
			Map.Entry<Integer, Integer> entry = (Map.Entry<Integer, Integer>)iter.next();
			this.mSoundPool.setVolume(entry.getValue(), mLeftVolume, mRightVolume);
		}
    }
}
