package com.clouddevelop.cloudbox;

import java.lang.ref.WeakReference;

import com.clouddevelop.billing.CBBillingManager;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.net.Uri;
import android.os.Handler;
import android.os.Message;

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
    
    private static native void nativeRequestFail(final String msg);
    private static native void nativeCompleteTransaction(final String buyProductTag);
    private static native void nativeFailedTransaction(final String msg, int errorCode);
    private static native void nativeRestoreTransaction(final String buyProductTag);
    private static native void nativePurchasingTransaction(final String buyProductTag);
    private static native void nativeRestoreCompletedTransactionsFinished();
    private static native void nativeRestoreCompletedTransactionsFailed(final String msg, int errorCode);
    
    public static String PackageName;
    private static CBAudioManager AudioManager;
    private static CBEffectManager EffectManager;
    private static CBMotion Motion;
    private static CBIQueneEvent QueneEvent;
    private static CBBillingManager BillingManager;
    
    public static void initQueneEvent(CBIQueneEvent view)
    {
    	QueneEvent = view;
    }
    
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
    
    public static void openUrl(final String url)
    {
    	final String newUrl = new String(url);
    	MainActivity.runOnUiThread(new Runnable() {
            public void run() {
            	MainActivity.startActivity(new Intent(Intent.ACTION_VIEW, Uri.parse(newUrl)));
            }
        });
    }
    
    private static void showDialog(String title, String message){
    	Dialog dialog = new AlertDialog.Builder(new WeakReference<Activity>(MainActivity).get())
	    .setTitle(title)
	    .setMessage(message)
	    .setPositiveButton("Close",
	    new DialogInterface.OnClickListener()
	    {
	    	public void onClick(DialogInterface dialog, int whichButton){
	    		MainActivity.runOnUiThread(new Runnable() {
	                public void run() {
	                	nativeAlertEvent(DialogTypeClose, DialogResultOK, 0);
	                }
	            });
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
    				QueneEvent.DoQueneEvent(new Runnable() {
    	                public void run() {
    	                	nativeAlertEvent(DialogTypeClose, DialogResultOK, 0);
    	                }
    	            });
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
    				QueneEvent.DoQueneEvent(new Runnable() {
    	                public void run() {
    	                	nativeAlertEvent(DialogTypeOK, DialogResultOK, 0);
    	                }
    	            });
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
    				QueneEvent.DoQueneEvent(new Runnable() {
    	                public void run() {
    	                	nativeAlertEvent(DialogTypeCancel, DialogResultCancel, 0);
    	                }
    	            });
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
    				QueneEvent.DoQueneEvent(new Runnable() {
    	                public void run() {
    	                	nativeAlertEvent(DialogTypeOKCancel, DialogResultOK, 0);
    	                }
    	            });
    			}
	    	})
    		.setNegativeButton("Cancel",
    				new DialogInterface.OnClickListener()
    		{
    			public void onClick(DialogInterface dialog, int whichButton){
    				QueneEvent.DoQueneEvent(new Runnable() {
    	                public void run() {
    	                	nativeAlertEvent(DialogTypeOKCancel, DialogResultCancel, 1);
    	                }
    	            });
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
    				QueneEvent.DoQueneEvent(new Runnable() {
    	                public void run() {
    	                	nativeAlertEvent(DialogTypeYesNo, DialogResultYes, 0);
    	                }
    	            });
    			}
	    	})
	    	.setNegativeButton("No",
    				new DialogInterface.OnClickListener()
    		{
    			public void onClick(DialogInterface dialog, int whichButton){
    				QueneEvent.DoQueneEvent(new Runnable() {
    	                public void run() {
    	                	nativeAlertEvent(DialogTypeYesNo, DialogResultNo, 1);
    	                }
    	            });
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
    				QueneEvent.DoQueneEvent(new Runnable() {
    	                public void run() {
    	                	nativeAlertEvent(DialogTypeRate, DialogResultRateMe, 0);
    	                }
    	            });
    			}
	    	})
	    	.setNeutralButton("Cancel",
            new DialogInterface.OnClickListener() {
                public void onClick(DialogInterface dialog, int id) {
                	QueneEvent.DoQueneEvent(new Runnable() {
    	                public void run() {
    	                	nativeAlertEvent(DialogTypeRate, DialogResultRateCancel, 1);
    	                }
    	            });
                }
            })
	    	.setNegativeButton("Never",
    				new DialogInterface.OnClickListener()
    		{
    			public void onClick(DialogInterface dialog, int whichButton){
    				QueneEvent.DoQueneEvent(new Runnable() {
    	                public void run() {
    	                	nativeAlertEvent(DialogTypeRate, DialogResultRateNever, 2);
    	                }
    	            });
    			}
	    	})
	    	.create();
    	}

	    dialog.show();
    }
    
    //--------------------------------------------------------------------------
  	// For Music
    public static void loadMusic(final String fileName)
	{
    	final String newFileName = new String(fileName);
    	MainActivity.runOnUiThread(new Runnable() {
            public void run() {
            	AudioManager.loadMusic(newFileName);
            }});
	}
	public static void releaseMusic()
    {
		MainActivity.runOnUiThread(new Runnable() {
            public void run() {
            	AudioManager.releaseMusic();
            }});
    }
	public static void playMusic()
    {
		MainActivity.runOnUiThread(new Runnable() {
            public void run() {
            	AudioManager.playMusic();
            }});
    }
	public static void stopMusic()
    {
		MainActivity.runOnUiThread(new Runnable() {
            public void run() {
            	AudioManager.stopMusic();
            }});
    }
	public static void pauseMusic()
    {
		MainActivity.runOnUiThread(new Runnable() {
            public void run() {
            	AudioManager.pauseMusic();
            }});
    }
	public static void resumeMusic()
    {
		MainActivity.runOnUiThread(new Runnable() {
            public void run() {
            	AudioManager.resumeMusic();
            }});
    }
    
	public static float getMusicVolume()
    {
		return AudioManager.getVolume();
    }
	public static void setMusicVolume(final float volume)
    {
		MainActivity.runOnUiThread(new Runnable() {
            public void run() {
            	AudioManager.setVolume(volume);
            }});
    }
	//--------------------------------------------------------------------------
  	// For Effect
	public static void initialEffect()
	{
		MainActivity.runOnUiThread(new Runnable() {
            public void run() {
            	EffectManager.initialEffect();
            }});
	}
	
    // using wave file.
	public static void loadEffect(final String fileName)
    {
		final String newFileName = new String(fileName);
		MainActivity.runOnUiThread(new Runnable() {
            public void run() {
            	EffectManager.loadEffect(newFileName);
            }});
    }
	
	public static void releaseAllEffect()
    {
		MainActivity.runOnUiThread(new Runnable() {
            public void run() {
            	EffectManager.releaseAllEffect();
            }});
    }
	public static void playEffect(final String fileName)
    {
		final String newFileName = new String(fileName);
		MainActivity.runOnUiThread(new Runnable() {
            public void run() {
            	EffectManager.playEffect(newFileName);
            }});
    }
	public static void stopEffect(final String fileName)
    {
		final String newFileName = new String(fileName);
		MainActivity.runOnUiThread(new Runnable() {
            public void run() {
            	EffectManager.stopEffect(newFileName);
            }});
    }
    
	public static float getEffectVolume()
    {
		return EffectManager.getVolume();
    }
	public static void setEffectVolume(final float volume)
    {
		MainActivity.runOnUiThread(new Runnable() {
            public void run() {
            	EffectManager.setVolume(volume);
           }});
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
    //--------------------------------------------------------------------------
  	// For In-app billing
    public static void buy(final String buyProductTag)
    {
    	if(BillingManager != null)
    	{
    		final String newBuyProductTag = new String(buyProductTag);
    		MainActivity.runOnUiThread(new Runnable() {
                public void run() {
                	BillingManager.buy(newBuyProductTag);
                }
            });
    	}
    }
    public static boolean isCanBuy()
    {
    	boolean canBuy = false;
    	if(BillingManager != null)
    	{
    		canBuy = BillingManager.isCanBuy();
    	}
    	return canBuy;
    }
    public static void initialStore()
    {
    	if(BillingManager == null)
    	{
    		MainActivity.runOnUiThread(new Runnable() {
                public void run() {
                	BillingManager = new CBBillingManager();
                	BillingManager.initialStore(MainActivity);
                }
            });
    	}
    }
    public static void releaseStore()
    {
    	if(BillingManager != null)
    	{
    		MainActivity.runOnUiThread(new Runnable() {
                public void run() {
                		BillingManager.releaseStore();
                }
            });
    	}
    }
    public static void restoreCompletedTransactions()
    {
    	if(BillingManager != null)
    	{
    		MainActivity.runOnUiThread(new Runnable() {
                public void run() {
                		BillingManager.restoreCompletedTransactions();
                }
            });
    	}
    }
    public static void requestFail(final String msg)
    {
    	QueneEvent.DoQueneEvent(new Runnable() {
            public void run() {
            	nativeRequestFail(msg);
            }
    	});
    }
    public static void completeTransaction(final String buyProductTag)
    {
    	QueneEvent.DoQueneEvent(new Runnable() {
            public void run() {
            	nativeCompleteTransaction(buyProductTag);
            }
    	});
    }
    public static void failedTransaction(final String msg, final int errorCode)
    {
    	QueneEvent.DoQueneEvent(new Runnable() {
            public void run() {
            	nativeFailedTransaction(msg,errorCode);
            }
    	});
    }
    public static void restoreTransaction(final String buyProductTag)
    {
    	QueneEvent.DoQueneEvent(new Runnable() {
            public void run() {
            	nativeRestoreTransaction(buyProductTag);
            }
    	});
    }
    public static void purchasingTransaction(final String buyProductTag)
    {
    	QueneEvent.DoQueneEvent(new Runnable() {
            public void run() {
            	nativePurchasingTransaction(buyProductTag);
            }
    	});
    }
    public static void restoreCompletedTransactionsFinished()
    {
    	QueneEvent.DoQueneEvent(new Runnable() {
            public void run() {
            	nativeRestoreCompletedTransactionsFinished();
            }
    	});
    }
    public static void restoreCompletedTransactionsFailed(final String msg, final int errorCode)
    {
    	QueneEvent.DoQueneEvent(new Runnable() {
            public void run() {
            		nativeRestoreCompletedTransactionsFailed(msg,errorCode);
            }
    	});
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