#ifndef MACROS_H_
#define MACROS_H_

#define bitRead(source, bit) (source >> bit) & 1
#define bitSet(source, bit) source |= (1 << bit)
#define bitClear(source, bit) source &= ~(1 << bit)
#define bitToggle(source, bit) source ^= (1 << bit)

#endif