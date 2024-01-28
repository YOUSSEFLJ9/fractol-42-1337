/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:38:35 by ymomen            #+#    #+#             */
/*   Updated: 2024/01/28 01:17:30 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_put_pixel(int x, int y, t_img *img, int color)
{
	int	addrn;

	addrn = (y * img->line_length) + (x * ( img->bits_per_pixel / 8));
	*(unsigned int *)(img->addr + addrn) = color;
}

double scale(double old_min, double old_max, double new_min, double new_max, double x)
{
	return (((new_max - new_min) * (x - old_min) /(old_max - old_min)) + new_min);
}

int	create_colors(int iter,t_color *a)
{
	int	 r;
	int	 g;
	int	 b;

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
		if ((fract->z.r * fract->z.r) + (fract->z.i * fract->z.i) > fract->range)
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
	while(y < HEIGHT)
	{
		x = 0;
		while(x < WIDTH)
		{
			init_complix(fract, x, y);
			set_pixel(fract, x ,y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->mlx_ptr, fract->mlx_win, fract->img.img, 0, 0);
}