#ifndef H_MXLOG
#define H_MXLOG

#ifndef H_MODEX
#include "core/mx_util.h"
#endif

#define MX_LOG(lvl, msg) mx_log_extra(lvl, msg, __FILE__, __func__, __LINE__)

typedef enum {
    MX_LOG_EMERG = 0,
    MX_LOG_ALERT,
    MX_LOG_CRIT,
    MX_LOG_ERR,
    MX_LOG_WARNING,
    MX_LOG_NOTICE,
    MX_LOG_INFO,
    MX_LOG_DEBUG,
    _MX_LOG_LEVEL_COUNT
} mx_log_level_t;

void mx_log(mx_log_level_t level, const char *const message);

void mx_log_extra(mx_log_level_t level,
                  const char *const message,
                  const char *const file,
                  const char *const func,
                  const int line);

#endif // H_MXLOG

