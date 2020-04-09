/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: conrodri <conrodri@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/12 21:07:30 by conrodri     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 17:59:14 by conrodri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!(dest = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	while (i < size)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
