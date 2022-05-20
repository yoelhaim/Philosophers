/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:50:00 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/05/19 12:55:50 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_philo(char **av, int ac, t_data *data)
{

    data->number_of_philosophers = ft_atoi(av[1]);
    data->time_to_die = ft_atoi(av[2]);
    data->time_to_eat = ft_atoi(av[3]);
    data->time_to_sleep = ft_atoi(av[4]);
    data->time_each_philo_must_eat = 0;
    if (ac == 6)
        data->time_each_philo_must_eat = ft_atoi(av[5]);
    return (1);
}