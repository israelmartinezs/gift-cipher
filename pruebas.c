#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include "funciones.h"
//typedef unsigned __int128 uint128_t;
//#include <inttypes.h>


int crypto_aead_decrypt(
	unsigned char *pt, unsigned long long *ptlen,
	unsigned char *nsec,
	const unsigned char *ct, unsigned long long ctlen,
	const unsigned char *ad, unsigned long long adlen,
	const unsigned char *npub,
	const unsigned char *k
){

}
int crypto_aead_encrypt(
	unsigned char *ct, unsigned long long *ctlen,
	 unsigned char *pt, unsigned long long ptlen,
	unsigned char *ad, unsigned long long adlen,
	unsigned char *nsec,
	unsigned char *npub,
	unsigned char *k
)
{
	uint64_t wxor=0;
	uint64_t c=0;
	uint64_t vxor=0;
	uint64_t kn1=0;
	uint64_t kn2=0;
	uint64_t n64p1=0;
	uint64_t n64p2=0;

	uint64_t deltan=0;
	//int div=numeroadlen?numeroadlen:(numeroadlen+1);
	uint64_t  * Key=(uint64_t *)k;
	uint64_t * npub64=(uint64_t *)npub; 
	//printf("%016llx \n", );
	printf("llave orignal 1 %016llx \n", Key[0] );
	printf("llave orignal 2 %016llx \n", Key[1] );
	printf("deltan %016llx \n", deltan);
	printf("vxor %016llx \n", vxor);
	//generar la llaves en 64 bits
	//genKeyFromChar(k,&kn1,&kn2);
	//generar nounce
	//genKeyFromChar(npub,&n64p1,&n64p2);
	//init
	//init(kn1, kn2, n64p1, n64p2, &kn1, &kn2, &deltan);
	printf("\n");
	printf("init\n");
	init(Key[0], Key[1], npub64[0], npub64[1], &kn1, &kn2, &deltan);
	printf("llave  1 %016llx \n", kn1 );
	printf("llave  2 %016llx \n", kn2 );
	printf("Deltan %016llx\n",deltan );
	//si tiene AD
	printf("\n");
	printf("AD\n");
	if (adlen!=0)
	{
		uint64_t * add=(uint64_t *)ad;
		proc_ad(&kn1,&kn2,&deltan,&vxor,add,adlen/8,adlen%8);
	}
	printf("llave  1 %016llx \n", kn1 );
	printf("llave  2 %016llx \n", kn2 );
	printf("vxor %016llx \n", vxor);

}
int proc_ad(uint64_t *kn1, uint64_t *kn2, uint64_t *deltan, uint64_t *vxor, uint64_t * ad, int bloques, int sobrante){
	uint64_t x,v;
	for (int i = 0; i < bloques; ++i)
	{
		x=ad[i]^*deltan;
		//multipicacion por dos
		Ek(0x2,*kn1,*kn2,x,&v);
		*vxor^=v;

	}
	
		uint64_t paddig=0;
		paddig=sobrante!=0?0x1:0x0;
		uint64_t salida=0;
		uint64_t llenado=0xffffffffffffffff;
		//uint64_t * cad=(uint64_t *)caden;
		salida=((llenado>>(((8-sobrante)*8)))&(ad[bloques]))^(paddig<<(sobrante*8));
	x=salida^*deltan;
	//multiplicacion por dos
	if (sobrante!=0)
	{
		Ek(0x3,*kn1,*kn2,x,&v);
	}
	else{
		Ek(0x2,*kn1,*kn2,x,&v);
	}
	*vxor^=v;

	
}

int init(uint64_t key1,uint64_t key2, uint64_t npub1, uint64_t npub2, uint64_t * kn1, uint64_t * kn2, uint64_t *deltan){
	uint64_t y=0;
	Ek(0x00, key1, key2, 0x0,&y);
	*kn1=key1^npub1;
	*kn2=key2^npub2;
	Ek(0x01, *kn1 ,*kn2, y, deltan);
}
int genKeyFromChar(unsigned char * k, uint64_t * key1, uint64_t * key2){
		*key1=0;
		*key2=0;
		*key2^=k[0]^(k[1]<<8)^(0x11&k[1]<<16)^((0x11&k[2])<<24)^((uint64_t)(k[3])<<32)^(((uint64_t)0x11&k[4])<<40)^(((uint64_t)k[5])<<48)^(((uint64_t)k[6])<<56);
		*key1=k[8]^(k[1]<<4)^(k[9]<<8)^(k[10]<<16)^(k[11]<<24)^((uint64_t)k[12]<<32)^((uint64_t)k[13]<<40)^((uint64_t)k[14]<<48)^((uint64_t)k[15]<<56);
		/*
		for (int i = 0; i < 16; ++i)
		{
			if (i<8)
			{
			key2=key2^k[i];	
			}
			key2=key2^k[i];
		}
		*/
}

uint64_t * char264bytes(char * datos, int datoslen, uint64_t * datossalida){
	printf("%s\n",datos );
	int bitsUsados=0;
	int ArreglosUsados=0;
	for (int i = 0; i <  datoslen ; ++i)

	{	

		if (bitsUsados<64)
		{
			datossalida[ArreglosUsados]=(datossalida[ArreglosUsados]<<8)^datos[i];
			bitsUsados+=8;
		}
		else{
			ArreglosUsados+=1;
			bitsUsados=0;
			datossalida[ArreglosUsados]=(datossalida[ArreglosUsados]<<8)^datos[i];
			//ArreglosUsados+=1;
			//bitsUsados=0;
			bitsUsados+=8;

		}
		//printf("%016llx : %d : %d : %d \n", datossalida[ArreglosUsados] , ArreglosUsados, bitsUsados, i);
	}
	
}

int main(int argc, char const *argv[])
{
	char  key []="hola esto es una llave";
	char nonce[]="";
	char nonceSec[]="";
	uint64_t k1=0;
	uint64_t k2=0;
	unsigned char AsociateData[]="israel Martinez Sanchez";
	char Message[]="Toda esa documentación la tienes que entregar en las oficinas de Conacyt, reciben hasta las 14";
	unsigned long long messageLen=sizeof(Message);
	char cipherText[messageLen];
	unsigned long long cipherTextLen=sizeof(cipherText);
	unsigned long long AsociateDataLen=sizeof(AsociateData);
	//char264bytes(AsociateData, strlen(AsociateData), AsociateDataBytes);
	//printf("%016llx \n",AsociateDataBytes[1] );




	crypto_aead_encrypt(cipherText, &cipherTextLen, Message, messageLen, AsociateData, AsociateDataLen, nonceSec, nonce,key );


	return 0;
}