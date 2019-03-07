/*Kullanıcıdan içinde boşlukların olduğu bir dizgiyi alan ve daha sonra tüm boşlukları
kaldırarak dizgiyi yeniden yazan bir program yaziniz.*/

/*4) Kullanıcıdan bir dizgi girmesini isteyen ve daha sonra bu dizgiyi aşağıdaki işi yapan bir
fonksiyona gönderen ve fonksiyondan gelen cevabı ekranda gösteren bir program yazınız.
Fonksiyon programdan gelen dizgideki bütün kelimeleri ilk harfleri büyük şekline
dönüştürerek geri göndermelidir.*/
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

void bosluklariKaldir(char* karakterDizisi);//Dizinin direk yollanacağı fonksiyon
uint8_t karakterSayisi(char* karakterDizisi);//dizideki karakter sayısını veren fonksiyon
void kaydir(char*,uint8_t);//boslukları kaldır fonksiyonunda nereden başladığını ve diziyi yollarsak yollanan noktadan başlayarak hepsini bir birim sağa kaydırır


int main(void)
{
	char *karakterDizisi;
	printf("Cumle:");
	gets(karakterDizisi);
	bosluklariKaldir(karakterDizisi);
	system("cls");
	printf("%s",karakterDizisi);
	return -1;
}
void bosluklariKaldir(char* karakterDizisi)
{
	uint8_t donguDegiskeni;
	for(donguDegiskeni = 0;donguDegiskeni<karakterSayisi(karakterDizisi);donguDegiskeni++)
	{
		if(*(karakterDizisi+donguDegiskeni)== ' ')
		{
			kaydir(karakterDizisi,donguDegiskeni);
		}
	}
}
void kaydir(char* karakterDizisi,uint8_t buradanBaslayarak)
{
	uint8_t donguDegiskeni;
	for(donguDegiskeni=0;donguDegiskeni<karakterSayisi(karakterDizisi)-buradanBaslayarak;donguDegiskeni++)
	{
		*(karakterDizisi+donguDegiskeni+buradanBaslayarak) = *(karakterDizisi+buradanBaslayarak+donguDegiskeni+1);
	}
	karakterDizisi = (char*)malloc(sizeof(char)*(karakterSayisi(karakterDizisi)));
}
uint8_t karakterSayisi(char* karakterDizisi)
{
	uint8_t karakterSayisi;
	while(*(karakterSayisi+karakterDizisi) != '\0')
	karakterSayisi++; return karakterSayisi;
}
