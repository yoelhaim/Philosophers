/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:29:29 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/06/06 10:47:30 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int ft_atoi(char *s)
{
    int i;
    int res;
    int sign;

    i = 0;
    res= 0;
    sign = 1;
    while(s[i] == 32 && (s[i] >= 9) && s[i] <= 13)
        i++;
    if (s[i] == '-')
    {
        sign *= -1;
        i++;
    }
    if (s[i] =='+')
        i++;
    while (s[i] && (s[i] >= 48 && s[i] <= 56))
    {
        res *= 10;
        res += s[i++] - '0';
    }
    return(res * sign);
}
int check_parse(char **str)
{
    int i;
    i = 0;
    if(ft_atoi(str[i + 1]) > 200)
        return(printf("Error nof is Long \n"),0);
    while (str[++i])
    {
       
       if(ft_atoi(str[i]) <= 0)
        return(printf("Error parsing \n"),0);
    
    }
    
    return(1);
}