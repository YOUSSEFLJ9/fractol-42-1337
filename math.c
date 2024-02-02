/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:38:35 by ymomen            #+#    #+#             */
/*   Updated: 2024/02/03 00:07:36 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_put_pixel(int x, int y, t_mg *img, int color)
{
	int	addrn;

	addrn = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->addr + addrn) = color;
}

double	scale(double omax, double nmin, double nmax, double x)
{
	return (((nmax - nmin) * (x - 0) / (omax - 0)) + nmin);
}

int	create_colors(int iter, t_color *a)
{
	int	r;
	int	g;
	int	b;

	r = (iter * a->r) % 256;
	g = (iter * a->g) % 256;
	b = (iter * a->b) % 256;
	return (r << 16 | g << 8 | b);
}

void	set_pixel(t_fractol *frc, int x, int y)
{
	int			i;
	int			color;

	i = -1;
	while (frc->etration > ++i)
	{
		app_formula(frc);
		if ((frc->z.r * frc->z.r) + (frc->z.i * frc->z.i) > frc->range)
		{
			color = create_colors(i, &frc->color);
			my_put_pixel(x, y, &frc->img, color);
			return ;
		}
	}
	my_put_pixel(x, y, &frc->img, 0x0000000);
}

void	math(t_fractol *frc)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			init_complix(frc, x, y);
			set_pixel(frc, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(frc->mlx_ptr, frc->mlx_win,
		frc->img.img, 0, 0);
}
