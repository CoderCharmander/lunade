#ifdef HAVE_CONFIG_H
#include "config.h"
#else
#error config.h is required.
#endif

#include <stdio.h>

#include "wmanager.h"

int main(int argc, char** args) {
  WindowManager * wm;
  printf("This is " PACKAGE
         " version " PACKAGE_VERSION
         ", bug report address is " PACKAGE_BUGREPORT "\n");
  if (argc > 1) wm = getWMInstance(args[1]);
  wm = getWMInstance(NULL);
  if (wm == NULL) {
    return -2;
  }

  return runWM(wm);
}
