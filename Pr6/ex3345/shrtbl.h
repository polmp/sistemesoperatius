#ifndef SHRTBL_H
#define SHRTNL_H
#include <stdbool.h>
#include <semaphore.h>

#define OK 0
#define ERR -1
#define NPARTITS 50

typedef struct{
char id[32];
int numvots;
bool enTaula;
} partit_individual;

typedef struct {
partit_individual partits[NPARTITS];
sem_t semafor;
} taula_partits,*apuntador_llista;

typedef void travapp(const char *const id, int votes, void *const data);

int create_shared_table(void);
int remove_shared_table(void);
int bind_shared_table(void);
void init_table(void);
int add_party(const char id[]);
void del_party(const char id[]);
void inc_votes(const char party[], int votes);
int get_votes(const char party[]);
int get_nparties(void);
void traverse(travapp *const f, void *const data);
#endif
