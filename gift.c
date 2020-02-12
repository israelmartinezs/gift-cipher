/*codigo por Israel Martinez*/
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
typedef unsigned __int128 uint128_t;
uint64_t key=0x1231123212331234;
uint64_t key2=0x1235123612371238;
uint64_t textoplano = 0x1234123412341234;
uint64_t mascaraso[]= {0x4000010000400001,0x0200008000028000,0x0010000410000400,0x0008200008000020};
uint64_t mascaraso2[]={0x0000420000800002,0x8400001000040000,0x0001000021000040,0x0020000800001800};
uint64_t mascaraso3[]={0x0000800002100004,0x1000042000080000,0x0002000040000180,0x0840000100002000};
uint64_t mascaraso4[]={0x2000080000210000,0x0000100004000018,0x0100004200004000,0x0084000080000200};

uint64_t mascaras[]= {0x4000010000400001,0x8000020000800002,0x1000040000100004,0x2000080000200008};
uint64_t mascaras2[]={0x0004200008000020,0x0008400001000040,0x0002100004000010,0x0001800002000080};
uint64_t mascaras3[]={0x0080000210000400,0x0010000420000800,0x0040000180000200,0x0020000840000100};
uint64_t mascaras4[]={0x0200008000021000,0x0100004000018000,0x0400001000042000,0x0800002000084000};

//uint32_t key={0x12341234};






