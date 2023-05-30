NAME = fract_ol

SRC = src/fract_ol_hooks.c\
src/fract_ol_drawing.c\
src/fract_ol_utils.c\
src/main.c\
src/fract_ol_warnings.c\

SRCB = srcb/fract_ol_hooks_bonus.c\
srcb/fract_ol_drawing_bonus.c\
srcb/fract_ol_utils_bonus.c\
srcb/main_bonus.c\
srcb/fract_ol_warnings_bonus.c\
srcb/alien_bonus.c\

OBJ = $(SRC:.c=.o)

OBJB = $(SRCB:.c=.o)

FLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	@${MAKE} -C Libft
	@cc $(FLAGS) $(OBJ) Libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o:%.c
	@cc $(FLAGS) -c $< -o $@

clean:
	@${MAKE} -C Libft fclean
	@rm -rf src/*.o
	@rm -rf srcb/*.o

bonus:
	@make OBJ="$(OBJB)" all

fclean: clean
	@rm -rf $(NAME) 

re: fclean $(NAME) 

rb: fclean bonus

.PHONY: all allb clean fclean bonus re rb