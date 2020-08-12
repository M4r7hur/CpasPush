/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 17:13:06 by armendes          #+#    #+#             */
/*   Updated: 2020/08/12 16:53:04 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		plus(int x, int y);
int		minus(int x, int y);
int		divide(int x, int y);
int		times(int x, int y);
int		modulo(int x, int y);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_strcmp(char *s1, char *s2);

int		ft_atoi(char *str)
{
	int i;
	int sign;
	int nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] && (str[i] == 32 || str[i] == '\f' || str[i] == '\n'
				|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v'))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * sign);
}

void	do_op(int x1, int x2, char op)
{
	int tmp;

	tmp = 12;
	if (op == '+')
		tmp = plus(x1, x2);
	else if (op == '-')
		tmp = minus(x1, x2);
	else if (op == '/')
		tmp = divide(x1, x2);
	else if (op == '*')
		tmp = times(x1, x2);
	else if (op == '%')
		tmp = modulo(x1, x2);
	ft_putnbr(tmp);
}

int		main(int argc, char **argv)
{
	if (argc == 4)
	{
		if (ft_strcmp(argv[2], "+") == 0 || ft_strcmp(argv[2], "-") == 0 ||
				ft_strcmp(argv[2], "/") == 0 || ft_strcmp(argv[2], "*") == 0 ||
				ft_strcmp(argv[2], "%") == 0)
		{
			if (ft_strcmp(argv[3], "0") == 0 && ft_strcmp(argv[2], "/") == 0)
				ft_putstr("Stop : division by zero");
			else if (ft_strcmp(argv[3], "0") == 0 &&
					ft_strcmp(argv[2], "%") == 0)
				ft_putstr("Stop : modulo by zero");
			else
			{
				do_op(ft_atoi(argv[1]), ft_atoi(argv[3]), argv[2][0]);
				return (0);
			}
		}
		else
			ft_putchar('0');
	}
	return (0);
}
