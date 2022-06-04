/*** ( From Effective C ) Declare an array of three pointers to functions and invoke the appropriate function based on
     an index value pass in as an argument***/

#include <stdio.h>
#include <string.h>

int func_1(int argc, char *argv[]);
int func_2(int argc, char *argv[]);
int func_3(int argc, char *argv[]);

char *func_to_exec[] = {
    "func_1", 
    "func_2", 
    "func_3"
};

int (*the_function[]) (int argc, char *argv[]) = {
    &func_1,
    &func_2, 
    &func_3
};

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        puts("Please enter an argument..");
        return -1;
    }

    for(int i = 0;i < (sizeof(func_to_exec) / sizeof(char *));i++){
        if(strcmp(argv[1], func_to_exec[i]) == 0)
        {
            puts("Found");
            return (*the_function[i])(argc, argv);
            return 0;
        }
    }
    return -1;
}

int func_1(int argc, char *argv[])
{
    puts("Hello from func_1!\n");
    return 0;

}

int func_2(int argc, char *argv[])
{
    puts("Hello from func_2!\n");
    return 0;
    
}

int func_3(int argc, char *argv[])
{
    puts("Hello from func_3!\n");
    return 0;
}
