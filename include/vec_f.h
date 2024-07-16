#ifndef _VEC_F__H
#define _VEC_F__H

#include "alloc_f.h"

#define TYPE_ALLOC_ADD 0
#define TYPE_ALLOC_DEL 1

#define PRED_ALLOC_COUNT_EL 4

typedef struct __struc_vec{
    void* alloc_mem_arr;
    
    size_t byte_size_type_el;
    size_t occupy;
    size_t count_el;
} __struc_vec;

#define nullptr_hand_sv(ptrsv) if(!ptrsv){ \
                                    printf("(*__sv)->nullptr"); \
                                    exit(1); \
                                }

extern void _alloc_mem(__struc_vec* __sv, unsigned char type_allocate);

extern __struc_vec create_vec(size_t size, size_t byte_size);
extern void delete_vec(__struc_vec *__sv);

extern void push(__struc_vec* __sv, void* value, size_t byte_size);
extern void push_on(__struc_vec* __sv, void* value, size_t byte_size, size_t index);

extern void* pop(__struc_vec* __sv);

#endif