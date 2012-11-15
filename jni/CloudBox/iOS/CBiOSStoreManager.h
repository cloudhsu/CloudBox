/*
 *  CBiOSStoreManager.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/10/30.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#import <UIKit/UIKit.h> 
#import <StoreKit/StoreKit.h>

@interface CBiOSStoreManager : NSObject<SKProductsRequestDelegate,SKPaymentTransactionObserver>
{
}

+ (id) sharedInstance;

- (void) buy:(NSString*)buyProductIDTag;
- (bool) CanMakePay;
- (void) initialStore;
- (void) releaseStore;
- (void) restoreCompletedTransactions;

- (void) requestProductData:(NSString*)buyProductIDTag;
//- (void) provideContent:(NSString *)product;
//- (void) recordTransaction:(NSString *)product;

// transaction result event
- (void) completeTransaction: (SKPaymentTransaction *)transaction;
- (void) failedTransaction: (SKPaymentTransaction *)transaction;
- (void) restoreTransaction: (SKPaymentTransaction *)transaction;

- (void) purchasedTransaction: (SKPaymentTransaction *)transaction;

//- (void) requestProUpgradeProductData:(NSString*)buyProductIDTag;
- (void) paymentQueue:(SKPaymentQueue *)queue updatedTransactions:(NSArray *)transactions;
- (void)paymentQueueRestoreCompletedTransactionsFinished:(SKPaymentQueue *)queue;
- (void) paymentQueue:(SKPaymentQueue *) paymentQueue restoreCompletedTransactionsFailedWithError:(NSError *)error;

@end