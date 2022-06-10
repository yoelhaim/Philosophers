/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:29:29 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/06/10 09:44:38 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include<unistd.h>
# include<stdio.h>
# include<pthread.h>
# include<stddef.h>
# include<time.h>
# include<semaphore.h>
# include<signal.h>
# include<stdlib.h>
# include<sys/time.h>

struct	s_philosophers;
typedef struct s_data
{
	int						nb_philos;
	int						time_die;
	int						time_eat;
	int						time_sleep;
	int						nb_eat;
	int						dieded;
	long long				first_time;
	sem_t					*fork;
	sem_t					*meal;
	sem_t					*write;
	struct s_philosophers	*philos;
}t_data;

typedef struct s_philosophers
{
	int				id;
	int				n_eat;
	int				id_fork;
	int				id_next_fork;
	long long		last_meal;
	int				pid;
	pthread_t		death;
	t_data			*data;

}t_filos;

void		routine(t_filos *arg);
int			ft_creat(t_data *all);
int			ft_strlen(char *str);
void		ft_print(t_data *data, int id, char *str, int dead);
int			parsing(int ac, char **av, t_data *all);
int			ft_atoi(char	*str);
long long	ft_gettime(void);
int			ft_error(char *str, void *ptr);
void		ft_destroy(t_data *data);
void		ft_eats(t_filos *filo);
void		*death(void *filo);
void		ft_sleep(long long time, t_data *data);

#endif