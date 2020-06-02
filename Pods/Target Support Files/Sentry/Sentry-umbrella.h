#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "NSData+SentryCompression.h"
#import "NSDate+SentryExtras.h"
#import "NSDictionary+SentrySanitize.h"
#import "NSString+SentryNSUIntegerValue.h"
#import "Sentry.h"
#import "SentryAsynchronousOperation.h"
#import "SentryAutoBreadcrumbTrackingIntegration.h"
#import "SentryAutoSessionTrackingIntegration.h"
#import "SentryBreadcrumb.h"
#import "SentryBreadcrumbTracker.h"
#import "SentryClient.h"
#import "SentryConcurrentRateLimitsDictionary.h"
#import "SentryCrashBinaryImageProvider.h"
#import "SentryCrashDefaultBinaryImageProvider.h"
#import "SentryCrashExceptionApplication.h"
#import "SentryCrashInstallationReporter.h"
#import "SentryCrashIntegration.h"
#import "SentryCrashReportConverter.h"
#import "SentryCrashReportSink.h"
#import "SentryCurrentDate.h"
#import "SentryCurrentDateProvider.h"
#import "SentryDateUtil.h"
#import "SentryDebugMeta.h"
#import "SentryDebugMetaBuilder.h"
#import "SentryDefaultCurrentDateProvider.h"
#import "SentryDefaultRateLimits.h"
#import "SentryDefines.h"
#import "SentryDsn.h"
#import "SentryEnvelope.h"
#import "SentryEnvelopeItemType.h"
#import "SentryEnvelopeRateLimit.h"
#import "SentryError.h"
#import "SentryEvent.h"
#import "SentryException.h"
#import "SentryFileContents.h"
#import "SentryFileManager.h"
#import "SentryFrame.h"
#import "SentryGlobalEventProcessor.h"
#import "SentryHexAddressFormatter.h"
#import "SentryHttpDateParser.h"
#import "SentryHttpTransport.h"
#import "SentryHub.h"
#import "SentryInstallation.h"
#import "SentryIntegrationProtocol.h"
#import "SentryLog.h"
#import "SentryMechanism.h"
#import "SentryMeta.h"
#import "SentryNSURLRequest.h"
#import "SentryOptions.h"
#import "SentryQueueableRequestManager.h"
#import "SentryRateLimitCategory.h"
#import "SentryRateLimitCategoryMapper.h"
#import "SentryRateLimitParser.h"
#import "SentryRateLimits.h"
#import "SentryRequestManager.h"
#import "SentryRequestOperation.h"
#import "SentryRetryAfterHeaderParser.h"
#import "SentryScope+Private.h"
#import "SentryScope.h"
#import "SentrySDK.h"
#import "SentrySerializable.h"
#import "SentrySerialization.h"
#import "SentrySession.h"
#import "SentrySessionTracker.h"
#import "SentryStacktrace.h"
#import "SentrySwizzle.h"
#import "SentryThread.h"
#import "SentryTransport.h"
#import "SentryTransportFactory.h"
#import "SentryUser.h"
#import "NSArray+SentrySanitize.h"
#import "SentryCrashInstallation+Private.h"
#import "SentryCrashInstallation.h"
#import "SentryCrashMonitor.h"
#import "SentryCrashMonitorContext.h"
#import "SentryCrashMonitorType.h"
#import "SentryCrashMonitor_AppState.h"
#import "SentryCrashMonitor_CPPException.h"
#import "SentryCrashMonitor_Deadlock.h"
#import "SentryCrashMonitor_MachException.h"
#import "SentryCrashMonitor_NSException.h"
#import "SentryCrashMonitor_Signal.h"
#import "SentryCrashMonitor_System.h"
#import "SentryCrashMonitor_User.h"
#import "SentryCrashMonitor_Zombie.h"
#import "SentryCrash.h"
#import "SentryCrashC.h"
#import "SentryCrashCachedData.h"
#import "SentryCrashDoctor.h"
#import "SentryCrashReport.h"
#import "SentryCrashReportFields.h"
#import "SentryCrashReportFixer.h"
#import "SentryCrashReportStore.h"
#import "SentryCrashReportVersion.h"
#import "SentryCrashReportWriter.h"
#import "SentryCrashSystemCapabilities.h"
#import "NSError+SentrySimpleConstructor.h"
#import "SentryCrashCPU.h"
#import "SentryCrashCPU_Apple.h"
#import "SentryCrashDate.h"
#import "SentryCrashDebug.h"
#import "SentryCrashDynamicLinker.h"
#import "SentryCrashFileUtils.h"
#import "SentryCrashID.h"
#import "SentryCrashJSONCodec.h"
#import "SentryCrashJSONCodecObjC.h"
#import "SentryCrashLogger.h"
#import "SentryCrashMach.h"
#import "SentryCrashMachineContext.h"
#import "SentryCrashMachineContext_Apple.h"
#import "SentryCrashMemory.h"
#import "SentryCrashObjC.h"
#import "SentryCrashObjCApple.h"
#import "SentryCrashSignalInfo.h"
#import "SentryCrashStackCursor.h"
#import "SentryCrashStackCursor_Backtrace.h"
#import "SentryCrashStackCursor_MachineContext.h"
#import "SentryCrashStackCursor_SelfThread.h"
#import "SentryCrashString.h"
#import "SentryCrashSymbolicator.h"
#import "SentryCrashSysCtl.h"
#import "SentryCrashThread.h"
#import "SentryCrashUUIDConversion.h"
#import "SentryCrashReportFilter.h"
#import "SentryCrashReportFilterBasic.h"
#import "Container+SentryDeepSearch.h"
#import "SentryCrashVarArgs.h"
#import "SentryCrashCString.h"

FOUNDATION_EXPORT double SentryVersionNumber;
FOUNDATION_EXPORT const unsigned char SentryVersionString[];

