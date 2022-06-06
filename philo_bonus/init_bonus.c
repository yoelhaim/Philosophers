/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:22:58 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/06/06 11:06:54 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int initailise_philo(t_data_b *data)
{
    int i;
    int nof;
    
    i = -1;
    nof = data->number_of_philosophers;
    data->philo = malloc(sizeof(t_data_b) * nof);
    if (!data->philo)
        return(printf("Error malloc  data philo \n"), 0);
    while (++i < nof)
    {
        data->philo[i].id = getpid();
        data->philo[i].left_chopstick = i;
		data->philo[i].right_chopstick = (i + 1) % nof;
		data->philo[i].check_die_time = 0;
		data->philo[i].eat = 0;
		// data->philo[i].data = data;
        i++;
            
    }
    
    return (1);
}
int initailise_data(int ac, char **av, t_data_b *data)
{
    data->number_of_philosophers = ft_atoi(av[1]);
    data->time_to_die = ft_atoi(av[2]);
    data->time_to_eat = ft_atoi(av[3]);
    data->time_to_sleep = ft_atoi(av[4]);
    data->beginning_time = 0;
	data->die = 0;
	data->check_eat = 0;
	data->time_each_philo_must_eat = 0;
    if(ac == 6)
        data->time_each_philo_must_eat = ft_atoi(av[5]);
    if(!(initailise_philo(data)))
        return(printf("ERROR : Initialization has failed !\n"), 0);
    return (1);
}