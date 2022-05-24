/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:06:44 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/05/23 18:56:25 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_atoi(char *str)
{
    int i;
    int res;
    int sign;

    i = 0;
    res = 0;
    sign = 1;
    while (str[i] <= 32)
        i++;
    if (str[i] == '-')
    {
        sign *= -1;
        i++;
    }
    if (str[i] == '+')
        i++;
    while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
        res *= 10;
        res += str[i++] - 48;
    }
    return (res * sign);
}

int check_parse(char **arg)
{
    int i;

    i = 0;

    if (ft_atoi(arg[1]) > 200)
        return (printf("%s", ERROR_Z_PHILO), 0);
    while (arg[++i])
    {
        if (ft_atoi(arg[i]) <= 0)
            return (printf("%s", ERROR_PARSE), 0);
    }

    return (1);
}
void write_message(t_data *data, int philoid, char *str)
{
    pthread_mutex_lock(&(data->print));
    if (!(data->die))
    {
        printf("\n%lld ", get_time() - data->beginning_time);
        printf("%d ", philoid);
        printf("%s\n", str);
    }
    pthread_mutex_unlock(&(data->print));
}
void check_dieth(t_data *data, t_philo *philo)
{
    int i;
    while (!(data->check_eat))
    {
        i = 0;

        while (i < data->number_of_philosophers)
        {
            // printf("\n time is =>  %lld  >  %d \n", get_time() - philo[i].check_die_time, data->time_to_die);
            pthread_mutex_lock(&(data->eating));
            if ((get_time() - philo[i].check_die_time) > data->time_to_die)
            {
                write_message(data, i, "is dead");
                data->die = 1;
            }
            pthread_mutex_unlock(&(data->eating));
            i++;
        }
        if (data->die)
            break;
        if (data->time_each_philo_must_eat > 0)
            check_eat(data, data->philo);
        usleep(300);
    }
}

void check_eat(t_data *data, t_philo *philo)
{
    int i;

    i = 0;
    while (data->time_each_philo_must_eat != 0 && i < data->number_of_philosophers && philo->eat > data->time_each_philo_must_eat)
        i++;
    if (i == data->number_of_philosophers)
        data->check_eat = 1;
}
void ft_usleep(int time_limit, t_data *data)
{
    long long time;

    time = get_time();
    if (!(data->die))
    {
        usleep((time_limit - (time_limit * 0.03)) * 1000);
        while ((get_time() - time) < time_limit)
            usleep(500);
    }
}
void end(t_data *data, t_philo *philo)
{
    int index;

    index = 0;
    while (index < data->number_of_philosophers)
        pthread_join(philo[index++].id_thread, NULL);
    index = 0;
    while (index < data->number_of_philosophers)
        pthread_mutex_destroy(&(data->forks[index++]));
    pthread_mutex_destroy(&(data->eating));
    pthread_mutex_destroy(&(data->print));
    free(data->philo);
    free(data->forks);
}