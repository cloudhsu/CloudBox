package com.clouddevelop.cloudbox;

import java.lang.ref.WeakReference;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.content.DialogInterface;
import android.hardware.SensorManager;
import android.media.AudioManager;
import android.media.SoundPool;
import android.os.Handler;
import android.os.Message;
import android.util.Log;

public class CBUtility {
	private static Activity MainActivity;
	
	private static Handler handler;
    private final static int HANDLER_SHOW_DIALOG = 1;
    private final static int HANDLER_SHOW_DIALOG_WITH_TYPE = 2;
    
    private final static int DialogTypeClose = 0;
    private final static int DialogTypeOK = 1;
    private final static int DialogTypeCancel = 2;
    private final static int DialogTypeOKCancel = 3;
    private final static int DialogTypeYesNo = 4;
    private final static int DialogTypeRate = 5;
    
    private final static int DialogResultNone = 0;
    private final static int DialogResultOK = 1;
    private final static int DialogResultCancel = 2;
    private final static int DialogResultYes = 3;
    private final static int DialogResultNo = 4;
    private final static int DialogResultAbort = 5;
    private final static int DialogResultRetry = 6;
    private final static int DialogResultIgnore = 7;
    private final static int DialogResultRateMe = 8;
    private final static int DialogResultRateCancel = 9;
    private final static int DialogResultRateNever = 10;
    
    private static native void nativeAlertEvent(int dialogType, int dialogResult, int buttonIndex);
    
    public static String PackageName;
    private static CBAudioManager AudioManager;
    private static CBEffectManager EffectManager;
    private static CBMotion Motion;
    
    public static void initUtility(Activity activity)
    {
    	MainActivity = activity;
    	AudioManager = new CBAudioManager();
    	EffectManager = new CBEffectManager();
    	PackageName = activity.getPackageName();
    	if(handler == null)
    	{
    		handler = new Handler(){
    			public void handleMessage(Message msg){
    				switch(msg.what){
    				case HANDLER_SHOW_DIALOG:
    					showDialog(((DialogMessage)msg.obj).title, ((DialogMessage)msg.obj).message);
    					break;
    				case HANDLER_SHOW_DIALOG_WITH_TYPE:
    					showDialog(((DialogMessage)msg.obj).type,((DialogMessage)msg.obj).title, ((DialogMessage)msg.obj).message);
    					break;
    				}
    			}
    		};
    	}
    }
    
    public static Activity getMainActivity()
    {
    	return MainActivity;
    }

	public static String getCurrentLanguage() {
    	String languageName = java.util.Locale.getDefault().getLanguage();
    	return languageName;
    }
	
	//--------------------------------------------------------------------------
	// For Dialog
	public static void showMessageBox(int type, String title, String message){
    	Message msg = new Message();
    	msg.what = HANDLER_SHOW_DIALOG_WITH_TYPE;
    	msg.obj = new DialogMessage(type,title, message);
    	
    	handler.sendMessage(msg);
    }
    
    public static void showMessageBox(String title, String message){
    	Message msg = new Message();
    	msg.what = HANDLER_SHOW_DIALOG;
    	msg.obj = new DialogMessage(title, message);
    	
    	handler.sendMessage(msg);
    }
    
    private static void showDialog(String title, String message){
    	Dialog dialog = new AlertDialog.Builder(new WeakReference<Activity>(MainActivity).get())
	    .setTitle(title)
	    .setMessage(message)
	    .setPositiveButton("Close",
	    new DialogInterface.OnClickListener()
	    {
	    	public void onClick(DialogInterface dialog, int whichButton){
	    		nativeAlertEvent(DialogTypeClose, DialogResultOK, 0);
	    	}
	    }).create();

	    dialog.show();
    }
    
