#include <stdlib.h>

#include "alloc_f.h"

void _alloc_new_mem_more(void** arr_p, size_t byte_size, size_t *size, size_t alloc_more){
    void* arr_new = malloc(byte_size*((*size)+alloc_more));
    for(size_t i = 0; i < byte_size*(*size); ++i){
        ((unsigned char*)arr_new)[i] = ((unsigned char*)(*arr_p))[i];
    }
    *size+=alloc_more;
    if(*arr_p)
        free(*arr_p);
    *arr_p = arr_new;
}

// wa_offset - with an offset
void _alloc_new_mem_more_wa_offset(void** arr_p, size_t byte_size, size_t *size, size_t index_offset, size_t alloc_more){
    void* arr_new = malloc(byte_size*((*size)+alloc_more));
    for(size_t i = 0, b = 0; i < byte_size*(*size); ++i){
        if(i >= byte_size*index_offset && i < byte_size*index_offset*alloc_more+byte_size) continue;
        ((unsigned char*)arr_new)[i] = ((unsigned char*)(*arr_p))[b];
        ++b;
    }
    *size += alloc_more;
    if(*arr_p)
        free(*arr_p);
    *arr_p = arr_new;
}

void _alloc_new_mem_less_o(void** arr_p, size_t byte_size, size_t *size, size_t index){
    void* arr_new = malloc(byte_size*((*size)-1));
    
    size_t mem_start_ind_el = index*byte_size;
    size_t mem_end_ind_el = index*byte_size+byte_size;

    for(size_t i = 0, b = 0; i < byte_size*(*size); ++i){
        if(i >= mem_start_ind_el && i <= mem_end_ind_el) continue;
        ((unsigned char*)arr_new)[b] = ((unsigned char*)(*arr_p))[i];
        ++b;
    }
    --*size;
    if(*arr_p)
        free(*arr_p);
    *arr_p = arr_new;
}