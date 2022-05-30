/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 09:39:50 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/05/25 17:44:41 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int taking_fork(t_data *data, t_philo *philo)
{
    pthread_mutex_lock(&(data->forks[philo->left_chopstick]));
    write_message(data, philo->id, "has taken a fork");
    pthread_mutex_lock(&(data->forks[philo->right_chopstick]));
    write_message(data, philo->id, "has taken a fork");
    start_eat(philo->data, philo);
    pthread_mutex_unlock(&(data->forks[philo->left_chopstick]));
    pthread_mutex_unlock(&(data->forks[philo->right_chopstick]));
    if (data->check_eat)
        return (0);
    return (1);
}
void start_eat(t_data *data, t_philo *philo)
{
    pthread_mutex_lock(&(data->eating));
    write_message(data, philo->id, "is eating");
    philo->check_die_time = get_time();
    pthread_mutex_unlock(&(data->eating));
    (philo->eat)++;
    ft_usleep(data->time_to_eat, data);
}
void *routine(void *philo)
{
    t_philo *copy_of_philo;
    t_data *data;

    copy_of_philo = (t_philo *)philo;
    data = copy_of_philo->data;
    if (data->number_of_philosophers == 1)
    {
        write_message(data, copy_of_philo->id, "has taken a fork");
        ft_usleep(data->time_to_die, data);
        return (NULL);
    }
    if (copy_of_philo->id % 2)
        usleep(10000);
    while (!(data->die))
    {
        if (!taking_fork(data, copy_of_philo))
            break;
        write_message(data, copy_of_philo->id, "is sleeping");
        ft_usleep(data->time_to_sleep, data);
        write_message(data, copy_of_philo->id, "is  thinking");
    }

    return (NULL);
}