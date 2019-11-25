#include <stdio.h>
#include <string.h>
unsigned char plainText[]={'h','o','l','a','\0'};
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
/*


*/
int main(int argc, char const *argv[])
{
	int i=0;
	imprimeCadena(plainText);
	imprimeCadenaHex(cadena);
	printf("%x\n",cadena[0]&0xf );
	pruebaregresaNumero();
	return 0;
}
