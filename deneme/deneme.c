#include "/cub3d.h"

int color_image(t_data *data, int x, int y)
{
	char *dst;

	dst = data->wizard_addr + (y * data->wizard_line_length + x * (data->wizard_bits_per_pixel / 8));
	data->color = *(unsigned int*)dst;
	return data->color;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_exit(void *temp)
{
	exit(1);
}

int main()
{
	t_data data;

	int a;
	int b;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1024, 1024, "lol");


	data.img = mlx_new_image(data.mlx, 1024, 1024);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

	data.wizard = mlx_xpm_file_to_image(data.mlx, WZ, &a, &b);
	data.wizard_addr = mlx_get_data_addr(data.wizard, &data.wizard_bits_per_pixel, &data.wizard_line_length, &data.wizard_endian);

	color_image(&data, 61, 63);

	int x = 0;
	int y = 0;
	while (y < 1024)
	{
		if (y < 524)
		{
			while (x < 1024)
			{
			my_mlx_pixel_put(&data, x, y, data.color);
			x++;
			}
		}
		else
		{
			while (x < 1024)
			{
				my_mlx_pixel_put(&data, x, y, 0x00000990);
				x++;
			}
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_key_hook(data.win, ft_exit, NULL);
	mlx_loop(data.mlx);
}