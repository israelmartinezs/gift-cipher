#include <stdio.h>
#include <stdlib.h>

unsigned long long getbit(unsigned long long N){
	int i;
	unsigned long long mask;
	unsigned long long R = 0;
	unsigned long long aux,aux1 = 0;
	
	mask = 0x8421842184218421;
	aux = N & mask;

	R = R | ((aux & (0x00000000000001))           | ((aux & (0x0000000000000020)) >> 4)  | ((aux & (0x0000000000000400)) >> 8)  | ((aux & (0x0000000000008000)) >> 12));
	R = R | (((aux & (0x0000000000010000)) >> 12) | ((aux & (0x0000000000200000)) >> 16) | ((aux & (0x0000000004000000)) >> 20) | ((aux & (0x0000000080000000)) >> 24));
	R = R | (((aux & (0x0000000100000000)) >> 24) | ((aux & (0x0000002000000000)) >> 28) | ((aux & (0x0000040000000000)) >> 32) | ((aux & (0x0000800000000000)) >> 36));
	R = R | (((aux & (0x0001000000000000)) >> 36) | ((aux & (0x0020000000000000)) >> 40) | ((aux & (0x0400000000000000)) >> 44) | ((aux & (0x8000000000000000)) >> 48));

	mask = 0x1842184218421842;
	aux = N & mask;
	R = R | (((aux & (0x0000000000000002)) << 16) | ((aux & (0x0000000000000040)) << 12) | ((aux & (0x0000000000000800)) << 8)  | ((aux & (0x0000000000001000)) << 4));
	R = R | (((aux & (0x0000000000020000)) << 4 ) | ((aux & (0x0000000000400000))      ) | ((aux & (0x0000000008000000))) >> 4  | ((aux & (0x0000000010000000)) >> 8));
	R = R | (((aux & (0x0000000200000000)) >> 8 ) | ((aux & (0x0000004000000000)) >> 12) | ((aux & (0x0000080000000000)) >> 16) | ((aux & (0x0000100000000000)) >> 20));
	R = R | (((aux & (0x0002000000000000)) >> 20 ) | ((aux & (0x0040000000000000)) >> 24 ) | ((aux & (0x0800000000000000)) >> 28) | ((aux & (0x1000000000000000)) >> 32));

	mask = 0x2184218421842184;
	aux = N & mask;
	R = R | (((aux & (0x0000000000000004)) << 32)  | ((aux & (0x0000000000000080)) << 28) | ((aux & (0x0000000000000100)) << 24) | ((aux & (0x0000000000002000)) << 20));
	R = R | (((aux & (0x0000000000040000)) << 20)  | ((aux & (0x0000000000800000)) << 16) | ((aux & (0x0000000001000000)) << 12) | ((aux & (0x0000000020000000)) << 8));
	R = R | (((aux & (0x0000000400000000)) << 8 )  | ((aux & (0x0000008000000000)) << 4)  | ((aux & (0x0000010000000000))      ) | ((aux & (0x0000200000000000)) >> 4));
	R = R | (((aux & (0x0004000000000000)) >> 4 )  | ((aux & (0x0080000000000000)) >> 8)  | ((aux & (0x0100000000000000)) >> 12) | ((aux & (0x2000000000000000)) >> 16));

	mask = 0x4218421842184218;
	aux = N & mask;
	R = R | (((aux & (0x0000000000000008)) << 48) | ((aux & (0x0000000000000010)) << 44) | ((aux & (0x0000000000000200)) << 40) | ((aux & (0x0000000000004000)) << 36));
	R = R | (((aux & (0x0000000000080000)) << 36) | ((aux & (0x0000000000100000)) << 32) | ((aux & (0x0000000002000000)) << 28) | ((aux & (0x0000000040000000)) << 24));
	R = R | (((aux & (0x0000000800000000)) << 24) | ((aux & (0x0000001000000000)) << 20) | ((aux & (0x0000020000000000)) << 16) | ((aux & (0x0000400000000000)) << 12));
	R = R | (((aux & (0x0008000000000000)) << 12) | ((aux & (0x0010000000000000)) << 8) | ((aux & (0x0200000000000000)) << 4 ) | ((aux & (0x4000000000000000))      ));


	return R;

}

unsigned long long SBOX(unsigned long long N){
	unsigned char SB[]={0x01,0x0A,0x04,0x0C,0x06,0x0F,0x03,0x09,0x02,0x0D,0x0B,0x07,0x05,0x00,0x08,0x0E};
	unsigned char *aux_in,*aux_out,byte_in,byte_out;
	unsigned long long S;
	int i;
	aux_in  = (unsigned char*)(&N);
	aux_out = (unsigned char*)(&S);

	for(i = 0;i < 8; i++){
		byte_out = 0;
		byte_in = aux_in[i];
		aux_out[i] = (SB[aux_in[i]>>4] << 4)|(SB[aux_in[i] & 0x0F]);
	}
	return S;
}

unsigned long long SBOX_inv(unsigned long long N){
	unsigned char SB[]={0x0D,0x00,0x08,0x06,0x02,0x0C,0x04,0x0B,0x0E,0x07,0x01,0x0A,0x03,0x09,0x0F,0x05};
	unsigned char *aux_in,*aux_out,byte_in,byte_out;
	unsigned long long S;
	int i;
	aux_in  = (unsigned char*)(&N);
	aux_out = (unsigned char*)(&S);

	for(i = 0;i < 8; i++){
		byte_out = 0;
		byte_in = aux_in[i];
		aux_out[i] = (SB[aux_in[i]>>4] << 4)|(SB[aux_in[i] & 0x0F]);
	}
	return S;
}

