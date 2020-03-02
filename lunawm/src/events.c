#include "events.h"
#include "client.h"

#include <stdio.h>

void OnCreateNotify(WindowManager * wm, XCreateWindowEvent evt) {
}
void OnDestroyNotify(WindowManager * wm, XDestroyWindowEvent evt) {
  printf("Destroy\n");
  ClientRemove(ClientGetByWindow(wm->head, evt.window));
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
  chg.width = w;
  chg.height = h;
  chg.border_width = e.border_width;
  chg.sibling = e.above;
  chg.stack_mode = e.detail;

  XConfigureWindow(wm->dpy, e.window, e.value_mask, &chg);
}

void OnMapRequest(WindowManager * wm, XMapRequestEvent e) {
  printf ("%p\n", wm->head);
  if (wm->head == NULL) {
    wm->head = ClientCreate(wm, e.window, NULL);
  }
  else {
    int i;
    Client * cl = ClientFindLast(wm->head, &i);
    cl->next = ClientCreate(wm, e.window, cl);
  }
  XMapWindow(wm->dpy, e.window);
}
