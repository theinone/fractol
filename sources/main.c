/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theinone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:53:43 by theinone          #+#    #+#             */
/*   Updated: 2020/02/20 15:44:30 by theinone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int mandelbrot(t_frac *frac)
{
	double	pr;
	double	pi;
	int		i;
	double	newRe;
	double	newIm;
	double	oldRe;
	double	oldIm;
	pr = 1.5 * (frac->x - W_WIDTH / 2) / (0.5 * frac->zoom * W_WIDTH) + frac->movex;
	pi = (frac->y - W_HEIGHT / 2) / (0.5 * frac->zoom * W_HEIGHT) + frac->movey;
	newRe = newIm = oldRe = oldIm = 0;

	i = 0;
	while (i < frac->max_iter)
    {
		oldRe = newRe;
		oldIm = newIm;
		newRe = oldRe * oldRe - oldIm * oldIm + pr;
		newIm = 2 * oldRe * oldIm + pi;
		if((newRe * newRe + newIm * newIm) > 4) 
			break;
		i++;
    }
	return (i);
}

void set_color(t_frac *frac, int i)
{
	if (i == 0 )
		frac->color = 0x000000;
	else if(i % 3 == 0)
		frac->color = 0x000000;
	else if(i % 4 == 0)
		frac->color = 0x0D1826;
	else if(i % 5 == 0)
		frac->color = 0x16F2B4;
	else if(i % 6 == 0)
		frac->color = 0xF2B279;
	else if(i % 7 == 0)
		frac->color = 0xF25050;
	else if(i % 8 == 0)
		frac->color = 0x027368;
	else if(i % 9 == 0)
		frac->color = 0xA7C8F2;
	else 
		frac->color = 0xff0000;
}

void draw(t_frac *frac)
{
	frac->x = 0;
	frac->y = 0;
	while ( frac->y < W_HEIGHT)
	{
		while (frac->x < W_WIDTH)
		{
			set_color(frac, mandelbrot(frac));
			frac->data[frac->y * W_WIDTH + frac->x] = frac->color;
			frac->x++;
		}
		frac->x = 0;
		frac->y++;
	}
	mlx_put_image_to_window(frac->mlx_ptr, frac->win, frac->img_ptr, 0, 0);
}

int		keypressed(int keycode, t_frac *frac)
{
	if (keycode == MAIN_PAD_ESC)
		exit(0);
	if (keycode == 27)
		{
			frac->zoom = frac->zoom * 2;
			draw(frac);
		}
	return (0);
}

int		zoom(int button, int x, int y, t_frac *frac)
{
	ft_putendl(" ");
	ft_putstr("x: ");
	ft_putnbr(x);
	ft_putstr(" y: ");
	ft_putnbr(y);
	frac->movex = x / W_WIDTH * frac->zoom;
	frac->movey = y / W_HEIGHT * frac->zoom;

	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
	{

		if (button == MOUSE_SCROLL_UP)
		{
			frac->zoom = frac->zoom * 2;
			frac->max_iter++;
		}
		else
		{
			frac->zoom = frac->zoom / 2;
			frac->max_iter--;
		}
		draw(frac);
	}
	return (0);
}

void init_fractol(void) {
	t_frac frac;

	frac.mlx_ptr = mlx_init();
	frac.win = mlx_new_window(frac.mlx_ptr, W_WIDTH, W_HEIGHT, "Fractol");
	frac.img_ptr = mlx_new_image(frac.mlx_ptr, W_WIDTH, W_HEIGHT);
	frac.size_l = 16;
	frac.bpp = 16;
	frac.endian = 1;
	frac.data = (int *)mlx_get_data_addr(frac.img_ptr, &frac.bpp, &frac.size_l, &frac.endian);
	frac.zoom = 0.8;
	frac.max_iter = 40;
	frac.movex = 0;
	frac.movey = 0;
	draw(&frac);
	mlx_key_hook(frac.win, keypressed, &frac);
	mlx_mouse_hook(frac.win, zoom, &frac);
	mlx_loop(frac.mlx_ptr);
}

int main(void)
{
	init_fractol();
	return (0);
}
