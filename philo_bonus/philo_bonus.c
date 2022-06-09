/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pro <pro@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:26:49 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/06/09 16:35:31 by pro              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
int main(int ac, char **av)
{
    t_data_b data;

    if (ac != 5 && ac != 6)
        return (printf("error arg \n"), 0);
    if (!(check_parse(av)))
        return (0);
    initailise_data(ac, av, &data);

    create_pr(&data, (&data)->philo);
    return (0);
}