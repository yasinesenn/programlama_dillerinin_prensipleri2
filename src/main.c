/*  Yasin Emin Esen b211210386
 *   esenyasinemin@gmail.com - yasin.esen2@ogr.sakarya.edu.tr
 *   programla ilgili her seyin kullanildigi,test edildigi, main fonksiyonu.
 */
#include <stdio.h>
#include <stdlib.h>
#include "oyun.h"

int main(int argc, char **argv)
{

    Oyun oyun = OyunOlustur();
    oyun->oyun(oyun);
    oyun->OyunYoket(oyun);

    
    return 0;
}