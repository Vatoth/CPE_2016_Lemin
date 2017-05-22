##
## Makefile for *** in /home/leandre/***
## 
## Made by Léandre Blanchard
## Login   <leandre.blanchard@epitech.eu>
## 
## Started on  Thu Dec 15 20:24:11 2016 Léandre Blanchard
## Last update Tue May  2 13:21:37 2017 Léandre Blanchard
##

NAME	= visu-hex

CC	= gcc

LIB	= -lc_graph_prog_full -L./lib/CSFML -l_my_csfml -lm -lncurses

SRCS	= src/main.c \
	  src/my_str_to_wordtab.c \
	  src/check.c		  \
	  src/parsing.c \
	  src/free.c \
	  src/server_sockets.c \
	  src/client_sockets.c \
	  src/sprites.c \
	  src/move_ant.c \
	  src/draw_line.c \
	  src/draw_tunnels.c \
	  src/socket.c

OBJ	= $(SRCS:.c=.o)

RM	= rm -f

CFLAGS	+= -W -Wall -Wextra -I ./include

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LIB)
	@       tput setaf 2; cat include/signature; tput sgr0

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
