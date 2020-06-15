#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int MAX_INPUT_INTS = 1024;
const int OP_HALT = 99;

int add(int a, int b) {
    return a+b;
}

int mult(int a, int b) {
    return a*b;
}

int (*ops[3])(int, int) = {NULL, add, mult};

int read_comma_sep_ints(int array[MAX_INPUT_INTS]) {
    int length=0;
    char buffer[MAX_INPUT_INTS];
    char *aux;
    fgets(buffer,MAX_INPUT_INTS,stdin);
    aux=strtok(buffer, ",");
    while(aux)
    {
        array[length]=atoi(aux);
        length++;
        aux=strtok(NULL, ",");
    }
    return length;
}

void alter_program(int *program) {
    program[1] = 12;
    program[2] = 2;
}

void run_program(int *program, int len) {
    int index = 0;
    while(index < len) {
        int op = program[index];
        if(op == OP_HALT) {
            break;
        }
        int arg1_index = program[index+1]; 
        int arg2_index = program[index+2];
        int res_index = program[index+3];
        program[res_index] = ops[op](program[arg1_index], program[arg2_index]);
        index += 4;
    }
}

void print_program(int *program, int len) {
    for(int i =0; i < len; i++) {
        printf("%d ", program[i]);
    }
    printf("\n");
}

int main()
{
    int program[MAX_INPUT_INTS];
    int len = read_comma_sep_ints(program);

    alter_program(program);
    run_program(program, len);
    print_program(program, len);
}
