#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"


void sayilariAl(int**,uint8_t); // Sayıları kullanıcıdan alan foknsiyon.
void yenidenDuzenle(int **,uint8_t);//Sayıları yeniden sıralayan fonksiyon.
void yazdir(int **,uint8_t);//Sıralanmış sayıları yazdıran fonksiyon.

int main(void)
{
	uint8_t mDegeri,donguDegiskeni=0;
	printf("m giriniz.");
	scanf("%d",&mDegeri);
	while(mDegeri<=1||mDegeri>=10)
	{
		printf("m degeri 1 ila 10 arasinda olmalidir. Tekrar giriniz.");
		scanf("%d",&mDegeri);
	}
	system("cls");
	
	int **kareMatris = (int**)malloc(sizeof(int)*mDegeri);
	for(;donguDegiskeni<mDegeri;donguDegiskeni++)
	{
		kareMatris[donguDegiskeni] = (int*)malloc(sizeof(int)*mDegeri);
	}
	sayilariAl(kareMatris,mDegeri);
	yazdir(kareMatris,mDegeri);
	yenidenDuzenle(kareMatris,mDegeri);
	yazdir(kareMatris,mDegeri);
	return -1;
}
void yazdir(int **kareMatris,uint8_t mDegeri)
{
	uint8_t donguDegiskeni=0,ikinciDonguDegiskeni=0;
	for(;donguDegiskeni<mDegeri;donguDegiskeni++)
	{
		for(;ikinciDonguDegiskeni<mDegeri;ikinciDonguDegiskeni++)
		{
			printf("%d   ",kareMatris[donguDegiskeni][ikinciDonguDegiskeni]);
			}
		ikinciDonguDegiskeni=0;
		printf("\n");
	}
	printf("\n\n\n\n\n\n");
}
void yenidenDuzenle(int **kareMatris,uint8_t mDegeri)
{
	uint8_t donguDegiskeni=0;
	int yardimciDegisken;
	for(;donguDegiskeni<mDegeri;donguDegiskeni++)
	{
		yardimciDegisken = kareMatris[0][donguDegiskeni];
		kareMatris[0][donguDegiskeni] = kareMatris[mDegeri-1][donguDegiskeni];
		kareMatris[mDegeri-1][donguDegiskeni] = yardimciDegisken;
	}
}
void sayilariAl(int **kareMatris,uint8_t mDegeri)
{
	uint8_t donguDegiskeni =0,ikinciDonguDegiskeni =0;
	for(;donguDegiskeni<mDegeri;donguDegiskeni++)
		{
			for(;ikinciDonguDegiskeni<mDegeri;ikinciDonguDegiskeni++)
		{
		printf("[%d][%d]",donguDegiskeni,ikinciDonguDegiskeni);
		scanf("%d",&kareMatris[donguDegiskeni][ikinciDonguDegiskeni]);
	}
	ikinciDonguDegiskeni =0;
		}
		system("cls");
}
