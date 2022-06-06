/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:50:00 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/06/06 11:50:10 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_struct_philo(t_data *data)
{
	int	i;
	int	nof;

	i = 0;
	nof = data->number_of_philosophers;
	data->philo = malloc(sizeof(t_data) * nof);
	if (!data->philo)
		return (1);
	while (i < data->number_of_philosophers)
	{
		data->philo[i].id = i;
		data->philo[i].left_chopstick = i;
		data->philo[i].right_chopstick = (i + 1) % nof;
		data->philo[i].check_die_time = 0;
		data->philo[i].eat = 0;
		data->philo[i].data = data;
		i++;
	}
	return (0);
}

int	ft_init_mutex(t_data *data)
{
	int	index;
	int	nof;

	index = 0;
	nof = data->number_of_philosophers;
	if (pthread_mutex_init(&(data->eating), NULL))
		return (1);
	if (pthread_mutex_init(&(data->print), NULL))
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * nof);
	if (!(data->forks))
		return (1);
	while (index < nof)
	{
		if (pthread_mutex_init(&(data->forks[index]), NULL))
			return (1);
		index++;
	}
	return (0);
}

int	init_philo(char **av, int ac, t_data *data)
{
	data->number_of_philosophers = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->beginning_time = 0;
	data->die = 0;
	data->check_eat = 0;
	data->time_each_philo_must_eat = 0;
	if (ac == 6)
		data->time_each_philo_must_eat = ft_atoi(av[5]);
	if (ft_init_mutex(data) || ft_init_struct_philo(data))
		return (printf("ERROR : Initialization has failed !\n"), 1);
	return (1);
}