unsigned short rot_short(unsigned short b,int rt){
	unsigned short tmp;
	tmp = b >> rt;
	b = b << (16-rt);
	return tmp|b;	
}

void put_bit_1(unsigned long long *U,int bit){
	int j;
	unsigned long long mask;
	mask=1;
	mask = mask << bit;
	*U=*U|mask;
}

int get_bit_p(unsigned long long K[2],int p){
	unsigned short *K_16,aux,mask;
	K_16=(unsigned short *)K;
	int i,j;
	i=p/16;
	j=p % 16;
	mask=1;
	mask = mask << j;
	aux=K_16[i]&mask;
	if(aux!=0)
		return 1;
	else
		return 0;
}

int get_bit_byte(unsigned char K,int p){
	unsigned char aux,mask;
	mask=1;
	mask = mask << p;
	aux=K&mask;
	if(aux!=0)
		return 1;
	else
		return 0;
}

void get_rnd_cte(unsigned char *c){
	unsigned char c5,c4;
	c5 = *c & 0x20;
	c5 = c5>>5;
	c4 = *c & 0x10;
	c4 = c4>>4;
    *c = (*c<<1)|(c5^c4^1);	
}

unsigned long long keygen(unsigned long long K[2],int rnd){
	unsigned short *K_16,K0,K1;
	K_16=(unsigned short *)K;
	unsigned long long rd_U;
	unsigned char cte[]={0x01,0x03,0x07,0x0F,0x1F,0x3E,0x3D,0x3B,
						0x37,0x2F,0x1E,0x3C,0x39,0x33,0x27,0x0E,     
		                 0x1D,0x3A,0x35,0x2B,0x16,0x2C,
		                 0x18,0x30,0x21,0x02,0x05,0x0B,
		                 0x17,0x2E,0x1C,0x38};
	int i;
	rd_U = 0;
	K0 = K_16[0];
	K1 = K_16[1];
		
	printf("ko: %.16llx\n", K0);	
	printf("k1: %.16llx\n", K1);	

  	
  for(i=0;i<6;i++)
		K_16[i] = K_16[i+2];
	K_16[6]=rot_short(K0,12);
	K_16[7]=rot_short(K1,2);
	printf("\n");
	printf("Ronda %d Llave actualizada %.16llx %.16llx\n", rnd, K[0], K[1]);

  for(i=0;i<16;i++){
		if(get_bit_p(K,i))
			put_bit_1(&rd_U,4*i);
  }
  printf("segundo for %.16llx\n", rd_U );
  for(i=16;i<32;i++){
		if(get_bit_p(K,i))
			put_bit_1(&rd_U,4*(i-16)+1);
  }
  printf("\n");
  printf("U||V antes: %.16llx\n", rd_U);
	
  if(get_bit_byte(cte[rnd],5))
		put_bit_1(&rd_U,23);
	if(get_bit_byte(cte[rnd],4))
		put_bit_1(&rd_U,19);
	if(get_bit_byte(cte[rnd],3))
		put_bit_1(&rd_U,15);
	if(get_bit_byte(cte[rnd],2))
		put_bit_1(&rd_U,11);
	if(get_bit_byte(cte[rnd],1))
		put_bit_1(&rd_U,7);
	if(get_bit_byte(cte[rnd],0))
		put_bit_1(&rd_U,3);
	put_bit_1(&rd_U,63);

	printf("U||V despues: %.16llx\n", rd_U);	

	return rd_U;
}

void Gift_enc(unsigned long long K[2],unsigned long long PT,unsigned long long *CT){
	unsigned long long state,state_k[2],rk;
	int i;
	state = PT;
	state_k[0]=K[0];
	state_k[1]=K[1];

	for(i=0;i<28;i++){
		state = SBOX(state);
		printf("\n SBOX state %.16llx",state); 
		state = getbit(state);
		printf("\n Perm state %.16llx",state);
		rk=keygen(state_k,i);
		printf("\n rnd_k %.16llx",rk);
		printf("\n state_k %.16llx %.16llx",state_k[1],state_k[0]);
		state = state^rk;
		printf("\n Ronda %d: Cipher state: %.16llx\n",i,state);

	}
	
	*CT=state;
	

}

int main(){
	unsigned short H=0xFFF0;
	
	//printf("\n perm %x %x \n",H,rot_short(H,1));
	
	unsigned long long K[2],PT,CT,state;
	PT  =0x1234123412341234;
	K[0]=0x1231123212331234;
	K[1]=0x1235123612371238;
	/*
	K[1]=0x1231123212331234;
	K[0]=0x12351236 12311232;
	*/
	int i;

	printf( "PT Original: %.16llx \n", PT );
	Gift_enc(K,PT,&CT);
	
	/*state = getbit(PT);
	printf("\n perm %016llx %016llx \n",PT,state);*/

	//unsigned long long prueba = 0x0123456789abcdef, resp;;
	//resp = SBOX( prueba );
	//printf("\n GS %016llx %016llx %d \n",prueba, resp, sizeof(unsigned long long));
	
	//resp = SBOX_inv( resp );
	//printf("\n Recuperado GS %016llx %016llx %d \n",prueba, resp, sizeof(unsigned long long));
	
	
	printf( "Cipher text: %.16llx \n", CT );
	//for( int i = 0; i < 28; i++ )
	//    keygen( K, i );

}

