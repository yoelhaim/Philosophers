/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pro <pro@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:50:00 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/06/01 18:43:35 by pro              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_init_struct_philo(t_data *data)
{
    int index;

    index = 0;
    data->philo = malloc(sizeof(t_data) * data->number_of_philosophers);
    if (!data->philo)
        return (1);
    while (index < data->number_of_philosophers)
    {
        data->philo[index].id = index;
        data->philo[index].left_chopstick = index;
        data->philo[index].right_chopstick = (index + 1) % data->number_of_philosophers;
        data->philo[index].check_die_time = 0;
        data->philo[index].eat = 0;
        data->philo[index].data = data;
        index++;
    }
    return (0);
}

int ft_init_mutex(t_data *data)
{
    int index;

    index = 0;
    if (pthread_mutex_init(&(data->eating), NULL))
        return (1);
    if (pthread_mutex_init(&(data->print), NULL))
        return (1);
    data->forks = malloc(sizeof(pthread_mutex_t) * data->number_of_philosophers);
    if (!(data->forks))
        return (1);
    while (index < data->number_of_philosophers)
    {
        if (pthread_mutex_init(&(data->forks[index]), NULL))
            return (1);
        index++;
    }
    return (0);
}

int init_philo(char **av, int ac, t_data *data)
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
        return (write(2, "ERROR : Initialization has failed !\n", 37), 1);

    return (1);
}