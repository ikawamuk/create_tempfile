# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/01 14:20:04 by ikawamuk          #+#    #+#              #
#    Updated: 2026/02/01 14:32:53 by ikawamuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= create_tmpfile.a

CC = cc
CFLAG = -Werror -Wall -Wextra $(addprefix -I, $(INCDIR))
RMDIR = $(RM) -rf

AR	=	ar

SRCS =	$(wildcard $(SRCDIR)/*.c)

OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

TEST = $(addprefix $(TESTDIR)/, test.sh)

LIBFT	=	libft/libft.a


SRCDIR = src
OBJDIR = obj
INCDIR = include libft/include
TESTDIR = test
TMPDIR = tmp_obj

all:$(NAME)

$(NAME):$(OBJS) $(LIBFT)
	@mkdir -p $(TMPDIR)
	@cd $(TMPDIR) && $(AR) x ../$(LIBFT)
	$(AR) rcs $@ $(OBJS) $(TMPDIR)/*.o
	@$(RMDIR) $(TMPDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAG) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft/

clean:
	@$(RMDIR) $(OBJDIER)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test:
	@./$(TEST)

.PHONY: all clean fclean re test