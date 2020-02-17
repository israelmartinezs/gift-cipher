/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h>
#include <inttypes.h>
#include <stdlib.h>

unsigned int rot_right(unsigned int, int);
void rot_short( unsigned short*, int );
unsigned int* keygen( unsigned int*, int );
void Gift_perm_bits( unsigned int* );
unsigned int SBOX( unsigned int );
void Gift_enc( unsigned int* ,unsigned int* ,unsigned int*, unsigned int[][2] );

void SBOX_inv( unsigned int N[2] );
void Gift_InvPerm_bits( unsigned int * );
void Gift_dec( unsigned int* , unsigned int* , unsigned int [][2]);

int main(void)
{
  unsigned int K[4],PT[2],CT[2], DT[2];
  PT[0] = 0x12341234;
  PT[1] = 0x12341234;

  K[0]  = 0x12331234;
  K[1]  = 0x12311232;
  K[2]  = 0x12371238;
  K[3]  = 0x12351236;

  unsigned int keys[28][2];

  printf( "\nOriginal text: %.8x %.8x\n", PT[1], PT[0] );
  //start = ARM_CM_DWT_CYCCNT;
  Gift_enc(K,PT,CT, keys);
  //stop  = ARM_CM_DWT_CYCCNT;
  //delta = stop - start;
  printf( "Cipher text: %.8x %.8x\n", CT[1], CT[0] );
  //printf("Execution time: %"PRIu32" \n", delta);

  //start = ARM_CM_DWT_CYCCNT;
  //Gift_dec( DT, CT, keys );
  //stop  = ARM_CM_DWT_CYCCNT;
  //delta = stop - start;
  printf( "\nDecipher text: %.8x %.8x\n", DT[1], DT[0] );
  //printf("Execution time: %"PRIu32" \n", delta);
}

unsigned int rot_right(unsigned int A, int n){
  unsigned int B;
  B = (A >> n) | (A << (32-n));
  return B;
}

void rot_short( unsigned short* d, int rt )
{
  unsigned short temp = *d >> rt;
  *d = (*d << (16 - rt))|temp;
}

/*unsigned int* keygen( unsigned int* k, int rnd )
{
  int i;
  unsigned short aux_u = 0, aux_v = 0, mask = 0x0001, U = 0, V = 0;
  unsigned int* exp_uv = (unsigned int*)malloc( 2*sizeof(unsigned int) );
  exp_uv[0] = 0;
  exp_uv[1] = 0;
  unsigned char cte_mask = 0x01, flag = 0;

  unsigned short* p = (unsigned short*)exp_uv;
  unsigned short* iter = (unsigned short*) k;

  unsigned int aux = 0x00000008;

  unsigned char cte[]={0x01,0x03,0x07,0x0F,0x1F,0x3E,0x3D,0x3B,0x37,0x2F,0x1E,0x3C,0x39,0x33,0x27,0x0E,
                     0x1D,0x3A,0x35,0x2B,0x16,0x2C,0x18,0x30,0x21,0x02,0x05,0x0B,0x17,0x2E,0x1C,0x38};

  int r = ( (rnd*2) % 8);
  rot_short( &iter[r], 12 );
  rot_short( &iter[r+1], 2 );

  r = (r + 2)%8;
  aux_v = iter[r];
  aux_u = iter[r+1];


  for( i = 0; i < 16; i++ )
  {
    mask = 0x0001;
    U = aux_u & (mask << i);
    mask = 0x0001;
    V = aux_v & (mask << i);

    U = U >> i;
    V = V >> i;


    p[i/4] = p[i/4] | ( U << ((4*i+1)%16) ) | ( V << ((4*i)%16) );
  }

  flag = cte[rnd] & cte_mask;
  if(flag)
    exp_uv[0] = exp_uv[0] | aux;

  flag = cte[rnd] & (cte_mask << 1);
  if(flag)
    exp_uv[0] = exp_uv[0] | (aux << 4);

  flag = cte[rnd] & (cte_mask << 2);
  if(flag)
    exp_uv[0] = exp_uv[0] | (aux << 8);

  flag = cte[rnd] & (cte_mask << 3);
  if(flag)
    exp_uv[0] = exp_uv[0] | (aux << 12);

  flag = cte[rnd] & (cte_mask << 4);
  if(flag)
    exp_uv[0] = exp_uv[0] | (aux << 16);

  flag = cte[rnd] & (cte_mask << 5);
  if(flag)
    exp_uv[0] = exp_uv[0] | (aux << 20);

  exp_uv[1] = exp_uv[1] | ( aux << 28 );

  return exp_uv;
}*/

