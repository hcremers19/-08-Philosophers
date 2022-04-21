# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/17 12:52:38 by hcremers          #+#    #+#              #
#    Updated: 2022/04/21 16:37:32 by hcremers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
DIRCPY	= \[07\]Philosophers

SRC		= $(wildcard *.c)

OBJ		= $(addprefix $(OBJDIR), $(SRC:.c=.o))
OBJDIR	= objs/

LIB		= srcs/libsrcs.a

DISTANT	= /Volumes/Clémentine/19/

CFLAGS	= -Wall -Wextra -Werror -pthread

CC		= gcc
RM		= rm -f
MKDIR	= mkdir
COPY	= cp -r
MV		= mv

###############################################################################

$(OBJDIR)%.o:	%.c
				$(CC) $(CFLAGS) -c $< -o $(addprefix $(OBJDIR), $(<:.c=.o))

all:			$(NAME)

$(NAME):		$(OBJ)
				make -C srcs/
				$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

$(OBJ):			| $(OBJDIR)

$(OBJDIR):
				$(MKDIR) $(OBJDIR)

clean:
				make clean -C srcs/
				$(RM) $(wildcard *.o)
				$(RM) -r $(OBJDIR)

fclean:			clean
				make fclean -C srcs/
				$(RM) $(NAME)

re:				fclean all

copy:			fclean
				$(RM) -r ../$(DIRCPY)/
				$(COPY) ../$(NAME)/ ../$(DIRCPY)/

xport:			copy
				$(RM) -r $(DISTANT)/$(DIRCPY)/
				$(MV) $(DIRCPY)/ $(DISTANT)

.PHONY:			all clean fclean re copy xport