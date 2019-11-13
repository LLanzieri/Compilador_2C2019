#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED


typedef struct{
char apellido[20],
    nombre[20];
int nota;
}t_info;

typedef struct s_nodo{
t_info info;
struct s_nodo *sig;
}t_nodo;

typedef struct{
 t_nodo *pri,
        *ult;
}t_cola;

void CrearCola(t_cola *);
int ColaLlena(const t_cola *);
int PonerenCola(t_cola *, const t_info *);
int ColaVacia(const t_cola *);
int VerPrimero(const t_cola *, t_info *d);
int SacardeCola(t_cola *, t_info *);
void VaciarCola(t_cola *);


#endif // COLA_H_INCLUDED
