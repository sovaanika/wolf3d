NAME = libft.a
INCLUDES = includes/libft.h
SRC = ft_isalpha.c ft_isdigit.c ft_strlen.c ft_putchar.c ft_wordcount.c ft_wordsize.c ft_putstr.c ft_memalloc.c ft_memdel.c ft_striter.c ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_putnbr.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_striteri.c ft_strlcat.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strstr.c ft_tolower.c ft_toupper.c ft_isascii.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strsplit.c ft_lstnew.c ft_lstdelone.c ft_lstadd.c ft_lstdel.c ft_lstiter.c ft_lstmap.c ft_split_whitespaces.c ft_btree_create_node.c ft_btree_apply_suffix.c ft_btree_apply_prefix.c ft_btree_apply_infix.c

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC) -I$(INCLUDES)
	ar rc $(NAME) ft_*.o

clean:
	/bin/rm -f ft_*.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
