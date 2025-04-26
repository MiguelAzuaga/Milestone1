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

#Rules
all: $(NAME)

logo:
	@echo "\033[1;31m"
	@echo ""
	@echo "   ██████╗ ██████╗ ██╗███╗   ██╗████████╗███████╗"
	@echo "   ██╔══██╗██╔══██╗██║████╗  ██║╚══██╔══╝██╔════╝"
	@echo "   ██████╔╝██████╔╝██║██╔██╗ ██║   ██║   █████╗  "
	@echo "   ██╔═══╝ ██╔══██╗██║██║╚██╗██║   ██║   ██╔══╝  "
	@echo "   ██║     ██║  ██║██║██║ ╚████║   ██║   ██║     "
	@echo "   ╚═╝     ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝   ╚═╝   ╚═╝     "
	@echo "\033[0m                                    By: Miguel Azuaga"
	@echo ""


$(NAME): $(OBJS)
	@echo "Building printf..."
	@$(AR) $(NAME) $(OBJS)
	@$(MAKE) --no-print-directory logo
	@echo "\033[1;32mBuild complete!\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

test: all
	$(CC) $(CFLAGS) main.c $(NAME) -o $(EXEC)

clean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJS)
	@echo "\033[1;32mCleaned all objects!\033[0m"

fclean: clean
	@echo "Full cleaning..."
	@$(RM) $(NAME) $(EXEC)
	@echo "\033[1;32mFull clean complete!\033[0m"

re: fclean all

.PHONY: all clean fclean re logo test
