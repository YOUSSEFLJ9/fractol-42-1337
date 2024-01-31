/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lj9 <lj9@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:38:35 by ymomen            #+#    #+#             */
/*   Updated: 2024/01/31 22:13:18 by lj9              ###   ########.fr       */
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

void	set_pixel(t_facral *fract, int x, int y)
{
	int			i;
	double		tmp;
	int			color;

	i = -1;
	while (fract->etration > ++i)
	{
		tmp = (fract->z.r * fract->z.r) - (fract->z.i * fract->z.i);
		fract->z.i = 2 * fract->z.i * fract->z.r;
		fract->z.r = tmp;
		fract->z.r += fract->c.r;
		fract->z.i += fract->c.i;
		if ((fract->z.r * fract->z.r) + (fract->z.i * fract->z.i)
			> fract->range)
		{
			color = create_colors(i, &fract->color);
			my_put_pixel(x, y, &fract->img, color);
			return ;
		}
	}
	my_put_pixel(x, y, &fract->img, 0x0000000);
}

void	math(t_facral *fract)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			init_complix(fract, x, y);
			set_pixel(fract, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->mlx_ptr, fract->mlx_win,
		fract->img.img, 0, 0);
}
