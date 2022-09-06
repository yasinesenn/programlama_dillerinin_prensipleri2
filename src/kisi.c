/*  Yasin Emin Esen b211210386
 *   esenyasinemin@gmail.com - yasin.esen2@ogr.sakarya.edu.tr
 *   Kisiler icin bellekten gerekli yer ayrilir.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "kisi.h"

Kisi Kisiler(int KisiSayisi){
     
    Kisi kisiler=malloc(sizeof(struct KISI)*KisiSayisi);
    
    return kisiler;
}
