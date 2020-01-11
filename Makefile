# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 17:03:41 by tguillem          #+#    #+#              #
#    Updated: 2020/01/11 15:26:19 by dholiday         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFTPATH = ./Libft
LIBFT = $(LIBFTPATH)/libft.a

CFLAGS =  -I. -I$(LIBFTPATH) -Iinc -g3
CC = gcc
LS = ft_ls

SRC_PATH = ./src/
SRC_NAME = main.c parset.c list.c recursion.c  read_all.c clean.c  sort.c flag_l.c \
razriad.c flag_l_perm.c flag_l_date.c sort_by_time.c sort_alpha.c flags_m_one.c \
new_elem.c flags.c error_list.c 
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ = $(SRC:%.c=%.o)

NAME = ft_ls

all: $(NAME)

$(NAME) : $(LIBFT) $(OBJ) 
	gcc $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ) : ./ft_ls.h

$(LIBFT) :
	make -C $(LIBFTPATH)

clean:
	make clean -C $(LIBFTPATH)
	rm -f $(OBJ) 

fclean: clean
	make fclean -C $(LIBFTPATH)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
