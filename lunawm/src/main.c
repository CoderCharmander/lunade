#ifdef HAVE_CONFIG_H
#include "config.h"
#else
#error config.h is required.
#endif

#include <stdio.h>

#include "wmanager.h"

int main() {
  WindowManager * wm;
  printf("This is " PACKAGE
         " version " PACKAGE_VERSION
         ", bug report address is " PACKAGE_BUGREPORT "\n");
  wm = getWMInstance();
  if (wm == NULL) {
    return -2;
  }
  return runWM(wm);
}
