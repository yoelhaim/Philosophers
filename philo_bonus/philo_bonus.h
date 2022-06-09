/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pro <pro@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:26:51 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/06/09 16:51:08 by pro              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
#define PHILO_BONUS_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
typedef struct s_philo_b
{
	pthread_t id_thread;
	int id;
	int eat;
	int left_chopstick;
	int right_chopstick;
	struct s_data_b *data;
	long long check_die_time;

} t_philo_b;
typedef struct s_data_b
{
	sem_t *sem_die;
	sem_t *forks;
	sem_t *print;
	sem_t *eating;
	pid_t *child_pid;
	int number_of_philosophers;
	int time_to_eat;
	int time_to_die;
	int time_to_sleep;
	int die;
	int check_eat;
	int time_each_philo_must_eat;
	long long beginning_time;
	t_philo_b *philo;
} t_data_b;

int ft_atoi(char *s);
int check_parse(char **str);
int initailise_data(int ac, char **av, t_data_b *data);
long long get_time(void);
int create_pr(t_data_b *data, t_philo_b *philo);
#endif