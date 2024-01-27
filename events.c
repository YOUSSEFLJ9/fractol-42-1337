/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 02:43:56 by ymomen            #+#    #+#             */
/*   Updated: 2024/01/27 09:44:36 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int keybord_press(int keycode, t_facral *fract)
{
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
		fract->etration += 10;
	else if (keycode == 78)
		fract->etration -= 10;
	else if (keycode == 49)
	{
		fract->color.b += 11;
		fract->color.g += 31;
		fract->color.r += 21;
	}
	printf("%f----->%f______code:%d\n",fract->shift_x,fract->shift_y ,keycode);
	math(fract);
	return (0);
}
int mouse_press(int button, int x, int y,t_facral *fract)
{
	(void)x;
	(void)y;
	if (button == 5)
		fract->zoom *= 0.8;
	else if (button == 4)
		fract->zoom *= 1.3;
	math(fract);
	return (0);
}
// int press_x_windo(t_facral *fract)
// {
	
// 	printf("worked exit: %d\n", 55);
// }

void events(t_facral *fract)
{
	mlx_hook(fract->mlx_win, 02, (1L<<0), keybord_press, fract);
	mlx_hook(fract->mlx_win, 04, (1L<<2), mouse_press, fract);
	mlx_hook(fract->mlx_win, 17, (1L<<19), end_fracts, fract);
	// mlx_hook(fract->mlx_win, 02, (1L<<0), keybord_press, fract);
}