#ifndef H_MXLOG
#define H_MXLOG

#include "mx_util.h"

#define OW_LOG_BUILD_STR(s) (__FILE__ ":" OW_STRINGIZE(__LINE__) " -- [" s "]")

enum MXLogLevel {
    MX_LOG_EMERG = 0,
    MX_LOG_ALERT,
    MX_LOG_CRIT,
    MX_LOG_ERR,
    MX_LOG_WARNING,
    MX_LOG_NOTICE,
    MX_LOG_INFO,
    MX_LOG_DEBUG,
    _MX_LOG_LEVEL_COUNT
};

void mx_log(enum MXLogLevel level, char const *const message);

#endif // H_MXLOG

