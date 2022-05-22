/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pro <pro@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 09:39:50 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/05/22 22:27:50 by pro              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine(void *philo)
{
    t_philo *copy_of_philo;
    t_data *data;

    copy_of_philo = (t_philo *)philo;
    data = copy_of_philo->data;
    (void)data;
    // printf("routine %lld \n", data->beginning_time);

    return (NULL);
}