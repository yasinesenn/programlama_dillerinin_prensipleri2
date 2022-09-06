/*  Yasin Emin Esen b211210386
 *   esenyasinemin@gmail.com - yasin.esen2@ogr.sakarya.edu.tr
 *   oyunun oynanısı ve onun icin gerekli olan fonksiyonlar burada kullanilmistir.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include "oyun.h"

Oyun OyunOlustur()
{
    Oyun this = malloc(sizeof(struct OYUN));
    this->dosya = DosyaOlustur();
    this->masa = 0.0;
    this->oyun = &oyun;
    this->OyunYoket = &oyunYoket;
    return this;
}

void bakiyeAzalt(Kisi p)
{
    p->Kisi_bakiye = p->Kisi_bakiye - p->Kisi_bakiye * p->Kisi_oran;
}

void bakiyeArtir(Kisi p)
{
    p->Kisi_bakiye = (p->Kisi_bakiye + p->Kisi_bakiye * p->Kisi_oran * 9);
}

void masaArtir(Kisi p, Oyun this)
{
    this->masa += (p->Kisi_bakiye * p->Kisi_oran);
}

void masaAzalt(Kisi p, Oyun this)
{
    this->masa -= (p->Kisi_bakiye * p->Kisi_oran * 9);
}

void EnZenginiBul(Kisi Kisiler)
{
    double maks = Kisiler->Kisi_bakiye;
    char *enZengin;
    int KisiSayisi = satirSayisiBul("Kisiler.txt");
    for (int i = 0; i < KisiSayisi; i++)
    {
        if (maks < (Kisiler + i)->Kisi_bakiye)
        {
            maks = (Kisiler + i)->Kisi_bakiye;
            enZengin = strdup((Kisiler + i)->Kisi_isim);
        }
    }
    printf("\t\t\t##                       EN ZENGIN KISI                        ##\n");
    printf("\t\t\t##                       %-20s                  ##\n", enZengin);
    printf("\t\t\t##                  BAKIYESI:%-7.0lf                           ##\n", maks);
}

void CurrentPrint(Kisi kisi, Oyun oyun, int tur, int sayi)
{
    system("cls");
    printf("\t\t\t#################################################################\n");
    printf("\t\t\t##                       SANSLI SAYI:%-3d                       ##\n", sayi);
    printf("\t\t\t#################################################################\n");
    printf("\t\t\t#################################################################\n");
    printf("\t\t\t##                       TUR: %-6d                           ##\n", tur);
    printf("\t\t\t##                  MASA BAKIYE: %.2lf TL                ##\n", oyun->masa);
    printf("\t\t\t##                                                             ##\n");
    printf("\t\t\t##-------------------------------------------------------------##\n");
    EnZenginiBul(kisi);
    printf("\t\t\t##                                                             ##\n");
    printf("\t\t\t##                                                             ##\n");
    printf("\t\t\t#################################################################\n");
}

void FinishPrint(Kisi kisi, Oyun oyun, int tur)
{
    system("cls");
    printf("\t\t\t#################################################################\n");
    printf("\t\t\t##                       TUR: %-6d                           ##\n", tur);
    printf("\t\t\t##                  MASA BAKIYE: %.2lf TL                ##\n", oyun->masa);
    printf("\t\t\t##                                                             ##\n");
    printf("\t\t\t##-------------------------------------------------------------##\n");
    printf("\t\t\t##                         OYUN BITTI                          ##\n");
    printf("\t\t\t##                                                             ##\n");
    printf("\t\t\t##                                                             ##\n");
    printf("\t\t\t#################################################################\n");
}

void oyun(Oyun this)
{
    int sayac = 0;
    for (int i = 0; i < this->dosya->sayiSayisi; i++)
    {
        sayac++;
        for (int j = 0; j < this->dosya->kisiSayisi; j++)
        {
            if (((this->dosya->kisiler + j)->Kisi_sansliSayi == this->dosya->sayilar[i]) && ((this->dosya->kisiler + j)->Kisi_bakiye >= 1000.00))
            {
                masaAzalt(this->dosya->kisiler + j, this);
                bakiyeArtir(this->dosya->kisiler + j);
            }
            else if (((this->dosya->kisiler + j)->Kisi_sansliSayi != this->dosya->sayilar[i]) && ((this->dosya->kisiler + j)->Kisi_bakiye >= 1000.00))
            {
                masaArtir(this->dosya->kisiler + j, this);
                bakiyeAzalt(this->dosya->kisiler + j);
            }
        }
        CurrentPrint(this->dosya->kisiler, this, i + 1, this->dosya->sayilar[i]);
        usleep(1);
    }
    FinishPrint(this->dosya->kisiler, this, sayac);
}

void oyunYoket(const Oyun this)
{
    if (this == NULL)
        return;

    this->dosya->yoket(this->dosya);
    free(this);
}