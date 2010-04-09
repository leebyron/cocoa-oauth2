#import "O2AuthFlow.h"

@implementation O2AuthFlow

@synthesize delegate = mDelegate;

+ (O2AuthFlow*)authFlowWithIdentifier:(NSString*)identifier
{
  O2AuthMacFlow* flow = [[[O2AuthMacFlow alloc] init] autorelease];
  flow.identifier = identifier;
  return flow;
}

- (void)visitAuthorizationServer:(NSURL*)url
{
  // Must override
  [NSException exceptionWithName:@"abstract class"
                          reason:@"Must use an overriding class of O2AuthFlow"
                        userInfo:nil];
}

@end


@implementation O2AuthMacFlow

- (id)init
{
  self = [super init];
  if(!self) return nil;
  
  return self;
}

- (void)dealloc
{
  
}

- (void)visitAuthorizationServer:(NSURL*)url
{
  NSURL*  serverWithParams;

  serverWithParams = [url absoluteString]
  [[NSWorkspace sharedWorkspace] openURL:url];
}

@end