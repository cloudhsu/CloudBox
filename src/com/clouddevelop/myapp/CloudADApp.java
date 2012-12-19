package com.clouddevelop.myapp;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.pm.ActivityInfo;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.util.DisplayMetrics;
import android.util.Log;
import android.view.KeyEvent;
import android.view.ViewGroup.LayoutParams;
import android.view.Window;
import android.view.WindowManager;
import android.widget.FrameLayout;

import com.clouddevelop.cloudbox.CBUtility;
import com.clouddevelop.cloudbox.CloudGLSurface;
import com.google.ads.AdRequest;
import com.google.ads.AdSize;
import com.google.ads.AdView;


public class CloudADApp extends Activity {
	
	private GLSurfaceView mGLView;
	FrameLayout m_layout;
	AdView adView;

	static
	{
		System.loadLibrary("cloudbox-app");
	}
	
	String adKey = "a14f15762b68302";

	@Override
	protected void onCreate(Bundle savedInstanceState)
	{
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		super.onCreate(savedInstanceState);
		CBUtility.initUtility(this);
		getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
				WindowManager.LayoutParams.FLAG_FULLSCREEN);
		getWindow().setFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON, WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
		//set orientation
		setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_PORTRAIT);
		DisplayMetrics displaymetrics = new DisplayMetrics();
        getWindowManager().getDefaultDisplay().getMetrics(displaymetrics);
        int ht = displaymetrics.heightPixels;
        int wt = displaymetrics.widthPixels;
        mGLView = new CloudGLSurface(this,wt,ht);
		//setContentView(mGLView);
		Log.i("cloudbox-app", "CloudLedApp.onCreate");
		
		// Create the adView
	    adView = new AdView(this, AdSize.BANNER, adKey);		
	    FrameLayout.LayoutParams layoutParams1 = new
	    		FrameLayout.LayoutParams(LayoutParams.MATCH_PARENT,
				                            LayoutParams.MATCH_PARENT);
	    FrameLayout.LayoutParams layoutParams2 = new
	    		FrameLayout.LayoutParams(LayoutParams.MATCH_PARENT,
				                            LayoutParams.WRAP_CONTENT);
		 
		m_layout = new FrameLayout(this);
		
		m_layout.addView(mGLView, layoutParams1);
		m_layout.addView(adView, layoutParams2);
		setContentView(m_layout);
		m_layout.invalidate();
		// Initiate a generic request to load it with an ad
	    adView.loadAd(new AdRequest());
	    Log.i("cloudbox-app", "CloudLedApp.loadAd");
	}
    
	@Override
	protected void onPause()
	{
		Log.i("cloudbox-app", "CloudLedApp.onPause");
		super.onPause();
		mGLView.onPause();
	}

	@Override
	protected void onResume()
	{
		Log.i("cloudbox-app", "CloudLedApp.onResume");
		super.onResume();
		mGLView.onResume();
	}

	public void adWhirlGeneric() {
		// TODO Auto-generated method stub
		Log.i("cloudbox-app", "CloudLedApp.adWhirlGeneric");
	}

	@Override
	protected void onDestroy() {
		// TODO Auto-generated method stub
		adView.destroy();
		super.onDestroy();
	}

	@Override
	public boolean onKeyDown(int keyCode, KeyEvent event) {
		if (keyCode == KeyEvent.KEYCODE_BACK) {
			// This function will move task to back
	        //moveTaskToBack(true);
			// Confirm to exit and delete process
			new AlertDialog.Builder(this)
			.setTitle("  ")
			.setMessage("Do you want to exit?")
			.setPositiveButton("No", new DialogInterface.OnClickListener() {
			public void onClick(DialogInterface dialog, int which) {
			 
			}
			}).setNeutralButton("Yes", new DialogInterface.OnClickListener() {
			 public void onClick(DialogInterface dialog, int which) {
			     finish();
			     System.exit(0);
			 }
			}).create().show();
	        return true;
	    }
		// TODO Auto-generated method stub
		return super.onKeyDown(keyCode, event);
	}
}
