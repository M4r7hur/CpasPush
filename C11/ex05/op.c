/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 17:48:09 by armendes          #+#    #+#             */
/*   Updated: 2020/08/12 14:54:35 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		plus(int x, int y)
{
	int i;

	i = x + y;
	return (i);
}

int		minus(int x, int y)
{
	int i;

	i = x - y;
	return (i);
}

int		divide(int x, int y)
{
	int i;

	i = x / y;
	return (i);
}

int		times(int x, int y)
{
	int i;

	i = x * y;
	return (i);
}

int		modulo(int x, int y)
{
	int i;

	i = x % y;
	return (i);
}
