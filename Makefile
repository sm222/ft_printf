
NAME	=	libftprintf.a
LIBFT	= 	libft.a
LDIR	=	libft/

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f

SRCS	=	ft_printf.c\
			ft_put_hex.c\
			ft_put_p.c\
			ft_put_u.c\
			ft_ulltoa.c

OBJS	=	$(SRCS:.c=.o)

all: $(LDIR)$(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LDIR)$(LIBFT)
	cp $(LDIR)$(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

$(LDIR)$(LIBFT):
	$(MAKE) -C $(LDIR)

clean:
	$(RM) $(OBJS)
	$(RM) $(LDIR)*.o

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LDIR)$(LIBFT)

re: fclean all