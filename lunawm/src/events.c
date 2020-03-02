#include "events.h"
#include "client.h"
#include "frame.h"

#include <stdlib.h>

void OnCreateNotify(WindowManager * wm, XCreateWindowEvent evt) {
}
void OnDestroyNotify(WindowManager * wm, XDestroyWindowEvent evt) {
  Client * c = ClientGetByWindow(wm->head, evt.window);
  if (!c) return;
  XDestroyWindow(wm->dpy, c->frame);
  ClientRemove(c);
  free(c);
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
  chg.x = e.x;//(w - chg.width) / 2;
  chg.y = e.y;//(h - chg.height) / 2;
  chg.width = e.width;
  chg.height = e.height;
  chg.border_width = e.border_width;
  chg.sibling = e.above;
  chg.stack_mode = e.detail;

  XConfigureWindow(wm->dpy, e.window, e.value_mask, &chg);
}

void OnMapRequest(WindowManager * wm, XMapRequestEvent e) {
  Client * c;
  if (wm->head == NULL) {
    wm->head = c = ClientCreate(wm, e.window, NULL);
  }
  else {
    int i;
    Client * lc = ClientFindLast(wm->head, &i);
    lc->next = c = ClientCreate(wm, e.window, lc);
  }
  // Framez
  FrameClient(wm, c);
  XAddToSaveSet(wm->dpy, c->wnd);
  XMapWindow(wm->dpy, e.window);
}

void OnUnmapNotify(WindowManager * wm, XUnmapEvent e) {
  Client * c;
  if (!(c = ClientGetByWindow(wm->head, e.window))) return;
  UnframeClient(wm, c);
  ClientRemove(c);
  free(c);
}
