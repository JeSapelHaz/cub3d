# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 13:38:30 by hbutt             #+#    #+#              #
#    Updated: 2024/04/24 15:09:38 by hbutt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

AR = @ar -rsc

SRC =  ft_atoi.c ft_bzero.c ft_calloc.c  ft_isascii.c ft_isdigit.c ft_isprint.c  ft_isalpha.c ft_isalnum.c\
		ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_split.c ft_strchr.c ft_strnstr.c\
		ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
		ft_strmapi.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
		ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
		
SRCB = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
		ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

SRCSALL = ${SRC} ${SRCB}

OBJ = $(SRC:.c=.o)

OBJB = ${SRCB:.c=.o}

OBJSALL = ${SRCSALL:.c=.o} 

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)
	
$(OBJ) :
	$(CC) $(CFLAGS) -c $(@:.o=.c) 

clean : 
	rm -f $(OBJSALL)

fclean : clean;
	rm -f $(NAME)

bonus : $(NAME) $(OBJB)
	@ar rc $(NAME) $(OBJB)

re : fclean all

.PHONY: all clean fclean bonus re