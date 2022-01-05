/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:06:12 by lduboulo          #+#    #+#             */
/*   Updated: 2022/01/05 15:12:55 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_txt_map	txt;
	t_file		file;
	t_map		map;

	file.name = argv[1];
	file.argc = argc;
	///////////////////////
	arg_check(file);
	file_desc_opening(&file);
	////////////////////////
	txt.line = ft_calloc(1, sizeof(char));
	nl_counter(&txt, file);
	/////////////////////////
	txt.array = ft_calloc((txt.nbline + 1), sizeof(int *));
	file_desc_closing(&file);
	file_desc_opening(&file);
	array_filling(&txt, file);	
	//////////////////////////
	file_digit_check(&txt);
	txt.x = 0;
	while (txt.x < (txt.nbline - 1))
	{
		map.splited = ft_split(txt.array[txt.x], ' ');
		map.x = 0;
		while (map.splited[map.x])
		{

		}
	}
	return (1);
}
