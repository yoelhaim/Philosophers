/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_prossess.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pro <pro@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:25:40 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/06/09 16:53:36 by pro              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int create_pr(t_data_b *data, t_philo_b *philo)
{
    int i;
    (void)philo;
    i = 0;
    // data->beginning_time = get_time();
    while (i < data->number_of_philosophers)
    {
        data->child_pid[i] = fork();
        printf("id the fork is => %d \n", i);
        i++;
    }

    return (1);
}