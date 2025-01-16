/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-26 12:35:57 by jepenoy           #+#    #+#             */
/*   Updated: 2024-12-26 12:35:57 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct s_list
{
	int				data;
	struct s_list	*next;
	struct s_list	*prev;
}			t_list;

typedef struct s_rotat
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
}			t_rotat;

t_list	*new_node(int data);
void	insert_end(t_list **head, int data);
void	insert_begin(t_list **head, int data);
void	delete_node(t_list **head, int key);
int		list_len(t_list *head);
void	swap(t_list **head, char *type);
void	push(t_list **a, t_list **b, char *type);
void	rotate(t_list **head, char *type);
void	rrotate(t_list **head, char *type);
int		ft_atoi(const char *nptr);
int		check_args(int argc, char *argv[], int i);
int		check_args_split(int argc, char *argv[], int i);
int		ft_strncmp(char *s1, char *s2, int n);
t_list	*fill_list(int c, char *arr[]);
void	sort(t_list **lst1);
char	**ft_split(char const *s, char c);
int		count_args(char **arr);
t_list	*findmax(t_list *lst);
t_list	*findmin(t_list *lst);
int		calculate_rota_cost(t_rotat **rot);
t_list	*find_target(int n, t_list *b);
int		check_pos(t_list *lst, int n);
t_list	*find_number(t_list *a, int n);
void	sort_three(t_list **lst);
void	sort_two(t_list **lst);
void	push_b_to_a(t_list **a, t_list **b);
void	final_rot(t_list **lst);
void	free_split(char **arr);
void	free_list(t_list *lst);
t_list	*fill_list_split(int c, char *arr[]);
void	do_rota(t_list **a, t_list **b, t_rotat **rot);
void	calculate_rota(t_list *lst, t_list *to_find, t_rotat **rot, char let);
int		is_sorted(t_list *lst);
t_list	*norme(int argc, char *argv[]);
t_list	*norme2(char *argv[]);
void	check_logic(t_list *lst, t_list *lst2);
int		check_int_min(char *str);
int		check_int_max(char *str);
#endif