uint64_t permutacion(uint64_t * texto){
	char binario[70];

	uint64_t salida=0; 
	uint64_t aux1=0, aux2=0,aux3=0, aux4=0;
	uint64_t aux5=0, aux6=0,aux7=0, aux8=0;
	uint64_t aux9=0, aux10=0,aux11=0, aux12=0;
	uint64_t aux13=0, aux14=0,aux15=0, aux16=0;

	uint64_t aux21=0, aux22=0,aux23=0, aux24=0;
	uint64_t aux25=0, aux26=0,aux27=0, aux28=0;
	uint64_t aux29=0, aux210=0,aux211=0, aux212=0;
	uint64_t aux213=0, aux214=0,aux215=0, aux216=0;

	aux1^=((*texto) &  mascaras[0]); aux2^=((*texto) &  mascaras[1]); aux3^=((*texto)& mascaras[2]); aux4^=((*texto)&mascaras[3]);
	aux5^=((*texto) &  mascaras2[0]); aux6^=((*texto) &  mascaras2[1]); aux7^=((*texto)& mascaras2[2]); aux8^=((*texto)&mascaras2[3]);
	aux9^=((*texto) &  mascaras3[0]); aux10^=((*texto) &  mascaras3[1]); aux11^=((*texto)& mascaras3[2]); aux12^=((*texto)&mascaras3[3]);
	aux13^=((*texto) &  mascaras4[0]); aux14^=((*texto) &  mascaras4[1]); aux15^=((*texto)& mascaras4[2]); aux16^=((*texto)&mascaras4[3]);
	//uint64_t mascaras[]={0x0008000400020001,0x0001000800040002,0x0002000100080004,0x0004000200010008};
	//printf("salida: %016llx \n",aux7 );
	uint64_t ref=0;
	aux21=aux1;
	ref=aux2 &  0xffff000000000000;	aux22=((aux2<<16)^(ref>>48));
	ref=aux3 &  0xffffffff00000000;	aux23=((aux3<<32)^(ref>>32)); 
	ref=aux4 &  0xffffffffffff0000;	aux24=((aux4<<48)^(ref>>16));
	ref=aux5 &  0xfffffffffffffff0;	aux25=((aux5<<60)^(ref>>4)); ////
	ref=aux6 &  0xfff0000000000000;	aux26=((aux6<<12)^(ref>>52));
	ref=aux7 &  0xfffffffffff00000;	aux27=((aux7<<44)^(ref>>20));
	ref=aux8 &  0xfffffff000000000;	aux28=((aux8<<28)^(ref>>36));
	ref=aux9 &  0xffffffffffffff00;	aux29=((aux9<<56)^(ref>>8));
	ref=aux10 & 0xff00000000000000;	aux210=((aux10<<8)^(ref>>56));
	ref=aux11 & 0xffffffffff000000;	aux211=((aux11<<40)^(ref>>24));       
	ref=aux12 & 0xffffff0000000000;	aux212=((aux12<<24)^(ref>>40));
	ref=aux13 & 0xf000000000000000;	aux213=((aux13<<4)^(ref>>60));
	ref=aux14 & 0xfffffffffffff000;	aux214=((aux14<<52)^(ref>>12));
	ref=aux15 & 0xfffff00000000000;	aux215=((aux15<<20)^(ref>>44));    
	ref=aux16 & 0xfffffffff0000000;	aux216=((aux16<<36)^(ref>>28)); 
	/*
	printf("\n");printf("\n");
	printf("auxiliares: %016llx\n",*texto );
	printf("auxiliares: %016llx\n",aux21 );
	printf("auxiliares: %016llX\n",aux22 );
	printf("auxiliares: %016llX\n",aux23 );
	printf("auxiliares: %016llX\n",aux24 );
	printf("auxiliares: %016llX\n",aux25 );
	printf("auxiliares: %016llX\n",aux26 );
	printf("auxiliares: %016llX\n",aux27 );
	printf("auxiliares: %016llX\n",aux28 );
	printf("auxiliares: %016llX\n",aux29 ); 
	printf("auxiliares: %016llX\n",aux210 );
	printf("auxiliares: %016llX\n",aux211 );
	printf("auxiliares: %016llX\n",aux212 );
	printf("auxiliares: %016llX\n",aux213 );
	printf("auxiliares: %016llX\n",aux214 );
	printf("auxiliares: %016llX\n",aux215 );
	printf("auxiliares: %016llx\n",aux216 );*/
	//printf("hola%"PRIx64"\n",aux216 );
	salida=aux21^aux22^aux23^aux24^aux25^aux26^aux27^aux28^aux29^aux210^aux211^aux212^aux213^aux214^aux215^aux216;
	//printf("auxisalida: %"PRIx64"\n",salida );
	
	
	//printf("permutacionin: %"PRIx64"\n",despermutacion(&salida) );
	salida=0xffffffffffffffff& salida;

	return salida;



}
uint64_t despermutacion (uint64_t* texto){
	char binario[70];

	uint64_t salida=0;
	uint64_t aux1=0, aux2=0,aux3=0, aux4=0;
	uint64_t aux5=0, aux6=0,aux7=0, aux8=0;
	uint64_t aux9=0, aux10=0,aux11=0, aux12=0;
	uint64_t aux13=0, aux14=0,aux15=0, aux16=0;

	uint64_t aux21=0, aux22=0,aux23=0, aux24=0;
	uint64_t aux25=0, aux26=0,aux27=0, aux28=0;
	uint64_t aux29=0, aux210=0,aux211=0, aux212=0;
	uint64_t aux213=0, aux214=0,aux215=0, aux216=0;
	uint64_t ref=0;
	aux21=aux1;
	/*
	ref=mascaras[1] &  0xffff000000000000;	mascaras[1]=((mascaras[1]<<16)^(ref>>48));
	ref=mascaras[2] &  0xffffffff00000000;	mascaras[2]=((mascaras[2]<<32)^(ref>>32)); 
	ref=mascaras[3] &  0xffffffffffff0000;	mascaras[3]=((mascaras[3]<<48)^(ref>>16));
	ref=mascaras2[0] & 0xfffffffffffffff0;	mascaras2[0]=((mascaras2[0]<<60)^(ref>>4)); ////
	ref=mascaras2[1] & 0xfff0000000000000;	mascaras2[1]=((mascaras2[1]<<12)^(ref>>52));
	ref=mascaras2[2] & 0xfffffffffff00000;	mascaras2[2]=((mascaras2[2]<<44)^(ref>>20));
	ref=mascaras2[3] & 0xfffffff000000000;	mascaras2[3]=((mascaras2[3]<<28)^(ref>>36));
	ref=mascaras3[0] & 0xffffffffffffff00;	mascaras3[0]=((mascaras3[0]<<56)^(ref>>8));
	ref=mascaras3[1] & 0xff00000000000000;	mascaras3[1]=((mascaras3[1]<<8)^(ref>>56));
	ref=mascaras3[2] & 0xffffffffff000000;	mascaras3[2]=((mascaras3[2]<<40)^(ref>>24));       
	ref=mascaras3[3] & 0xffffff0000000000;	mascaras3[3]=((mascaras3[3]<<24)^(ref>>40));
	ref=mascaras4[0] & 0xf000000000000000;	mascaras4[0]=((mascaras4[0]<<4)^(ref>>60));
	ref=mascaras4[1] & 0xfffffffffffff000;	mascaras4[1]=((mascaras4[1]<<52)^(ref>>12));
	ref=mascaras4[2] & 0xfffff00000000000;	mascaras4[2]=((mascaras4[2]<<20)^(ref>>44));    
	ref=mascaras4[3] & 0xfffffffff0000000;	mascaras4[3]=((mascaras4[3]<<36)^(ref>>28)); 
	
	printf("salidassss\n");
	printf("%016llx \n", mascaras[1]);
	printf("%016llx \n", mascaras[2]);
	printf("%016llx \n", mascaras[3]);
	printf("%016llx \n", mascaras2[0]);
	printf("%016llx \n", mascaras2[1]);
	printf("%016llx \n", mascaras2[2]);
	printf("%016llx \n", mascaras2[3]);
	printf("%016llx \n", mascaras3[0]);
	printf("%016llx \n", mascaras3[1]);
	printf("%016llx \n", mascaras3[2]);
	printf("%016llx \n", mascaras3[3]);
	printf("%016llx \n", mascaras4[0]);
	printf("%016llx \n", mascaras4[1]);
	printf("%016llx \n", mascaras4[2]);
	printf("%016llx \n", mascaras4[3]);
	printf("fin\n");
	*/
	//printf("despermutacion\n");


	aux1^=((*texto) &  mascaraso[0]); aux2^=((*texto) &  mascaraso[1]); aux3^=((*texto)& mascaraso[2]); aux4^=((*texto)&mascaraso[3]);
	aux5^=((*texto) &  mascaraso2[0]); aux6^=((*texto) &  mascaraso2[1]); aux7^=((*texto)& mascaraso2[2]); aux8^=((*texto)&mascaraso2[3]);
	aux9^=((*texto) &  mascaraso3[0]); aux10^=((*texto) &  mascaraso3[1]); aux11^=((*texto)& mascaraso3[2]); aux12^=((*texto)&mascaraso3[3]);
	aux13^=((*texto) &  mascaraso4[0]); aux14^=((*texto) &  mascaraso4[1]); aux15^=((*texto)& mascaraso4[2]); aux16^=((*texto)&mascaraso4[3]);
	//uint64_t mascaras[]={0x0008000400020001,0x0001000800040002,0x0002000100080004,0x0004000200010008};
	//uint64_t 
	ref=0;
	aux21=aux1;
	//printf("adentro: %016llx -----> %016llx \n", aux21,aux1);
	ref=aux2 &  0xffffffffffff0000;	aux22=((aux2<<48)^(ref>>16));
	//printf("adentro: %016llx -----> %016llx \n", aux22,aux2);
	ref=aux3 &  0xffffffff00000000;	aux23=((aux3<<32)^(ref>>32)); 
	//printf("adentro: %016llx -----> %016llx \n", aux23,aux3);
	ref=aux4 &  0xffff000000000000;	aux24=((aux4<<16)^(ref>>48));
	//printf("adentro: %016llx -----> %016llx \n", aux24,aux4);
	ref=aux5 &  0xf000000000000000;	aux25=((aux5<<4)^(ref>>60)); 
	//printf("adentro: %016llx -----> %016llx \n", aux25,aux5);
	ref=aux6 &  0xfffffffffffff000;	aux26=((aux6<<52)^(ref>>12));
	//printf("adentro: %016llx -----> %016llx \n", aux26,aux6);
	ref=aux7 &  0xfffff00000000000;	aux27=((aux7<<20)^(ref>>44));
	//printf("adentro: %016llx -----> %016llx \n", aux27,aux7);
	ref=aux8 &  0xfffffffff0000000;	aux28=((aux8<<36)^(ref>>28));
	//printf("adentro: %016llx -----> %016llx \n", aux28,aux8);
	ref=aux9 &  0xff00000000000000;	aux29=((aux9<<8)^(ref>>56));
	//printf("adentro: %016llx -----> %016llx \n", aux29,aux9);
	ref=aux10 & 0xffffffffffffff00;	aux210=((aux10<<56)^(ref>>8));
	//printf("adentro: %016llx -----> %016llx \n", aux210,aux10);
	ref=aux11 & 0xffffff0000000000;	aux211=((aux11<<24)^(ref>>40));       
	//printf("adentro: %016llx -----> %016llx \n", aux211,aux11);
	ref=aux12 & 0xffffffffff000000;	aux212=((aux12<<40)^(ref>>24));
	//printf("adentro: %016llx -----> %016llx \n", aux212,aux12);
	ref=aux13 & 0xfffffffffffffff0;	aux213=((aux13<<60)^(ref>>4));
	//printf("adentro: %016llx -----> %016llx \n", aux213,aux13);
	ref=aux14 & 0xfff0000000000000;	aux214=((aux14<<12)^(ref>>52));
	//printf("adentro: %016llx -----> %016llx \n", aux214,aux14);
	ref=aux15 & 0xfffffffffff00000;	aux215=((aux15<<44)^(ref>>20));    
	//printf("adentro: %016llx -----> %016llx \n", aux215,aux15);
	ref=aux16 & 0xfffffff000000000;	aux216=((aux16<<28)^(ref>>36)); 
	/*printf("adentro: %016llx -----> %016llx \n", aux216,aux16);
	printf("\n");printf("\n");
	printf("entrada: %016llx\n",*texto );
	printf("auxiliares: %016llx\n",aux21 );
	printf("auxiliares: %016llX\n",aux22 );
	printf("auxiliares: %016llX\n",aux23 );
	printf("auxiliares: %016llX\n",aux24 );
	printf("auxiliares: %016llX\n",aux25 );
	printf("auxiliares: %016llX\n",aux26 );
	printf("auxiliares: %016llX\n",aux27 );
	printf("auxiliares: %016llX\n",aux28 );
	printf("auxiliares: %016llX\n",aux29 ); 
	printf("auxiliares: %016llX\n",aux210 );
	printf("auxiliares: %016llX\n",aux211 );
	printf("auxiliares: %016llX\n",aux212 );
	printf("auxiliares: %016llX\n",aux213 );
	printf("auxiliares: %016llX\n",aux214 );
	printf("auxiliares: %016llX\n",aux215 );
	printf("auxiliares: %016llx\n",aux216 );*/

	//printf("hola%"PRIx64"\n",aux216 );
	/*
	mascaras=mascaraso;
	mascaras2=mascaraso2;
	mascaras3=mascaraso3;
	mascaras4=mascaraso4;
	*/
	salida=aux21^aux22^aux23^aux24^aux25^aux26^aux27^aux28^aux29^aux210^aux211^aux212^aux213^aux214^aux215^aux216;
	//printf("hola%"PRIx64"\n",salida );
	
	
	//salida=0xffffffffffffffff& salida;

	return salida;
}


