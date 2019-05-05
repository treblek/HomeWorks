#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "string.h"

#define SEHIRSAYISI 3

typedef struct
{
	char *sehir_;
	float en_Yuksek_,en_Dusuk_;
}hava_analiz_;

void bilgileriAl(hava_analiz_*);
void analiz(hava_analiz_*);

int main()
{
	hava_analiz_ *_sehirler_;
	_sehirler_ = (hava_analiz_*)malloc(sizeof(hava_analiz_)*SEHIRSAYISI);
	bilgileriAl(_sehirler_);
	analiz(_sehirler_);
	
	return -1;
}

void bilgileriAl(hava_analiz_ *_sehirler_)
{
	uint8_t i;
	char veri[20];
	for(i=0;i<SEHIRSAYISI;i++)
	{
		printf("sehir");
		scanf("%s",veri);
		_sehirler_[i].sehir_ = (char*)malloc(sizeof(char)*(sizeof(veri)+1));
		strcpy(_sehirler_[i].sehir_,veri);
		printf("en yuksek sicaklik");
		scanf("%f",&_sehirler_[i].en_Yuksek_);
		printf("en dusuk sicaklik");
		scanf("%f",&_sehirler_[i].en_Dusuk_);
	}
}

void analiz(hava_analiz_ *veri)
{
	float enYuksekFark=0,enDusukFark=100;
	uint8_t i,enYuksekFarkSehir,enDusukFarkSehir;
	system("cls");
	for(i=0;i<SEHIRSAYISI;i++)
	{
		printf("%s Sehri ---> En Dusuk Sicaklik: %f ---> En Yuksek Sicaklik %f\n",veri[i].sehir_,veri[i].en_Dusuk_,veri[i].en_Yuksek_);
		if(veri[i].en_Yuksek_-veri[i].en_Dusuk_>enYuksekFark)
		{
			enYuksekFark = veri[i].en_Yuksek_-veri[i].en_Dusuk_;
			enYuksekFarkSehir = i;
		}
		
		if(veri[i].en_Yuksek_-veri[i].en_Dusuk_ <enDusukFark)
		{
			enDusukFark = veri[i].en_Yuksek_-veri[i].en_Dusuk_;
			enDusukFarkSehir = i;
		}
	}
	printf("En yuksek fark olan sehir: %s ----> En Yuksek Sicaklik %f ----> En Dusuk Sicaklik %f ----> Fark %f\n\n",veri[enYuksekFarkSehir].sehir_,veri[enYuksekFarkSehir].en_Yuksek_,veri[enYuksekFarkSehir].en_Dusuk_,enYuksekFark);
	printf("En dusuk fark olan sehir: %s ----> En Yuksek Sicaklik %f ----> En Dusuk Sicaklik %f ----> Fark %f\n\n",veri[enDusukFarkSehir].sehir_,veri[enDusukFarkSehir].en_Yuksek_,veri[enDusukFarkSehir].en_Dusuk_,enDusukFark);
}
