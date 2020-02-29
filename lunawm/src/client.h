#ifndef CLIENT_H
#define CLIENT_H

#include "wmanager.h"

typedef struct Client_ {
  Window buttons[3];
  Window wnd;
  Window frame;
  WindowManager * wm;
} Client;
