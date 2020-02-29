#ifndef WMANAGER_H
#define WMANAGER_H

#include <X11/Xlib.h>

typedef struct _WindowManager {
	Display *dpy;
	Window root;
} WindowManager;

WindowManager * getWMInstance();
int runWM(WindowManager *);

int XError     (Display*, XErrorEvent*);
#endif
