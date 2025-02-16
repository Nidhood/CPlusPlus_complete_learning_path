#include <iostream>

// What's a pointer?
// ---> A pointer is a variable whose value is an address in memory.
// Creation : int *i;
// Initialization : int i{1}; - int *p1 = &i;

int *p2 = new int{13};

// What's the diference between 'new' and simply initialization ?
// ---> The diference is when we use 'new' initialization  the variable 'p2' points to memory
// allocated from the heap.

// What's the meaning of variable that is pointing to the memory allocated from the heap?
// ---> That's mean that the variable using 'new' to initialice it, will remain the allocated 
// to the program. But in the otherwise if 'new' initialization isn't explicitly realased, th memory
// will realocate it until the program terminates.

// But it's important to know that if the program uses too much memory, the operating system may 
// refuse to allocate any more memory, that because the operating system restrics the amount of
// memory may allocate.

// What's the meaning of memory leak?
// ---> It refere to the failing to release memory when it is no longer needed causes a "memory leak".

// How could we solve this problem of leaks?
// ---> We need realisng the memory, for that we need to know the function of:

// delete. (the delete operator releases memory that was allocated by new)
// It's important to know that without using delete method the variable 'p2' will still exist in the 
// memory but it will no be accesible by the program, or in other words, this will be a waste of memory
// or undefinied behavior that can causes problem or errors after.
// So ... in conclution, for every new operation there should be a matching delete operator.

// In the case when we're using an array of pointers, the delete method is diferent:

/*
int *pa = new int[20];
for (int i = 0; i < 20; i++){
    pa[i] = i;
}

delete [] pa;
*/

void badfunc() {
    int *p4 = new int{42};
    return;
};

void badfunc_fixed() {

    // Creation of the space in the memory, allocated in the heap, it reference to the value of '42'.
    int *p4 = new int{42};

    // Realice the memory in to the address of the pointer 'p4'.
    delete p4;
    *p4 = 0;
    return;
};

int main() {
    std::cout << *p2 << std::endl;
    badfunc();
    return 0;
}