#include "wmanager.h"

#ifndef HAVE_CONFIG_H
#error config.h required
#endif
#include "config.h"

#include "events.h"
#ifndef HAVE_STDLIB_H
#error stdlib.h is required
#endif

#include <stdlib.h>
#include <stdio.h>

static int wm_detected = 0;

int WMDetected(Display* dpy, XErrorEvent* err) {
  wm_detected = 1;
}

int XError(Display * dpy, XErrorEvent * err) {
  static char errt[1024];
  XGetErrorText(dpy, err->error_code, errt, sizeof(errt));
  fprintf(stderr, "X error received: %s", errt);
}

WindowManager* getWMInstance(char* dpy) {
  static WindowManager * wm;
  if (wm != NULL)
    return wm;
  wm = (WindowManager *)malloc(sizeof(WindowManager));
  if (wm == NULL) {
    fprintf(stderr, "Could not allocate memory\n");
    return NULL;
  }
  wm->dpy = XOpenDisplay(dpy);
  if (wm->dpy == NULL) {
    fprintf(stderr, "Can't open display; did you start this with xinit or a display manager? Is display argument valid?\n");
    return NULL;
  }
  wm->root = DefaultRootWindow(wm->dpy);
  wm->head = NULL;
  return wm;
}

int runWM(WindowManager * wm) {
  XEvent e;
  XSetErrorHandler(WMDetected);
  XSelectInput(wm->dpy, wm->root, SubstructureRedirectMask | SubstructureNotifyMask);
  XSync(wm->dpy, 0);
  if (wm_detected) {
    fprintf(stderr, "Other window manager is already running on display %s\n", XDisplayString(wm->dpy));
    return -1;
  }

  XSetErrorHandler(XError);

  while (1) {
    XNextEvent(wm->dpy, &e);

    switch (e.type) {
    case CreateNotify:
      OnCreateNotify(wm, e.xcreatewindow);
      break;
    case DestroyNotify:
      OnDestroyNotify(wm, e.xdestroywindow);
      break;
    case ReparentNotify:
      OnReparentNotify(wm, e.xreparent);
      break;

    case ConfigureRequest:
      OnConfigureRequest(wm, e.xconfigurerequest);
      break;
    case MapRequest:
      OnMapRequest(wm, e.xmaprequest);
      break;
    case UnmapNotify:
      OnUnmapNotify(w, e.xunmap);
      break;
    }
  }
}