unsigned char GSbox[]=	  {0x1,0xa,0x4,0xc,0x6,0xf,0x3,0x9,0x2,0xd,0xb,0x7,0x5,0x0,0x8,0xe};
unsigned char GSInversa[]={0xd,0x0,0x8,0x6,0x2,0xc,0x4,0xb,0xe,0x7,0x1,0xa,0x3,0x9,0xf,0x5};
unsigned char plainText[]={'H','o','l','a','c','o','m','o'};
unsigned char cadena[]={
	0x9a, 0xc1, 0x99, 0x54, 0xce, 0x13, 0x19, 0xb3,
    0x54, 0xd3, 0x22, 0x04, 0x60, 0xf7, 0x1c, 0x1e,'\0'
};

int regresaNumero(int numero){
	int resultado=0;
	int primeraParte=4*(numero/16);
	int use=numero%4;
	int segundaParte=16*((3*((numero%16)/4))+use%4);
	resultado= primeraParte+segundaParte+use;
	return resultado%64;
}

void imprimeCadena(unsigned char * cadena1){
	int i=0;
	printf("%d: ",strlen(cadena1) );
	for (i = 0; i < strlen(cadena1); i++)
	{
		printf("%c,",cadena1[i] );
	}
	printf("\n");
}
void imprimeCadenaHex(unsigned char* cadena2){
	int i=0;
	printf("%d: ",strlen(cadena2) );
	for ( i = 0; i < strlen(cadena2); i++)
	{
		printf("%x,", cadena2[i] );
	}
	printf("\n");
}
void pruebaregresaNumero(){
	for (int i = 0; i < 64; i++)
	{
		printf("%d--->%d\n",i,regresaNumero(i) );
		printf("salida: %d --->%d\n",i,(regresaNumero(i)-i)%64 );
	}
}
unsigned char * GS(unsigned char * texto){
	unsigned char salida[8];
	int i=0;
	unsigned char high;
	unsigned char low;
	if (strlen(texto)==8)
	{
		for (i = 0; i < 8; i++)
			{	
				//printf("%x\n",texto[i] );
				high=(texto[i]&0xf0)>>4;
				//printf("%x\n",high );
				low=(texto[i]&0x0f);
				high=GSbox[high];
				low=GSbox[low];
				//printf("%x %x\n",high,low );
				texto[i]=(high<<4)^low;
				//printf("salida: %x\n",texto[i] );
				high=0x00;
				low=0x00;
			}	
	}
	//texto=salida;

}
unsigned char * GSINV(unsigned char * texto){
	unsigned char salida[8];
	int i=0;
	unsigned char high;
	unsigned char low;
	if (strlen(texto)==8)
	{
		for (i = 0; i < 8; i++)
			{	
				//printf("%x\n",texto[i] );
				high=(texto[i]&0xf0)>>4;
				//printf("%x\n",high );
				low=(texto[i]&0x0f);
				high=GSInversa[high];
				low=GSInversa[low];
				//printf("%x %x\n",high,low );
				texto[i]=(high<<4)^low;
				//printf("salida: %x\n",texto[i] );
				high=0x00;
				low=0x00;
			}	
	}
	//texto=salida;

}
uint64_t  GSx(uint64_t * texto){
	int i=0;
	uint64_t mascara=0x0f;
	uint64_t salida=0;
	char obtenido=0;
	uint64_t anadir;
	for (i = 0; i < 16; ++i)
		{
			//printf("%d\n",i );
			//printf("%016llx\n",mascara<<(4*i) );
			//printf("%016llx\n",((mascara<<(4*i))&(*texto))>>(4*i) );
			obtenido=((mascara<<(4*i))&(*texto))>>(4*i) ;
			//printf("1 %016llx\n",obtenido );
			obtenido=GSbox[obtenido];
			anadir=obtenido;
			//printf("2 %016llx\n",obtenido );
			//printf("por meter: %016llx\n",anadir<<(4*i) );
			salida=salida^(anadir<<(4*i));
			//printf("salida: %016llx\n",salida );
		}
		//printf("salida: %016llx\n",salida );
	return salida;
}
uint64_t  GSxinv(uint64_t * texto){
	int i=0;
	uint64_t mascara=0x0f;
	uint64_t salida=0;
	char obtenido=0;
	uint64_t anadir;
	for (i = 0; i < 16; ++i)
		{
			//printf("%d\n",i );
			//printf("%016llx\n",mascara<<(4*i) );
			//printf("%016llx\n",((mascara<<(4*i))&(*texto))>>(4*i) );
			obtenido=((mascara<<(4*i))&(*texto))>>(4*i) ;
			//printf("1 %016llx\n",obtenido );
			obtenido=GSInversa[obtenido];
			anadir=obtenido;
			//printf("2 %016llx\n",obtenido );
			//printf("por meter: %016llx\n",anadir<<(4*i) );
			salida=salida^(anadir<<(4*i));
			//printf("salida: %016llx\n",salida );
		}
		//printf("salida: %016llx\n",salida );
	return salida;
}
unsigned char * PermBits(unsigned char * state){
	int indice=0;
	unsigned char* salida;
	for (int i = 0; i < 8; i++)//cadena[]
	{
		for (int j = 0; j < 8; ++j)
		{
			// i9

		}
	}
}
/*


*/
uint8_t constantes[]={0x01,0x03,0x07,0x0f,0x1f,0x3e,0x3d,0x3b,
					0x37,0x2f,0x1e,0x3c,0x39,0x33,0x27,
					0x0e,0x1d,0x3a,0x35,0x2b,0x16,0x2c,
					0x18,0x30,0x21,0x02,0x05,0x0b};