unsigned int* keygen( unsigned int* k, int rnd )
{
  int i;
  unsigned short aux_u = 0, aux_v = 0, mask = 0x0001, U = 0, V = 0;
  unsigned int* exp_uv = (unsigned int*)malloc( 2*sizeof(unsigned int) );
  exp_uv[0] = 0;
  exp_uv[1] = 0;
  unsigned char cte_mask = 0x01, flag = 0;

  unsigned short* p = (unsigned short*)exp_uv;
  unsigned short* iter = (unsigned short*) k;

  unsigned int aux = 0x00000008;

  unsigned char cte[]={0x01,0x03,0x07,0x0F,0x1F,0x3E,0x3D,0x3B,0x37,0x2F,0x1E,0x3C,0x39,0x33,0x27,0x0E,
                     0x1D,0x3A,0x35,0x2B,0x16,0x2C,0x18,0x30,0x21,0x02,0x05,0x0B,0x17,0x2E,0x1C,0x38};

  int r = ( (rnd*2) % 8);
  int r2 = r;



  //r = (r + 2)%8;
  aux_v = iter[r];
  aux_u = iter[r+1];

  //printf("\n U: %.8x, V: %.8x\n",aux_u, aux_v);


  for( i = 0; i < 16; i++ )
  {
    mask = 0x0001;
    U = aux_u & (mask << i);
    mask = 0x0001;
    V = aux_v & (mask << i);

    U = U >> i;
    V = V >> i;


    p[i/4] = p[i/4] | ( U << ((4*i+1)%16) ) | ( V << ((4*i)%16) );
    //printf("%.8x \n", exp_uv[0] );
    //printf("%.8x \n", exp_uv[1] );
  }

//printf("%016llx \n", exp_uv[0] );
  //printf("%016llx \n", exp_uv[1] );
  flag = cte[rnd] & cte_mask;
  if(flag)
    exp_uv[0] = exp_uv[0] | aux;

  flag = cte[rnd] & (cte_mask << 1);
  if(flag)
    exp_uv[0] = exp_uv[0] | (aux << 4);

  flag = cte[rnd] & (cte_mask << 2);
  if(flag)
    exp_uv[0] = exp_uv[0] | (aux << 8);

  flag = cte[rnd] & (cte_mask << 3);
  if(flag)
    exp_uv[0] = exp_uv[0] | (aux << 12);

  flag = cte[rnd] & (cte_mask << 4);
  if(flag)
    exp_uv[0] = exp_uv[0] | (aux << 16);

  flag = cte[rnd] & (cte_mask << 5);
  if(flag)
    exp_uv[0] = exp_uv[0] | (aux << 20);

  exp_uv[1] = exp_uv[1] | ( aux << 28 );

  rot_short( &iter[r2], 12 );
  rot_short( &iter[r2+1], 2 );

  return exp_uv;
}

