#include "events.h"

void OnCreateNotify(WindowManager * wm, XCreateWindowEvent evt) {
}
void OnDestroyNotify(WindowManager * wm, XDestroyWindowEvent evt) {
}
void OnReparentNotify(WindowManager * wm, XReparentEvent evt) {
}

void OnConfigureRequest(WindowManager * wm, XConfigureRequestEvent e) {
  XWindowChanges chg;

  chg.x = e.x;
  chg.y = e.y;
  chg.width = e.width;
  chg.height = e.height;
  chg.border_width = e.border_width;
  chg.sibling = e.above;
  chg.stack_mode = e.detail;

  XConfigureWindow(wm->dpy, e.window, e.value_mask, &changes);
}
