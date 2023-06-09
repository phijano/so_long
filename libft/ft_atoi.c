/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:22:04 by phijano-          #+#    #+#             */
/*   Updated: 2022/04/29 11:20:56 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	unsigned long	num;
	unsigned int	count;
	int				sign;

	sign = 1;
	count = 0;
	num = 0;
	while (str[count] == ' ' || str[count] == '\t' || str[count] == '\f'
		|| str[count] == '\r' || str[count] == '\n' || str[count] == '\v')
		count++;
	if (str[count] == '+' || str[count] == '-')
		if (str[count++] == '-')
			sign = -1;
	while (str[count] >= '0' && str[count] <= '9')
	{
		num = num * 10 + (str[count] - '0');
		count++;
	}
	if (sign > 0)
		if (num > 2147483647)
			return (-1);
	if (sign < 0)
		if (num > 2147483648)
			return (0);
	return ((int)(num * sign));
}
