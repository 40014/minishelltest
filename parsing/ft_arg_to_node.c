#include "../minishell.h"

t_arg_node *create_arg_node(char *arg)
{
    t_arg_node *new_node = malloc(sizeof(t_arg_node));
    if (!new_node)
        return NULL;
    new_node->arg = ft_strdup(arg);
    new_node->next = NULL;
    return (new_node);
}

void append_arg_node(t_arg_node **head, t_arg_node *new_node)
{
    if (!*head)
    {
        *head = new_node;
    }
    else
    {
        t_arg_node *temp = *head;
        while (temp->next)
            temp = temp->next;
        temp->next = new_node;
    }
}

int count_arg_nodes(t_arg_node *head)
{
    int count;

    count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return (count);
}

char **convert_list_to_array(t_arg_node *head)
{
    int count;
    int i; 
    char    **args;
    

    i = 0; 
    count = count_arg_nodes(head);
    args = malloc(sizeof(char *) * (count + 1));
    if (!args)
        return (NULL);
    t_arg_node *temp = head;
    while (i < count)
    {
        args[i] = ft_strdup(temp->arg);
        temp = temp->next;
        i++;
    }
    args[count] = NULL;
    return (args);
}
