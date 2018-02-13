#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvarga <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/31 16:56:44 by mvarga            #+#    #+#              #
#    Updated: 2018/01/31 16:56:47 by mvarga           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = checker
LIB_NAME = libft.a
CC = gcc
LIB_PATH = ./../libft/
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
INSTR_PATH = ./../instructions/
INSTR = reverse_rotate.o rotate.o swap_push.o
SRC = main.c build_stecks.c check_digits.c display.c instructions.c save_check_input.c
SRC_LIB = $(addprefix $(LIB_PATH), $(LIB))
SRC_INSTR = $(addprefix $(INSTR_PATH), $(INSTR))
OBJ = $(LIB) $(INSTR)
FLAGS = -Wall -Wextra -Werror
all: $(NAME)

$(NAME): $(OBJ)
		ar rc $(LIB_NAME) $(OBJ)
		ranlib $(LIB_NAME)
		@$(CC) $(FLAGS) $(SRC) $(LIB_NAME) -o $(NAME)

$(LIB): %.o: $(LIB_PATH)%.c
		@$(CC) -c $(FLAGS) -I $(LIB_PATH) $< -o $@

$(INSTR): %.o: $(INSTR_PATH)%.c
		@$(CC) -c $(FLAGS) -I $(LIB_PATH) $< -o $@
clean:
		rm -f $(OBJ) checker.h.gch $(LIB_NAME)

fclean: clean
		rm -f $(NAME)

re: fclean all