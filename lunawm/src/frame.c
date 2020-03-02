#include "frame.h"

void FrameClient(WindowManager * wm, Client * c) {
  XWindowAttributes xattr;
  if (c->frame || !c->wnd) return;
  XGetWindowAttributes(wm->dpy, c->wnd, &xattr);
  c->frame = XCreateSimpleWindow(wm->dpy, wm->root,
                                 xattr.x,
                                 xattr.y,
                                 xattr.width + FRAME_BORDERWIDTH * 2,
                                 xattr.height + FRAME_BORDERWIDTH + FRAME_TOPWIDTH,
                                 0, 0xaaaaaa, 0xaaaaaa);
  XSelectInput(wm->dpy, c->frame,
               SubstructureRedirectMask | SubstructureNotifyMask);
  XAddToSaveSet(wm->dpy, c->wnd);
  XReparentWindow(wm->dpy, c->wnd, c->frame, FRAME_BORDERWIDTH, FRAME_TOPWIDTH);
  XMapWindow(wm->dpy, c->frame);
}

void UnframeClient(WindowManager * wm, Client * c) {
  
}
