#ifndef SHRTBL_H
#define SHRTNL_H
#include <stdbool.h>

#define OK 0
#define ERR -1
#define NPARTITS 50

typedef struct{
char id[32];
int numvots=0;
bool enTaula = false;
} partit_individual;

typedef struct {
partit_individual partits[NPARTITS];
int semafor;
} taula_partits;

typedef taula_partits(*apuntador_llista);
typedef void travapp(const char *const id, int votes, void *const data);

int create_shared_table(void);
int remove_shared_table(void);
#endif
