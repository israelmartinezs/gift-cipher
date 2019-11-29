/*codigo por Israel Martinez*/
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
uint64_t textoplano = 0x1234123412341234;
uint64_t mascaras[]= {0x4000010000400001,0x8000020000800002,0x1000040000100004,0x2000080000200008};
uint64_t mascaras2[]={0x0004200008000020,0x0008400001000040,0x0002100004000010,0x0001800002000080};
uint64_t mascaras3[]={0x0080000210000400,0x0010000420000800,0x0040000180000200,0x0020000840000100};
uint64_t mascaras4[]={0x0200008000021000,0x0100004000018000,0x0400001000042000,0x0800002000084000};

uint64_t permutacion(uint64_t * texto){
	uint64_t salida=0;
	uint64_t aux1=0, aux2=0,aux3=0 aux4=0;
	uint64_t aux5=0, aux6=0,aux7=0 aux8=0;
	uint64_t aux9=0, aux10=0,aux11=0 aux12=0;
	uint64_t aux13=0, aux14=0,aux15=0 aux16=0;

	aux^=((*texto) &  mascaras[0]); aux2^=((*texto) &  mascaras[1]); aux3^=((*texto)& mascaras[2]); aux4^=((*texto)&mascaras[3]);
	aux5^=((*texto) &  mascaras2[0]); aux6^=((*texto) &  mascaras2[1]); aux7^=((*texto)& mascaras2[2]); aux8^=((*texto)&mascaras2[3]);
	aux9^=((*texto) &  mascaras3[0]); aux10^=((*texto) &  mascaras3[1]); aux11^=((*texto)& mascaras3[2]); aux12^=((*texto)&mascaras3[3]);
	aux13^=((*texto) &  mascaras4[0]); aux14^=((*texto) &  mascaras4[1]); aux15^=((*texto)& mascaras3[2]); aux16^=((*texto)&mascaras4[3]);
	//uint64_t mascaras[]={0x0008000400020001,0x0001000800040002,0x0002000100080004,0x0004000200010008};
	return aux;



}



unsigned char GSbox[]={0x1,0xa,0x4,0xc,0x6,0xf,0x3,0x9,0x2,0xd,0xb,0x7,0x5,0x0,0x8,0xe};
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
				printf("%x %x\n",high,low );
				texto[i]=(high<<4)^low;
				printf("salida: %x\n",texto[i] );
				high=0x00;
				low=0x00;
			}	
	}
	//texto=salida;

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
int main(int argc, char const *argv[])
{
	int i=0;
	//imprimeCadena(plainText);
	//imprimeCadenaHex(cadena);
	unsigned char ar=0xa>>4;
	///printf("%x\n",ar );
	printf("%"PRIx64"\n",permutacion(&textoplano) );
	imprimeCadenaHex(plainText);
	(*plainText+0)^(0x1);
	imprimeCadenaHex(plainText);
	(*plainText+0)|(0x1);
	imprimeCadenaHex(plainText);
	printf("%x\n",plainText[0] );
	printf("%x\n",(*plainText+0) & (0x0<<3));
	//printf("%x\n",(0x4<<4)^0x1);
	GS(plainText);
	imprimeCadena(plainText);
	//pruebaregresaNumero();
	//printf("%d\n",sizeof(plainText) );
	return 0;
}
