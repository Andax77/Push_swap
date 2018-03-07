NAME = checker
NAME2 = push_swap
SRC_PATH = src
SRC_NAME = checker.c \
			init.c \
			operate.c \
			operate2.c \
			operate3.c \

SRC_NAME2 = push_swap.c \
			init.c \
			operate.c \
			operate2.c \
			operate3.c \
			algo.c

OBJ_PATH2 = obj2
OBJ_PATH = obj
LDFLAGS = -L libft/ -lft
CFLAGS = -I includes -I libft
FLAGS = -Wall -Werror -Wextra
RM = rm -f

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_NAME2 = $(SRC_NAME2:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
SRC2 = $(addprefix $(SRC_PATH)/,$(SRC_NAME2))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJ2 = $(addprefix $(OBJ_PATH2)/,$(OBJ_NAME2))

all: $(NAME2)
	# $(NAME2)

$(NAME): $(OBJ)
	@make -C libft
	@libtool -static -o $(NAME) $(OBJ) libft/libft.a
	@gcc $(FLAGS) $(LDFLAGS) $(CFLAGS) -o $@ $^
	@printf '\033[32m[ ✔ ] %s\n\033[0m' "Create checker"

$(NAME2): $(OBJ2)
	@make -C libft
	@libtool -static -o $(NAME2) $(OBJ2) libft/libft.a
	@gcc $(FLAGS) $(LDFLAGS) $(CFLAGS) -o $@ $^
	@printf '\033[32m[ ✔ ] %s\n\033[0m' "Create Push_swap"

obj/%.o: src/%.c
	@mkdir -p obj
	@gcc $(FLAGS) $(CFLAGS) -c $< -o $@
	@printf '\033[35m[ ✔ ] %s\n\033[0m' "$<"

obj2/%.o: src/%.c
	@mkdir -p obj2
	@gcc $(FLAGS) $(CFLAGS) -c $< -o $@
	@printf '\033[35m[ ✔ ] %s\n\033[0m' "$<"

clean:
	@make -C libft clean
	$(RM) $(OBJ)
	$(RM) $(OBJ2)
	@rm -rf $(OBJ_PATH) 2> /dev/null || true
	@rm -rf $(OBJ_PATH2) 2> /dev/null || true
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean complete"

fclean: clean
	@make -C libft fclean
	$(RM) $(NAME)
	$(RM) $(NAME2)
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean complete"

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

.PHONY: all, clean, fclean, re, norme
