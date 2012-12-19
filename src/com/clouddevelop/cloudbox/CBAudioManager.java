/*
 *  CBAudioManager.java
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2012/7/11.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

package com.clouddevelop.cloudbox;

import android.content.res.AssetFileDescriptor;
import android.media.MediaPlayer;
import android.util.Log;

public class CBAudioManager
{
	private static final String TAG = "cloudbox-app";
	private float mLeftVolume;
	private float mRightVolume;
	private MediaPlayer mBackgroundMediaPlayer;
	private boolean mIsPaused;
	
	public CBAudioManager()
	{
		mLeftVolume = 0.5f;
		mRightVolume = 0.5f;
		//mContext = CBUtility.getMainActivity();
		mIsPaused = false;
	}
	
	public void loadMusic(String fileName)
	{
		if(fileName.length() == 0)
			return;
		releaseMusic();
		mBackgroundMediaPlayer = createMediaplayerFromAssets(fileName);
		mBackgroundMediaPlayer.setLooping(true);
		try
		{
			//mBackgroundMediaPlayer.prepare();
			mBackgroundMediaPlayer.seekTo(0);
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
		Log.e(TAG, "loadMusic succeed.");
	}
	public void releaseMusic()
    {
		if (mBackgroundMediaPlayer != null)
		{
			mBackgroundMediaPlayer.release();
			mBackgroundMediaPlayer = null;
		}
    }
	public void playMusic()
    {
		if (mBackgroundMediaPlayer == null)
		{
			Log.e(TAG, "playBackgroundMusic: background media player is null");
		}
		else {		
			// if the music is playing or paused, stop it
			if(!mBackgroundMediaPlayer.isPlaying())
			{
				try {
					mBackgroundMediaPlayer.prepare();
				} catch (Exception e){
					e.printStackTrace();
				}
				mBackgroundMediaPlayer.start();
			}
		}
    }
	public void stopMusic()
    {
		if (mBackgroundMediaPlayer != null)
		{
			mBackgroundMediaPlayer.stop();
			//mBackgroundMediaPlayer.pause();
			//mBackgroundMediaPlayer.seekTo(0);
			this.mIsPaused = false;
		}
    }
	public void pauseMusic()
    {
		if (mBackgroundMediaPlayer != null && mBackgroundMediaPlayer.isPlaying())
		{
			mBackgroundMediaPlayer.pause();
			this.mIsPaused = true;
		}
    }
	public void resumeMusic()
    {
		if (mBackgroundMediaPlayer != null && this.mIsPaused)
		{
			mBackgroundMediaPlayer.start();
			this.mIsPaused = false;
		}
    }
    
	public float getVolume()
    {
		if (this.mBackgroundMediaPlayer != null)
		{
			return (this.mLeftVolume + this.mRightVolume) / 2;
		}
		else
		{
			return 0.0f;
		}
    }
	public void setVolume(float volume)
    {
		if (volume < 0.0f)
		{
			volume = 0.0f;
		}
		
		if (volume > 1.0f)
		{
			volume = 1.0f;
		}
		
	    this.mLeftVolume = this.mRightVolume = volume;
		if (this.mBackgroundMediaPlayer != null)
		{
			this.mBackgroundMediaPlayer.setVolume(this.mLeftVolume, this.mRightVolume);
		}
    }
	
	private MediaPlayer createMediaplayerFromAssets(String fileName){
		MediaPlayer mediaPlayer = null;
		
		try{			
			AssetFileDescriptor assetFileDescritor = CBUtility.getMainActivity().getAssets().openFd(fileName);
			
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
