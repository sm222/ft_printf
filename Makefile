
# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -I. -I./$(INCDIR)
RM		=	rm -f

# Output file name
NAME	=	libftprintf.a
LIBFT	= 	libft.a
LDIR	=	libft/

# Sources are all .c files
SRCDIR	=	./
SRCS	=	$(wildcard $(SRCDIR)*.c) # Wildcard for sources is forbidden by norminette

# Objects are all .o files
OBJDIR	=	bin/
OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))

# Includes are all .h files
INCDIR	=	include/
INC		=	$(wildcard $(INCDIR)*.h)


all: $(LDIR)$(LIBFT) $(NAME)


$(NAME): $(OBJS) $(LDIR)$(LIBFT)
	$(HIDE) cp $(LDIR)$(LIBFT) $@
	$(HIDE) ar rcs $(NAME) $(OBJS) $@
	

$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c $(INC) | $(OBJDIR)
	$(HIDE)$(CC) $(CFLAGS) -c $< -o $@


$(OBJDIR):
	$(HIDE)mkdir -p $@

$(LDIR)$(LIBFT):
	$(HIDE)$(MAKE) -C $(LDIR)


clean:
	$(HIDE)$(RM) $(OBJS)
	$(HIDE)$(RM) $(LDIR)*.o


fclean: clean
	$(HIDE)$(RM) $(NAME)
	$(HIDE)$(RM) $(LDIR)$(LIBFT)

re: fclean all