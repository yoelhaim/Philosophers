/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pro <pro@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:29:29 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/06/09 22:45:12 by pro              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int ft_atoi(char *s)
{
    int i;
    int res;
    int sign;

    i = 0;
    res = 0;
    sign = 1;
    while (s[i] == 32 && (s[i] >= 9) && s[i] <= 13)
        i++;
    if (s[i] == '-')
    {
        sign *= -1;
        i++;
    }
    if (s[i] == '+')
        i++;
    while (s[i] && (s[i] >= 48 && s[i] <= 56))
    {
        res *= 10;
        res += s[i++] - '0';
    }
    return (res * sign);
}
int check_parse(char **str)
{
    int i;
    i = 0;
    if (ft_atoi(str[i + 1]) > 200)
        return (printf("Error nof is Long \n"), 0);
    while (str[++i])
    {

        if (ft_atoi(str[i]) <= 0)
            return (printf("Error parsing \n"), 0);
    }

    return (1);
}

long long get_time(void)
{
    struct timeval time;

    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void print_message(t_data_b *data, char *string, int philo_id)
{
    sem_wait(data->print);
    if (!(data->die))
    {
        printf("%lld ", get_time() - data->beginning_time);
        printf("%d ", philo_id + 1);
        printf("%s\n", string);
    }
    sem_post(data->print);
}

void check_eat(t_data_b *data, t_philo_b *philo)
{
    int index;

    index = 0;
    while (data->time_each_philo_must_eat != 0 && index < data->number_of_philosophers && philo->eat > data->time_each_philo_must_eat)
        index++;
    if (index == data->number_of_philosophers)
        data->check_eat = 1;
}

void check_death(t_data_b *data, t_philo_b *philo)
{
    int index;

    while (!(data->check_eat))
    {
        index = 0;
        while ((index < data->number_of_philosophers) && (!(data->die)))
        {
            sem_wait(data->eating);
            if ((get_time() - philo->check_die_time) > data->time_to_die)
            {
                sem_wait(data->sem_die);
                print_message(data, "died", index);
                data->die = 1;
            }
            sem_post(data->eating);
            index++;
        }
        if (data->die)
            break;
        if (data->time_each_philo_must_eat > 0)
            check_eat(data, data->philo);
        usleep(1000);
    }
}

void kill_process(t_data_b *data)
{
    int i;

    i = 0;
    while (i < data->number_of_philosophers)
        kill(data->child_pid[i++], SIGKILL);
}

void end(t_data_b *data)
{
    kill_process(data);
    sem_close(data->forks);
    sem_unlink("FORKS");
    sem_close(data->print);
    sem_unlink("PRINT");
    sem_close(data->eating);
    sem_unlink("EATING");
    free(data->child_pid);
    free(data->philo);
}