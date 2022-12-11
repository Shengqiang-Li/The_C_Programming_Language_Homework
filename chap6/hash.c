#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nlist
{
    struct nlist *next;
    char *name;
    char *defn;
};

struct nlist* lookup(char* s);
struct nlist* install(char* name, char* defn);

int main() {
  install("IN", "1");
  if (lookup("IN") != NULL) {
    printf("name: %s\n", lookup("IN")->name);
    printf("defn: %s\n", lookup("IN")->defn);
  }
  if (lookup("OUT") != NULL) {
    printf("name: %s\n", lookup("OUT")->name);
    printf("defn: %s\n", lookup("OUT")->defn);
  }
  return 0;
}

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s){
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++){
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
    }
}

struct nlist *lookup(char *);
char *my_strdup(char *);

struct nlist *install(char *name, char *defn){
    struct nlist *np;
    unsigned hashval;
    if ((np = lookup(name)) == NULL){
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = my_strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else
        free((void *) np->defn);
    if ((np->defn = my_strdup(defn)) == NULL)
        return NULL;
    return np;
}

char *my_strdup(char *s){
    char *p;
    p = (char *) malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p, s);
    return p;
}

struct nlist *lookup(char *s){
    struct nlist *np;
    for (np = hashtab[hash(s)]; np!= NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;
    return NULL; 
}
