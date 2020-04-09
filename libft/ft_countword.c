/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_countword.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: conrodri <conrodri@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 15:46:37 by conrodri     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 15:54:19 by conrodri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_countword(char const *s, char c)
{
	int	i;
	int	nbword;

	i = 0;
	nbword = 0;
	while (s[i] != '\0')
	{
		if (s[i + 1] == c || s[i + 1] == '\0')
			if (s[i] != c)
				nbword++;
		i++;
	}
	return (nbword);
}
