#ifndef _ALLOC_F__H
#define _ALLOC_F__H

#include <stdio.h>

extern void 
    _alloc_new_mem_more(
        void** arr_p,
        size_t byte_size,
        size_t *size,
        size_t alloc_more);

extern void
    _alloc_new_mem_more_wa_offset(
        void** arr_p,
        size_t byte_size,
        size_t *size,
        size_t index_offset,
        size_t alloc_more);

extern void
    _alloc_new_mem_less_o(
        void** arr_p,
        size_t byte_size,
        size_t *size,
        size_t index);

#endif