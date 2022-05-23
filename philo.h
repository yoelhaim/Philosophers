/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:05:33 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/05/23 18:47:03 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#define ERROR_PARSE "error parsing"
#define ERROR_Z_PHILO "error nember the philo is not valid"
#define ERROR_AC "error number of argument"
#define ERROR_TH "create threads has feiled  "

typedef struct s_philo
{
    pthread_t id_thread;
    int id;
    int eat;
    int left_chopstick;
    int right_chopstick;
    struct s_data *data;
    long long check_die_time;

} t_philo;
typedef struct s_data
{
    pthread_mutex_t *forks;
    pthread_mutex_t eating;
    pthread_mutex_t print;
    int number_of_philosophers;
    int time_to_eat;
    int time_to_die;
    int time_to_sleep;
    int die;
    int check_eat;
    int time_each_philo_must_eat;
    long long beginning_time;
    t_philo *philo;
} t_data;

int ft_atoi(char *str);
int check_parse(char **arg);
int init_philo(char **av, int ac, t_data *data);
int create_tread(t_data *data, t_philo *philo);
long long get_time();
void *routine(void *philo);
void check_dieth(t_data *data, t_philo *philo);
void check_eat(t_data *data, t_philo *philo);
void write_message(t_data *data, int philoid, char *str);
void ft_usleep(int time_limit, t_data *data);
void end(t_data *data, t_philo *philo);
void start_eat(t_data *data, t_philo *philo);
#endif