#include "test-u.h"

void test_allocate_100_el_struct(){
    __struc_vec vec = create_vec(0, sizeof(test_struct_u));

    for(size_t i = 0; i < 100; ++i){
        test_struct_u tmp;
        tmp.var = i;
        tmp.var2 = i+1;
        tmp.var3 = i+2;
        tmp.var4 = i+3;
        push(&vec, &tmp, sizeof(test_struct_u));
    }
    
    assert((((test_struct_u*)vec.alloc_mem_arr)[99].var==99)&&(((test_struct_u*)vec.alloc_mem_arr)[99].var4==99+3));

    delete_vec(&vec);
}
void test_allocate_100_el_struct_push_and_pop(){
    __struc_vec vec = create_vec(0, sizeof(test_struct_u));

    for(size_t i = 0; i < 100; ++i){
        test_struct_u tmp;
        tmp.var = i;
        tmp.var2 = i+1;
        tmp.var3 = i+2;
        tmp.var4 = i+3;
        push(&vec, &tmp, sizeof(test_struct_u));
    }
    for(size_t i = 0; i < 50; ++i){
        free(pop(&vec));
    }
    
    assert(vec.occupy == 50 && ((test_struct_u*)vec.alloc_mem_arr)[49].var == 49.f);

    delete_vec(&vec);
}