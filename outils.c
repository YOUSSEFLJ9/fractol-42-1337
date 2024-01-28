/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   umy: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:50:35 by ymomen            #+#    #+#             */
/*   Updated: 2024/01/28 02:39:43 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_and_exit(char *s, int exite)
{
	if (exite == -9)
	{
		write(2, s, ft_strlen(s));
		exit(1);
	}
	perror(s);
	if (exite != 0)
		exit(exite);
}

int	end_fracts(t_facral *fract)
{
	mlx_destroy_image(fract->mlx_ptr,fract->img.img);
	mlx_destroy_window(fract->mlx_ptr, fract->mlx_win);
	exit(0);
}

void	init_complix(t_facral *fract, int x, int y)
{
	if (fract->is_julia)
	{
		fract->c.r = ft_atof(fract->av[2]);
		fract->c.i = ft_atof(fract->av[3]);
		fract->z.r = (scale(0, WIDTH , -2, 2 , x)) * fract->zoom + fract->shift_x;
		fract->z.i = (scale(0, HEIGHT, 2, -2, y)) * fract->zoom + fract->shift_y;
	}
	else
	{
	fract->z.i = 0;
	fract->z.r = 0; 
	fract->c.r = (scale(0, WIDTH , -2, 2, x)) * fract->zoom + fract->shift_x;
	fract->c.i = (scale(0, HEIGHT, 2, -2, y)) * fract->zoom + fract->shift_y;
	}
}

double ft_atof(char *str)
{
	double		num;
	double		fraction;
	double		p;
	int			sign;
	
	sign = 1;
	num = 0;
	p = 1;
	fraction =0.0;
	if (!str || !*str)
		error_and_exit("USAGE:\n./fractol Mandelbrot.\n./fractol Julia x y.\n", -9);
	while (*str == ' ')
		 str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -sign;
	while(*str != '.' && *str)
		num = (num * 10) + (*str++ - 48);
	if (*str == '.')
		str++;
	while(*str)
	{
		p /= 10;
		fraction = fraction  + (*str++ - 48) * p;
	}
	return ((num + fraction) * sign);
}
