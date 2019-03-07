/*4) Kullanıcıdan bir dizgi girmesini isteyen ve daha sonra bu dizgiyi aşağıdaki işi yapan bir
fonksiyona gönderen ve fonksiyondan gelen cevabı ekranda gösteren bir program yazınız.
Fonksiyon programdan gelen dizgideki bütün kelimeleri ilk harfleri büyük şekline
dönüştürerek geri göndermelidir.*/

/*4) Kullanıcıdan bir dizgi girmesini isteyen ve daha sonra bu dizgiyi aşağıdaki işi yapan bir
fonksiyona gönderen ve fonksiyondan gelen cevabı ekranda gösteren bir program yazınız.
Fonksiyon programdan gelen dizgideki bütün kelimeleri ilk harfleri büyük şekline
dönüştürerek geri göndermelidir.*/
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

void ilkHarfleriBuyukYap(char*);
uint8_t karakterSayisi(char*); // Bir dizinin eleman sayısını veren fonksiyon

int main(void)
{
	char*karakterDizisi;
	printf("Girdi:");
	gets(karakterDizisi);
	ilkHarfleriBuyukYap(karakterDizisi);
	system("cls");
	printf("%s",karakterDizisi);
	
	return -1;
}
void ilkHarfleriBuyukYap(char* karakterDizisi)
{
	uint8_t donguDegiskeni;
	//alttaki ilk kelime hariç cümlenin geri kalanı
	for(donguDegiskeni=0;donguDegiskeni<karakterSayisi(karakterDizisi)-1;donguDegiskeni++)
	{
		if(*(karakterDizisi+donguDegiskeni)  == ' ')
		{
			if(*(karakterDizisi+donguDegiskeni+1) >=61 && *(karakterDizisi+donguDegiskeni+1)<=122)
			{
				*(karakterDizisi+donguDegiskeni+1) -=32 ;
			}
		}
	}
	// altta ise ilk elemanı kontrol eder.
	if(*karakterDizisi >=61 && *karakterDizisi<=122) *karakterDizisi -=32;
}
uint8_t karakterSayisi(char* karakterDizisi)
{
	uint8_t karakterSayisi;
	while(*(karakterSayisi+karakterDizisi) != '\0')
	karakterSayisi++; return karakterSayisi;
}
