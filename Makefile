#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

# Special variables
DEFAULT_GOAL: all
.DELETE_ON_ERROR: $(NAME)
.PHONY: all bonus clean fclean re
# 'HIDE = @' will hide all terminal output from Make
HIDE =


#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

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


#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(LDIR)$(LIBFT) $(NAME)

# Generates output file
$(NAME): $(OBJS) $(LDIR)$(LIBFT)
	$(HIDE) cp $(LDIR)$(LIBFT) $@
	$(HIDE) ar rcs $(NAME) $(OBJS) $@
	
# Compiles sources into objects
$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c $(INC) | $(OBJDIR)
	$(HIDE)$(CC) $(CFLAGS) -c $< -o $@

# Creates directory for binaries
$(OBJDIR):
	$(HIDE)mkdir -p $@

$(LDIR)$(LIBFT):
	$(HIDE)$(MAKE) -C $(LDIR)

# Removes objects
clean:
	$(HIDE)$(RM) $(OBJS)
	$(HIDE)$(RM) $(LDIR)*.o

# Removes objects and executables
fclean: clean
	$(HIDE)$(RM) $(NAME)
	$(HIDE)$(RM) $(LDIR)$(LIBFT)

# Removes objects and executables and remakes
re: fclean all