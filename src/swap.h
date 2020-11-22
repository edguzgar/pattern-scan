#ifndef SWAP_H
#define SWAP_H

#define SWAP_INT16(x) (((x) >> 8) | ((x) << 8))
#define SWAP_INT32(x) (((x) >> 24) | (((x) & 0x00FF0000) >> 8) | (((x) & 0x0000FF00) << 8) | ((x) << 24))

int swap_int16(int num);
int swap_int32(int num);

#endif // !SWAP_H
