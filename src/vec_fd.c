#include <stdlib.h>

#include "../include/vec_f.h"

void _alloc_mem(__struc_vec* __sv, unsigned char type_allocate){
    nullptr_hand_sv(__sv)
    if(type_allocate == TYPE_ALLOC_ADD){
        if((*__sv).occupy==(*__sv).count_el)
            _alloc_new_mem_more(&(*__sv).alloc_mem_arr, (*__sv).byte_size_type_el, &(*__sv).count_el, PRED_ALLOC_COUNT_EL);
        else
            _alloc_new_mem_more(&(*__sv).alloc_mem_arr, (*__sv).byte_size_type_el, &(*__sv).count_el, 1);
    }
    else if(type_allocate == TYPE_ALLOC_DEL)
        _alloc_new_mem_less_o(&(*__sv).alloc_mem_arr, (*__sv).byte_size_type_el, &(*__sv).count_el, (*__sv).occupy-1);
}

__struc_vec create_vec(size_t size, size_t byte_size){
    __struc_vec vec;
    vec.alloc_mem_arr = NULL;
    vec.occupy = 0;
    vec.count_el = 0;
    vec.byte_size_type_el = byte_size;

    return vec;
}

void delete_vec(__struc_vec *__sv){
    nullptr_hand_sv(__sv)
    __sv->byte_size_type_el = 0;
    __sv->count_el = 0;
    __sv->occupy = 0;
    if((*__sv).alloc_mem_arr) free((*__sv).alloc_mem_arr);
}

void push(__struc_vec* __sv, void* value, size_t byte_size){
    nullptr_hand_sv(__sv)
    if(byte_size != (*__sv).byte_size_type_el){
        printf("BYTE_SIZE-%zu, WHICH WAS PASSED TO PUSH(), IT DOESN'T MATCH WITH (*__sv).BYTE_SIZE_TYPE_EL-%zu!!!", (*__sv).byte_size_type_el, byte_size);
        exit(1);
    }
    _alloc_mem(__sv, TYPE_ALLOC_ADD);
    ++__sv->occupy;
    for(size_t i = 0; i < byte_size; ++i){
        ((unsigned char*)(*__sv).alloc_mem_arr)[((*__sv).occupy-1)*(*__sv).byte_size_type_el+i] = ((unsigned char*)value)[i];
    }
}

void push_on(__struc_vec* __sv, void* value, size_t byte_size, size_t index){
    nullptr_hand_sv(__sv)
    if(byte_size != (*__sv).byte_size_type_el) {
        printf("BYTE_SIZE-%zu, WHICH WAS PASSED TO PUSH(), IT DOESN'T MATCH WITH (*__sv).BYTE_SIZE_TYPE_EL-%zu!!!", (*__sv).byte_size_type_el, byte_size);
        exit(1);
    }
    _alloc_new_mem_more_wa_offset(&(*__sv).alloc_mem_arr, (*__sv).byte_size_type_el, &(*__sv).count_el, index, 1);
    ++__sv->occupy;
    for(size_t i = 0; i < byte_size; ++i){
        ((unsigned char*)(*__sv).alloc_mem_arr)[(index*(*__sv).byte_size_type_el)+i] = ((unsigned char*)value)[i];
    }
}

void* pop(__struc_vec* __sv){
    nullptr_hand_sv(__sv)
    if((*__sv).count_el == 0){
        printf("(*__sv).COUNT_EL HAS A VALUE OF - 0!!!");
        exit(1);
    }
    void* val = malloc((*__sv).byte_size_type_el);
    for(size_t i = 0; i < (*__sv).byte_size_type_el; ++i){
        ((unsigned char*)val)[i] = ((unsigned char*)(*__sv).alloc_mem_arr)[((*__sv).occupy-1)*(*__sv).byte_size_type_el+i];
    }
    _alloc_mem(__sv, TYPE_ALLOC_DEL);
    --__sv->occupy;
    return val;
}