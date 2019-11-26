/*codigo por Israel Martinez*/
#include <stdio.h>
#include <string.h>
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
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; ++j)
		{
			

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
	printf("%x\n",(0x4<<4)^0x1);
	GS(plainText);
	imprimeCadena(plainText);
	//pruebaregresaNumero();
	//printf("%d\n",sizeof(plainText) );
	return 0;
}
