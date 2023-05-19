NAME = fract_ol

SRC = $(wildcard src/*.c)

HEADER = $(wildcard include/*.h)

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