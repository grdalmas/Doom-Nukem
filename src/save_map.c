/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 23:11:14 by cmartine          #+#    #+#             */
/*   Updated: 2019/02/28 06:01:53 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void			free_line(char **line_split)
{
	int i;

	i = 0;
	while (line_split[i])
	{
		free(line_split[i]);
		i++;
	}
	free(line_split);
}

static void		create_map2(t_struct *p, int i, char **l_s, int k)
{
	int j;

	j = -1;
	while (++j < 15 && l_s[j] != '\0')
	{
		p->map[k][i][j] = ft_atoi(l_s[j]);
		if ((i == 0 || i == 14)
				&& (p->map[k][i][j] < 0 || p->map[k][i][j] > TEX))
		{
			ft_putendl("error, invalid map");
			// FREE AVANT DE SORTIR !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			exit(EXIT_FAILURE);
		}
		if ((j == 0 || j == 14)
				&& (p->map[k][i][j] < 0 || p->map[k][i][j] > TEX))
		{
			ft_putendl("error, invalid map");
			// FREE AVANT DE SORTIR !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			exit(EXIT_FAILURE);
		}
	}
	if (j != 15)
	{
		ft_putendl("error, invalid map");
			// FREE AVANT DE SORTIR !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		exit(EXIT_FAILURE);
	}
}

static void		create_map(t_struct *info, int fd, int k)
{
	int		i;
	char	**line_split;
	char	*line;

	i = 0;
	while (get_next_line(fd, &line) > 0 && i < 16)
	{
		line_split = ft_strsplit(line, ' ');
		free(line);
		if (!(info->map[k][i] = (int *)malloc(sizeof(int) * 16)))
			exit(EXIT_FAILURE);
		create_map2(info, i, line_split, k);
		free_line(line_split);
		i++;
	}
	free(line);
	if (i != 15)
	{
		ft_putendl("error, invalid map");
			// FREE AVANT DE SORTIR !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		exit(EXIT_FAILURE);
	}
}

void			save_map2(t_struct *param, const char *file, int k)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (!(param->map[k] = (int **)malloc(sizeof(int *) * 16)))
		exit(EXIT_FAILURE);
	create_map(param, fd, k);
	close(fd);
}

void			save_map(t_struct *param)
{
	if (!(param->map = (int ***)malloc(sizeof(int **) * 9)))
		exit(EXIT_FAILURE);
	save_map2(param, "maps/laby.tkt", 0);
	save_map2(param, "maps/boris.tkt", 1);
	save_map2(param, "maps/celeste.tkt", 2);
	save_map2(param, "maps/greg.tkt", 4);
	save_map2(param, "maps/tim.tkt", 3);
	save_map2(param, "maps/3.tkt", 5);
	save_map2(param, "maps/1.tkt", 7);
	save_map2(param, "maps/4.tkt", 8);
	save_map2(param, "maps/5.tkt", 9);
}
