#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"


void degerleriAl(int**,uint8_t);
int* matrisTara(int**,uint8_t);
uint8_t tekSayiAdedi = 0;

int main(void)
{
	uint8_t donguDegiskeni,matrisBoyutu,ikinciDonguDegiskeni;
	int *donenDizininIlkDegeri;
	printf("Kare matrisin boyutunu giriniz (n<=10):");
	scanf("%d",&matrisBoyutu);
	while(matrisBoyutu<2||matrisBoyutu>10)
	{
		printf("Dizi boyutu 1 ila 11 arasinda olmalidir.");
		scanf("%d",&matrisBoyutu);
	}
	
	int **kareMatris = (int**)malloc(sizeof(int*)*matrisBoyutu);
	for(donguDegiskeni=0;donguDegiskeni<matrisBoyutu;donguDegiskeni++)
	kareMatris[donguDegiskeni] = (int*)malloc(sizeof(int)*matrisBoyutu);
	degerleriAl(kareMatris,matrisBoyutu);
	
	donenDizininIlkDegeri = matrisTara(kareMatris,matrisBoyutu);
	system("cls");
	printf("Tek sayilar dizisi:");
	for(ikinciDonguDegiskeni=0;ikinciDonguDegiskeni<tekSayiAdedi;ikinciDonguDegiskeni++)
	printf("  %d  ",donenDizininIlkDegeri[ikinciDonguDegiskeni]);
	
	
	return -1;
}

void degerleriAl(int**kareMatris,uint8_t matrisBoyutu)
{
	uint8_t donguDegiskeni,ikinciDonguDegiskeni;
	for(donguDegiskeni=0;donguDegiskeni<matrisBoyutu;donguDegiskeni++)
	{
		for(ikinciDonguDegiskeni=0;ikinciDonguDegiskeni<matrisBoyutu;ikinciDonguDegiskeni++)
		{
			printf("[%d][%d]",donguDegiskeni,ikinciDonguDegiskeni);
			scanf("%d",&kareMatris[donguDegiskeni][ikinciDonguDegiskeni]);
		}
	}
}

int* matrisTara(int**kareMatris,uint8_t matrisBoyutu)
{
	uint8_t donguDegiskeni,ikinciDonguDegiskeni,ucuncuDonguDegiskeni=0;
	for(donguDegiskeni=0;donguDegiskeni<matrisBoyutu;donguDegiskeni++)
	{
		for(ikinciDonguDegiskeni=0;ikinciDonguDegiskeni<matrisBoyutu;ikinciDonguDegiskeni++)
		{
			if(kareMatris[donguDegiskeni][ikinciDonguDegiskeni]%2!=0)
			{
				tekSayiAdedi++;
			}
		}
	}
	int *donecekMatris = (int*)malloc(sizeof(int)*tekSayiAdedi);
	
	for(donguDegiskeni=0;donguDegiskeni<matrisBoyutu;donguDegiskeni++)
	{
		for(ikinciDonguDegiskeni=0;ikinciDonguDegiskeni<matrisBoyutu;ikinciDonguDegiskeni++)
		{
			if(kareMatris[donguDegiskeni][ikinciDonguDegiskeni]%2!=0)
			{
			donecekMatris[ucuncuDonguDegiskeni] = kareMatris[donguDegiskeni][ikinciDonguDegiskeni];
			ucuncuDonguDegiskeni++;	
			}
		}
	}
	
	return donecekMatris;
}
