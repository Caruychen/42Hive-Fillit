# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    deploy_vogsphere.sh                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 16:12:17 by cchen             #+#    #+#              #
#    Updated: 2022/01/14 16:15:03 by cchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VOGSPHERE=$(ls | sed -n '/intra-uuid/p')

rm -rf ./${VOGSPHERE}/*
cp ./$REPO_NAME/author ./${VOGSPHERE}
cp ./$REPO_NAME/Makefile ./${VOGSPHERE}
cp -r ./$REPO_NAME/src ./${VOGSPHERE}
cp -r ./$REPO_NAME/libft ./${VOGSPHERE}
