
#import "O2Client.h"
#import "O2AuthFlow.h"

@implementation O2Client

@synthesize delegate = mDelegate;
@synthesize accessToken = mAccessToken;
@synthesize refreshToken = mRefreshToken;

+ (O2Client*)clientWithServer:(NSURL*)server
             identifier:(NSString*)identifier
             secret:(NSString*)secret
{
  return [[[O2Client alloc] initWithServer:server
                            identifier:identifier
                            secret:secret] autorelease];
}

- (O2Client*)initWithServer:(NSURL*)server
             identifier:(NSString*)identifier
             secret:(NSString*)secret
{
  self = [super init];
  if(!self) return nil;
  
  mServer = [server copy];
  mIdentifier = [identifier copy];
  mSecret = [secret copy];
    
  return self;
}

- (void)dealloc
{
  mDelegate = nil;
  [mServer release];
  [mIdentifier release];
  [mSecret release];
  [mAccessToken release];
  [mRefreshToken release];
  [mAuthFlow release];
  [super dealloc];
}

#pragma mark -

- (void)authorize
{
  // Forget tokens and reauthorize from scratch
  
  // Open Authentication URL
  if(!mAuthFlow) mAuthFlow = [[O2AuthFlow authFlow] retain];
  [mAuthFlow visitAuthorizationServer:mServer identifier:mIdentifier];
}

@end
