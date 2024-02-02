/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:50:35 by ymomen            #+#    #+#             */
/*   Updated: 2024/02/03 00:07:09 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_and_exit(char *s, int exite)
{
	if (exite == -9)
	{
		if (write(2, s, ft_strlen(s)))
			exit(-1);
		exit(1);
	}
	perror(s);
	if (exite != 0)
		exit(exite);
}

void	init_complix(t_fractol *fract, int x, int y)
{
	if (fract->is_julia == 1)
	{
		fract->c.r = ft_atof(fract->av[2]);
		fract->c.i = ft_atof(fract->av[3]);
		fract->z.r = (scale(WIDTH, fract->str.r, fract->end.r, x))
			+ fract->shift_x;
		fract->z.i = (scale(HEIGHT, fract->str.i, fract->end.i, y))
			+ fract->shift_y;
	}
	else
	{
		fract->z.i = 0;
		fract->z.r = 0;
		fract->c.r = (scale(WIDTH, fract->str.r, fract->end.r, x))
			+ fract->shift_x;
		fract->c.i = (scale(HEIGHT, fract->str.i, fract->end.i, y))
			+ fract->shift_y;
	}
}

void	app_formula(t_fractol *frc)
{
	double	tmp;

	if (frc->is_julia == 2)
	{
		tmp = frc->z.r * frc->z.r - frc->z.i * frc->z.i + frc->c.r;
		frc->z.i = -2 * frc->z.r * frc->z.i + frc->c.i;
		frc->z.r = tmp;
	}
	else
	{
		tmp = (frc->z.r * frc->z.r) - (frc->z.i * frc->z.i);
		frc->z.i = 2 * frc->z.i * frc->z.r;
		frc->z.r = tmp;
		frc->z.r += frc->c.r;
		frc->z.i += frc->c.i;
	}
}

double	ft_atof(char *str)
{
	double		num;
	double		p;
	int			sign;

	sign = 1;
	num = 0;
	p = 1;
	if (!str || !*str)
		error_and_exit(
			"USAGE:\n./fractol Mandelbrot.\n./fractol Julia x y.\n", -9);
	while (*str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -sign;
	while (*str != '.' && *str)
		num = (num * 10) + (*str++ - 48);
	if (*str == '.')
		str++;
	while (*str)
	{
		p /= 10;
		num += (*str++ - 48) * p;
	}
	return (num * sign);
}
