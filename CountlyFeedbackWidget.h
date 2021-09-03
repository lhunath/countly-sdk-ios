// CountlyFeedbackWidget.h
//
// This code is provided under the MIT License.
//
// Please visit www.count.ly for more information.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString* CLYFeedbackWidgetType NS_EXTENSIBLE_STRING_ENUM;
extern CLYFeedbackWidgetType const CLYFeedbackWidgetTypeSurvey;
extern CLYFeedbackWidgetType const CLYFeedbackWidgetTypeNPS;


@interface CountlyFeedbackWidget : NSObject
#if (TARGET_OS_IOS)

@property (nonatomic, readonly) CLYFeedbackWidgetType type;
@property (nonatomic, readonly) NSString* ID;
@property (nonatomic, readonly) NSString* name;
@property (nonatomic, readonly) NSDictionary* data;

/**
 * Modally presents the feedback widget above the top visible view controller.
 * @discussion Calls to this method will be ignored if consent for @c CLYConsentFeedback is not given
 * while @c requiresConsent flag is set on initial configuration.
 */
- (void)present;

/**
 * Modally presents the feedback widget above the top visible view controller and executes given blocks.
 * @param appearBlock Block to be executed when widget is displayed.
 * @param dismissBlock Block to be executed when widget is dismissed.
 * @discussion Calls to this method will be ignored if consent for @c CLYConsentFeedback is not given
 * while @c requiresConsent flag is set on initial configuration.
 */
- (void)presentWithAppearBlock:(void(^ __nullable)(void))appearBlock andDismissBlock:(void(^ __nullable)(void))dismissBlock;

/**
 * Fetches feedback widget's data for manual presenting.
 * @discussion When feedback widget's data is fetched successfully, @c completionHandler will be executed with an @c NSDictionary
 * @discussion This @c NSDictionary represents the feedback widget's data and can be used for creating custom widget UI.
 * @discussion Otherwise, @c completionHandler will be executed with an @c NSError.
 * @param completionHandler A completion handler block to be executed when data is fetched successfully or there is an error.
 */
- (void)getWidgetData:(void (^)(NSDictionary * __nullable widgetData, NSError * __nullable error))completionHandler;

#endif
@end

NS_ASSUME_NONNULL_END
