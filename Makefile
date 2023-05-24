NAME = fract_ol

SRC = src/fract_ol_hooks.c\
src/fract_ol_Mandelbrot.c\
src/fract_ol_utils.c\
src/main.c\

HEADER = include/fract_ol.h

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	@cc $(FLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o:%.c
	@cc $(FLAGS) -c $< -o $@

clean:
	@rm -rf *.o src/*.o

fclean: clean
	@rm -rf $(NAME) 

re: fclean $(NAME) 

rb: fclean 

.PHONY: all allb clean fclean