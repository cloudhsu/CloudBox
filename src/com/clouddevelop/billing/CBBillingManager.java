/*
 *  CBBillingManager.java
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/11/18.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

package com.clouddevelop.billing;

import java.util.Locale;

import android.app.Activity;
import android.os.Handler;
import android.util.Log;

import com.clouddevelop.billing.BillingService.RequestPurchase;
import com.clouddevelop.billing.BillingService.RestoreTransactions;
import com.clouddevelop.billing.Consts.PurchaseState;
import com.clouddevelop.billing.Consts.ResponseCode;
import com.clouddevelop.cloudbox.CBUtility;

/**
 * A sample application that demonstrates in-app billing.
 */
public class CBBillingManager
{
    private static final String TAG = "cloudbox-billing";

    /**
     * Used for storing the log text.
     */
    private static final String LOG_TEXT_KEY = "cloudbox-billing";

    private CBPurchaseObserver mCBPurchaseObserver;
    private Handler mHandler;

    private BillingService mBillingService;

    /**
     * The developer payload that is sent with subsequent
     * purchase requests.
     */
    private String mPayloadContents = null;

    /**
     * A {@link PurchaseObserver} is used to get callbacks when Android Market sends
     * messages to this application so that we can update the UI.
     */
    private class CBPurchaseObserver extends PurchaseObserver
    {
    	private boolean mSupported;
    	
        public CBPurchaseObserver(Activity activity, Handler handler)
        {
            super(activity, handler);
        }

        @Override
        public void onBillingSupported(boolean supported, String type)
        {
        	setSupported(supported);
        	Log.i(TAG, "supported: " + supported);
        }

        @Override
        public void onPurchaseStateChange(PurchaseState purchaseState, String itemId,
                int quantity, long purchaseTime, String developerPayload)
        {
        	Log.i(TAG, "onPurchaseStateChange() itemId: " + itemId + " " + purchaseState);
        	
        	if (purchaseState == PurchaseState.PURCHASED)
        	{
        		completeTransaction(itemId);
        	}
        	else if (purchaseState == PurchaseState.CANCELED)
        	{
        		failedTransaction(itemId,purchaseState.ordinal());
        	}
        	else if(purchaseState == PurchaseState.REFUNDED)
        	{
        		restoreTransaction(itemId);
        	}
        }

        @Override
        public void onRequestPurchaseResponse(RequestPurchase request,
                ResponseCode responseCode)
        {
        	Log.d(TAG, request.mProductId + ": " + responseCode);
            if (responseCode == ResponseCode.RESULT_OK) {
            	Log.i(TAG, "purchase was successfully sent to server");
            } else if (responseCode == ResponseCode.RESULT_USER_CANCELED) {
            	Log.i(TAG, "user canceled purchase");
            	failedTransaction("User canceled purchase.",responseCode.ordinal());
            } else {
            	Log.i(TAG, "purchase failed");
            	failedTransaction("Purchase failed.",responseCode.ordinal());
            }
        }

        @Override
        public void onRestoreTransactionsResponse(RestoreTransactions request,
                ResponseCode responseCode)
        {
            if (responseCode == ResponseCode.RESULT_OK)
            {
            	Log.d(TAG, "completed RestoreTransactions request");
            	restoreCompletedTransactionsFinished();
            }
            else
            {
            	Log.d(TAG, "RestoreTransactions error: " + responseCode);
            	restoreCompletedTransactionsFailed("RestoreTransactions error",responseCode.ordinal());
            }
        }

		public boolean isSupported() {
			return mSupported;
		}

		private void setSupported(boolean mSupported) {
			this.mSupported = mSupported;
		}
    }

    /**
     * Initial billing manager 
     */
    public void initialStore(Activity activity) {
        mHandler = new Handler();
        mCBPurchaseObserver = new CBPurchaseObserver(activity, mHandler);
        mBillingService = new BillingService();
        mBillingService.setContext(activity);
        ResponseHandler.register(mCBPurchaseObserver);
        mBillingService.checkBillingSupported(Consts.ITEM_TYPE_INAPP);
    }

    /**
     * Destroy billing manager 
     */
    public void releaseStore() {
        ResponseHandler.unregister(mCBPurchaseObserver);
        mBillingService.unbind();
    }

    public void buy(String productID)
    {
    	boolean result = mBillingService.requestPurchase(productID, Consts.ITEM_TYPE_INAPP, mPayloadContents);
    	if(result == false)
    	{
    		Log.d(TAG, "connect to android market error!");
    		requestFail("connect to android market error!");
    	}
    }
    
    public void restoreCompletedTransactions()
    {
    	boolean result = mBillingService.restoreTransactions();
    	if(result == false)
    	{
    		Log.d(TAG, "connect to android market error!");
    		requestFail("connect to android market error!");
    	}
    }
    
    public boolean isCanBuy()
    {
    	return mCBPurchaseObserver.isSupported();
    }
    
    void requestFail(String msg)
    {
    	CBUtility.requestFail(msg);
    }
    
    void completeTransaction(String buyProductTag)
    {
    	CBUtility.completeTransaction(buyProductTag);
    }
    void failedTransaction(String msg, int errorCode)
    {
    	CBUtility.failedTransaction(msg, errorCode);
    }
    void restoreTransaction(String buyProductTag)
    {
    	CBUtility.restoreTransaction(buyProductTag);
    }
    void purchasingTransaction(String buyProductTag)
    {
    	CBUtility.purchasingTransaction(buyProductTag);
    }
    void restoreCompletedTransactionsFinished()
    {
    	CBUtility.restoreCompletedTransactionsFinished();
    }
    void restoreCompletedTransactionsFailed(String msg, int errorCode)
    {
    	CBUtility.restoreCompletedTransactionsFailed(msg, errorCode);
    }
    
}
