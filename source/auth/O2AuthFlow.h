
// OAuthFlow

// This factory class defines an abstract interface
// for interface controller code for the different
// cocoa platforms

@interface O2AuthFlow : NSObject
{
  id mDelegate;
  NSString* identifier;
}

// Factory
+ (O2AuthFlow*)authFlowWithIdentifier:(NSString*)identifier

// Authorization
- (void)visitAuthorizationServer:(NSURL*)url;

// Delegate
@property (assign) id delegate;
@property (retain) NSString* identifer;

@end


// OAuthFlow Delegates

// For now delegates only are notified if authentication
// succeeds or is cancelled.

@protocol O2AuthDelegate <NSObject>

@required

- (void)authFlowDone:(O2AuthFlow*)authFlow;
- (void)authFlowCancelled:(O2AuthFlow*)authFlow;

@end


// OAuthMacFlow

// Interface controller class for Mac that implements
// the OAuthFlow contract. For now, pops a window
// with an webview and watches for URL changes.

// In the future, will send users to their
// preferred browser and brings them back with a
// protocol scheme handler.

@class WebView;

@interface O2AuthMacFlow : O2AuthFlow
{
  NSWindow*   mWindow;
  WebView*    mWebView;
}

@end

