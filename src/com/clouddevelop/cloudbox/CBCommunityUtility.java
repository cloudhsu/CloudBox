/*
 *  FacebookManager.java
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2013/04/19.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

package com.clouddevelop.cloudbox;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;

public class CBCommunityUtility  {

	public static void initUtility(Activity activity)
	{
		Log.i("cloudbox-community", "call initUtility");
		FacebookManager.getInstance().setMainActivity(activity);
	}
	
	public static void autoLoginFB(Bundle savedInstanceState)
	{
		Log.i("cloudbox-community", "call autoLoginFB");
		FacebookManager.getInstance().autoLogin(savedInstanceState);
	}
	
	public static  void loginFB()
	{
		Log.i("cloudbox-community", "call loginFB");
		FacebookManager.getInstance().login();
	}
	
	public static  void logoutFB()
	{
		Log.i("cloudbox-community", "call logoutFB");
		FacebookManager.getInstance().logout();
	}
	
	public static void postStatusToFB(String msg)
	{
		Log.i("cloudbox-community", "call postStatusToFB");
		FacebookManager.getInstance().postStatus(msg);
	}
	
	public static void postStatusToFB(String msg, String imageName)
	{
		Log.i("cloudbox-community", "call postStatusToFB");
		FacebookManager.getInstance().postStatus(msg, imageName);
	}
	
	public static void postFeedToFB(String name,String link, String caption, String description, String msg)
	{
		Log.i("cloudbox-community", "call postFeedToFB");
		FacebookManager.getInstance().postFeed(name, link, caption, description, msg);
	}
}
