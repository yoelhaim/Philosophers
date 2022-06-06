/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:16:18 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/06/06 11:53:54 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_data	data;

	if (ac != 5 && ac != 6)
		return (printf("%s", ERROR_AC), 0);
	if (!(check_parse(av)))
		exit(1);
	if (!(init_philo(av, ac, &data)))
		exit(1);
	if (!(create_tread(&data, (&data)->philo)))
		exit(1);
}
