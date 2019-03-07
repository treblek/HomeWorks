/*En fazla 100 karakterden oluşan dizgileri girdi olarak alınız. Bu dizgiler boş bir karakterle
birbirinden ayrılmış olan kelimelerden oluşmaktadır. Her dizginin içinde yer alan kelimelerin
ilk harflerini görüntüleyiniz. Dizgilerin girilme işlemi boş bir dizgi girilinceye kadar devam
etmelidir. Ayrıca, dizgide yer alan kelimelerin ilk harflerinin bulunmasını bir fonksiyonda
yapınız. Bu fonksiyon bir dizgiyi parametre olarak almalı ve her kelimenin ilk harfinden oluşan
kısaltmayı çağrıldığı yere geri döndürmelidir.*/


#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

uint8_t karakterSayisi(char* karakterDizisi);//dizideki karakter sayısını veren fonksiyon
char* kisaltVeDonder(char*);//boslukları kaldır fonksiyonunda nereden başladığını ve diziyi yollarsak yollanan noktadan başlayarak hepsini bir birim sağa kaydırır


int main(void)
{
	char *karakterDizisi,*kisaltilmisDizi;
	printf("Cumle:");
	gets(karakterDizisi);
	kisaltilmisDizi = kisaltVeDonder(karakterDizisi);
	printf("%s",kisaltilmisDizi);
	return -1;
}
char* kisaltVeDonder(char* karakterDizisi)
{
	uint8_t kisaltilmisDiziUzunlugu = 1; // ilk harfi döngüde saymadığımız için burada ekledim.
	uint8_t donguDegiskeni;
	for(donguDegiskeni=0;donguDegiskeni<karakterSayisi(karakterDizisi);donguDegiskeni++)
	{
		if(*(karakterDizisi+donguDegiskeni) == ' ') kisaltilmisDiziUzunlugu++; // burada oluşturacağımız ve döndüreceğimiz dizinin uzunluğunu hesapladık
	}
	
	char *kisaltilmisDizi = (char*)malloc(sizeof(char)*(kisaltilmisDiziUzunlugu+1)); // Burada kısaltılmış dizimizi oluturduk

	if(*karakterDizisi >=97 && *karakterDizisi<=122) // Burada dizinin ilk harfini atadık kalanları boşluklardan tespit edeceğiz.
	{
		*kisaltilmisDizi = *karakterDizisi-32;
	}
	else
	{
		*kisaltilmisDizi = *karakterDizisi;
	}
	
	
	
	uint8_t yardimciDonguDegiskeni=1;
	for(donguDegiskeni = 0;donguDegiskeni<karakterSayisi(karakterDizisi);donguDegiskeni++)// Burada boşlukları bulup sonrakileri büyülteceğiz
	{
		if(*(karakterDizisi+donguDegiskeni) == ' ')
		{
			if(*(karakterDizisi+donguDegiskeni+1)>=97 && *(karakterDizisi+donguDegiskeni+1)<=122)
			{
				*(kisaltilmisDizi+yardimciDonguDegiskeni) = *(karakterDizisi+donguDegiskeni+1)-32; 
				yardimciDonguDegiskeni++;
			}
			else
			{
				*(kisaltilmisDizi+yardimciDonguDegiskeni) = *(karakterDizisi+donguDegiskeni+1); 
				yardimciDonguDegiskeni++;
			}
		}
	}
	
	*(kisaltilmisDizi+kisaltilmisDiziUzunlugu) = '\0'; // burada son karaktere boşluk koyduk
	return kisaltilmisDizi;
}
uint8_t karakterSayisi(char* karakterDizisi)
{
	uint8_t karakterSayisi;
	while(*(karakterSayisi+karakterDizisi) != '\0')
	karakterSayisi++; return karakterSayisi;
}
