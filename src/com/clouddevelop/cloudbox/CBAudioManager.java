/*
 *  CBAudioManager.java
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2012/7/11.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

package com.clouddevelop.cloudbox;

import android.content.Context;
import android.content.res.AssetFileDescriptor;
import android.media.MediaPlayer;
import android.util.Log;

public class CBAudioManager
{
	private static final String TAG = "cloudbox-app";
	private float mLeftVolume;
	private float mRightVolume;
	private Context mContext;
	private MediaPlayer mBackgroundMediaPlayer;
	private boolean mIsPaused;
	
	public CBAudioManager()
	{
		mLeftVolume = 0.5f;
		mRightVolume = 0.5f;
		mContext = CBInstance.MainActivity;
		mIsPaused = false;
	}
	
	public void loadMusic(String fileName)
	{
		if (mBackgroundMediaPlayer != null){
			mBackgroundMediaPlayer.release();
		}
		mBackgroundMediaPlayer = createMediaplayerFromAssets(fileName);
		mBackgroundMediaPlayer.setLooping(true);
		try {
			mBackgroundMediaPlayer.prepare();
			mBackgroundMediaPlayer.seekTo(0);
		} catch (Exception e){
			e.printStackTrace();
		}
	}
	public void releaseMusic()
    {
		if (mBackgroundMediaPlayer != null){
			mBackgroundMediaPlayer.release();
		}
    }
	public void playMusic()
    {
		if (mBackgroundMediaPlayer == null){
			Log.e(TAG, "playBackgroundMusic: background media player is null");
		} else {		
			// if the music is playing or paused, stop it
			mBackgroundMediaPlayer.stop();			
			mBackgroundMediaPlayer.start();		
		}
    }
	public void stopMusic()
    {
		if (mBackgroundMediaPlayer != null){
			mBackgroundMediaPlayer.stop();
			mBackgroundMediaPlayer.seekTo(0);
			this.mIsPaused = false;
		}
    }
	public void pauseMusic()
    {
		if (mBackgroundMediaPlayer != null && mBackgroundMediaPlayer.isPlaying()){
			mBackgroundMediaPlayer.pause();
			this.mIsPaused = true;
		}
    }
	public void resumeMusic()
    {
		if (mBackgroundMediaPlayer != null && this.mIsPaused){
			mBackgroundMediaPlayer.start();
			this.mIsPaused = false;
		}
    }
    
	public float getVolume()
    {
		if (this.mBackgroundMediaPlayer != null){
			return (this.mLeftVolume + this.mRightVolume) / 2;
		} else {
			return 0.0f;
		}
    }
	public void setVolume(float volume)
    {
		if (volume < 0.0f){
			volume = 0.0f;
		}
		
		if (volume > 1.0f){
			volume = 1.0f;
		}
		
	    this.mLeftVolume = this.mRightVolume = volume;
		if (this.mBackgroundMediaPlayer != null){
			this.mBackgroundMediaPlayer.setVolume(this.mLeftVolume, this.mRightVolume);
		}
    }
	
	private MediaPlayer createMediaplayerFromAssets(String fileName){
		MediaPlayer mediaPlayer = null;
		
		try{			
			AssetFileDescriptor assetFileDescritor = mContext.getAssets().openFd(fileName);
			
			mediaPlayer = new MediaPlayer();
	        mediaPlayer.setDataSource(assetFileDescritor.getFileDescriptor(), 
	        		assetFileDescritor.getStartOffset(), assetFileDescritor.getLength());
	        mediaPlayer.prepare();
	        
	        mediaPlayer.setVolume(mLeftVolume, mRightVolume);
		}catch (Exception e) {
			mediaPlayer = null;
            Log.e(TAG, "error: " + e.getMessage(), e);
        }
		
        return mediaPlayer;
	}
}
