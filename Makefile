NAME = fract_ol

SRC = src/fract_ol_hooks.c\
src/fract_ol_drawing.c\
src/fract_ol_utils.c\
src/main.c\
src/fract_ol_warnings.c\

HEADER = include/fract_ol.h

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	@${MAKE} -C Libft
	@cc $(FLAGS) $(OBJ) Libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o:%.c
	@cc $(FLAGS) -c $< -o $@

clean:
	@${MAKE} -C Libft fclean
	@rm -rf src/*.o

fclean: clean
	@rm -rf $(NAME) 

re: fclean $(NAME) 

rb: fclean 

.PHONY: all allb clean fclean