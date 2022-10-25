#include <stdlib.h>
#include <stdio.h>
#include "cadeia.h"


int main(int narg, char *argv[])
{
    char n[100] = "";

    int unid, deze, cent;


    deze = dezena_extensa("sessenta");
    cent = centena_extensa("duzentos");
    printf("%d", cent);

}