uint16_t mascasKey[]={0x0001,0x0002,0x0004,0x0008,0x0010,0x0020,0x0040,0x0080,0x0100,0x0200,0x0400,0x0800,0x1000,0x2000,0x4000,0x8000};

uint64_t xorData(uint32_t * stateKey, uint8_t  constantes){
	uint32_t u32=(0xffff0000 & (*stateKey));
	uint16_t u=u32>>16;
	uint16_t v=0x0000ffff & (*stateKey);
	uint64_t llaveCompleta=0;
	uint64_t bitEncontradou=0;
	uint64_t bitEncontradov=0;
	uint64_t constanteCompleta=0x8000000000000000;
	uint64_t constanteEncontrada=0;
	int i=0;
	int a=3;
	for(i=0; i<16; i++){
		bitEncontradou=mascasKey[i]&u;
		bitEncontradov=mascasKey[i]&v;
		bitEncontradou=bitEncontradou>>i;
		bitEncontradov=bitEncontradov>>i;
		//printf("bitEncontradou %016llx \n",bitEncontradou);

		bitEncontradou=bitEncontradou<<((4*i)+1);
		bitEncontradov=bitEncontradov<<(4*i);
		//printf("bitEncontradou %016llx \n",bitEncontradou);
		//printf("bitEncontradov %016llx \n",bitEncontradov);
		llaveCompleta=llaveCompleta^bitEncontradou^bitEncontradov;
		//mascasKey[0]+=0x1;
		//printf("creacion de la llave: %016llx \n", llaveCompleta );
	}
	for (int i = 0; i < 6; ++i)
	{
			constanteEncontrada=mascasKey[i]&constantes;
			constanteEncontrada=constanteEncontrada>>i;
			constanteCompleta=constanteCompleta^(constanteEncontrada<<a);
			a+=4;
			//printf("constanteComplet: %016llx\n",constanteCompleta );
	}
	//printf("llave sin constantes %016llx \n",llaveCompleta  );
	llaveCompleta=llaveCompleta^constanteCompleta;
	//printf("creacion de la llave: %016llx \n", llaveCompleta );
	//uint32_t mascasKey[];

	//printf("%016llx \n",0x00a40+0x2 );
	//printf("stateKey: %016llx \n",*stateKey );
	//printf("U %016llx \n",u );
	//printf("V %016llx \n",v);

	return llaveCompleta;
}
unsigned char twe=0x00;
/*

int encript( uint64_t texto, uint64_t * textocifrado, unsigned char twek, uint64_t key, uint64_t key2, uint64_t * Keys){


}
*/
int genKey(uint64_t key, uint64_t key2, uint64_t * Keys){
		for (int i = 0; i < 28; ++i)
	{
		uint32_t cacho=0xffffffff & key;
		Keys[i]=xorData(&cacho,constantes[i]);/////
		uint32_t u32=(0xffff0000 & (cacho));
		uint16_t u=u32>>16; uint16_t copiau=u;
		uint16_t v=0x0000ffff & (cacho); uint16_t copiav=v;
		uint64_t corridou=0xffff&((u>>2)^(copiau<<14));
		uint64_t corridov=0xffff&((v>>12)^(copiav<<4));
		key=key>>32;
		uint64_t dosa1=key2&0xffffffff;
		dosa1=dosa1<<32;
		key=key^dosa1;
		key2=key2>>32;
		key2^=(corridou<<48)^(corridov<<32);
	}

}
int genTwek(unsigned char twe, uint64_t * tweA)
{
		uint64_t mas=0x01;
	uint64_t tweF=0;
	//uint64_t tweA=0;
	unsigned char twe0=0x01&twe;
	unsigned char twe1=(0x02&twe)>>1;
	unsigned char twe2=(0x04&twe)>>2;
	unsigned char twe3=(0x08&twe)>>3;
	unsigned char twex=twe0^twe1^twe2^twe3;
	unsigned char twese=0;
	uint64_t au=0;
	twese=twe;
	twese^=(twex^twe0)<<4;
	twese^=(twex^twe1)<<5;
	twese^=(twex^twe2)<<6;
	twese^=(twex^twe3)<<7;
	for (int i = 0; i < 2; ++i)
	{
		tweF^=twese<<(i*8);
	}
	//printf("%016llx \n",tweF );
	for (int i = 0; i < 15; ++i)
	{
		au=(tweF&mas)>>i;
		*tweA^=au<<((4*i)+2);
		mas=mas<<1;
	}
	//printf("%016llx twe\n", *tweA );
}
int cifrar(uint64_t twek, uint64_t *textoplano,uint64_t *textocifrado, uint64_t * Keys){
	uint64_t salida=0;
	for (int i = 0; i < 28; ++i)
	{
	
		salida=GSx(textoplano);
		salida=permutacion(&salida);
		*textocifrado=salida^Keys[i];
		if (((i+1)%4)==0 && i!=27)
		{
			//printf("%d\n",i );
			*textocifrado=*textocifrado^twek;
		}
	}
}
int descifrar(uint64_t twek, uint64_t *textoplano,uint64_t *textocifrado, uint64_t * Keys){
	for (int i =27 ; i>=0; --i)
	{
		if (i!=27 && ((i+1)%4==0))
		{
			//printf("%d\n",i );
			*textoplano=*textoplano^twek;
		}
		*textoplano=*textoplano^Keys[i];
		//printf("cifrado %016llx \n",textoplano );
		*textoplano=despermutacion(textoplano);
		//printf("permutacion %016llx \n", textoplano );
		*textoplano=GSxinv(textoplano);
		
		//printf("texto GS %016llx\n",textoplano );
	}
}
int Ek(unsigned char twek, uint64_t key1, uint64_t key2, uint64_t textoplano, uint64_t * textocifrado){
	uint64_t tweA=0;
	genTwek(twek,&tweA);
	uint64_t Keys[28];
	genKey(key1,key2,Keys);
	cifrar(tweA, &textoplano, textocifrado, Keys);
	//descifrar(tweA,&textocifrado,&textoplano,Keys);
	/*
	printf("texto Cifrado: %016llx \n",*textocifrado);
	descifrar(tweA,textocifrado,&textoplano,Keys);
	printf("texto descifrado: %016llx \n",textoplano );
	*/
}

int main(int argc, char const *argv[])
{	
	uint64_t textocifrado=0;
	Ek(0x04,key,key2,textoplano, &textocifrado);
	printf("texto Cifrado: %016llx \n",textocifrado);
	/*
	printf("texto Cifrado: %016llx \n",textocifrado);
	descifrar(tweA,&textocifrado,&textoplano,Keys);
	printf("texto descifrado: %016llx \n",textoplano );
	*/
}

