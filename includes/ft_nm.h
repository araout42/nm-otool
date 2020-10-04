/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 04:32:17 by araout            #+#    #+#             */
/*   Updated: 2020/10/04 05:51:37 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#ifndef __FT_NM_H__
# define MALLOC_ERR 1

# define FLAG_P 1
# define FLAG_Q 2
# define FLAG_R 4
# define FLAG_S 8

typedef struct s_nm
{
	char **files;
	int file_count;
	int flag;
} t_nm;

t_nm g_nm;

//int			get_args(int ac,char ** av);

#endif
