/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:06:12 by lduboulo          #+#    #+#             */
/*   Updated: 2022/01/04 19:23:31 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	map;
	t_file	file;

	file.name = argv[1];
	file.argc = argc;
	///////////////////////
	arg_check(file);
	file_desc_opening(&file);
	////////////////////////
	map.line = ft_calloc(1, sizeof(char));
	nl_counter(&map, file);
	/////////////////////////
	map.array = ft_calloc((map.nbline + 1), sizeof(int *));
	file_desc_closing(&file);
	file_desc_opening(&file);
	array_filling(&map, file);	
	//////////////////////////
	file_digit_check(&map);
	return (1);
}
