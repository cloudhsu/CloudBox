/*
 *  FacebookManager.java
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2013/04/14.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

package com.clouddevelop.cloudbox;

import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;

import android.app.Activity;
import android.content.Intent;
import android.content.res.AssetManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.util.Log;

import com.facebook.HttpMethod;
import com.facebook.LoggingBehavior;
import com.facebook.Request;
import com.facebook.Response;
import com.facebook.Session;
import com.facebook.SessionState;
import com.facebook.Settings;

public class FacebookManager  {

    private Session.StatusCallback statusCallback = new SessionStatusCallback();
    
    private Activity m_activity = null;
    boolean m_isInitial;
    
    private static FacebookManager m_instance = new FacebookManager();
    
    public static FacebookManager getInstance()
    {
    	return m_instance;
    }
    
    public void setMainActivity(Activity activity)
    {
    	m_activity = activity;
    	m_isInitial = true;
    }
    
    private FacebookManager()
    {
    	// singleton
    }
    
    public void initial()
    {
    	Session.getActiveSession().addCallback(statusCallback);
    }
    
    public void uninitial()
    {
    	Session.getActiveSession().removeCallback(statusCallback);
    }
    
    public void autoLogin(Bundle savedInstanceState)
    {
    	if(m_activity == null || !m_isInitial)
    	{
    		return;
    	}
    	Settings.addLoggingBehavior(LoggingBehavior.INCLUDE_ACCESS_TOKENS);

        Session session = Session.getActiveSession();
        if (session == null) {
            if (savedInstanceState != null) {
                session = Session.restoreSession(m_activity, null, statusCallback, savedInstanceState);
            }
            if (session == null) {
                session = new Session(m_activity);
            }
            Session.setActiveSession(session);
            if (session.getState().equals(SessionState.CREATED_TOKEN_LOADED)) {
            	List<String> permissions = new ArrayList<String>();
            	permissions.add("publish_stream");
            	permissions.add("publish_actions");
                session.openForRead(new Session.OpenRequest(m_activity).setCallback(statusCallback).setPermissions(permissions));
            }
        }
    }
    
    public void login()
    {
    	if(m_activity == null || !m_isInitial)
    	{
    		return;
    	}
    	Session session = Session.getActiveSession();
        if (!session.isOpened() && !session.isClosed()) {
        	List<String> permissions = new ArrayList<String>();
        	permissions.add("publish_stream");
        	permissions.add("publish_actions");
            session.openForRead(new Session.OpenRequest(m_activity).setCallback(statusCallback).setPermissions(permissions));
        } else {
            Session.openActiveSession(m_activity, true, statusCallback);
        }
    }
    
    public void logout()
    {
    	Session session = Session.getActiveSession();
        if (!session.isClosed()) {
            session.closeAndClearTokenInformation();
        }
    }

    public void onActivityResult(int requestCode, int resultCode, Intent data) {
        Session.getActiveSession().onActivityResult(m_activity, requestCode, resultCode, data);
    }

    public void onSaveInstanceState(Bundle outState) {
        Session session = Session.getActiveSession();
        Session.saveSession(session, outState);
    }
    
    private boolean hasPublishPermission()
    {
        Session session = Session.getActiveSession();
        return session != null && session.getPermissions().contains("publish_actions");
    }
    
    public void postStatus(String msg)
    {
    	if(!m_isInitial)
    		return;
    	if (hasPublishPermission())
    	{
            Request request = Request
                    .newStatusUpdateRequest(Session.getActiveSession(), msg, new Request.Callback() {
                        @Override
                        public void onCompleted(Response response) {
                        	Log.v("postStatus response ", response.toString());
                        }
                    });
            request.executeAsync();
        }
    }
    
    public void postStatus(String msg, String imageName)
    {
    	if(!m_isInitial)
    		return;
    	if (hasPublishPermission())
    	{
            Bitmap image = getBitmapFromAsset(imageName);
            Request request = Request.newUploadPhotoRequest(Session.getActiveSession(), image, new Request.Callback() {
                @Override
                public void onCompleted(Response response) {
                	 Log.v("postStatus response ", response.toString());
                }
            });
            request.executeAsync();
        }
    }
    
    public void postFeed(String name,String link, String caption, String description, String msg)
    {
    	if(!m_isInitial)
    		return;
    	 Bundle parameters = new Bundle();
         parameters.putString("message", msg);
         parameters.putString("name", name);
         parameters.putString("link", link);
         parameters.putString("caption", caption);
         parameters.putString("description", description);

         Request request = new Request(Session.getActiveSession(), "me/feed", parameters, 
                 HttpMethod.POST, new Request.Callback() {
             @Override
             public void onCompleted(Response response) {
             	 Log.v("postFeed response ", response.toString());
             }
         });
         request.executeAsync();
        
    }
    
    public Bitmap getBitmapFromAsset(String strName) {
        AssetManager assetManager = m_activity.getAssets();

        InputStream istr;
        Bitmap bitmap = null;
        try {
            istr = assetManager.open(strName);
            bitmap = BitmapFactory.decodeStream(istr);
        } catch (IOException e) {
            return null;
        }

        return bitmap;
    }
    
    private class SessionStatusCallback implements Session.StatusCallback {
        @Override
        public void call(Session session, SessionState state, Exception exception)
        {
        }
    }
}
