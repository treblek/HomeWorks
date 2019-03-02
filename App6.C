#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "conio.h"
void sifirla(int **,uint8_t);
void duzenle(int **,uint8_t);
void yazdir(int **,uint8_t);

int main(void)
{
	uint8_t matrisBoyutu,donguDegiskeni=0;
	printf("Kare matrisin boyutu:");
	scanf("%d",&matrisBoyutu);
	if(matrisBoyutu<2||matrisBoyutu>10)
	{
		printf("Matris boyutu 1 ila 11 arasinda olmalidir.");
		scanf("%d",&matrisBoyutu);
	}
	int **kareMatris = (int**)malloc(sizeof(int*)*matrisBoyutu);
	
	
	for(;donguDegiskeni<matrisBoyutu;donguDegiskeni++)
	*(kareMatris+donguDegiskeni)= (int*)malloc(sizeof(int)*matrisBoyutu);
		
	sifirla(kareMatris,matrisBoyutu);
	duzenle(kareMatris,matrisBoyutu);
	yazdir(kareMatris,matrisBoyutu);
	return -1;
}
void sifirla(int **kareMatris,uint8_t matrisBoyutu)
{
	uint8_t donguDegiskeni=0,ikinciDonguDegiskeni;
	for(donguDegiskeni;donguDegiskeni<matrisBoyutu;donguDegiskeni++)
	{
		for(ikinciDonguDegiskeni =0;ikinciDonguDegiskeni<matrisBoyutu;ikinciDonguDegiskeni++)
		{
								kareMatris[donguDegiskeni][ikinciDonguDegiskeni] = 0;
		}
	}
}
void duzenle(int **kareMatris,uint8_t matrisBoyutu)
{
	uint8_t donguDegiskeni=0;
			for(;donguDegiskeni<matrisBoyutu;donguDegiskeni++)
			{//0 4 1 3 2 2 3 1 4 0
				kareMatris[donguDegiskeni][donguDegiskeni]=1;
				kareMatris[donguDegiskeni][(matrisBoyutu-1)-donguDegiskeni]=1;
			
			}
			
	}

void yazdir(int **kareMatris,uint8_t matrisBoyutu)
{
	uint8_t donguDegiskeni,ikinciDonguDegiskeni;
	for(donguDegiskeni=0;donguDegiskeni<matrisBoyutu;donguDegiskeni++)
	{
		for(ikinciDonguDegiskeni =0;ikinciDonguDegiskeni<matrisBoyutu;ikinciDonguDegiskeni++)
		{
			printf("%d ",kareMatris[donguDegiskeni][ikinciDonguDegiskeni]);
		}
		printf("\n");
	}
}
