#ifndef WMANAGER_H
#define WMANAGER_H

#include <X11/Xlib.h>

struct Client_;

typedef struct _WindowManager {
  Display *dpy;
  Window root;
  struct Client_ * head;
} WindowManager;

WindowManager * getWMInstance();
int runWM(WindowManager *);

int XError     (Display*, XErrorEvent*);

#endif
