#include <stdio.h>
#include <conio.h>
#include "cola.h"

void CrearCola(t_cola *p)
{
    p->pri=NULL;
    p->ult=NULL;
}
int ColaLlena(const t_cola *p)
{
    t_nodo *aux=(t_nodo *)malloc(sizeof(t_nodo));
    free(aux);
    return (aux==NULL);
}
int PonerenCola(t_cola *p, const t_info *d)
{
    t_nodo *nue=(t_nodo*)malloc(sizeof(t_nodo));
    if(nue==NULL)
        return 0;
    nue->info=*d;
    nue->sig=NULL;
    if(p->pri==NULL)
    {
        p->pri=nue;
    }else
    {
        p->ult->sig=nue;
    }
    p->ult=nue;
    return 1;
}
int ColaVacia(const t_cola *p)
{
    return(p->ult==NULL);
}
int VerPrimero(const t_cola *p, t_info *d)
{
    if(p->pri==NULL)
        return 0;
    *d=p->pri->info;
    return 1;
}
int SacardeCola(t_cola *p, t_info *d)
{

    if(p->pri==NULL)
        return 0;

    *d=p->pri->info;
    p->pri=p->pri->sig;

    if(p->pri==NULL)
        p->ult =NULL;
    return 1;
}
void VaciarCola(t_cola *p)
{
    t_nodo *aux;
    while(p->pri != NULL)
    {
        aux = p->pri;
        free(aux);
    }
    p->ult=NULL;
}
