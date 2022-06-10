/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:29:29 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/06/10 09:51:58 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine(t_filos	*filo)
{
	t_data	*data;

	data = filo->data;
	filo->last_meal = ft_gettime();
	pthread_create(&filo->death, NULL, death, filo);
	if (filo->id % 2)
		usleep(1000);
	while (!data->dieded)
	{
		ft_eats(filo);
		if ((filo->n_eat >= data->nb_eat && data->nb_eat != -1) || data->dieded)
			break ;
		ft_print(data, filo->id, "is sleeping", data->dieded);
		ft_sleep(data->time_sleep, data);
		ft_print(data, filo->id, "is thinking", data->dieded);
	}
	pthread_join(filo->death, NULL);
	exit(0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (!parsing(ac, av, &data))
		return (0);
	if (!ft_creat(&data))
		return (0);
	free(data.philos);
	return (1);
}
