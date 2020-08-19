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
#include <stdio.h>

int			mandelbrot(t_frac *frac)
{
	frac->pr = 2.0 * (frac->x - W_WIDTH / 2) / (0.5 * frac->zoom * W_WIDTH) + frac->movex;
	frac->pi = 2.0 * (frac->y - W_HEIGHT / 2) / (0.5 * frac->zoom * W_HEIGHT) + frac->movey;
	
	frac->new_re = 0;
	frac->new_im = 0;
	frac->old_re = 0;
	frac->old_im = 0;
	frac->iterations = 0;
	while (frac->iterations < frac->max_iter)
	{
		frac->old_re = frac->new_re;
		frac->old_im = frac->new_im;
		frac->new_re = frac->old_re * frac->old_re - frac->old_im * frac->old_im + frac->pr;
		frac->new_im = 2 * frac->old_re * frac->old_im + frac->pi;
		if ((frac->new_re * frac->new_re + frac->new_im * frac->new_im) > 4)
			break ;
		frac->iterations++;
	}
	return (frac->iterations);
}

int			mandelbar(t_frac *frac)
{
	frac->pr = 2.0 * (frac->x - W_WIDTH / 2) / (0.5 * frac->zoom * W_WIDTH) + frac->movex;
	frac->pi = 2.0 * (frac->y - W_HEIGHT / 2) / (0.5 * frac->zoom * W_HEIGHT) + frac->movey;

	frac->new_re = 0;
	frac->new_im = 0;
	frac->old_re = 0;
	frac->old_im = 0;
	frac->iterations = 0;
	while (frac->iterations < frac->max_iter)
	{
		frac->old_re = frac->new_re;
		frac->old_im = frac->new_im;
		frac->new_re = frac->old_re * frac->old_re - frac->old_im * frac->old_im + frac->pr;
		frac->new_im = -2 * frac->old_re * frac->old_im + frac->pi;
		if ((frac->new_re * frac->new_re + frac->new_im * frac->new_im) > 4)
			break ;
		frac->iterations++;
	}
	return (frac->iterations);
}

void		set_color(t_frac *frac, int i)
{
	if (i == 0 || i >= frac->max_iter)
		frac->color = 0x000000;
	else if (i % 3 == 0)
		frac->color = 0x000000;
	else if (i % 4 == 0)
		frac->color = 0x0D1826;
	else if (i % 5 == 0)
		frac->color = 0x16F2B4;
	else if (i % 6 == 0)
		frac->color = 0xF2B279;
	else if (i % 7 == 0)
		frac->color = 0xF25050;
	else if (i % 8 == 0)
		frac->color = 0x027368;
	else if (i % 9 == 0)
		frac->color = 0xA7C8F2;
	else
		frac->color = 0xff0000;
}

void		draw(t_frac *frac)
{
	frac->x = 0;
	frac->y = 0;
	while (frac->y < W_HEIGHT)
	{
		while (frac->x < W_WIDTH)
		{
			if (frac->fractal == 0)
				set_color(frac, mandelbrot(frac));
			else if (frac->fractal == 1)
				set_color(frac, mandelbrot(frac));
			else
				set_color(frac, mandelbar(frac));
			frac->data[frac->y * W_WIDTH + frac->x] = frac->color;
			frac->x++;
		}
		frac->x = 0;
		frac->y++;
	}
	mlx_put_image_to_window(frac->mlx_ptr, frac->win, frac->img_ptr, 0, 0);
}

int			keypressed(int keycode, t_frac *frac)
{
	if (keycode == MAIN_PAD_ESC)
		exit(0);
	else if (keycode == ARROW_UP)
		frac->movey = frac->movey - (0.1 / frac->zoom);
	else if (keycode == ARROW_DOWN)
		frac->movey = frac->movey + (0.1 / frac->zoom);
	else if (keycode == ARROW_LEFT)
		frac->movex = frac->movex + (0.1 / frac->zoom);
	else if (keycode == ARROW_RIGHT)
		frac->movex = frac->movex - (0.1 / frac->zoom);
	else if (keycode == NUMPAD_PLUS)
		frac->zoom =  frac->zoom * 2;
	else if (keycode == NUMPAD_MINUS)
		frac->zoom =  frac->zoom / 2;
	else if (keycode == NUMPAD_ENTER)
		frac->max_iter += 10;
	draw(frac);
	return (0);
}

int			zoom(int button, int x, int y, t_frac *frac)
{
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
	{
		if (button == MOUSE_SCROLL_UP)

			frac->zoom =  frac->zoom * 1.2;
		else
			frac->zoom =  frac->zoom * 0.8;

		draw(frac);
	}
	return (0);
}

void init_fractol(char *name)
{
    t_frac frac;
    frac.mlx_ptr = mlx_init();
	if (ft_strcmp(name, "mandelbrot") == 0)
		frac.fractal = 0;
	else if (ft_strcmp(name, "julia") == 0)
		frac.fractal = 1;
	else if (ft_strcmp(name, "mandelbar") == 0)
		frac.fractal = 2;
    frac.win = mlx_new_window(frac.mlx_ptr, W_WIDTH, W_HEIGHT, name);
    frac.img_ptr = mlx_new_image(frac.mlx_ptr, W_WIDTH, W_HEIGHT);
    frac.size_l = 16;
    frac.bpp = 16;
    frac.endian = 1;
    frac.data = (int *)mlx_get_data_addr(frac.img_ptr, &frac.bpp, &frac.size_l, &frac.endian);
    frac.zoom = 0.5;
    frac.max_iter = 60;
    frac.movex = 0.1;
    frac.movey = 0.1;
    draw(&frac);
    mlx_key_hook(frac.win, keypressed, &frac);
    mlx_mouse_hook(frac.win, zoom, &frac);
    mlx_loop(frac.mlx_ptr);
}

void    show_usage(void)
{
    ft_putendl("Usage: ./fractol <fractal name>");
    ft_putendl("Available fractals:");
    ft_putendl("mandelbrot");
    ft_putendl("julia");
}

int     check_name(char *name)
{
    if (ft_strcmp(name, "mandelbrot") == 0)
        return (1);
    else if (ft_strcmp(name, "julia") == 0)
		return (1);
	else if (ft_strcmp(name, "mandelbar") == 0)
        return (1);
    else
        return (0);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl("error: insufficient input. See usage.");
		show_usage();
		exit(0);
	}
	if (check_name(argv[1]) == 0)
	{
		ft_putendl("error: insufficient input. See usage.");
		show_usage();
		exit(0);
	}
	init_fractol(argv[1]);
	return (0);
}
