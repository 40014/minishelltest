#include "../minishell.h"

int ft_skip_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}
int	check_prompt(char *input)
{
	int	i;

	i = 0;
	if (input == NULL)
		exit(exit_code);
	while (input[i] != '\0')
	{
		while ((input[i] == '\t' || input[i] == '\n' || input[i] == '\v' || input[i] == '\f' || input[i] == '\r' || input[i] == ' ') && (input[i] != '\0'))
			i++;
		if (input[i] == '\0')
			return (0);
		else 
			return (1);
	}
	return (0);
}

int ft_count_args(char *input)
{
	int	count;
	int	i;
	char	quote;

	i = 0;
	quote = 0;
	count = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '\'' || input[i] == '"')
		{
			quote = ft_handle_quote(input[i], quote);
			i++;
		}
		else if (((input[i] == '>' && input[i + 1] == '>') || (input[i] == '<' && input[i + 1] == '<')) && quote == 0)
		{
			count++;
			i += 2;
			while (ft_skip_space(input[i]) == 1)
				i++;
			if (input[i] != '\0' && ft_skip_space(input[i]) == 0)
			{
				count++;
				while (input[i] != '\0' && ft_skip_space(input[i]) == 0 && input[i] != '>' && input[i] != '<' && input[i] != '\'' && input[i] != '"')
					i++;
			}
		}
		else if ((input[i] == '>' || input[i] == '<') && quote == 0)
		{
			count++;
			i++;
			while (ft_skip_space(input[i]) == 1)
				i++;
			if (input[i] != '\0' && ft_skip_space(input[i]) == 0)
			{
				count++;
				while (input[i] != '\0' && ft_skip_space(input[i]) == 0 && input[i] != '>' && input[i] != '<' && input[i] != '\'' && input[i] != '"')
					i++;
			}
		}
		else if (ft_skip_space(input[i]) == 1 && quote == 0)
		{
			while (ft_skip_space(input[i]) == 1)
				i++;
			if (input[i] != '\0' && input[i] != '>' && input[i] != '<' && ft_skip_space(input[i]) == 0)
				count++;
		}
		else
			i++;
	}
	return count + 1;
}
