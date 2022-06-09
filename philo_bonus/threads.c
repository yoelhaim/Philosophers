/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pro <pro@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:37:29 by pro               #+#    #+#             */
/*   Updated: 2022/06/09 23:28:18 by pro              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
void ft_usleep(int time_limit)
{
	long long time;

	time = get_time();
	usleep((time_limit - (time_limit * 0.03)) * 1000);
	while ((get_time() - time) < time_limit)
		usleep(1);
}

void start_eat(t_data_b *data, t_philo_b *philo)
{
	sem_wait(data->eating);
	print_message(data, "is eating", philo->id);
	philo->check_die_time = get_time();
	sem_post(data->eating);
	(philo->eat)++;
	ft_usleep(data->time_to_eat);
}

int taking_fork(t_data_b *data, t_philo_b *philo)
{
	sem_wait(data->forks);
	print_message(data, "has taken a fork", philo->id);
	sem_wait(data->forks);
	print_message(data, "has taken a fork", philo->id);
	start_eat(philo->data, philo);
	sem_post(data->forks);
	sem_post(data->forks);
	if (data->check_eat)
		return (1);
	return (0);
}

void *routine(void *philo)
{
	t_philo_b *copy_of_philo;
	t_data_b *data;

	copy_of_philo = (t_philo_b *)philo;
	data = copy_of_philo->data;
	if (copy_of_philo->id % 2)
		usleep(10000);
	while (!(data->die))
	{
		if (data->number_of_philosophers < 2)
		{
			print_message(data, "has taken a fork", copy_of_philo->id);
			ft_usleep(data->time_to_die);
			break;
		}
		if (taking_fork(data, copy_of_philo))
			break;
		print_message(data, "is sleeping", copy_of_philo->id);
		ft_usleep(data->time_to_sleep);
		print_message(data, "is  thinking", copy_of_philo->id);
	}
	return (NULL);
}

void create_thread(t_data_b *data, t_philo_b *philo)
{
	philo->check_die_time = get_time();
	if (pthread_create(&philo->id_thread, NULL, routine, (void *)philo))
		exit(1);
	pthread_detach(philo->id_thread);
	check_death(data, philo);
	exit(0);
}