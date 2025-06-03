/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:10:00 by sperron           #+#    #+#             */
/*   Updated: 2025/06/03 14:24:50 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "primesh.h"
#include "utils.h"

static int	ft_is_negative(int *n)
{
	if (*n < 0)
	{
		*n = -(*n);
		return (1);
	}
	return (0);
}

static int	ft_int_to_str(int n, char *tmpbuf)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		tmpbuf[i++] = '0';
	}
	else
	{
		while (n > 0)
		{
			tmpbuf[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	return (i);
}

static void	ft_reverse_to_buf(const char *src, int len, char *dst)
{
	while (len--)
		*dst++ = src[len];
}

void	ft_itoa_buf(int n, char *buf)
{
	char	tmpbuf[12];
	int		neg;
	int		len;

	neg = ft_is_negative(&n);
	len = ft_int_to_str(n, tmpbuf);
	if (neg)
		*buf++ = '-';
	ft_reverse_to_buf(tmpbuf, len, buf);
	buf[len] = '\0';
}

const char	*get_status_color(void)
{
	if (g_signal_status == 0)
		return ("\e[38;5;82m");
	return ("\e[38;5;196m");
}
