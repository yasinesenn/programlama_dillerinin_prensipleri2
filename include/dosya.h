#ifndef DOSYA_H
#define DOSYA_H
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "kisi.h"

struct DOSYA{
    int satirSayisi;
    int sayiSayisi;
    int kisiSayisi;
    int* sayilar;
    Kisi kisiler;
    void (*yoket)(struct DOSYA*);
};
typedef struct DOSYA *Dosya;
Dosya DosyaOlustur();
int satirSayisiBul(char* );
Kisi kisileri_oku();
int* SansliSayilariOku();
void dosyaYoket(const Dosya);
#endif
