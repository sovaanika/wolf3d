NAME = wolf3d
SRC = ./srcs/test.c ./srcs/dda.c ./srcs/textureread.c ./srcs/main.c ./srcs/raycaster.c ./srcs/validation.c ./srcs/draw.c ./srcs/keyfunctions.c
INC = wolf.h
LIBFTFOLDER = ./libft
LIBFTINC = -I ./libft -L ./libft -lft
FLAGS = -Wall -Wextra -Werror

MLX = -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -framework OpenCL

all: $(NAME)

$(NAME): makelibft
	gcc -g $(FLAGS) $(MLX) $(LIBFTINC) -I $(INC) $(SRC) -o $(NAME)

clean:
	make -C $(LIBFTFOLDER) clean

fclean:
	make -C $(LIBFTFOLDER) fclean
	rm -f $(NAME)

re: fclean all

makelibft:
	$(MAKE) -C $(LIBFTFOLDER)