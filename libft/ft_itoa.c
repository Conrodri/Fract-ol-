/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: conrodri <conrodri@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 15:58:05 by conrodri     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 15:40:34 by conrodri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*str;
	long		len;
	long		nb;
	long		neg;

	nb = n;
	neg = n < 0 ? 1 : 0;
	len = 1;
	while (nb /= 10)
		len++;
	if (!(str = ft_strnew(len + neg)))
		return (NULL);
	if (neg == 1)
		str[0] = '-';
	while (len--)
	{
		if (neg == 0)
			str[len + neg] = (n % 10) + 48;
		if (neg == 1)
			str[len + neg] = -(n % 10) + 48;
		n /= 10;
	}
	return (str);
}
