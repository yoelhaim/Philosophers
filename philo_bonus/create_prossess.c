/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_prossess.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pro <pro@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:25:40 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/06/09 23:43:19 by pro              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int create_pr(t_data_b *data, t_philo_b *philo)
{
    int i;
    (void)philo;
    i = 0;
    data->beginning_time = get_time();
    while (i < data->number_of_philosophers)
    {
        data->child_pid[i] = fork();
        if (!data->child_pid[i])
            create_thread(data, &philo[i]);
        if (data->child_pid[i] == -1)
        {
            kill_process(data);
            return (0);
        }
        // printf("id the fork is => %d \n", data->child_pid[i]);
        i++;
    }
    waitpid(-1, NULL, 0);
    end(data);
    return (1);
}