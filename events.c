/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 02:43:56 by ymomen            #+#    #+#             */
/*   Updated: 2024/02/02 23:32:04 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keybord_press(int keycode, t_fractol *fract)
{
	if (keycode == 76 || keycode == 36)
		init_values(fract);
	if (keycode == 53)
		end_fracts(fract);
	else if (keycode == 124)
		fract->shift_x += (0.5 * fract->zoom);
	else if (keycode == 123)
		fract->shift_x -= (0.5 * fract->zoom);
	else if (keycode == 126)
		fract->shift_y += (0.5 * fract->zoom);
	else if (keycode == 125)
		fract->shift_y -= (0.5 * fract->zoom);
	else if (keycode == 69)
		fract->etration += 5;
	else if (keycode == 78)
		fract->etration -= 5;
	else if (keycode == 49)
	{
		fract->color.b += 11;
		fract->color.g += 31;
		fract->color.r += 21;
	}
	math(fract);
	return (0);
}

int	mouse_press(int button, int x, int y, t_fractol *fract)
{
	double	mousex;
	double	mousey;
	double	zoom;

	if (button == 5 || button == 4)
	{
		mousex = fract->str.r + ((double)x / WIDTH)
			* (fract->end.r - fract->str.r);
		mousey = fract->str.i + ((double)y / HEIGHT)
			* (fract->end.i - fract->str.i);
		if (button == 5)
			zoom = 0.8;
		else
			zoom = 1.2;
		fract->zoom *= zoom;
		fract->str.r = mousex + zoom * (fract->str.r - mousex);
		fract->end.r = mousex + zoom * (fract->end.r - mousex);
		fract->str.i = mousey + zoom * (fract->str.i - mousey);
		fract->end.i = mousey + zoom * (fract->end.i - mousey);
		math(fract);
	}
	return (0);
}

int	end_fracts(t_fractol *fract)
{
	mlx_destroy_image(fract->mlx_ptr, fract->img.img);
	mlx_destroy_window(fract->mlx_ptr, fract->mlx_win);
	exit(0);
}

void	events(t_fractol *fract)
{
	mlx_hook(fract->mlx_win, 02, (1L << 0), keybord_press, fract);
	mlx_hook(fract->mlx_win, 04, (1L << 2), mouse_press, fract);
	mlx_hook(fract->mlx_win, 17, (1L << 17), end_fracts, fract);
}
