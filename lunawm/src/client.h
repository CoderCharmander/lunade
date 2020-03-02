#ifndef CLIENT_H
#define CLIENT_H

#include "wmanager.h"

typedef struct Client_ {
  Window buttons[3];
  Window wnd;
  Window frame;
  WindowManager * wm;
  struct Client_ * next;
  struct Client_ * prev;
} Client;

// Create a client object from a window manager, and a window.
Client * ClientCreate(WindowManager *, Window, Client *);

// Get last item and length of linked list.
Client * ClientFindLast(Client *, int *);
// Free all clients in list.
void     ClientFreeAll(Client *);
// Remove a client. DOESN'T FREE IT!
void     ClientRemove(Client *);
#endif
