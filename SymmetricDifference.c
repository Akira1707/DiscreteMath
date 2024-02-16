#include<stdio.h>
#include<stdlib.h>

typedef struct elem{
    int i;
    struct elem* p;
} elem;

void Append(elem** c, elem** e, int d){
    elem* newElem = (elem*)malloc(sizeof(elem));
    newElem->i = d;
    newElem->p = NULL;

    if (*c == NULL){
        *c = newElem;
    } else{
        (*e)->p = newElem;
    }
    *e = newElem;
}

elem* SymmetricDifference(elem* a, elem* b){
    elem* c = NULL;
    elem* e = NULL;

    while(a!=NULL && b!= NULL){
        if(a->i <b->i){
            Append(&c,&e, a->i);
            a = a->p;
        } else if(a->i > b->i){
            Append(&c, &e, b->i);
            b = b->p;
        }else{
            a = a->p;
            b = b->p;
        }
    }

    while(a!= NULL){
        Append(&c, &e, a->i);
        a = a->p;
    }

    while(b!= NULL){
        Append(&c, &e, b->i);
        b = b->p;
    }
    
    return c;
}

void PrintList(elem * c){
    while(c!=NULL){
        printf("%d ", c->i);
        c = c->p;
    }
    printf("\n");
}

int main() {
    elem* a = NULL;
    elem* b = NULL;
    elem* e = NULL;
    
    Append(&a, &e, 1);
    Append(&a, &e, 2);
    Append(&a, &e, 5);
    Append(&b, &e, 2);
    Append(&b, &e, 3);
    Append(&b, &e, 5);

    elem* c = SymmetricDifference(a, b);
    PrintList(c);

    return 0;
}
