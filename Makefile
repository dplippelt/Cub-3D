# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/16 12:34:50 by dlippelt          #+#    #+#              #
#    Updated: 2025/06/16 15:50:27 by dlippelt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		cub3D

CC =		cc
RM =		rm -rf
VALG =		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

CFLAGS =	-Wall -Werror -Wextra -g3
IFLAGS =	-I$(INCDIR) -I$(MLXDIR)
OUTPUT =	-o
EXLIBS =	-L$(MLXDIR) -lmlx -lXext -lX11 -lm

MLXDIR =	./mlx
SRCDIR =	./src
INCDIR =	./inc
OBJDIR =	./obj

MLXLIB =	$(MLXDIR)/libmlx.a
MLXMAKE =	make -C $(MLXDIR)

SRCS =		$(shell find $(SRCDIR) -name "*.c" | sed 's|$(SRCDIR)/||')

HDRS =		$(shell find $(INCDIR) -name "*.h" | sed 's|$(INCDIR)/||')

OBJS =		$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

OBJDIRS =	$(sort $(dir $(OBJS)))

all: $(NAME)

$(OBJDIRS):
	mkdir -p $@

$(NAME): $(MLXLIB) $(OBJDIRS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(EXLIBS) $(OUTPUT) $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(addprefix $(INCDIR)/, $(HDRS))
	$(CC) $(CFLAGS) $(IFLAGS) -c $< $(OUTPUT) $@

$(MLXLIB):
	$(MLXMAKE)

clean:
	$(RM) $(OBJDIR)
	$(RM) *.xml
	$(MLXMAKE) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

valgrind: $(NAME)
	$(VALG) ./$(NAME) $(ARGS)

memory: CFLAGS += -fsanitize=address
memory: re

.PHONY: all clean fclean re valgrind memory
