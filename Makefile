NAME = push_swap
NAME_1 = checker

SRC_DIR = Mandatory
BONUS_DIR = Bonus

SRC_FILES = push_swap.c ft_strjoin.c ft_putstr.c ft_split.c ft_substr.c res.c \
			init_stack_a.c errors.c sort_stacks.c stack_sorted.c push.c swap.c sort_three.c \
			rotate.c rev_rotate.c init_a_to_b.c init_b_to_a.c
			

SRCB_FILES = checker.c init_stack_a_bonus.c get_next_line.c get_next_line_utils.c \
             ft_strcmp.c checker_moves.c ft_atol.c rev_rotate_b.c rotate_b.c swap_b.c push_b.c \
             ft_putstr_fd.c ../Mandatory/process_arguments.c ../Mandatory/errors.c \
			 ../Mandatory/split.c ../Mandatory/res2.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
SRCB = $(addprefix $(BONUS_DIR)/, $(SRCB_FILES))

OBG = $(SRC:.c=.o)
OBGB = $(SRCB:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(OBG)
	$(CC) $(CFLAGS) $(OBG) -o $(NAME)

bonus : $(NAME_1)

$(NAME_1): $(OBGB) 
	$(CC) $(CFLAGS) $(OBGB)  -o $(NAME_1)

clean:
	$(RM) $(OBG) $(OBGB) 

fclean: clean
	$(RM) $(NAME) $(NAME_1)

re: fclean all

