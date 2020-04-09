/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: conrodri <conrodri@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 16:48:07 by conrodri     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/20 17:40:44 by conrodri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!(dest = ft_strnew(len)))
		return (NULL);
	if (s != NULL)
	{
		while (i < len)
		{
			dest[i] = (char)s[start];
			i++;
			start++;
		}
	}
	dest[i] = '\0';
	return (dest);
}
