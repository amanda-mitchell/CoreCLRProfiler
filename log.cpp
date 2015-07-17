
#include "log.h"
#include <stdio.h>

void LogProfilerActivity(const char *format, ...)
{
  va_list ap;

  va_start(ap, format);
  vprintf(format, ap);
  va_end(ap);
}
