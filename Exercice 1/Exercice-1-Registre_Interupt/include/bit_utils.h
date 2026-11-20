#pragma once

#define SetBit(x,y)  ((x) |= (1 << (y)))
#define ClrBit(x,y)  ((x) &= ~(1 << (y)))
#define TestBit(x,y) ((x) & (1 << (y)))