void Gift_InvPerm_bits( unsigned int *state ){

  unsigned int Rh=0,Rl=0,Ah,Al;
  Ah = state[1];
  Al = state[0];

    Rl = Rl |  ( Ah     & 0x00100004);
  Rl = Rl |  ( Al     & 0x00400001);

  Rl = Rl | (rot_right((Ah & 0x00840000), 4));
  Rl = Rl | (rot_right((Al & 0x00210000), 4));

  Rl = Rl | (rot_right((Ah & 0x00020020), 8));
  Rl = Rl | (rot_right((Al & 0x00080080), 8));

  Rl = Rl | (rot_right((Ah & 0x00010010), 12));
  Rl = Rl | (rot_right((Al & 0x00040040), 12));

  Rl = Rl | (rot_right((Ah & 0x00080080), 16));
  Rl = Rl | (rot_right((Al & 0x00020020), 16));

  Rl = Rl | (rot_right((Ah & 0x00000042), 20));
  Rl = Rl | (rot_right((Al & 0x00000018), 20));

    Rl = Rl | (rot_right((Ah & 0x00400001), 24));
  Rl = Rl | (rot_right((Al & 0x00100004), 24));

    Rl = Rl | (rot_right((Ah & 0x00200008), 28));
  Rl = Rl | (rot_right((Al & 0x00800002), 28));

//------------------------------------------------------------------------

  Rh = Rh |  ( Ah     & 0x40000100);
  Rh = Rh |  ( Al     & 0x10000400);

  Rh = Rh | (rot_right((Ah & 0x20000800), 4));
  Rh = Rh | (rot_right((Al & 0x80000200), 4));

  Rh = Rh | (rot_right((Ah & 0x10000400), 8));
  Rh = Rh | (rot_right((Al & 0x40000100), 8));

  Rh = Rh | (rot_right((Ah & 0x84000000), 12));
  Rh = Rh | (rot_right((Al & 0x21000000), 12));

  Rh = Rh | (rot_right((Ah & 0x02002000), 16));
  Rh = Rh | (rot_right((Al & 0x08008000), 16));

  Rh = Rh | (rot_right((Ah & 0x01001000), 20));
  Rh = Rh | (rot_right((Al & 0x04004000), 20));

    Rh = Rh | (rot_right((Ah & 0x08008000), 24));
  Rh = Rh | (rot_right((Al & 0x02002000), 24));

    Rh = Rh | (rot_right((Ah & 0x00004200), 28));
  Rh = Rh | (rot_right((Al & 0x00001800), 28));


  state[1] = Rh;
    state[0] = Rl;
}

void Gift_perm_bits( unsigned int *state ){

  unsigned int Rh=0,Rl=0,Ah,Al;
  Ah = state[1];
  Al = state[0];

    Rl = Rl |  ( Ah     & 0x10000400);
  Rl = Rl |  ( Al     & 0x00400001);

  Rl = Rl | (rot_right((Ah & 0x00018000), 4));
  Rl = Rl | (rot_right((Al & 0x08000020), 4));

  Rl = Rl | (rot_right((Ah & 0x00200002), 8));
  Rl = Rl | (rot_right((Al & 0x10000400), 8));

  Rl = Rl | (rot_right((Ah & 0x04000040), 12));
  Rl = Rl | (rot_right((Al & 0x00018000), 12));

  Rl = Rl | (rot_right((Ah & 0x80000800), 16));
  Rl = Rl | (rot_right((Al & 0x00200002), 16));

  Rl = Rl | (rot_right((Ah & 0x00021000), 20));
  Rl = Rl | (rot_right((Al & 0x04000040), 20));

    Rl = Rl | (rot_right((Ah & 0x00400001), 24));
  Rl = Rl | (rot_right((Al & 0x80000800), 24));

    Rl = Rl | (rot_right((Ah & 0x08000020), 28));
  Rl = Rl | (rot_right((Al & 0x00021000), 28));

//------------------------------------------------------------------------

  Rh = Rh |  ( Ah     & 0x40000100);
  Rh = Rh |  ( Al     & 0x00100004);

  Rh = Rh | (rot_right((Ah & 0x00042000), 4));
  Rh = Rh | (rot_right((Al & 0x02000080), 4));

  Rh = Rh | (rot_right((Ah & 0x00800008), 8));
  Rh = Rh | (rot_right((Al & 0x40000100), 8));

  Rh = Rh | (rot_right((Ah & 0x01000010), 12));
  Rh = Rh | (rot_right((Al & 0x00042000), 12));

  Rh = Rh | (rot_right((Ah & 0x20000200), 16));
  Rh = Rh | (rot_right((Al & 0x00800008), 16));

  Rh = Rh | (rot_right((Ah & 0x00084000), 20));
  Rh = Rh | (rot_right((Al & 0x01000010), 20));

    Rh = Rh | (rot_right((Ah & 0x00100004), 24));
  Rh = Rh | (rot_right((Al & 0x20000200), 24));

    Rh = Rh | (rot_right((Ah & 0x02000080), 28));
  Rh = Rh | (rot_right((Al & 0x00084000), 28));


  state[1] = Rh;
    state[0] = Rl;
}

