#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
void sayilariAl(int[],uint8_t); // for döngüsü ile sayıları alır.
void karsilastir(int[],int[],uint8_t); // karşılaştırma işlemini yapıp sayıları mainden yollanan yeni diziye aktarır.
void yazdir(int[],uint8_t);//yeni diziyi yazdırır.

int main(void)
{
	uint8_t nDegeri,donguDegiskeni = 0;
	printf("n degerini giriniz.");
	scanf("%d",&nDegeri);
	while(nDegeri<2||nDegeri>=30)
	{
		printf("n degeri 1 ila 30 arasinda olmalidir.");
		scanf("%d",&nDegeri);
	}
	system("cls");
	int *matris = (int*)malloc(sizeof(int)*nDegeri);
	int *ikinciMatris = (int*)malloc(sizeof(int)*(nDegeri-1));
	
	sayilariAl(matris,nDegeri);
	karsilastir(matris,ikinciMatris,nDegeri);
	yazdir(ikinciMatris,nDegeri);
	
	
	return -1;
}
void yazdir(int ikinciMatris[],uint8_t nDegeri)
{
	uint8_t donguDegiskeni=0;
	for(;donguDegiskeni<nDegeri-1;donguDegiskeni++)
	printf("b[%d] = %d\n",donguDegiskeni,ikinciMatris[donguDegiskeni]);
}
void karsilastir(int matris[],int ikinciMatris[],uint8_t nDegeri)
{
	uint8_t donguDegiskeni = 0;
	for(;donguDegiskeni <nDegeri-1;donguDegiskeni++)
	{
		if(matris[donguDegiskeni]<matris[donguDegiskeni+1])
		{
			ikinciMatris[donguDegiskeni] = matris[donguDegiskeni+1];
		}
		else
		{
			ikinciMatris[donguDegiskeni] = matris[donguDegiskeni];
		}
	}
}
void sayilariAl(int matris[],uint8_t nDegeri)
{
	uint8_t donguDegiskeni = 0;
	for(;donguDegiskeni <nDegeri;donguDegiskeni++)
	{
		printf("a[%d]",donguDegiskeni);
		scanf("%d",&matris[donguDegiskeni]);
	}
	system("cls");
}
