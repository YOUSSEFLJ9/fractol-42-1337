/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:38:35 by ymomen            #+#    #+#             */
/*   Updated: 2024/01/27 09:49:49 by ymomen           ###   ########.fr       */
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
	return ((new_max - new_min) * (x - old_min) / (old_max - old_min) + new_min);
}

int	create_trgb(int iter,t_color *a)
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
	t_number	z;
	t_number	c;
	int			i;
	double		tmp;
	int			color;

	i = -1;
	z.i = 0;
	z.r = 0; 
	c.r = (scale(0, WIDTH , -2, 2 , x)) * fract->zoom + fract->shift_x;
	c.i = (scale(0, HEIGHT, 2, -2, y)) * fract->zoom + fract->shift_y;
	while (fract->etration > ++i)
	{
		tmp = (z.r * z.r) - (z.i * z.i);
		z.i = 2 * z.i * z.r;
		z.r = tmp;
		z.r += c.r;
		z.i += c.i;
		if ((z.r * z.r) + (z.i * z.i) > fract->range)
		{
			color = create_trgb(i, &fract->color);	
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
			set_pixel(fract, x ,y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->mlx_ptr, fract->mlx_win, fract->img.img, 0, 0);
}