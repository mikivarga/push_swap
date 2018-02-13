#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvarga <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/31 15:02:07 by mvarga            #+#    #+#              #
#    Updated: 2018/01/31 15:02:12 by mvarga           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

P_NAME = push_swap
C_NAME = checker
LIB_NAME = libft.a
CC = gcc
LIB_PATH = ./libft/
LIB = ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o \
	ft_isprint.o ft_itoa.o ft_lstadd.o ft_lstdel.o ft_lstdelone.o ft_lstiter.o \
	ft_lstmap.o ft_lstnew.o ft_memalloc.o ft_memccpy.o ft_memchr.o ft_memcmp.o \
	ft_memcpy.o ft_memdel.o ft_memmove.o ft_memset.o ft_putchar.o ft_putchar_fd.o \
	ft_putendl.o ft_putendl_fd.o ft_putnbr.o ft_putnbr_fd.o ft_putstr.o ft_putstr_fd.o \
	ft_strcat.o ft_strchr.o ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdel.o \
	ft_strdup.o ft_strequ.o ft_striter.o ft_striteri.o ft_strjoin.o ft_strlcat.o \
	ft_strlen.o ft_strmap.o ft_strmapi.o ft_strncat.o ft_strncmp.o ft_strncpy.o \
	ft_strnequ.o ft_strnew.o ft_strnstr.o ft_strrchr.o ft_strsplit.o ft_strstr.o \
	ft_strsub.o ft_strtrim.o ft_tolower.o ft_toupper.o
INSTR_PATH = ./instructions/
INSTR = reverse_rotate.o rotate.o swap_push.o
P_SRC = main.c quick_select.c save_check_input.c separation_steck_a.c separation_steck_b.c \
	sort_steck_a.c sort_steck_b.c sort.c
P_SRC_PATH = ./push_swap_dir/
C_SRC = main.c build_stecks.c check_digits.c display.c instructions.c save_check_input.c
C_SRC_PATH = ./checker_dir/
SRC_LIB = $(addprefix $(LIB_PATH), $(LIB))
SRC_INSTR = $(addprefix $(INSTR_PATH), $(INSTR))
SRC_P = $(addprefix $(P_SRC_PATH), $(P_SRC))
SRC_C = $(addprefix $(C_SRC_PATH), $(C_SRC))
OBJ = $(LIB) $(INSTR)
FLAGS = -Wall -Wextra -Werror
all: $(LIB_NAME)
		gcc $(FLAGS) $(SRC_P) $(LIB_NAME) -o $(P_NAME)
		gcc $(FLAGS) $(SRC_C) $(LIB_NAME) -o $(C_NAME)

$(LIB_NAME): $(OBJ)
		ar rc $(LIB_NAME) $(OBJ)
		ranlib $(LIB_NAME)

$(LIB): %.o: $(LIB_PATH)%.c
		@$(CC) -c $(FLAGS) -I $(LIB_PATH) $< -o $@

$(INSTR): %.o: $(INSTR_PATH)%.c
		@$(CC) -c $(FLAGS) -I $(LIB_PATH) $< -o $@

clean:
		rm -f $(OBJ) $(LIB_NAME)

fclean: clean
		rm -f $(P_NAME) $(C_NAME)

re: fclean all