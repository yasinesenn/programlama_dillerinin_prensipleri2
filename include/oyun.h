#ifndef OYUN_H
#define OYUN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "dosya.h"

struct OYUN
{
    Dosya dosya;
    double masa;
    void (*oyun)(struct OYUN *);
    void (*OyunYoket)(struct OYUN *);
};
typedef struct OYUN *Oyun;

Oyun OyunOlustur();
void bakiyeAzalt(Kisi);
void bakiyeArtir(Kisi);
void masaArtir(Kisi, Oyun);
void masaAzalt(Kisi, Oyun);
void EnZenginiBul(Kisi);
void CurrentPrint(Kisi, Oyun, int, int);
void FinishPrint(Kisi, Oyun, int);
void oyun(Oyun);
void oyunYoket(const Oyun);

#endif