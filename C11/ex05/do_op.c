/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 17:13:06 by armendes          #+#    #+#             */
/*   Updated: 2020/08/11 17:59:13 by armendes         ###   ########.fr       */
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

int	ft_atoi(char *str)
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

void	do_op(int x1, int x2, char op, int (*f[])(int x, int y))
{
	int tmp;

	if (op == '+')
		tmp = f[0](x1, x2);
	if (op == '-')
		tmp = f[1](x1, x2);
	if (op == '/')
		tmp = f[2](x1, x2);
	if (op == '*')
		tmp = f[3](x1, x2);
	if (op == '%')
		tmp = f[4](x1, x2);
	ft_putnbr(tmp);
}

int		main(int argc, char **argv)
{
	int	(*operateur[5])(int x, int y);

	operateur[0] = &plus;
	operateur[1] = &minus;
	operateur[2] = &divide;
	operateur[3] = &times;
	operateur[4] = &modulo;
	if (argc == 4)
	{
		if (argv[2] == "+" || argv[2] == '-' || argv[2] == '/' ||
				argv[2] == '*' || argv[2] == '%')
		{
			if (argv[3] == 0 && argv[2] == '/')
				ft_putstr("Stop : division by zero");
			if (argv[3] == 0 && argv[2] == '%')
				ft_putstr("Stop : modulo by zero");
			else
				do_op(ft_atoi(argv[1]), ft_atoi(argv[3]), *argv[2], &operateur[5]);
		}
		ft_putchar('0');
	}
	return (0);
}