void SBOX_inv( unsigned int N[2] ){
  unsigned char SB[]={0x0D,0x00,0x08,0x06,0x02,0x0C,0x04,0x0B,0x0E,0x07,0x01,0x0A,0x03,0x09,0x0F,0x05};
  unsigned char *aux_in,*aux_out;
  unsigned int S[2];
  int i;
  aux_in  = (unsigned char*)(N);
  aux_out = (unsigned char*)(S);

  for(i = 0;i < 8; i++){
    aux_out[i] = (SB[aux_in[i]>>4] << 4)|(SB[aux_in[i] & 0x0F]);
  }

  N[1] = S[1];
  N[0] = S[0];
}

unsigned int SBOX( unsigned int state )
{
  unsigned int X0,X1,X2,X3,t;
  X1 = (state^((state<<1)&(state>>1)))&(0x22222222);
  t  = (state^((X1>>1)&(state>>3)))&(0x11111111);
  X2 = (state^((t<<2)|(X1<<1)))&(0x44444444);
  X0 = ((state>>3)^(X2>>2))&(0x11111111);
  X1 = (X1^(X0<<1));
  X0 = (~X0)&(0x11111111);
  X2 = (X2^((t<<2)&(X1<<1)));
  X3 = (X0|X1|X2|(t<<3));
  return(X3);
}

void Gift_enc(unsigned int* K, unsigned int* PT, unsigned int *CT, unsigned int keys[][2]){
  unsigned int state[2],state_k[4],*rk;
  int i;
  state[0] = PT[0];
  state[1] = PT[1];
  state_k[0]=K[0];
  state_k[1]=K[1];
  state_k[2]=K[2];
  state_k[3]=K[3];

  for(i=0;i<28;i++){
    state[1] = SBOX(state[1]);
    state[0] = SBOX(state[0]);
    printf("\n SBOX state %.8x %.8x",state[1], state[0]);
    Gift_perm_bits(state);
    printf("\n Perm state %.8x %.8x",state[1], state[0]);
    rk=keygen(state_k,i);
    keys[i][0] = rk[0];
    keys[i][1] = rk[1];
    //printf("\n rnd_k %.8x %.8x\n",rk[1], rk[0] );
    printf("\n state_k: %.8x %.8x %.8x %.8x",state_k[3],state_k[2],state_k[1],state_k[0]);
    state[1] = state[1]^rk[1];
    state[0] = state[0]^rk[0];
    printf("\n");
    printf("k0 %.8x\n", rk[0] );
    printf("k1%.8x\n", rk[1] );
    printf("\n Ronda %d: Cipher state: %.8x %.8x\n",i,state[1], state[0]);

  }

  CT[1]=state[1];
  CT[0]=state[0];

}

void Gift_dec( unsigned int* DT, unsigned int *CT, unsigned int keys[][2]){
  unsigned int state[2];
  int i;
  state[0] = CT[0];
  state[1] = CT[1];

  for(i=0;i<28;i++){
    state[1] = state[1]^keys[27-i][1];
    state[0] = state[0]^keys[27-i][0];
    printf("\n Ronda %d: RK_inv state: %.8x %.8x",i,state[1], state[0]);


    Gift_InvPerm_bits(state);
    printf("\n InvPerm state %.8x %.8x",state[1], state[0]);

    SBOX_inv(state);
    printf("\n Inv_SBOX state %.8x %.8x\n",state[1], state[0]);

  }

  DT[1]=state[1];
  DT[0]=state[0];

}

