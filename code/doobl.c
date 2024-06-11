#include <stdio.h>
#include <stdlib.h>

#define NIL 0
#define CONS 1

#pragma pack(1)
struct list {
    char type;
    long head;
    struct list *tail;
};

void doobl(struct list* xs) {
    struct list * reg = xs;
    doubles:
        if (reg->type == NIL) {
            goto ret;
        }
        // else
        struct list* ys = reg->tail;
        reg->tail = (struct list *) malloc(sizeof(struct list));
        reg->tail->type = CONS;
        reg->tail->head = reg->head;
        reg->tail->tail = ys;
        reg = ys;
        goto doubles;
    ret:
        return;
}

void enumerate(int limit, struct list* target) {
    int reg1 = 0;
    struct list* reg2;
    struct list* xs;
    enums:
        xs = (struct list *) malloc(sizeof(struct list));
        if (limit == 0) {
            xs->type = NIL;
            goto ret;
        }
        else {
            xs->type = CONS;
            xs->head = limit;
        }
        reg2->tail = xs;
        reg2 = xs;
        reg1 = limit - 1;
        goto enums;
    ret:
        return;
}

int length (struct list* xs) {
    int reg1 = 0;
    struct list* reg2 = xs;
    lens:
        if (xs->type == NIL) {
            goto ret;
        }
        reg1++;
        goto lens;
    ret:
        return reg1;
}

int main(void) {
    struct list* xs;
    enumerate(1e7, xs); 
    doobl(xs);
    printf("%l\n", length(xs));
}

