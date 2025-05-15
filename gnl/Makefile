# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mqueiros <mqueiros@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 15:42:21 by mqueiros          #+#    #+#              #
#    Updated: 2025/05/ by mqueiros         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Name
NAME = gnl.a
EXEC = a.out test_1 test_10 test_42 test_100000 test_0 
TEST_FILES = t_empty.txt t_newline.txt t_hello_world.txt t_mult_newlines.txt

#Compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

#Files & Directories
SRCS = get_next_line.c get_next_line_utils.c
BONUS_SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

#Commands
AR = ar rcs
RM = rm -rf

#Colors
WHITE = \033[0m
GREEN = \033[1;38;5;120m
COLOR = \033[1;33m

#Rules
all: $(NAME)

logo:
	@echo -n "$(COLOR)"
	@echo ""
	@echo "    _____  _____  _____        "
	@echo "   |   __||   __||_   _|       "
	@echo "   |  |  ||   __|  | |         "
	@echo "   |_____||_____|  |_|         "
	@echo "    _____  _____  __ __  _____ "
	@echo "   |   | ||   __||  |  ||_   _|"
	@echo "   | | | ||   __||-   -|  | |  "
	@echo "   |_|___||_____||__|__|  |_|  "
	@echo "    __     _____  _____  _____ "
	@echo "   |  |   |_   _||   | ||   __|"
	@echo "   |  |__  _| |_ | | | ||   __|"
	@echo "   |_____||_____||_|___||_____|"
	@echo -n "\033[0m"
	@echo "        By: Miguel Azuaga"
	@echo ""
$(NAME): $(OBJS)
	@echo "Building Get Next Line library..."
	@$(AR) $(NAME) $(OBJS)
	@$(MAKE) --no-print-directory logo
	@echo "$(GREEN)Build complete!$(WHITE)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_OBJS)
	@echo "Building the Get Next Line's Bonus library..."
	@$(AR) $(NAME) $(BONUS_OBJS) $(OBJS)
	@echo "$(GREEN)Build complete!$(WHITE)"

test: $(NAME)
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=1 main.c $(NAME) -o test_1
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=10 main.c $(NAME) -o test_10
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=42 main.c $(NAME) -o test_42
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=100000 main.c $(NAME) -o test_100000
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=0 main.c $(NAME) -o test_0

# Run All Tests
tester: create_test_files test
	@echo "$(COLOR)Running tests...$(WHITE)\n\nBUFFER_SIZE = 1"
	@./test_1 && echo "\n\nBUFFER_SIZE = 10"
	@./test_10 && echo "\n\nBUFFER_SIZE = 42"
	@./test_42 && echo "\n\nBUFFER_SIZE = 100000"
	@./test_100000 && echo "\n\nBUFFER_SIZE = 0"
	@./test_0 || echo "BUFFER_SIZE = 0 is expected to fail"

create_test_files:
	@echo "Creating test files..."
	@echo -n "" > t_empty.txt
	@echo -n "\n" > t_newline.txt
	@echo -n "Hello World" > t_hello_world.txt
	@echo -n "Hello\n\n\nWorld" > t_mult_newlines.txt
	@echo "$(GREEN)Test files created!$(WHITE)"


clean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJS)
	@echo "$(GREEN)Cleaned all objects!$(WHITE)"

fclean: clean
	@echo "Full cleaning..."
	@$(RM) $(NAME) $(EXEC) $(TEST_FILES)
	@echo "$(GREEN)Full clean complete!$(WHITE)"

re: fclean all

.PHONY: all clean fclean re logo test tester
