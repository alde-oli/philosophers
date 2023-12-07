/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_state_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:07:15 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/07 21:44:02 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static int	ft_strlen(char *str);
static int	ft_nbrlen(int n);
static char	*ft_itoa(int n);
static char	*ft_strjoin(char *s1, char *s2);

void	display_action(int id, char *action, long long unsigned start_time)
{
	char		*time;
	char		*id_s;
	char		*temp;
	char		*msg;

	time = ft_itoa(get_cur_time() - start_time);
	id_s = ft_itoa(id);
	temp = ft_strjoin(time, " ");
	free(time);
	time = ft_strjoin(temp, id_s);
	free(temp);
	free(id_s);
	msg = ft_strjoin(time, action);
	free(time);
	write(1, msg, ft_strlen(msg));
	free(msg);
}

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_nbrlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (ft_nbrlen(n) + 1));
	if (!str)
		return (NULL);
	i = ft_nbrlen(n);
	str[i--] = '\0';
	while (i >= 0)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = '\0';
	return (str);
}
