/*
 *  CloudLed.java
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2012/1/17.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */
/*
 * 2012/7/11 update to with handler
 */
package com.clouddevelop.cloudbox;

import android.hardware.Camera;
import android.os.Handler;
import android.os.Message;
import android.util.Log;

public class CloudLed {
	Camera mCamera;
	
	Handler handler;
	
	private static final int HANDLER_ON_LED = 1;
	private static final int HANDLER_OFF_LED = 2;
	
	public CloudLed()
	{
		handler = new Handler(){
        	public void handleMessage(Message msg){
        		switch(msg.what){
        		case HANDLER_ON_LED:
        			turnOnLed();
        			break;
        		case HANDLER_OFF_LED:
        			turnOffLed();
        			break;
        		}
        	}
        };
	}
	
	void turnOnLed()
	{
		try
		{
			Log.i("cloudbox-app", "CloudLed.turnOnLed()");
			mCamera = Camera.open();
			Camera.Parameters mParameters;
			mParameters = mCamera.getParameters();
			mParameters.setFlashMode(Camera.Parameters.FLASH_MODE_TORCH);
			mCamera.setParameters(mParameters);
		}catch(Exception ex)
		{
			ex.printStackTrace();
		}
	}

	public void turnOn()
	{
		try
		{
			Log.i("cloudbox-app", "CloudLed.turnOn()");
			handler.sendEmptyMessage(HANDLER_ON_LED);
		}catch(Exception ex)
		{
			ex.printStackTrace();
		}
	}
	
	void turnOffLed()
	{
		try
		{
			Log.i("cloudbox-app", "CloudLed.turnOffLed()");
			Camera.Parameters mParameters;
			mParameters = mCamera.getParameters();
			mParameters.setFlashMode(Camera.Parameters.FLASH_MODE_OFF);
			mCamera.setParameters(mParameters);
			mCamera.release();
		}catch(Exception ex)
		{
			ex.printStackTrace();
		}
	}
	
	public void turnOff()
	{
		try
		{
			Log.i("cloudbox-app", "CloudLed.turnOff()");
			handler.sendEmptyMessage(HANDLER_OFF_LED);
		}catch(Exception ex)
		{
			ex.printStackTrace();
		}
	}
}
