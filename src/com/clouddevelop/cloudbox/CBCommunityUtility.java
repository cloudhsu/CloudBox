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

public class CBCommunityUtility  {

	public static void initUtility(Activity activity)
	{
		FacebookManager.getInstance().setMainActivity(activity);
	}
	
	public static void autoLoginFB(Bundle savedInstanceState)
	{
		FacebookManager.getInstance().autoLogin(savedInstanceState);
	}
	
	public static  void loginFB()
	{
		FacebookManager.getInstance().login();
	}
	
	public static  void logoutFB()
	{
		FacebookManager.getInstance().logout();
	}
	
	public static void postStatusToFB(String msg)
	{
		FacebookManager.getInstance().postStatus(msg);
	}
	
	public static void postStatusToFB(String msg, String imageName)
	{
		FacebookManager.getInstance().postStatus(msg, imageName);
	}
	
	public static void postFeedToFB(String name,String link, String caption, String description, String msg)
	{
		FacebookManager.getInstance().postFeed(name, link, caption, description, msg);
	}
}
