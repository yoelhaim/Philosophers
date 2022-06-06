/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:26:49 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/06/06 11:10:02 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
int main(int ac, char **av)
{
    t_data_b data;
    
    if(ac != 5 && ac != 6)
        return(printf("error arg \n"), 0);
    if(!(check_parse(av)))
        return(0);
    initailise_data(ac, av, &data);
    return (0);
}