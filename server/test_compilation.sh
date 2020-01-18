#!/bin/bash
clang src/logic/*.c src/logic/gfx/*.c src/logic/client/*.c src/logic/gfx/client_info/*.c src/logic/ascension/*.c src/util/*.c -I./includes -I./libft -L./libft -lft -o server -g
