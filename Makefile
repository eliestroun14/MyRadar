##
## EPITECH PROJECT, 2023
## Untitled (Workspace)
## File description:
## Makefile
##

NAME	= my_radar

#bootstrap
SRC		= ./src/bootstrap/main.c
SRC		+=./src/bootstrap/create_circle.c
SRC		+=./src/bootstrap/intersecting_circles.c

SRC		+= ./src/fps/print_fps.c

SRC 	+= ./src/init_textures/window_init.c

SRC		+= ./src/handle_events/handle_window_closed.c

OBJS	= $(SRC:.c=.o)

LDFLAGS	= -L. -lmy -I./include/

RM		= rm

LIB		= make -C lib/

all: $(NAME)
.PHONY:all

$(NAME): $(OBJS)
	$(LIB)
	gcc -o $(NAME) $(OBJS) -L /usr/lib/ -I/usr/include -lcsfml-graphics \
		-lcsfml-window -lcsfml-system -lcsfml-audio -lm -g $(LDFLAGS)

lib:
	$(LIB)

lclean:
	make clean -C lib/

lfclean:
	make fclean -C lib/

lre:
	make re -C lib/

clean:
	$(RM) $(OBJS)
.PHONY:clean

fclean: clean
	$(RM) -f $(NAME)
.PHONY:fclean

re: fclean all
.PHONY:re
