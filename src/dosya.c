/*  Yasin Emin Esen b211210386
 *   esenyasinemin@gmail.com - yasin.esen2@ogr.sakarya.edu.tr
 *   Dosyadan bilgileri okuma bunlari structlarin icine atma gibi fonskiyonalr burada kullanilmistir.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "dosya.h"

Dosya DosyaOlustur()
{
    Dosya this = malloc(sizeof(struct DOSYA));
    this->sayiSayisi = satirSayisiBul("Sayilar.txt");
    this->kisiSayisi = satirSayisiBul("Kisiler.txt");
    this->sayilar = SansliSayilariOku();
    this->kisiler = kisileri_oku();
    this->yoket = &dosyaYoket;
    return this;
}

int satirSayisiBul(char *str)
{
    FILE *f = fopen(str, "r");
    int TahminiSatirUzunlugu = 100;
    if (f == NULL)
        printf("bulunamadi");
    char satir[TahminiSatirUzunlugu];
    int SatirSayisi = 0;

    while (fgets(satir, TahminiSatirUzunlugu, f))
    {
        SatirSayisi++;
    }
    fclose(f);
    return SatirSayisi;
}

int *SansliSayilariOku()
{
    int SansliSayiAdedi = satirSayisiBul("Sayilar.txt");
    int *Sayilar = malloc(sizeof(int) * SansliSayiAdedi);
    FILE *p = fopen("Sayilar.txt", "r");

    if (p == NULL)
        printf("bulunamadi");

    for (int i = 0; i < SansliSayiAdedi; i++)
    {
        fscanf(p, "%d", &Sayilar[i]);
        // printf("\n%d. sayi :%d\n",i+1,Sayilar[i]);
    }

    fclose(p);
    return Sayilar;
}

Kisi kisileri_oku()

{
    FILE *f = fopen("Kisiler.txt", "r");
    int kisiSayisi = satirSayisiBul("Kisiler.txt");
    Kisi kisiler = Kisiler(kisiSayisi);
    int TahminiSatirUzunlugu = 100;
    if (f == NULL)
        printf("bulunamadi");
    int parcaSayisi = 0;
    char satir[TahminiSatirUzunlugu];
    while (fgets(satir, TahminiSatirUzunlugu, f))
    {
        char *parca;
        parca = strtok(satir, "#");
        (kisiler + parcaSayisi)->Kisi_isim = strdup(parca);
        // printf("Kisi isim: %s\n",(kisiler + parcaSayisi)->Kisi_isim);
        parca = strtok(NULL, "#");
        (kisiler + parcaSayisi)->Kisi_bakiye = atof(parca);
        // printf("Kisi isim: %lf\n",(kisiler + parcaSayisi)->Kisi_bakiye);
        parca = strtok(NULL, "#");
        (kisiler + parcaSayisi)->Kisi_oran = atof(parca);
        // printf("Kisi isim: %f\n",(kisiler + parcaSayisi)->Kisi_oran);
        parca = strtok(NULL, "#");
        (kisiler + parcaSayisi)->Kisi_sansliSayi = atoi(parca);
        // printf("Kisi isim: %d\n",(kisiler + parcaSayisi)->Kisi_sansliSayi);
        parca = strtok(NULL, "#");
        parcaSayisi++;
    }
    fclose(f);
    return kisiler;
}

void dosyaYoket(const Dosya this)
{
    if (this == NULL)
        return;

    free(this->kisiler);
    free(this);
}