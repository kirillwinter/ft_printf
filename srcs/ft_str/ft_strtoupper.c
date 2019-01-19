/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 20:14:25 by jwillem-          #+#    #+#             */
/*   Updated: 2019/01/17 20:14:31 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_toupper(char *str)
{
	char	*res;
	char	*start_res;
	
	res = ft_strnew(ft_strlen(str));
	start_res = res;
	while (*str)
	{
		if (*str >= 97 && *str <= 122)
			*res++ = *str++ - 32;
		else
			*res++ = *str++;
	}
	return (start_res);
}
