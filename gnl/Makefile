# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mqueiros <mqueiros@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 15:42:21 by mqueiros          #+#    #+#              #
#    Updated: 2025/05/07 17:36:04 by mqueiros         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Name
NAME = gnl.a
EXEC = a.out \
	test_1 test_10 test_42 test_100000 test_0 \
	t_empty.txt t_newline.txt t_hello_world.txt t_multiple_newlines.txt

#Compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
BUFFER_SIZES = 1 10 42 100000 0

#Files & Directories
SRCS = get_next_line.c get_next_line_utils.c
BONUS_SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

#Commands
AR = ar rcs
RM = rm -rf

#Rules
all: $(NAME)

logo:
	@echo -n "\033[1;33m"
	@echo ""
	@echo "    _____ _____ _____       _____ _____ __ __ _____       __    _____ _____ _____ "
	@echo "   |   __|   __|_   _|     |   | |   __|  |  |_   _|     |  |  |_   _|   | |   __|"
	@echo "   |  |  |   __| | |       | | | |   __|-   -| | |       |  |__ _| |_| | | |   __|"
	@echo "   |_____|_____| |_|  _____|_|___|_____|__|__| |_|  _____|_____|_____|_|___|_____|"
	@echo "                     |_____|                       |_____|                    "
	@echo -n "\033[0m"
	@echo "                                                             By: Miguel Azuaga"
	@echo ""


$(NAME): $(OBJS)
	@echo "Building Get Next Line library..."
	@$(AR) $(NAME) $(OBJS)
	@$(MAKE) --no-print-directory logo
	@echo "\033[1;32mBuild complete!\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_OBJS)
	@echo "Building the Get Next Line's Bonus library..."
	@$(AR) $(NAME) $(BONUS_OBJS) $(OBJS)
	@echo "\033[1;32mBuild complete!\033[0m"

test:
	@if [ ! -f $(NAME) ]; then \
		@$(MAKE) all; \
	fi
	@$(CC) $(CFLAGS) main.c $(NAME) -o $(EXEC)

# Loop through each BUFFER_SIZE
tester: create_test_files
	@for size in $(BUFFER_SIZES); do \
		echo "Testing with BUFFER_SIZE=$$size..."; \
		$(CC) $(CFLAGS) -DBUFFER_SIZE=$$size main.c $(NAME) -o test_$$size; \
		if [ -x test_$$size ]; then \
			echo "Output for BUFFER_SIZE=$$size:"; \
			./test_$$size; \
			echo ""; \
		else \
			echo "Compilation failed for BUFFER_SIZE=$$size"; \
		fi; \
	done

create_test_files:
	@echo "Creating test files..."
	@echo -n "" > t_empty.txt
	@echo "\n" > t_newline.txt
	@echo "Hello World" > t_hello_world.txt
	@echo -e "Hello\n\n\nWorld" > t_multiple_newlines.txt
	@echo "\033[1;32mTest files created!\033[0m"


clean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJS)
	@echo "\033[1;32mCleaned all objects!\033[0m"

fclean: clean
	@echo "Full cleaning..."
	@$(RM) $(NAME) $(EXEC)
	@echo "\033[1;32mFull clean complete!\033[0m"

re: fclean all

.PHONY: all clean fclean re logo test tester
