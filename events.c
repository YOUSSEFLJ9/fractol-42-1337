/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lj9 <lj9@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 02:43:56 by ymomen            #+#    #+#             */
/*   Updated: 2024/01/31 00:57:12 by lj9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keybord_press(int keycode, t_facral *fract)
{
	if (keycode == 65307)
		end_fracts(fract);
	else if (keycode == 65363)
		fract->shift_x += (0.5 * fract->zoom);
	else if (keycode == 65361)
		fract->shift_x -= (0.5 * fract->zoom);
	else if (keycode == 65362)
		fract->shift_y += (0.5 * fract->zoom);
	else if (keycode == 65364)
		fract->shift_y -= (0.5 * fract->zoom);
	else if (keycode == 65365)
		fract->etration += 5;
	else if (keycode == 65366)
		fract->etration -= 5;
	else if (keycode == 32)
	{
		fract->color.b += 11;
		fract->color.g += 31;
		fract->color.r += 21;
	}
	math(fract);
	return (0);
}

int	mouse_press(int button, int x, int y, t_facral *fract)
{
	double	mousex;
	double	mousey;
	double	zoom;

	if (button == 5 || button == 4 || button == 3 || button == 1)
	{
		mousex = fract->str.r + ((double)x / WIDTH)
			* (fract->end.r - fract->str.r);
		mousey = fract->str.i + ((double)y / HEIGHT)
			* (fract->end.i - fract->str.i);
		if (button == 1 || button == 5)
			zoom = 0.8;
		else
			zoom = 1.3;
		fract->zoom *= zoom;
		fract->str.r = mousex + zoom * (fract->str.r - mousex);
		fract->end.r = mousex + zoom * (fract->end.r - mousex);
		fract->str.i = mousey + zoom * (fract->str.i - mousey);
		fract->end.i = mousey + zoom * (fract->end.i - mousey);
		math(fract);
	}
	return (0);
}

void	events(t_facral *fract)
{
	mlx_hook(fract->mlx_win, 02, (1L << 0), keybord_press, fract);
	mlx_hook(fract->mlx_win, 04, (1L << 2), mouse_press, fract);
	mlx_hook(fract->mlx_win, 17, (1L << 17), end_fracts, fract);
}
