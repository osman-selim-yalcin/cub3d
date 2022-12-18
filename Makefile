SRCS = *c

OBJS = $(SRCS:.c=.o)

MLX = minilibx/libmlx.a 

CC = gcc

FLAGS =  -Wall -Wextra -Werror

RM = rm -rf

NAME = cub3D

	
all :$(MLX) $(NAME)

$(MLX):
	make -C minilibx

$(NAME): $(MLX) $(OBJS)
	$(CC) $(OBJS) $(MLX) $(FLAGS) -framework OpenGL -framework AppKit -o $(NAME)

fclean : clean
	$(RM) *.a
	$(RM) $(NAME)
	make clean -C minilibx

clean :
	$(RM) *.o

re : fclean all

.PHONY : all bonus fclean clean re
