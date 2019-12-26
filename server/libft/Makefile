# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmohlamo <gmohlamo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/13 17:11:46 by gmohlamo          #+#    #+#              #
#    Updated: 2018/08/24 11:49:54 by gmohlamo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strlen.c \
	ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
	ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c \
	ft_isalnum.c ft_islower.c ft_isupper.c ft_isprint.c ft_isascii.c ft_isspace.c \
	ft_toupper.c ft_tolower.c ft_strncpy.c ft_memalloc.c ft_memdel.c \
	ft_strnew.c ft_strdel.c ft_strclr.c ft_putchar.c ft_putstr.c ft_striter.c \
	ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strsub.c ft_strjoin.c \
	ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c \
	ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strnequ.c \
	ft_putsred.c ft_putsblue.c ft_putsgreen.c ft_putsblack.c ft_putsyellow.c ft_putspurple.c \
	ft_putscyan.c ft_putswhite.c ft_strsafejoin.c ft_lstposdel.c ft_strrev.c get_next_line.c \
	ft_power.c ft_atoll.c
OBJ = ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o ft_memmove.o ft_memchr.o ft_memcmp.o ft_strlen.o \
	ft_strdup.o ft_strcpy.o ft_strcat.o ft_strncat.o ft_strlcat.o ft_strchr.o  ft_isspace.o \
	ft_strrchr.o ft_strstr.o ft_strnstr.o ft_strcmp.o ft_strncmp.o ft_atoi.o ft_isalpha.o ft_isdigit.o \
	ft_isalnum.o ft_islower.o ft_isupper.o ft_isprint.o ft_isascii.o ft_toupper.o ft_tolower.o ft_strncpy.o \
	ft_memalloc.o ft_memdel.o ft_strnew.o ft_strdel.o ft_strclr.o ft_putchar.o ft_putstr.o ft_striter.o \
	ft_striteri.o ft_strmap.o ft_strmapi.o ft_strequ.o ft_strsub.o ft_strjoin.o ft_strtrim.o ft_strsplit.o \
	ft_itoa.o ft_putendl.o ft_putnbr.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o \
	ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o ft_lstmap.o ft_strnequ.o \
	ft_putsred.o ft_putsblue.o ft_putsgreen.o ft_putsblack.o ft_putsyellow.o ft_putspurple.o ft_putscyan.o \
	ft_putswhite.o ft_strsafejoin.o ft_lstposdel.o ft_strrev.o get_next_line.o ft_power.o ft_atoll.o
INC = -I./include/
NAME = libft.a

$(NAME): $(OBJ)
	@echo "\033[0;32mMaking the library\033[0m"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[2;32mDone!\033[0m"

all: $(NAME)

$(OBJ): $(SRCS)
	@echo "\033[33;mCompiling object files\033[0m"
	@gcc -c $(SRCS) -Wall -Wextra -Werror $(INC)

clean:
	@echo "\033[0;34mRemoving object files\033[0m"
	@rm -f $(OBJ)

fclean:
	@make clean
	@echo "\033[0;34mRemoving library\033[0m"
	@rm -f $(NAME)

re:
	@echo "\033[1;25mRemaking library\033[0m"
	@make fclean && make

lib:
	@make fclean && make && make clean
