
@class O2AuthFlow;

@interface O2Client : NSObject
{
  NSURL*            mServer;
  NSString*         mIdentifier;
  NSString*         mSecret;

  NSString*         mAccessToken;
  NSString*         mRefreshToken;

  O2AuthFlow*       mAuthFlow;
  id                mDelegate;
}

// Factory
+ (O2Client*)clientWithServer:(NSURL*)server
             identifier:(NSString*)identifier
             secret:(NSString*)secret;

// Initialization
- (O2Client*)initWithServer:(NSURL*)server
             identifier:(NSString*)identifier
             secret:(NSString*)secret;

// Authorization
- (void)authorize;
@property (readonly) NSString*  accessToken;
@property (readonly) NSString*  refreshToken;

// Reauthorization
- (void)reauthorizeWithRefreshToken:(NSString*)refreshToken;

// Delegate
@property (assign) id  delegate;

@end

@interface NSObject (O2ClientDelegate)

// Authorization
- (void)O2ClientAuthorizationDone:(O2Client*)client;
- (void)O2Client:(O2Client*)client authorizationError:(NSError*)error;

// Errors
- (void)O2ClientError:(O2Client*)client error:(NSError*)error;

@end
