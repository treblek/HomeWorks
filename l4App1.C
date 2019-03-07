/* Çağrıldığı yerden bir isim alan ve bu ismi tekrarlayan bir şekilde aşağıdaki örnekteki gibi
yeniden yazarak çağrıldığı yere geri gönderen bir fonksyion yazınız.*/


#include "stdio.h"
#include "stdint.h"
#include "stdint.h"
#include "stdlib.h"
void yazdir(char*);
uint8_t karakterSayisi(char*);

int main(void)
{
	char *kelime;
	printf("Kelime:");
	gets(kelime);
	yazdir(kelime);
}

void yazdir(char* gonderilenKelime)
{
	system("cls");
	int8_t donguDegiskeni,ikinciDonguDegiskeni;//gonca
	for(donguDegiskeni=0;donguDegiskeni<=karakterSayisi(gonderilenKelime);donguDegiskeni++)
	{
		
		for(ikinciDonguDegiskeni =0;ikinciDonguDegiskeni <donguDegiskeni;ikinciDonguDegiskeni++)
		{
			printf("%c",*(gonderilenKelime+ikinciDonguDegiskeni));
		}
	}
}

uint8_t karakterSayisi(char*gonderilenKelime)
{
	uint8_t karakterSayisi=0;
	while(*(gonderilenKelime+karakterSayisi) != '\0')
			karakterSayisi++;
	return karakterSayisi;
}
