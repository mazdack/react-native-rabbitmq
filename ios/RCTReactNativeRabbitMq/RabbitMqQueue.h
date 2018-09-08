
#ifdef OLDER_IMPORT
    #import "RCTBridge.h"
    #import "RCTEventDispatcher.h"
#else
    #import <React/RCTBridge.h>
    #import <React/RCTEventDispatcher.h>
#endif

#import <RMQClient/RMQClient.h>

@interface RabbitMqQueue : NSObject <RCTBridgeModule>

    - (nonnull id) initWithConfig:(nonnull NSDictionary *)config 
                          channel:(nonnull id<RMQChannel>)channel
                           bridge:(nonnull RCTBridge *)bridge;

    - (void) bind:(nonnull RMQExchange *)exchange routing_key:(NSString *)routing_key;
    - (void) unbind:(nonnull RMQExchange *)exchange routing_key:(NSString *)routing_key;
    - (void) delete;
    - (void) basicConsume;
    - (void) basicCancel;
    - (void) ack: (NSNumber *)deliveryTag;
    - (void) nack: (NSNumber *)deliveryTag requeue:(BOOL *)requeue;
@end
