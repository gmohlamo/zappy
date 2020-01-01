#!/bin/bash
clang src/*.c src/logic/*.c src/logic/gfx/*.c src/logic/client/*.c src/logic/gfx/client_info/*.c src/util/*.c -I./includes -I./libft -L./libft -lft -o server -g
