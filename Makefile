##
## Makefile for lemin in /home/vatoth/Epitech/CPE_2016_Lemin
## 
## Made by 
## Login   <quentin.sonnefraud@epitech.eu>
## 
## Started on  Mon Apr 17 14:34:33 2017 
## Last update Sun Apr 30 12:45:54 2017 
##

CC    	=    gcc

RM    	=    rm -rf

CFLAGS	+= -Wall -Wextra -std=gnu90

CPPFLAGS += -I./include

LDFLAGS =    $(CFLAGS)

SRCS    =	src/main.c			\
		src/tools2.c			\
		src/tools.c			\
		src/get_next_line.c		\
		src/clear_file.c		\
		src/parse.c			\
		src/create_edge.c		\
		src/check_info.c		\
		src/print_info.c 		\
		src/clear_list.c		\
		src/free_list.c			\
		src/algo.c			\
		src/algo_fcts.c			\
		src/resolve.c			\
		src/my_getnbr.c			\
		src/recup_info.c		\
		src/my_str_to_wordtab.c 	\
		./my_printf/my_putchar.c 	\
		./my_printf/my_strlen.c 	\
		./my_printf/my_printable.c 	\
		./my_printf/my_putstr.c 	\
		./my_printf/my_put_nbr.c 	\
		./my_printf/my_put_long.c 	\
		./my_printf/my_printf.c 	\
		./my_printf/my_base.c 		\
		./my_printf/my_put_pointers.c 	\
		./my_printf/my_put_unsigned.c

OBJS    =    $(SRCS:.c=.o)

LIBS	=    $(OBJS)

NAME    =    lem_in

all:    $(NAME)

$(NAME):  $(OBJS)
	$(CC) -o $(NAME) $(OBJ) $(LIBS) $(LDFLAGS)

clean :
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:    fclean all

.PHONY: all clean fclean re
