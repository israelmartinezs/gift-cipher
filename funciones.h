#include <stdio.h>

int Ek(unsigned char twek, uint64_t key1, uint64_t key2, uint64_t textoplano, uint64_t * textocifrado);
int genKeyFromChar(unsigned char * k, uint64_t * key1, uint64_t * key2);
int init(uint64_t key1,uint64_t key2, uint64_t npub1, uint64_t npub2, uint64_t * kn1, uint64_t * kn2, uint64_t *deltan);