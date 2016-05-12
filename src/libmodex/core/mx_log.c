#include "core/mx_memory.h"

#include "mx_log.h"

#include <stdio.h>
#include <stdlib.h>

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

static const char *const _mx_log_get_errstr(const mx_log_level_t level) {
    if (MX_CHECKBOUNDS(_mx_log_errstrs, level, _MX_LOG_LEVEL_COUNT)) {
        return _mx_log_errstrs[level];
    }

    return "INVALID_LOG_LEVEL";
}

// TODO:  this all needs to be building strings first.. won't be writing to
// stdout for long...

void mx_log(const mx_log_level_t level, const char *const message) {
    static const char *const fmt = "%s: %s\n";

    fprintf(stderr, fmt, _mx_log_get_errstr(level), message);
    
    if (level == MX_LOG_EMERG) exit(EXIT_FAILURE);
}

void mx_log_extra(const mx_log_level_t level,
                  const char *const message,
                  const char *const file,
                  const char *const func,
                  const int line) {

    static const char *const fmt = "%s:%s:%d: %s: %s\n"; 
        
    fprintf(stderr, fmt, file, func, line, _mx_log_get_errstr(level), message);
    
    if (level == MX_LOG_EMERG) exit(EXIT_FAILURE);
}
