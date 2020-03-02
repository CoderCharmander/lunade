#include "client.h"
#include "frame.h"

#include <stdlib.h>
#include <stdio.h>

Client * ClientCreate(WindowManager * wm, Window cw, Client * prev) {
  Client * cl = (Client *)malloc(sizeof(Client));
  cl->wm = wm;
  cl->wnd = cw;
  cl->frame = NULL;
  cl->next = NULL;
  cl->prev = prev;
  return cl;
}

Client * ClientFindLast(Client * head, int * count) {
  Client * current = head;
  if (count)
    *count = 0;
  int c = 0;
  while (current->next) {
    if (count)
      (*count)++;
    c++; // xd
    printf("-- %d %p %p\n", c, current, current->next);
    current = current->next;
  }
  return current;
}

void ClientFreeAll(Client * head) {
  Client * current = head;
  Client * next;
  while(current->next) {
    next = current->next;
    free(current);
    current = next;
  }
}

void ClientRemove(Client * cl) {
  if (!cl) return;

  if (cl->prev)
    cl->prev->next = cl->next;
  if (cl->next)
    cl->next->prev = cl->prev;

  cl->next = cl->prev = NULL;
}

Client * ClientGetByWindow(Client * head, Window target) {
  Client * current = head;
  while (current->wnd != target && current->next) {
    current = current->next;
  }
  if (current->wnd != target) return NULL;
  return current;
}
