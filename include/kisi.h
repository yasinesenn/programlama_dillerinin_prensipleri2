#ifndef KISI_H
#define KISI_H
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct KISI
{
    char *Kisi_isim;
    double Kisi_bakiye;
    float Kisi_oran;
    int Kisi_sansliSayi;
};
typedef struct KISI *Kisi;

Kisi Kisiler(int);


#endif