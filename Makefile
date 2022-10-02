SRCS = *c

OBJS = $(SRCS:.c=.o)

EXT = minilibx/libmlx.a 

CC = gcc

FLAGS =  -Wall -Wextra -Werror

RM = rm -rf

NAME = cub3d

all :$(EXT) $(NAME)

$(EXT):
	make -C minilibx

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(EXT) $(FLAGS) -framework OpenGL -framework AppKit -o $(NAME) -g

fclean : clean
	$(RM) *.a
	$(RM) $(NAME)

clean :
	$(RM) *.o

re : fclean all


.PHONY : all bonus fclean clean re
