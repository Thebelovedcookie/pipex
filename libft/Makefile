# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmahfoud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 09:24:12 by mmahfoud          #+#    #+#              #
#    Updated: 2023/11/16 10:14:04 by mmahfoud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a
CFLAGS			= -Werror -Wall -Wextra

SRC				= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
				ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
				ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
				ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
				ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
				ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
				ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
				ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
				ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c 

SRC_PRINTF		= ./ft_printf/ft_printf.c ./ft_printf/ft_printf_tools.c ./ft_fprintf/ft_fprintf.c ./ft_fprintf/ft_fprintf_tools.c
HEADER_PRINTF	= ./ft_printf/libft_printf.h
HEADER_FPRINTF  = ./ft_fprintf/libft_fprintf.h

OBJ				= $(SRC:.c=.o)

OBJ_PF			= $(SRC_PRINTF:.c=.o)

HEADER			= libft.h

all:			$(NAME) 

$(NAME):		$(OBJ) $(OBJ_PF) $(OBJ FPF)
					@ar rcs $(NAME) $(OBJ) $(OBJ_PF) $(OBJ_FPF)
					@ranlib $(NAME)
					@echo "done."

$(OBJ):			$(SRC) 
					@cc $(CFLAGS) -c $(HEADER) $(SRC)

$(OBJ_PF) :		$(SRC_PRINTF)
					$(MAKE) -C ./ft_printf
					$(MAKE) -C ./ft_fprintf

clean:
					@rm -f $(OBJ) $(OBJ_PF) $(OBJ_FPF)
					@echo "clean done."

fclean:			clean
					@rm -f $(NAME)

re:				fclean all
