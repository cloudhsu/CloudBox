package com.clouddevelop.cloudbox;

import android.content.Context;
import android.content.res.Configuration;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.view.Display;
import android.view.Surface;
import android.view.WindowManager;

public class CBMotion implements SensorEventListener {
	
	private static final String TAG = "CloudBoxAccelerometer";
	private Context mContext;
	private SensorManager mSensorManager;
	private Sensor mAccelerometer;
	private int mNaturalOrientation;
	
	public CBMotion()
	{
		mContext = CBUtility.getMainActivity();

		//Get an instance of the SensorManager
	    mSensorManager = (SensorManager) mContext.getSystemService(Context.SENSOR_SERVICE);
	    mAccelerometer = mSensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
	    
	    Display display = ((WindowManager)mContext.getSystemService(Context.WINDOW_SERVICE)).getDefaultDisplay();
	    mNaturalOrientation = display.getOrientation();
	}
	
	public void startAccelerometer()
	{
		mSensorManager.registerListener(this, mAccelerometer, SensorManager.SENSOR_DELAY_GAME);
	}

    public void stopAccelerometer()
    {
    	mSensorManager.unregisterListener(this);
    }

	public void onAccuracyChanged(Sensor arg0, int arg1) {
		// TODO Auto-generated method stub
		
	}

	public void onSensorChanged(SensorEvent event) {
		// TODO Auto-generated method stub
		if (event.sensor.getType() != Sensor.TYPE_ACCELEROMETER){
            return;
		}

		float x = event.values[0];
		float y = event.values[1];
		float z = event.values[2];
		
		int orientation = mContext.getResources().getConfiguration().orientation;
		if ((orientation == Configuration.ORIENTATION_LANDSCAPE) && (mNaturalOrientation != Surface.ROTATION_0)){
			float tmp = x;
			x = y;
			y = tmp;
		}
				
        //onSensorChanged(x, y, z, event.timestamp);
		onSensorChanged(x, y* 0.1f, z);
	}
	//private static native void onSensorChanged(float x, float y, float z, long timeStamp);
	private static native void onSensorChanged(float x, float y, float z);
}
