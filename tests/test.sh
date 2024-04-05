#!/bin/bash
gcc -Wall -Wextra -Werror -o test_get_next_line tests.c ../get_next_line.c ../get_next_line_utils.c
./test_get_next_line