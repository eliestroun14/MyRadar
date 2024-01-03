##
## EPITECH PROJECT, 2023
## Untitled (Workspace)
## File description:
## Makefile
##

NAME	= my_radar

SRC		= src/main.c
SRC		+= src/my_radar.c
SRC		+= src/open/open.c

SRC		+= src/aircrafts/fill_plane.c
SRC		+= src/aircrafts/destroy_plane.c
SRC		+= src/tower/fill_tower.c

SRC		+= src/csmfl_lib/texture_init.c
SRC		+= src/csmfl_lib/window_init.c
SRC		+= src/csmfl_lib/handle_events.c

SRC		+= src/simulation/simulation.c
SRC		+= src/simulation/update_plane.c
SRC		+= src/simulation/render_simulation.c

OBJS	= $(SRC:.c=.o)

LDFLAGS	= -L. -lmy -I include/

CFLAGS = -Wextra -Wall -g

RM		= rm

LIB		= make -C lib/

all: $(NAME)
.PHONY:all

$(NAME): $(OBJS)
	$(LIB)
	gcc -o $(NAME) $(OBJS) -L /usr/lib/ -I/usr/include -lcsfml-graphics \
		-lcsfml-window -lcsfml-system -lcsfml-audio -lm $(LDFLAGS)

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
