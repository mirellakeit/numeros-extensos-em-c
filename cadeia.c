#include <stdio.h>
#include <stdlib.h>

int str_tamanho(char *s)
{
    int length = 0;
    while(s[length] != '\0')
    {
        length++;
    }
    return length;
}


void str_copia (char *s, char *d)
{
    int size_s, size_d, length;
    size_s = str_tamanho(s);
    size_d = str_tamanho(d);

    if(size_s <= size_d)
    {
        while(s[length] != '\0')
        {
            d[length] = s[length];
            length++; 
        }
        if(size_s != size_d)
        {
            d[length] = '\0';
        }

    }
    else
    {
        printf("impossível sobrescrever.");
    }

}

void str_concatena (char *s, char *d)
{
    int i, tamanho;
    i = 0;
    tamanho = str_tamanho(d);
    
    while(s[i] != '\0')
    {
        d[tamanho + i] = s[i];
        i++;
    }

}

char *unidade(int i)
{
    char *numeros[9] = {"um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito", "nove"};
    char *numeros_decimais[10] = {"dez", "onze", "doze", "treze", "quatorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove"};
    
    if(i < 10)
    {
        return (numeros[i - 1]);
    }
    else
    {
        return (numeros_decimais[i % 10]);
    }
    
}

char *dezena(int i)
{
    char *dezenas[8] = {"vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"};
    return(dezenas[i - 2]);


}

char *centena(int i)
{
    char *centenas[9] = {"cem", "duzentos", "trezentos", "quatrocentos", "quinhentos", "seicentos", "setecentos", "oitocentos", "novecentos"};

    return(centenas[i - 1]);
}

void retorna_numero_extenso(char *n, int i)
{
    int unid, deze, cent;
    
    cent = (i - (i % 100)) / 100;
    deze = (i - cent*100);
    deze = (deze - (deze % 10)) / 10;
    unid = i - cent*100 - deze*10;
    str_concatena(centena(cent), n);

    str_concatena(" e ", n);
 

    if(deze == 1)
    {
        str_concatena(unidade(deze*10 + unid), n);
    

    }
    else
    {
        str_concatena(dezena(deze), n);
        str_concatena(" e ", n);
       
        
        str_concatena(unidade(unid), n);


    }
 
}
/*
int unidade_extensa(char *u)
{
    char *numeros[9] = {"um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito", "nove"};
    char *numeros_decimais[10] = {"dez", "onze", "doze", "treze", "quatorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove"};
    
    if(i < 10)
    {
        return (numeros[i - 1]);
    }
    else
    {
        return (numeros_decimais[i % 10]);
    }
    
}

*/

int dezena_extensa(char *d)
{
    int i;
    int dezenas[8] = {'v', 't', 'q', 'c', 's', 's', 'o', 'n'};
    int numero = d[0];
    int numero_t_posic = d[2];



    if(numero == 's')
    {
        if(numero_t_posic == 't')
        {
            return(70);
        } 
        else
        {
            return(60);
        }
        
    }
    else
    {
        for(i = 0; i < 9; i++)
        {
            if(numero == dezenas[i])
            {
                return(10 * (i + 2));
            }
        }
    }
    

}


int centena_extensa(char *c)
{
    int centenas[9] = {'c', 'd', 't', 'q', 'q', 's', 's', 'o', 'n'};
    int i, numero;
    if(c[0] == 'q')
    {
        if(c[2] == 'i')
        {
            return(500);
        }
        else
        {
            return(400);
        }
    }

    if(c[0] == 's')
    {
        if(c[2] == 't')
        {
            return(700);
        }
        else
        {
            return(600);
        }
    }

    for(i = 0; i < 9; i++)
    {
        if(c[0] == centenas[i])
        {
            return(100 * (i + 1));
        }
    }

    
}
