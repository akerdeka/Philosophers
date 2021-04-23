SRC =	main.c srcs/parsing/parsing.c srcs/parsing/pars_utils.c srcs/list_utils/new_list.c srcs/philosophers.c\
		srcs/print_philo.c srcs/actions.c srcs/ft_free.c srcs/parsing/ft_itoa.c srcs/create_sem.c

HEADERS = philo_three.h
OBJ = $(SRC:.c=.o)
NAME = philo_three
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
SANITIZE = -Wall -Wextra -Werror -fsanitize=address
RM = rm -f

all :		${NAME}

$(NAME) :	$(OBJ)
				$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o :		%.c $(HEADERS)
				@$(CC) $(CFLAGS) -o $@ -c $<
			
clean :
			rm -rf $(OBJ)

fclean :	clean
				rm -rf ${NAME}

re : fclean all

sanitize : fclean $(NAME) $(FSANITIZE)

$(FSANITIZE) : $(OBJ)
				$(CC) $(SANITIZE) -o $@ $(OBJ)

.PHONY : all clean fclean re