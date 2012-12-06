/*
 *  CloudRender.java
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2012/1/17.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

package com.clouddevelop.cloudbox;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.content.Context;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.content.pm.PackageManager.NameNotFoundException;
import android.opengl.GLSurfaceView;
import android.util.Log;

public class CloudRenderer implements GLSurfaceView.Renderer
{
	boolean mResume;
	private Context mContext;
	TextManager mTextManager;
	boolean mInitialed;
	public CloudRenderer (Context context, int w, int h)
	{
		Log.i("cloudbox-app", "CloudRenderer.CloudRenderer()");
		nativeSetsize(w, h);
		this.mContext = context;
		mInitialed = false;
	}
	
	public void onSurfaceCreated(GL10 gl, EGLConfig config)
	{
		Log.i("cloudbox-app", "CloudRenderer.onSurfaceCreated()");
		nativeInitGL();
		if(!mInitialed)
		{
			mInitialed = true;
			String apkFilePath = null;
			ApplicationInfo appInfo = null;
			Log.i("cloudbox-app", "PackageName:" + mContext.getPackageName());
			PackageManager packMgmr = mContext.getPackageManager();
			mTextManager = new TextManager();
			try
			{
				appInfo = packMgmr.getApplicationInfo(mContext.getPackageName(), 0);
			}
			catch (NameNotFoundException e)
			{
				e.printStackTrace();
				throw new RuntimeException("Unable to locate assets, aborting...");
			}
			apkFilePath = appInfo.sourceDir;
			nativeTextInit(mTextManager);
			Log.i("cloudbox-app", "CloudRenderer.onSurfaceCreated() 11111");
			try
			{
				nativeInit(apkFilePath, CBUtility.PackageName);
			}
			catch(Exception e)
			{
				e.printStackTrace();
			}
			Log.i("cloudbox-app", "CloudRenderer.onSurfaceCreated() 22222");
		}
	}

	public void onSurfaceChanged(GL10 gl, int w, int h) {
		Log.i("cloudbox-app", "CloudRenderer.onSurfaceChanged()");
		if(mResume)
		{
			mResume = false;
			nativeResume();
		}
	}

	public void onDrawFrame(GL10 gl) {
		try
		{
			nativeRender();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}

	private static native void nativeInit(final String apkPath,final String packageName);
	private static native void nativeInitGL();
	private static native void nativeResume();
	private static native void nativeTextInit(final TextManager textManager);

	private static native void nativeSetsize(int w, int h);

	private static native void nativeRender();

	public void setResume(boolean resume) {
		this.mResume = resume;
	}
}
