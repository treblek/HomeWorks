#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

void sayilariAl(int *dizi,int diziBoyutu);
void ayristir(int *,int ,int,int **);
void yazdir(int*,int);
int *donenEleman;
int main(void)
{
	uint8_t diziBoyutu,tamSayiDegeri;
	printf("Dizi boyutunu giriniz.");
	scanf("%d",&diziBoyutu);
	while(diziBoyutu<2||diziBoyutu>20)
	{
		printf("n Değeri 1 ila 21 arasinda bir sayi olmalidir.");
		scanf("%d",&diziBoyutu);
	}
	int *dizi = (int*)malloc(sizeof(int)*diziBoyutu);
	sayilariAl(dizi,diziBoyutu);
	printf("Bir tamsayi degeri giriniz.");
	scanf("%d",&tamSayiDegeri);
	ayristir(dizi,diziBoyutu,tamSayiDegeri,&donenEleman);
	yazdir(donenEleman,diziBoyutu);
	return -1;
}
void yazdir(int *dizininIlkElemani ,int diziBoyutu)
{
	uint8_t donguDegiskeni = 0,ikinciDonguDegiskeni;
	for(;donguDegiskeni <diziBoyutu;donguDegiskeni++)
	{
		printf("%d",*(donenEleman+donguDegiskeni));
	}
	printf("\n\n");
	for(ikinciDonguDegiskeni = diziBoyutu;ikinciDonguDegiskeni <diziBoyutu;ikinciDonguDegiskeni++)
	{
		printf("%d",*(donenEleman+ikinciDonguDegiskeni));
	}
}
void sayilariAl(int *dizi,int diziBoyutu)
{
	uint8_t donguDegiskeni =0;
	for(;donguDegiskeni<diziBoyutu;donguDegiskeni++)
	{
		printf("Dizinin %d. elemani : ",donguDegiskeni+1);
		scanf("%d",&dizi[donguDegiskeni]);
	}
}
void ayristir(int *dizi,int diziBoyutu,int tamSayiDegeri,int **donenEleman)
{
	uint8_t donguDegiskeni=0,ikinciDonguDegiskeni =0,kucukEsit=0,buyuk=0,ucuncuDonguDegiskeni=0,dorduncuDonguDegiskeni=0;
	int **donecekDizi = (int**)malloc(sizeof(int)*2);
	for(;donguDegiskeni<diziBoyutu;donguDegiskeni++)
	{
		donecekDizi[donguDegiskeni] = (int*)malloc(sizeof(int)*diziBoyutu);
	}
	for(;ikinciDonguDegiskeni<diziBoyutu;ikinciDonguDegiskeni++)
	{
		if(dizi[ikinciDonguDegiskeni]<=tamSayiDegeri)
		{
			donecekDizi[1][kucukEsit] = dizi[kucukEsit];
			kucukEsit++;
		}
		else
		{
			donecekDizi[0][buyuk] = dizi[buyuk];
			buyuk++;
		}
	}
	for(ucuncuDonguDegiskeni = kucukEsit;ucuncuDonguDegiskeni<diziBoyutu;ucuncuDonguDegiskeni++)
	{
		donecekDizi[1][ucuncuDonguDegiskeni] = 0;
	}
	for(dorduncuDonguDegiskeni = buyuk;dorduncuDonguDegiskeni<diziBoyutu;dorduncuDonguDegiskeni++)
	{
		donecekDizi[0][dorduncuDonguDegiskeni] = 0;
	}
	donenEleman =  donecekDizi;
}
