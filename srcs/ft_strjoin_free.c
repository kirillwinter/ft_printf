/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:58:13 by wballaba          #+#    #+#             */
/*   Updated: 2019/01/16 17:58:14 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** данная функция чистит
** первую строку при operation == 1
** вторую строку при operation == 2
** обе строки при operation == 3
*/

char	*ft_strjoin_free(char *s1, char *s2, int operation)
{
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(str = (char *)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	str = ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	if (operation == 1)
		free(s1);
	else if (operation == 2)
		free(s2);
	else if (operation == 3)
	{
		free(s1);
		free(s2);
	}
	return (str);
}
