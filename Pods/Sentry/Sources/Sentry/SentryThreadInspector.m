#import "SentryThreadInspector.h"
#import "SentryFrame.h"
#import "SentryStacktrace.h"
#import "SentryStacktraceBuilder.h"
#import "SentryThread.h"

@interface
SentryThreadInspector ()

@property (nonatomic, strong) SentryStacktraceBuilder *stacktraceBuilder;
@property (nonatomic, strong) id<SentryCrashMachineContextWrapper> machineContextWrapper;

@end

@implementation SentryThreadInspector

- (id)initWithStacktraceBuilder:(SentryStacktraceBuilder *)stacktraceBuilder
       andMachineContextWrapper:(id<SentryCrashMachineContextWrapper>)machineContextWrapper
{
    if (self = [super init]) {
        self.stacktraceBuilder = stacktraceBuilder;
        self.machineContextWrapper = machineContextWrapper;
    }
    return self;
}

- (NSArray<SentryThread *> *)getCurrentThreadsSkippingFrames:(NSInteger)framesToSkip
{
    NSMutableArray<SentryThread *> *threads = [NSMutableArray new];

    SentryCrashMC_NEW_CONTEXT(context);
    [self.machineContextWrapper fillContextForCurrentThread:context];

    int threadCount = [self.machineContextWrapper getThreadCount:context];

    for (int i = 0; i < threadCount; i++) {
        SentryCrashThread thread = [self.machineContextWrapper getThread:context withIndex:i];
        SentryThread *sentryThread = [[SentryThread alloc] initWithThreadId:@(i)];

        sentryThread.name = [self getThreadName:thread];

        sentryThread.crashed = @NO;
        bool isCurrent = thread == sentrycrashthread_self();
        sentryThread.current = @(isCurrent);

        // For now we can only retrieve the stack trace of the current thread.
        if (isCurrent) {
            sentryThread.stacktrace =
                [self.stacktraceBuilder buildStacktraceForCurrentThreadSkippingFrames:framesToSkip];
        }

        [threads addObject:sentryThread];
    }

    return threads;
}

- (NSString *)getThreadName:(SentryCrashThread)thread
{
    char threadName[128];
    char *const pThreadName = threadName;
    [self.machineContextWrapper getThreadName:thread andBuffer:pThreadName andBufLength:128];
    return [NSString stringWithCString:pThreadName encoding:NSUTF8StringEncoding];
}

@end
