#Name
NAME = libftprintf.a
EXEC = a.out

#Compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror

#Files & Directories
SRCS = ft_printf.c ft_utils.c
OBJS = $(SRCS:.c=.o)
SRCS_DIR = .

#Commands
AR = ar rcs
RM = rm -rf

#Colors
WHITE = \033[0m
GREEN = \033[1;38;5;120m
COLOR = \033[1;31m

#Rules
all: $(NAME)

logo:
	@echo -n "$(COLOR)"
	@echo ""
	@echo "   ██████╗ ██████╗ ██╗███╗   ██╗████████╗███████╗"
	@echo "   ██╔══██╗██╔══██╗██║████╗  ██║╚══██╔══╝██╔════╝"
	@echo "   ██████╔╝██████╔╝██║██╔██╗ ██║   ██║   █████╗  "
	@echo "   ██╔═══╝ ██╔══██╗██║██║╚██╗██║   ██║   ██╔══╝  "
	@echo "   ██║     ██║  ██║██║██║ ╚████║   ██║   ██║     "
	@echo "   ╚═╝     ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝   ╚═╝   ╚═╝     "
	@echo -n "$(WHITE)"
	@echo "                                By: Miguel Azuaga"
	@echo ""


$(NAME): $(OBJS)
	@echo "Building printf..."
	@$(AR) $(NAME) $(OBJS)
	@$(MAKE) --no-print-directory logo
	@echo "$(GREEN)Build complete!$(WHITE)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

test:
	@$(CC) $(CFLAGS) main.c $(NAME) -o $(EXEC)

clean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJS)
	@echo "$(GREEN)Cleaned all objects!$(WHITE)"

fclean: clean
	@echo "Full cleaning..."
	@$(RM) $(NAME) $(EXEC)
	@echo "$(GREEN)Full clean complete!$(WHITE)"

re: fclean all

.PHONY: all clean fclean re logo test
