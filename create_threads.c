/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pro <pro@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:58:48 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/06/01 18:47:35 by pro              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
long long get_time()
{
    struct timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int create_tread(t_data *data, t_philo *philo)
{
    int i;

    i = -1;
    data->beginning_time = get_time();
    while (++i < data->number_of_philosophers)
    {
        philo[i].check_die_time = get_time();
        if ((pthread_create(&data->philo[i].id_thread, NULL, routine, (void *)(&philo[i]))))
            return (printf("%s \n", ERROR_TH), 0);
    }
    check_dieth(data, data->philo);
    end(data, data->philo);
    return (1);
}