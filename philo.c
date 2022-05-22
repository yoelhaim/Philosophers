/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pro <pro@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:16:18 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/05/22 22:11:42 by pro              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char *av[])
{
    t_data data;
    // t_philo philo;

    if (ac != 5 && ac != 6)
        return (printf("%s", ERROR_AC), 0);
    if (!(check_parse(av)))
        exit(1);
    if (!(init_philo(av, ac, &data)))
        exit(1);
    if (!(create_tread(&data, (&data)->philo)))
        exit(1);
    // printf("%d\n", data.number_of_philosophers);
}