/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:58:48 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/06/03 15:42:08 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	create_tread(t_data *data, t_philo *philo)
{
	int	i;
	int	nof;

	i = -1;
	nof = data->number_of_philosophers;
	data->beginning_time = get_time();
	while (++i < nof)
	{
		philo[i].check_die_time = get_time();
		if ((pthread_create(&data->philo[i].id_thread, NULL, \
		routine, (void *)(&philo[i]))))
			return (printf("%s \n", ERROR_TH), 0);
	}
	check_dieth(data, data->philo);
	end(data, data->philo);
	return (1);
}

void	ft_usleep(int time_limit, t_data *data)
{
	long long	time;

	time = get_time();
	if (!(data->die))
	{
		usleep((time_limit - (time_limit * 0.03)) * 1000);
		while ((get_time() - time) < time_limit)
			usleep(500);
	}
}

void	end(t_data *data, t_philo *philo)
{
	int	index;

	index = 0;
	while (index < data->number_of_philosophers)
		pthread_join(philo[index++].id_thread, NULL);
	index = 0;
	while (index < data->number_of_philosophers)
		pthread_mutex_destroy(&(data->forks[index++]));
	pthread_mutex_destroy(&(data->eating));
	pthread_mutex_destroy(&(data->print));
	free(data->philo);
	free(data->forks);
}
