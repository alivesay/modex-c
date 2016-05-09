#include "core/mx_memory.h"

#include "mx_log.h"

#include <stdio.h>

static const char *const _mx_log_errstrs[_MX_LOG_LEVEL_COUNT] = {
    "EMERG",
    "ALERT",
    "CRIT",
    "ERR",
    "WARNING",
    "NOTICE",
    "INFO",
    "DEBUG"
};


// TODO:  this all needs to be building strings first.. won't be writing to
// stdout for long...

void mx_log(mx_log_level_t level, const char *const message) {
    if (MX_CHECKBOUNDS(_mx_log_errstrs, level, _MX_LOG_LEVEL_COUNT)) {
        fprintf(stderr, "%s: %s\n", _mx_log_errstrs[level], message);
    } else {
        fprintf(stderr, "%s: %s\n", "INVALID_LOG_LEVEL", message);
    }
}

void mx_log_extra(mx_log_level_t level,
        const char *const message,
        const char *const file,
        const char *const func,
        const int line) {

    if (MX_CHECKBOUNDS(_mx_log_errstrs, level, _MX_LOG_LEVEL_COUNT)) {
        fprintf(stderr, "%s:%s:%d: %s: %s\n", file, func, line, _mx_log_errstrs[level], message);
    } else {
        fprintf(stderr, "%s:%s:%d: %s: %s\n", file, func, line, "INVALID_LOG_LEVEL", message);
    }
}
