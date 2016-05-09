#include "mx_memory.h"
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

void mx_log(enum MXLogLevel level, const char *const message) {
    if (MX_CHECKBOUNDS(_mx_log_errstrs, level, _MX_LOG_LEVEL_COUNT)) {
        fprintf(stderr, "%s: %s\n", _mx_log_errstrs[level], message);
    } else {
        fprintf(stderr, "%s: %s\n", "INVALID_LOG_LEVEL", message);
    }
}
