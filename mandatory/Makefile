NAME = fract_ol

CHECKER = checker

SRC = $(wildcard *.c)

SRCB = $(wildcard bonus/*.c)

HEADER = $(wildcard *.h)

HEADERB = $(wildcard bonus/*.h)

HEADERGNL = get_next_line.h

OBJ = $(SRC:.c=.o)

OBJB = $(SRCB:.c=.o)


FLAGS = -Wall -Wextra -Werror #-fsanitize=address

all: $(NAME)
$(NAME): $(OBJ)
	@cc $(FLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

allb: $(CHECKER)
$(CHECKER): $(OBJB)
	@cc $(FLAGS) $(OBJB) -o $(CHECKER)

%.o:%.c
	@cc $(FLAGS) -c $< -o $@

clean:
	@rm -rf *.o bonus/*.o

bonus: $(CHECKER) allb

fclean: clean
	@rm -rf $(NAME) 

re: fclean $(NAME) 

rb: fclean bonus

.PHONY: all allb clean fclean bonus rb