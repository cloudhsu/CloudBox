/*
 *  CBiOSStoreManager.mm
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/10/30.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#include <string>
using namespace std;

#import "CBiOSStoreManager.h"
#import "CBStoreManager.h"

@implementation CBiOSStoreManager

static CBiOSStoreManager* _sharedInstance = nil;

+(id)sharedInstance
{
	@synchronized([CBiOSStoreManager class])
	{
		if (!_sharedInstance)
			[[self alloc] init];
        
		return _sharedInstance;
	}
	return nil;
}

+(id)alloc
{
	@synchronized([CBiOSStoreManager class])
	{
		NSAssert(_sharedInstance == nil, @"Attempted to allocate a second instance of a singleton.\n");
		_sharedInstance = [super alloc];
		return _sharedInstance;
	}
	return nil;
}

-(id)init {
	self = [super init];
	if (self != nil) {
		// initialize stuff here
	}
	return self;
}

-(void)initialStore
{
    [[SKPaymentQueue defaultQueue] addTransactionObserver:self];
}
-(void)releaseStore
{
    [[SKPaymentQueue defaultQueue] removeTransactionObserver:self];
}

- (void) restoreCompletedTransactions
{
    [[SKPaymentQueue defaultQueue] restoreCompletedTransactions];
}

-(void)buy:(NSString*)buyProductIDTag
{
    [self requestProductData:buyProductIDTag];
}

-(bool)CanMakePay
{
    return [SKPaymentQueue canMakePayments];
}   

-(void)requestProductData:(NSString*)buyProductIDTag
{
    // step 1
    NSLog(@"---------Request product information------------\n");
    NSArray *product = [[NSArray alloc] initWithObjects:buyProductIDTag,nil];
    NSSet *nsset = [NSSet setWithArray:product];
    SKProductsRequest *request=[[SKProductsRequest alloc] initWithProductIdentifiers: nsset];
    request.delegate=self;
    [request start];
    [product release];
}

- (void)productsRequest:(SKProductsRequest *)request didReceiveResponse:(SKProductsResponse *)response
{
    // step 2
    NSLog(@"-----------Getting product information--------------\n");
    NSArray *myProduct = response.products;
    NSLog(@"Product ID:%@\n",response.invalidProductIdentifiers);
    NSLog(@"Product count: %d\n", [myProduct count]);
    // populate UI
    for(SKProduct *product in myProduct){
        NSLog(@"Detail product info\n");
        NSLog(@"SKProduct description: %@\n", [product description]);
        NSLog(@"Product localized title: %@\n" , product.localizedTitle);
        NSLog(@"Product localized descitption: %@\n" , product.localizedDescription);
        NSLog(@"Product price: %@\n" , product.price);
        NSLog(@"Product identifier: %@\n" , product.productIdentifier);
    }
    SKPayment *payment = nil;
    if(myProduct.count > 0)
    {
        payment = [SKPayment paymentWithProduct:[response.products objectAtIndex:0]];
        NSLog(@"---------Request payment------------\n");
        [[SKPaymentQueue defaultQueue] addPayment:payment];
        [request autorelease];
    }
    else
    {
        NSLog(@"---------Request failed, product count = 0------------\n");
    }
}
//- (void)requestProUpgradeProductData:(NSString*)buyProductIDTag
//{
//    NSLog(@"------Request to upgrade product data---------\n");
//    NSSet *productIdentifiers = [NSSet setWithObject:buyProductIDTag];
//    SKProductsRequest* productsRequest = [[SKProductsRequest alloc] initWithProductIdentifiers:productIdentifiers];
//    productsRequest.delegate = self;
//    [productsRequest start];    
//}

- (void)request:(SKRequest *)request didFailWithError:(NSError *)error
{
    string errorMsg = string([[error localizedDescription]UTF8String]);
    SStoreManager.requestFail(errorMsg);
}

-(void) requestDidFinish:(SKRequest *)request
{
    // step 5
    NSLog(@"Request finished\n");
    SStoreManager.requestFinished();
}

-(void) purchasedTransaction: (SKPaymentTransaction *)transaction
{
    //NSLog(@"-----Purchased Transaction----\n");
    NSArray *transactions =[[NSArray alloc] initWithObjects:transaction, nil];
    [self paymentQueue:[SKPaymentQueue defaultQueue] updatedTransactions:transactions];
    [transactions release];
}

- (void)paymentQueue:(SKPaymentQueue *)queue updatedTransactions:(NSArray *)transactions
{
    // step 4
    for (SKPaymentTransaction *transaction in transactions)
    {
        switch (transaction.transactionState)
        {
            case SKPaymentTransactionStatePurchased:
                [self completeTransaction:transaction];
                break;
            case SKPaymentTransactionStateFailed:
                [self failedTransaction:transaction];
                break;
            case SKPaymentTransactionStateRestored:
                [self restoreTransaction:transaction];
                break;
            case SKPaymentTransactionStatePurchasing:
                NSLog(@"-----Transcation puchasing--------\n");
                break;
            default:
                break;
        }
    }
}

- (void) completeTransaction: (SKPaymentTransaction *)transaction   
{
    NSString *product = transaction.payment.productIdentifier;
    if ([product length] > 0)
    {
        string productId = string([product UTF8String]);
        SStoreManager.completeTransaction(productId);
    }
//#if TARGET_OS_IPHONE
//    NSArray *downloads = nil;
//#ifdef __IPHONE_6_0
//    downloads = transaction.downloads;
//    if([downloads count] > 0) {
//        
//        [[SKPaymentQueue defaultQueue] startDownloads:transaction.downloads];
//    }
//#endif
//#endif
    // Remove the transaction from the payment queue.
    [[SKPaymentQueue defaultQueue] finishTransaction: transaction];
}

- (void) failedTransaction: (SKPaymentTransaction *)transaction
{
    if (transaction.error.code != SKErrorPaymentCancelled)
    {
        NSString *product = transaction.payment.productIdentifier;
        if ([product length] > 0)
        {
            string productId = string([product UTF8String]);
            string errorMsg = string([[transaction.error localizedDescription]UTF8String]);
            SStoreManager.failedTransaction(errorMsg, transaction.error.code);
        }
    }
    [[SKPaymentQueue defaultQueue] finishTransaction: transaction];
}
- (void)paymentQueueRestoreCompletedTransactionsFinished:(SKPaymentQueue *)queue
{
    NSLog(@"received restored transactions: %i\n", queue.transactions.count);
    SStoreManager.restoreCompletedTransactionsFinished();
//    for (SKPaymentTransaction *transaction in queue.transactions)
//    {
//        NSLog(@"tran for product: %@ of state: %i\n", [[transaction payment] productIdentifier], [transaction transactionState]);
//        switch ([transaction transactionState])
//        {
//            case SKPaymentTransactionStateRestored:
//                NSLog(@"found restored transaction: %@ productIdentifier: %@\n", transaction.transactionIdentifier, transaction.payment.productIdentifier);
//                [self restoreTransaction:transaction];
//                break;
//            default:
//                break;
//        }
//    }
}

- (void) restoreTransaction: (SKPaymentTransaction *)transaction
{
    NSString *product = transaction.payment.productIdentifier;
    if ([product length] > 0)
    {
        string productId = string([product UTF8String]);
        SStoreManager.restoreTransaction(productId);
    }
//#if TARGET_OS_IPHONE
//    NSArray *downloads = nil;
//    
//#ifdef __IPHONE_6_0
//    downloads = transaction.downloads;
//#endif
//#endif
    [[SKPaymentQueue defaultQueue] finishTransaction: transaction];
}

#ifdef __IPHONE_6_0
- (void)paymentQueue:(SKPaymentQueue *)queue updatedDownloads:(NSArray *)downloads
{
    //[self hostedContentDownloadStatusChanged:downloads];
    NSLog(@"Payment Queue updatedDownloads\n");
}
#endif

-(void) paymentQueue:(SKPaymentQueue *) paymentQueue restoreCompletedTransactionsFailedWithError:(NSError *)error
{
    NSLog(@"-------Payment Queue restoreCompletedTransactionsFailedWithError----\n");
    string errorMsg = string([[error localizedDescription]UTF8String]);
    SStoreManager.restoreCompletedTransactionsFailed(errorMsg, error.code);
}

-(void) provideContent: (NSString*) productIdentifier
            forReceipt:(NSData*) receiptData
         hostedContent:(NSArray*) hostedContent
{
    NSLog(@"-------provideContent----\n");
}

#pragma mark connection delegate
- (void)connection:(NSURLConnection *)connection didReceiveData:(NSData *)data
{
    NSLog(@"%@\n",  [[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding] autorelease]);
}
- (void)connectionDidFinishLoading:(NSURLConnection *)connection
{   
    
}   

- (void)connection:(NSURLConnection *)connection didReceiveResponse:(NSURLResponse *)response
{
    switch([(NSHTTPURLResponse *)response statusCode]) {
        case 200:
        case 206:
            break;
        case 304:
            break;
        case 400:
            break;
        case 404:
            break;
        case 416:
            break;
        case 403:
            break;
        case 401:
        case 500:
            break;
        default:
            break;
    }
}   

- (void)connection:(NSURLConnection *)connection didFailWithError:(NSError *)error
{
    NSLog(@"To Connect to appstore error:%d\n",error.code);
}

-(void)dealloc
{
    [super dealloc];
}

@end