#include "events.h"

void OnCreateNotify(WindowManager * wm, XCreateWindowEvent evt) {
}
void OnDestroyNotify(WindowManager * wm, XDestroyWindowEvent evt) {
}
void OnReparentNotify(WindowManager * wm, XReparentEvent evt) {
}

void OnConfigureRequest(WindowManager * wm, XConfigureRequestEvent e) {
  XWindowChanges chg;

  unsigned int w,h;
  int x,y;
  unsigned int bw,d;
  Window root;

  XGetGeometry(wm->dpy, wm->root, &root, &x, &y, &w, &h, &bw, &d);

  // Center windoz
  
  chg.x = (w - chg.width) / 2;
  chg.y = (h - chg.height) / 2;
  chg.width = e.width;
  chg.height = e.height;
  chg.border_width = e.border_width;
  chg.sibling = e.above;
  chg.stack_mode = e.detail;

  XConfigureWindow(wm->dpy, e.window, e.value_mask, &chg);
}

void OnMapRequest(WindowManager * wm, XMapRequestEvent e) {
  XMapWindow(wm->dpy, e.window);
}
