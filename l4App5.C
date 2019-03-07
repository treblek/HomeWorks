#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "stdint.h"
//Sadece ilk bulduğunu siler.
uint8_t karakterSayisi(char*); // Dizi karakter sayısını dönderen fonksiyon
void bulVeSil(char*,char*);// Bulma ve silme işlemini yapan fonksiyon
int main(void)
{
	printf("Lutfen cumle giriniz.");
	char *karakterDizisi,*silinecekKarakterDizisi;
	gets(karakterDizisi);
	printf("Lutfen silinecek kelimeyi giriniz. ");
	gets(silinecekKarakterDizisi);
	system("cls");
	printf("Eski Hali :%s\n",karakterDizisi);
	bulVeSil(karakterDizisi,silinecekKarakterDizisi);
	printf("Yeni Hali %s",karakterDizisi);
		return -1;
}
void bulVeSil(char*karakterDizisi,char*silinecekKarakterDizisi)
{
	uint8_t donguDegiskeni,ikinciDonguDegiskeni,yardimciDegisken=0;
	for(donguDegiskeni=0;donguDegiskeni<karakterSayisi(karakterDizisi)-karakterSayisi(silinecekKarakterDizisi);donguDegiskeni++)
	{
		for(ikinciDonguDegiskeni=0;ikinciDonguDegiskeni<karakterSayisi(silinecekKarakterDizisi);ikinciDonguDegiskeni++)
		{
			if(*(karakterDizisi+donguDegiskeni+ikinciDonguDegiskeni) ==*(silinecekKarakterDizisi+ikinciDonguDegiskeni))
			{
				yardimciDegisken++;
			}
		}
		if(yardimciDegisken== karakterSayisi(silinecekKarakterDizisi))
		{
				for(ikinciDonguDegiskeni=0;ikinciDonguDegiskeni<karakterSayisi(silinecekKarakterDizisi);ikinciDonguDegiskeni++)
		{
			*(karakterDizisi+donguDegiskeni+ikinciDonguDegiskeni) =*(silinecekKarakterDizisi+ikinciDonguDegiskeni);
		}
		break;
		}
		yardimciDegisken =0;
	}
	for(ikinciDonguDegiskeni = donguDegiskeni;ikinciDonguDegiskeni<=karakterSayisi(karakterDizisi)-karakterSayisi(silinecekKarakterDizisi);ikinciDonguDegiskeni++)
	{
		*(karakterDizisi+ikinciDonguDegiskeni) = *(karakterDizisi+ikinciDonguDegiskeni+karakterSayisi(silinecekKarakterDizisi));
		*(karakterDizisi+ikinciDonguDegiskeni+karakterSayisi(silinecekKarakterDizisi)) = '0';
	}
}
uint8_t karakterSayisi(char*karakterDizisi)
{
	uint8_t donguDegiskeni=0;
	while(*(karakterDizisi+donguDegiskeni) != '\0')
	{
		donguDegiskeni++;
	}
	return donguDegiskeni;
}
