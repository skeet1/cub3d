# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/24 15:56:34 by ren-nasr          #+#    #+#              #
#    Updated: 2022/07/24 16:03:57 by ren-nasr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

BONUS_PATH = ./bonus/
MNDTR_PATH = ./mandatory/

all: $(MNDTR_PATH)
	$(MAKE) -C $(MNDTR_PATH)

bonus:
	$(MAKE) -C $(BONUS_PATH)

clean:
	$(MAKE) -C $(MNDTR_PATH) clean
	$(MAKE) -C $(BONUS_PATH) clean
	
fclean: clean
	$(MAKE) -C $(MNDTR_PATH) fclean
	$(MAKE) -C $(BONUS_PATH) fclean

re: fclean all 

.PHONY: clean fclean re bonus