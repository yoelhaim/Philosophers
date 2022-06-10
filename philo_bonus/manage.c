/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 09:45:30 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/06/10 09:57:24 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eats(t_filos *filo)
{
	t_data	*data;

	data = filo->data;
	sem_wait(data->fork);
	ft_print(data, filo->id, "has taken a fork", data->dieded);
	sem_wait(data->fork);
	ft_print(data, filo->id, "has taken a fork", data->dieded);
	ft_print(data, filo->id, "is eating", data->dieded);
	ft_sleep(data->time_eat, data);
	filo->last_meal = ft_gettime();
	if (data->dieded)
		return ;
	filo->n_eat++;
	sem_post(data->fork);
	sem_post(data->fork);
}

void	*death(void *philo)
{
	int		i;
	t_filos	*data;

	data = (t_filos *)philo;
	while (1)
	{
		i = 0;
		sem_wait(data->data->meal);
		while (i < data->data->nb_philos && !data->data->dieded)
		{
			if ((ft_gettime() - data->last_meal) >= data->data->time_die)
			{
				data->data->dieded = 1;
				sem_wait(data->data->write);
				printf("%lld %d died.\n", ft_gettime() - data->data->first_time,
					i + 1);
				exit (1);
			}
			i++;
		}
		sem_post(data->data->meal);
		if (data->data->nb_eat != -1 && data->n_eat >= data->data->nb_eat)
			return (NULL);
	}
	return (NULL);
}
