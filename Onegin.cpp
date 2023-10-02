#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Text_Funcs.h"
#include "Qsort.h"

int main() {
    struct text Onegin = {NULL, 0, NULL, NULL, 0};
    char filename[100] = "";
    scanf("%s", filename);
    Onegin.open_file = fopen(filename, "r");
    Onegin.len = file_len(Onegin.open_file);
    Onegin.buffer = (char*) calloc(Onegin.len + 1, sizeof(char));

    assert(Onegin.buffer != NULL);

    fread(Onegin.buffer, sizeof(char), Onegin.len, Onegin.open_file);
    Onegin.str_num = str_num(Onegin.buffer);
    Onegin.lines = (struct line*) calloc(Onegin.str_num, sizeof(struct line));

    assert(Onegin.lines != NULL);

    read_lines(Onegin.lines, Onegin.buffer);
    my_qsort(Onegin.lines, 0, Onegin.str_num - 1, str_compare_lr);
    print_lines(Onegin.lines, Onegin.str_num, "Onegin_st_lr_rand.txt");
    my_qsort(Onegin.lines, 0, Onegin.str_num - 1, str_compare_rl);
    print_lines(Onegin.lines, Onegin.str_num, "Onegin_st_rl_rand.txt");
    clear_lines(Onegin.lines, Onegin.str_num);
    fclose(Onegin.open_file);
    clear_text(&Onegin);
    return 0;
}