    private static void showDialog(int type, String title, String message){
    	Dialog dialog = null;
    	if(type == CBUtility.DialogTypeClose)
    	{
    		dialog = new AlertDialog.Builder(new WeakReference<Activity>(MainActivity).get())
    		.setTitle(title)
    		.setMessage(message)
    		.setPositiveButton("Close",
    				new DialogInterface.OnClickListener()
    		{
    			public void onClick(DialogInterface dialog, int whichButton){
    				nativeAlertEvent(DialogTypeClose, DialogResultOK, 0);
    				dialog.dismiss();
    			}
	    	}).create();
    	}
    	else if(type == CBUtility.DialogTypeOK)
    	{
    		dialog = new AlertDialog.Builder(new WeakReference<Activity>(MainActivity).get())
    		.setTitle(title)
    		.setMessage(message)
    		.setPositiveButton("OK",
    				new DialogInterface.OnClickListener()
    		{
    			public void onClick(DialogInterface dialog, int whichButton){
    				nativeAlertEvent(DialogTypeOK, DialogResultOK, 0);
    				dialog.dismiss();
    			}
	    	}).create();
    	}
    	else if(type == CBUtility.DialogTypeCancel)
    	{
    		dialog = new AlertDialog.Builder(new WeakReference<Activity>(MainActivity).get())
    		.setTitle(title)
    		.setMessage(message)
    		.setPositiveButton("Cancel",
    				new DialogInterface.OnClickListener()
    		{
    			public void onClick(DialogInterface dialog, int whichButton){
    				nativeAlertEvent(DialogTypeCancel, DialogResultCancel, 0);
    				dialog.dismiss();
    			}
	    	}).create();
    	}
    	else if(type == CBUtility.DialogTypeOKCancel)
    	{
    		dialog = new AlertDialog.Builder(new WeakReference<Activity>(MainActivity).get())
    		.setTitle(title)
    		.setMessage(message)
    		.setPositiveButton("OK",
    				new DialogInterface.OnClickListener()
    		{
    			public void onClick(DialogInterface dialog, int whichButton){
    				nativeAlertEvent(DialogTypeOKCancel, DialogResultOK, 0);
    				dialog.dismiss();
    			}
	    	})
    		.setNegativeButton("Cancel",
    				new DialogInterface.OnClickListener()
    		{
    			public void onClick(DialogInterface dialog, int whichButton){
    				nativeAlertEvent(DialogTypeOKCancel, DialogResultCancel, 1);
    				dialog.dismiss();
    			}
	    	}).create();
    	}
    	else if(type == CBUtility.DialogTypeYesNo)
    	{
    		dialog = new AlertDialog.Builder(new WeakReference<Activity>(MainActivity).get())
    		.setTitle(title)
    		.setMessage(message)
    		.setPositiveButton("Yes",
    				new DialogInterface.OnClickListener()
    		{
    			public void onClick(DialogInterface dialog, int whichButton){
    				nativeAlertEvent(DialogTypeYesNo, DialogResultYes, 0);
    				dialog.dismiss();
    			}
	    	})
	    	.setNegativeButton("No",
    				new DialogInterface.OnClickListener()
    		{
    			public void onClick(DialogInterface dialog, int whichButton){
    				nativeAlertEvent(DialogTypeYesNo, DialogResultNo, 1);
    				dialog.dismiss();
    			}
	    	}).create();
    	}
    	else if(type == CBUtility.DialogTypeRate)
    	{
    		dialog = new AlertDialog.Builder(new WeakReference<Activity>(MainActivity).get())
    		.setTitle(title)
    		.setMessage(message)
    		.setPositiveButton("Rate",
    				new DialogInterface.OnClickListener()
    		{
    			public void onClick(DialogInterface dialog, int whichButton){
    				nativeAlertEvent(DialogTypeRate, DialogResultRateMe, 0);
    				dialog.dismiss();
    			}
	    	})
	    	.setNeutralButton("Cancel",
            new DialogInterface.OnClickListener() {
                public void onClick(DialogInterface dialog, int id) {
                	nativeAlertEvent(DialogTypeRate, DialogResultRateCancel, 1);
                	dialog.dismiss();
                }
            })
	    	.setNegativeButton("Never",
    				new DialogInterface.OnClickListener()
    		{
    			public void onClick(DialogInterface dialog, int whichButton){
    				nativeAlertEvent(DialogTypeRate, DialogResultRateNever, 2);
    				dialog.dismiss();
    			}
	    	})
	    	.create();
    	}

	    dialog.show();
    }
    
    //--------------------------------------------------------------------------
  	// For Music
    public static void loadMusic(String fileName)
	{
    	AudioManager.loadMusic(fileName);
	}
	public static void releaseMusic()
    {
		AudioManager.releaseMusic();
    }
	public static void playMusic()
    {
		AudioManager.playMusic();
    }
	public static void stopMusic()
    {
		AudioManager.stopMusic();
    }
	public static void pauseMusic()
    {
		AudioManager.pauseMusic();
    }
	public static void resumeMusic()
    {
		AudioManager.resumeMusic();
    }
    
	public static float getMusicVolume()
    {
		return AudioManager.getVolume();
    }
	public static void setMusicVolume(float volume)
    {
		AudioManager.setVolume(volume);
    }
	//--------------------------------------------------------------------------
  	// For Effect
	public static void initialEffect()
	{
		EffectManager.initialEffect();
	}
	
    // using wave file.
	public static void loadEffect(String fileName)
    {
		EffectManager.loadEffect(fileName);
    }
	
	public static void releaseAllEffect()
    {
		EffectManager.releaseAllEffect();
    }
	public static void playEffect(String fileName)
    {
		EffectManager.playEffect(fileName);
    }
	public static void stopEffect(String fileName)
    {
		EffectManager.stopEffect(fileName);
    }
    
	public static float getEffectVolume()
    {
		return EffectManager.getVolume();
    }
	public static void setEffectVolume(float volume)
    {
		EffectManager.setVolume(volume);
    }
	//--------------------------------------------------------------------------
  	// For Motion
	public static void startAccelerometer()
	{
		if(Motion == null)
			Motion = new CBMotion();
		Motion.startAccelerometer();
	}

    public static void stopAccelerometer()
    {
    	Motion.stopAccelerometer();
    }
}

class DialogMessage {
	public int type;
	public String title;
	public String message;
	
	public DialogMessage(String title, String message){
		type = 0;
		this.message = message;
		this.title = title;
	}
	public DialogMessage(int type,String title, String message){
		this.type = type;
		this.message = message;
		this.title = title;
	}
}