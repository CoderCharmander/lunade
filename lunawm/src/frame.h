#ifndef FRAME_H
#define FRAME_H

#define FRAME_BORDERWIDTH 3
#define FRAME_TOPWIDTH 16

#include "wmanager.h"
#include "client.h"

void FrameClient(WindowManager *, Client *);
void UnframeClient(WindowManager *, Client *);

#endif
