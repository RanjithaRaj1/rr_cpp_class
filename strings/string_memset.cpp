#include <iostream>
#include <string.h>

typedef struct state {
    char name[256];
    int cnt;
}state_t;

void setState(int i, const char* name, state_t* st)
{
    // Good idea to memset the string.. so in case we dont set the value
    // strlen returns 0 and strcmp returns 0 when compared with empty string
    if (i == 0) {
        memset(st->name, '\0', sizeof(char)*256);
    }
    else if (i == 1) {
        st->cnt = i;
        size_t sz = sizeof st->name - 1;
        strncpy(st->name, name, sz);
        st->name[sz] = '\0';
    } 
    else {
 
    }     
}

int main()
{
    char name[256];
    state_t st1, st2, st3;
    setState(1, "continental", &st1);
    setState(2, "continental", &st2);
    setState(0, "continental", &st3);
    std::cout << "name set: " << st1.name << ", len: " << strlen(st1.name) << ", size: " << sizeof(st1.name) << std::endl;
    std::cout << "name set: " << st2.name << ", len: " << strlen(st2.name) << ", size: " << sizeof(st2.name) << std::endl;
    std::cout << "name set: " << st3.name << ", len: " << strlen(st3.name) << ", size: " << sizeof(st3.name) << std::endl;
    
    // when a string is not initialized, strlen might have some value
    // if strlen is non-zero, it doesnt mean we are setting the string
    std::cout << "when string is initialized, the length is: " << strlen(st3.name) << std::endl;
    std::cout << "when string is NOT initialized, the length is: " << strlen(st2.name) << std::endl;
    
    // same thing with strcmp
    std::cout << "when string is initialized, strcmp returns: " << strcmp(st3.name, "") << std::endl;
    std::cout << "when string is NOT initialized, strcmp returns: " << strcmp(st2.name, "") << std::endl;

}

/*
name set: continental, len: 11, size: 256
name set: , len: 1, size: 256
name set: , len: 0, size: 256
when string is initialized, the length is: 0
when string is NOT initialized, the length is: 1
when string is initialized, strcmp returns: 0
when string is NOT initialized, strcmp returns: 1
*/
