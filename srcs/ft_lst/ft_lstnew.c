/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:07:42 by jwillem-          #+#    #+#             */
/*   Updated: 2018/12/05 19:07:43 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newl;

	if (!(newl = (t_list *)malloc(sizeof(*newl))))
		return (NULL);
	if (content == NULL)
	{
		newl->content = NULL;
		newl->content_size = 0;
	}
	else
	{
		if (!(newl->content = malloc(sizeof(*newl) * content_size)))
		{
			free(newl);
			return (NULL);
		}
		ft_memcpy(newl->content, content, content_size);
		newl->content_size = content_size;
	}
	newl->next = NULL;
	return (newl);
}
