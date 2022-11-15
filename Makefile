
NAME	=	libftprintf.a

SRCS	=	ft_printf.c\
			ft_put_hex.c\
			ft_put_p.c\
			ft_put_u.c\
			ft_ulltoa.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

LIBFT	= 	libft.a
LDIR	=	libft/


$(NAME): $(OBJS) $(LDIR)$(LIBFT)
	cp $(LDIR)$(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJS)

all: $(LDIR)$(LIBFT) $(NAME)


$(LDIR)$(LIBFT):
	$(MAKE) -C $(LDIR)

clean:
	$(RM) $(OBJS)
	$(RM) $(LDIR)*.o

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LDIR)$(LIBFT)

re: fclean all