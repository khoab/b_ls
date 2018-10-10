/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 21:09:35 by kbui              #+#    #+#             */
/*   Updated: 2018/09/29 13:45:52 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*cpy_dst;
	char	*cpy_src;

	cpy_dst = (char *)dst;
	cpy_src = (char *)src;
	while (n--)
		*(cpy_dst++) = *(cpy_src);
	return (dst);
}
