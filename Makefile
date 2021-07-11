SRCS	=	main.c							\
			utils/ft_exit.c					\
			utils/ft_malloc.c				\
			utils/ft_memcpy.c				\
			utils/ft_strdup.c				\
			utils/ft_strlen.c				\
			utils/ft_itoa.c					\
			srcs/map_parse.c				\
			srcs/finish.c					\
			srcs/map_parse_return.c			\
			srcs/parsings.c					\
			srcs/so_long.c					\
			srcs/utils.c					\
			gnl/get_next_line_utils.c		\
			gnl/get_next_line.c				\
			engine/draw.c					\
			engine/keys.c					\
			engine/render.c					\
			engine/engine.c					\
			engine/free.c					\

BONUS	=	main_bonus.c					\
			utils/ft_exit.c					\
			utils/ft_malloc.c				\
			utils/ft_memcpy.c				\
			utils/ft_strdup.c				\
			utils/ft_strlen.c				\
			utils/ft_itoa.c					\
			srcs/map_parse.c				\
			srcs/finish.c					\
			srcs/map_parse_return_bonus.c	\
			srcs/parsings_bonus.c			\
			srcs/so_long_bonus.c			\
			srcs/utils.c					\
			srcs/patrols_bonus.c			\
			srcs/mob_bonus.c				\
			gnl/get_next_line_utils.c		\
			gnl/get_next_line.c				\
			engine/draw.c					\
			engine/keys_bonus.c				\
			engine/render.c					\
			engine/engine.c					\
			engine/free.c					\

CC		=	clang

FLAG	=	-Wall -Wextra -Werror -I./includes/

NAME	=	so_long

OBJS	=	${SRCS:.c=.o}

BNSOBJ	=	${BONUS:.c=.o}

.c.o:
				$(CC) $(FLAG) -c $< -o $(<:.c=.o)

MAP		=	map/test.ber

MAPBNS	=	map/bonus.ber

VALF	=	--tool=memcheck --leak-check=full --leak-resolution=high --show-reachable=yes --track-origins=yes --log-file=valgrind_log

#LNAME	=	libft.a

#LPATH	=	./libft

MNAME	=	libmlx_Linux.a

MPATH	=	./minilibx-linux

all: ${MNAME} ${NAME} 

${NAME}	:	${MNAME} ${OBJS}
				${CC} ${FLAG} ${OBJS} -o ${NAME} ${MNAME} -lX11 -lXext

${MNAME} :
			rm -f ${MNAME}
			make -C ${MPATH} all
			cp ${MPATH}/${MNAME} .

#${LNAME}:
#				rm -f ${LNAME}
#				make -C ${LPATH} all
#				cp ${LPATH}/${LNAME} .

clean	:
				rm -f ${OBJS}
				rm -f ${BNSOBJ}
				rm -f ${MNAME}
				rm -f valgrind_log

fclean	:	clean
				rm -f ${NAME}
				make -C ${MPATH} clean

bonus	:	${MNAME} ${BNSOBJ}
				${CC} ${FLAG} ${BNSOBJ} -o ${NAME} ${MNAME} -lX11 -lXext


no_flag	:	
			${CC} -lbsd -lm -lX11 -lXext ${SRCS} -o ${NAME} MNAME

re		:	fclean all

test	:	all
				./${NAME} ${MAP}

leaks	:
				valgrind ${VALF} ./${NAME} ${MAP}
				grep -A1 "valgrind" valgrind_log | grep ${NAME} || echo -n

leaks_bonus	:
				valgrind ${VALF} ./${NAME} ${MAPBNS}
				grep -A1 "valgrind" valgrind_log | grep ${NAME} || echo -n

Phony: all clean fclean test re leaks
