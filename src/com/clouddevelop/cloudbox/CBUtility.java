package com.clouddevelop.cloudbox;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.content.DialogInterface;
import android.os.Handler;
import android.os.Message;

public class CBUtility {
	private static Activity MainActivity;
	
	private static Handler handler;
    private final static int HANDLER_SHOW_DIALOG = 1;
    
    
    
    public static void initUtility(Activity activity)
    {
    	MainActivity = activity;
    	if(handler == null)
    	{
    		handler = new Handler(){
    			public void handleMessage(Message msg){
    				switch(msg.what){
    				case HANDLER_SHOW_DIALOG:
    					showDialog(((DialogMessage)msg.obj).title, ((DialogMessage)msg.obj).message);
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
    
    public static void showMessageBox(String title, String message){
    	Message msg = new Message();
    	msg.what = HANDLER_SHOW_DIALOG;
    	msg.obj = new DialogMessage(title, message);
    	
    	handler.sendMessage(msg);
    }
    
    private static void showDialog(String title, String message){
    	Dialog dialog = new AlertDialog.Builder(MainActivity)
	    .setTitle(title)
	    .setMessage(message)
	    .setPositiveButton("Ok",
	    new DialogInterface.OnClickListener()
	    {
	    	public void onClick(DialogInterface dialog, int whichButton){
	    		
	    	}
	    }).create();

	    dialog.show();
    }
}

class DialogMessage {
	public String title;
	public String message;
	
	public DialogMessage(String title, String message){
		this.message = message;
		this.title = title;
	}
}