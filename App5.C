#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "conio.h"

#define matrisSutunBoyutu 2
#define matrisSatirBoyutu 5

void sayilariAl(float**);
void hesaplaVeYazdir(float**);
int main(void)
{
	uint8_t donguDegiskeni;
	float **matris = (float**)malloc(sizeof(float*)*matrisSatirBoyutu);
	for(donguDegiskeni=0;donguDegiskeni<matrisSatirBoyutu;donguDegiskeni++)
	matris[donguDegiskeni] = (float*)malloc(sizeof(float)*matrisSutunBoyutu);
	
	sayilariAl(matris);
	hesaplaVeYazdir(matris);
	return -1;
}
void hesaplaVeYazdir(float**matris)
{
	uint8_t donguDegiskeni,ikinciDonguDegiskeni,ucuncuDonguDegiskeni,dorduncuDonguDegiskeni,ikinciYardimciDegisken,yardimciDegisken;
	float ucuncuYardimciDegisken,dorduncuYardimciDegisken;
	float *satirOrtalamalari = (float *)malloc(sizeof(float)*matrisSatirBoyutu);
	float *sutunOrtalamalari = (float *)malloc(sizeof(float)*matrisSutunBoyutu);
	yardimciDegisken = 0;
	dorduncuYardimciDegisken=0;
	for(donguDegiskeni=0;donguDegiskeni<matrisSatirBoyutu;donguDegiskeni++)
	{
		for(ucuncuDonguDegiskeni =0;ucuncuDonguDegiskeni<matrisSutunBoyutu;ucuncuDonguDegiskeni++)
		{
			dorduncuYardimciDegisken +=matris[yardimciDegisken][ucuncuDonguDegiskeni];
		}
		satirOrtalamalari[donguDegiskeni] = dorduncuYardimciDegisken/matrisSutunBoyutu;
		yardimciDegisken++;
		dorduncuYardimciDegisken=0;
	}
	
	ucuncuYardimciDegisken=0;
	for(ikinciDonguDegiskeni=0;ikinciDonguDegiskeni<matrisSutunBoyutu;ikinciDonguDegiskeni++)
	{
		for(dorduncuDonguDegiskeni =0;dorduncuDonguDegiskeni<matrisSatirBoyutu;dorduncuDonguDegiskeni++)
		{
			ucuncuYardimciDegisken +=matris[dorduncuDonguDegiskeni][ikinciYardimciDegisken];
		}
		sutunOrtalamalari[ikinciDonguDegiskeni] = ucuncuYardimciDegisken/matrisSatirBoyutu;
		ucuncuYardimciDegisken =0;
		ikinciYardimciDegisken++;
	}
	
	
	uint8_t besinciDonguDegiskeni,altinciDonguDegiskeni;
	system("cls");
	printf("Satir ortalamalari:\n");
	for(besinciDonguDegiskeni=0;besinciDonguDegiskeni<matrisSatirBoyutu;besinciDonguDegiskeni++)
	{
		printf("Satir %d = %.2f\n",besinciDonguDegiskeni,satirOrtalamalari[besinciDonguDegiskeni]);
	}
	printf("\n\n\n");
	printf("Sutun ortalamari:\n");
	for(altinciDonguDegiskeni=0;altinciDonguDegiskeni<matrisSutunBoyutu;altinciDonguDegiskeni++)
	{
		printf("Sutun %d = %.2f\n",altinciDonguDegiskeni,sutunOrtalamalari[altinciDonguDegiskeni]);
	}
}
void sayilariAl(float**matris)
{
	uint8_t donguDegiskeni,ikinciDonguDegiskeni;
	for(donguDegiskeni =0;donguDegiskeni<matrisSatirBoyutu;donguDegiskeni++)
	{
		for(ikinciDonguDegiskeni=0;ikinciDonguDegiskeni<matrisSutunBoyutu;ikinciDonguDegiskeni++)
		{
			printf("[%d][%d]:",donguDegiskeni,ikinciDonguDegiskeni);
			scanf("%f",&matris[donguDegiskeni][ikinciDonguDegiskeni]);
		}
	}
}
