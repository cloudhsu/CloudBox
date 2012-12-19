/*
 *  CloudGLSurface.java
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2012/1/17.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

package com.clouddevelop.cloudbox;

import android.content.Context;
import android.graphics.PixelFormat;
import android.opengl.GLSurfaceView;
import android.util.Log;
import android.view.MotionEvent;

public class CloudGLSurface extends GLSurfaceView implements CBIQueneEvent
{
	CloudRenderer mRenderer;

	private static native void nativePause();
	private static native void touchBegan(float x, float y);
	private static native void touchMoved(float x, float y);
	private static native void touchEnded(float x, float y);
	
	public CloudGLSurface(Context context, int w, int h)
	{
		super(context);
		setEGLConfigChooser(8, 8, 8, 8, 0, 0);
		getHolder().setFormat(PixelFormat.RGBA_8888);
		setDebugFlags(DEBUG_CHECK_GL_ERROR | DEBUG_LOG_GL_CALLS);
		Log.i("cloudbox-app", "CloudGLSurface.CloudGLSurface()");
		mRenderer = new CloudRenderer(context,w,h);
		setRenderer(mRenderer);
	}
	
	protected void doTouchEvent(final MotionEvent event)
	{
		try
		{
			if (event.getAction() == MotionEvent.ACTION_DOWN) {
				touchBegan(event.getX(),event.getY());
			}
			else if (event.getAction() == MotionEvent.ACTION_MOVE) {
				touchMoved(event.getX(),event.getY());
			}
			else if (event.getAction() == MotionEvent.ACTION_UP) {
				touchEnded(event.getX(),event.getY());
			}
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}

	public boolean onTouchEvent(final MotionEvent event)
	{
		queueEvent(new Runnable() {
            public void run() {
            	doTouchEvent(event);
            }
        });
//		doTouchEvent(event);
		return true;
	}
	@Override
	public void onPause() {
		// TODO Auto-generated method stub
		super.onPause();
		queueEvent(new Runnable() {
            public void run() {
            	nativePause();
            }
        });
	}
	@Override
	public void onResume() {
		// TODO Auto-generated method stub
		super.onResume();
		mRenderer.setResume(true);
	}
	
	@Override
	public void DoQueneEvent(Runnable run) {
		// TODO Auto-generated method stub
		queueEvent(run);
	}
}

