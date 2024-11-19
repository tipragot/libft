CFLAGS = -Wall -Werror -Wextra
AR = ar
CC = cc

SRC = print/ft_printf.c print/ft_putnbr.c print/ft_putstr.c \
      list/ft_list_get.c list/ft_list_len.c list/ft_list_new.c \
      list/ft_list_push.c list/ft_list_pop.c list/ft_list_rotate.c \
      list/ft_list_iter.c
OBJ = $(SRC:.c=.o)
NAME = libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) rcs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(NAME) $(OBJ)

re: fclean $(NAME)

push: fclean
	rm -rf /tmp/libft
	git clone git@github.com:tipragot/libft.git /tmp/libft
	cp -r * /tmp/libft/.
	cd /tmp/libft && git add . && git commit -m "Update libft" && git push
	rm -rf /tmp/libft

pull:
	git init
	git remote add origin git@github.com:tipragot/libft.git
	git clean -fd
	git pull origin master
	rm -rf .git

.PHONY: all clean fclean re push pull
