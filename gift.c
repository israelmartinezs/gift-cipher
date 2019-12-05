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
	uint64_t ref=0;
	aux21=aux1;
	ref=aux2 & 0xffff000000000000;	aux22=((aux2<<16)^(ref>>48));
	ref=aux3 & 0xffffffff00000000;	aux23=((aux3<<32)^(ref>>32)); 
	ref=aux4 & 0xffffffffffff0000;	aux24=((aux4<<48)^(ref>>16));
	ref=aux5 & 0xfffffffffffffff0;	aux25=((aux5<<60)^(ref>>4)); ////
	ref=aux6 & 0xfff0000000000000;	aux26=((aux6<<12)^(ref>>52));
	ref=aux7 & 0xfffffffffff00000;	aux27=((aux7<<44)^(ref>>20));
	ref=aux8 & 0xfffffff000000000;	aux28=((aux8<<28)^(ref>>36));
	ref=aux9 & 0xffffffff0fffff00;	aux29=((aux9<<56)^(ref>>8));
	ref=aux10 & 0xff00000000000000;	aux210=((aux10<<8)^(ref>>56));
	ref=aux11 & 0xffffffffff000000;	aux211=((aux11<<40)^(ref>>24));       
	ref=aux12 & 0xffffffff00000000;	aux212=((aux12<<24)^(ref>>40));
	ref=aux13 & 0xf000000000000000;	aux213=((aux13<<4)^(ref>>60));
	ref=aux14 & 0xfffffffffffff000;	aux214=((aux14<<52)^(ref>>12));
	ref=aux15 & 0xfffff00000000000;	aux215=((aux15<<20)^(ref>>44));    
	ref=aux16 & 0xfffffffff0000000;	aux216=((aux16<<36)^(ref>>28)); 
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
	printf("auxiliares: %016llx\n",aux216 );
	//printf("hola%"PRIx64"\n",aux216 );
	salida=aux21^aux22^aux23^aux24^aux25^aux26^aux27^aux28^aux29^aux210^aux211^aux212^aux213^aux214^aux215^aux216;
	//printf("auxisalida: %"PRIx64"\n",salida );
	
	
	//printf("permutacionin: %"PRIx64"\n",despermutacion(&salida) );

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
	//printf("despermutacion\n");

	aux1^=((*texto) &  mascaras[0]); aux2^=((*texto) &  mascaras[1]); aux3^=((*texto)& mascaras[2]); aux4^=((*texto)&mascaras[3]);
	aux5^=((*texto) &  mascaras2[0]); aux6^=((*texto) &  mascaras2[1]); aux7^=((*texto)& mascaras2[2]); aux8^=((*texto)&mascaras2[3]);
	aux9^=((*texto) &  mascaras3[0]); aux10^=((*texto) &  mascaras3[1]); aux11^=((*texto)& mascaras3[2]); aux12^=((*texto)&mascaras3[3]);
	aux13^=((*texto) &  mascaras4[0]); aux14^=((*texto) &  mascaras4[1]); aux15^=((*texto)& mascaras4[2]); aux16^=((*texto)&mascaras4[3]);
	//uint64_t mascaras[]={0x0008000400020001,0x0001000800040002,0x0002000100080004,0x0004000200010008};
	uint64_t ref=0;
	aux21=aux1;
	ref=aux2 & 0xffffffffffff0000;	aux22=((aux2<<48)^(ref>>16));
	ref=aux3 & 0xffffffff00000000;	aux23=((aux3<<32)^(ref>>32)); 
	ref=aux4 & 0xffff000000000000;	aux24=((aux4<<16)^(ref>>48));
	ref=aux5 & 0xf000000000000000;	aux25=((aux5<<4)^(ref>>60)); 
	ref=aux6 & 0xfffffffffffff000;	aux26=((aux6<<52)^(ref>>12));
	ref=aux7 & 0xfffff00000000000;	aux27=((aux7<<20)^(ref>>44));
	ref=aux8 & 0xfffffffff0000000;	aux28=((aux8<<36)^(ref>>28));
	ref=aux9 & 0xff00000000000000;	aux29=((aux9<<8)^(ref>>56));
	ref=aux10 & 0xffffffffffffff00;	aux210=((aux10<<56)^(ref>>8));
	ref=aux11 & 0xffffff0000000000;	aux211=((aux11<<24)^(ref>>40));       
	ref=aux12 & 0xffffffffff000000;	aux212=((aux12<<40)^(ref>>24));
	ref=aux13 & 0xfffffffffffffff0;	aux213=((aux13<<60)^(ref>>4));
	ref=aux14 & 0xfff0000000000000;	aux214=((aux14<<12)^(ref>>52));
	ref=aux15 & 0xfffffffffff00000;	aux215=((aux15<<44)^(ref>>20));    
	ref=aux16 & 0xfffffff000000000;	aux216=((aux16<<28)^(ref>>36)); 
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
	printf("auxiliares: %016llx\n",aux216 );

	//printf("hola%"PRIx64"\n",aux216 );
	salida=aux21^aux22^aux23^aux24^aux25^aux26^aux27^aux28^aux29^aux210^aux211^aux212^aux213^aux214^aux215^aux216;
	//printf("hola%"PRIx64"\n",salida );
	
	


	return salida;
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
	uint64_t salidapermutacion=permutacion(&textoplano);
	printf("permutacion: %016llx\n", salidapermutacion );
	uint64_t salidaPermutacionInversa=despermutacion(&salidapermutacion);
	printf("salidaPermutacionInversa: %016llx\n", salidaPermutacionInversa);
	//printf("permutacionin: %"PRIx64"\n",despermutacion(&textoplano) );
	//imprimeCadenaHex(plainText);
	//(*plainText+0)^(0x1);
	//imprimeCadenaHex(plainText);
	//(*plainText+0)|(0x1);
	//imprimeCadenaHex(plainText);
	//printf("%x\n",plainText[0] );
	//printf("%x\n",(*plainText+0) & (0x0<<3));
	//printf("%x\n",(0x4<<4)^0x1);
	//GS(plainText);
	//imprimeCadena(plainText);
	//pruebaregresaNumero();
	//printf("%d\n",sizeof(plainText) );
	return 0;
}



//juan.perezmar@issste.gob.mx
//3233440431112222
//3233440431012222
