# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 14:05:22 by ivalimak          #+#    #+#              #
#    Updated: 2024/01/08 18:13:21 by ivalimak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
BNAME	=	checker

BUILD	=	normal

CC				=	cc
cflags.common	=	-Wall -Wextra -Werror
cflags.debug	=	-g
cflags.debugm	=	$(cflags.debug) -D DEBUG_MSG=1
cflags.asan		=	$(cflags.debug) -fsanitize=address -static-libsan
cflags.normal	=	
CFLAGS			=	$(cflags.common) $(cflags.$(BUILD))

SRCDIR	=	src
OBJDIR	=	obj
LIBDIR	=	libft

LIBFT	=	$(LIBDIR)/libft.a

CSRCS	=	$(SRCDIR)/args.c \
			$(SRCDIR)/push.c \
			$(SRCDIR)/swap.c \
			$(SRCDIR)/utils.c \
			$(SRCDIR)/shift.c \
			$(SRCDIR)/rotate.c \
			$(SRCDIR)/reverse.c \
			$(SRCDIR)/stackutils.c

MSRCS	=	$(SRCDIR)/main.c \
			$(SRCDIR)/solve.c \
			$(SRCDIR)/ops.c \
			$(SRCDIR)/pos.c

BSRCS	=	$(SRCDIR)/main_bonus.c \
			$(SRCDIR)/ops_bonus.c

COBJS	=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(CSRCS))
MOBJS	=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(MSRCS))
BOBJS	=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(BSRCS))

all: $(OBJDIR) $(NAME)

bonus: $(OBJDIR) $(BNAME)

$(NAME): $(LIBFT) $(COBJS) $(MOBJS)
	@echo Compiling $(NAME)...
	@$(CC) $(CFLAGS) $(MOBJS) $(COBJS) -L$(LIBDIR) -lft -o $(NAME)

$(BNAME): $(LIBFT) $(COBJS) $(BOBJS)
	@echo Compiling $(BNAME)...
	@$(CC) $(CFLAGS) $(BOBJS) $(COBJS) -L$(LIBDIR) -lft -o $(BNAME)

$(LIBFT):
	@make -C $(LIBDIR) --no-print-directory BUILD=$(BUILD)

$(OBJDIR):
	@echo Creating objdir...
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C $(LIBDIR) clean --no-print-directory
	@rm -f $(COBJS)
	@rm -f $(MOBJS)
	@rm -f $(BOBJS)

fclean: clean
	@make -C $(LIBDIR) fclean --no-print-directory
	@rm -rf $(OBJDIR)
	@rm -f $(BNAME)
	@rm -f $(NAME)

re: fclean all
