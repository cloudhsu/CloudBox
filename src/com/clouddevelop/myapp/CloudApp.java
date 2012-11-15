/*
 *  CloudApp.java
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2012/1/17.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

package com.clouddevelop.myapp;

import android.app.Activity;
import android.content.pm.ActivityInfo;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.util.DisplayMetrics;
import android.util.Log;
import android.view.Window;
import android.view.WindowManager;
import com.clouddevelop.cloudbox.*;

public class CloudApp extends Activity {
	private GLSurfaceView mGLView;

	static
	{
		System.loadLibrary("cloudbox-app");
	}

	@Override
	protected void onCreate(Bundle savedInstanceState)
	{
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		super.onCreate(savedInstanceState);
		getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
				WindowManager.LayoutParams.FLAG_FULLSCREEN);
		CBUtility.initUtility(this);
		getWindow().setFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON, WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);  
		//set orientation
		//setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_PORTRAIT);
		setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE);
		DisplayMetrics displaymetrics = new DisplayMetrics();
        getWindowManager().getDefaultDisplay().getMetrics(displaymetrics);
        int ht = displaymetrics.heightPixels;
        int wt = displaymetrics.widthPixels;
		mGLView = new CloudGLSurface(this,wt,ht);
		setContentView(mGLView);
		Log.i("cloudbox-app", "GLSurfaceView.onCreate");
	}
    
	@Override
	protected void onPause()
	{
		Log.i("cloudbox-app", "GLSurfaceView.onPause");
		super.onPause();
		mGLView.onPause();
	}

	@Override
	protected void onResume()
	{
		Log.i("cloudbox-app", "GLSurfaceView.onResume");
		super.onResume();
		mGLView.onResume();
	}
}
