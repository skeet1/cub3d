/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:13:16 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/05/07 09:40:07 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
// command line works uppercase and lowercase

// create a pair value array in c



// think of a clean architecture : 
/* 


	=> Problem analysis : 
		- split a string into an array of strings by a delimiter.
		- sections of the string between quotes are skipped.
		- the delimiter is not included in the resulting array.
		- the strings between quotes could have spaces. between them.
		
	=> simplestic solution
		- split the string by the delimiter.
		- skip the strings between quotes.
		- return the resulting array.
	=> Detailed solution: 
		- 

	-> state machine : 
		-> we're at a non-delimiter character.
			- store index of first non-delimter character index only once at var.
			- while we're no at a delimiter or quote keep skipping.
		-> we're at a delimiter character: 
			- keep skipping until we're at a non-delimiter character.
			- create a new string starting from var until current index - 1. exculding the delimiter or delimiters.
			- update var to index.
		-> we're at a quote.
			- while we're at a quote or space or tab.
				-if we're at a quote.
					- count++
					- add quote index to arr[i + 1].
					-i++;
				else 
					i++;
			arr[0] = count;
			- keep skipping until we're at a quote character again.
			- while we're at a quote or space or tab.
				if we're at a quote.
					- count++
					- add quote index to arr2[i + 1].
					-i++;
				else 
					i++;
			arr2[0] = count;

			- if arr[0] == arr2[0]
				- create a new string starting from arr[arr[count]] to arr2[arr2[count]]. 
				- update i to arr2[arr2[count]] + 1.
				
			- else
				- if arr[0] > arr2[0]
					- start = arr[1] - arr2[arr2[count]].
					- create a string from arr[start] to arr2[arr2[count]].
					- update i to arr2[arr2[count]] + 1.
				- else
					- end = arr2[arr2[count]] - arr[arr[count]].
					- create a string from arr[arr[count]] to arr2[end].
					- update i to arr2[end] + 1.
		
					
					
			
			
		
		
		// 

*/


size_t count_(const char *s, char c)
{
	size_t count;
	int i;

	i= 0;
	count = 0;
	while (s[i])
	{
		if (ft_isprint(s[i]) && s[i + 1] == c)
		{
			while (s[i + 1] == c)
				i++;
			count++;
		}
		i++;
	}
	return (count);
}


void	exitFree(char **split, int index)
{
	while (index > 0)
	{
		free(split[index]);
		index--;
	}
	free(split);
	ft_putendl_fd("allocation failed", 2);
}

char	**ft_splitq(const char *s, char c)
{
	char **split;
	size_t i;
	int index;
	int j;
	int *arr;
	int *arr2;
	int count;
	char *tmp;
	int q2_index = 0;
	int q2_index2 = 0;
	j = 0;
	i = 0;	
	split = malloc(sizeof(char *));
	// printf("%zu\n", count_(s, c));
	exitIF(split == NULL, "allocation failed");
	int cond = 0;
	while (s[i])
	{
		if (s[i] == '"' || s[i] == '\'')
		{
			char q = s[i] == '"' ? '"' : '\'';
			char q2 = s[i] == '"' ? '\'' : '"';
			arr = malloc(sizeof(int) * 2);
			arr2 = malloc(sizeof(int) * 2);
			count = 0;
			exitIF(arr == NULL || arr2 == NULL, "allocation failed");
			while (s[i] && (s[i] == q || ft_isspace(s[i]) || s[i] == q2 ))
			{
				if (s[i] && s[i] == q)
				{
					if (s[i] == q2 && s[i + 1] == q)
					{
						q2_index = i;
					}
					arr[count + 1] = i;
					count++;
					i++;
					arr = ft_realloc(arr, sizeof(int) * (count + 1));
					exitIF(arr == NULL, "allocation failed");
				}
				else 
					i++;
			}

			arr[0] = count + 1;
			count = 0;
			while (s[i] && s[i] != q)
				i++;
			while (s[i] && (s[i] == q || ft_isspace(s[i]) || s[i] == q2))
			{
				if (s[i] == q2)
				{
					q2_index2 = i;
				}
				if (s[i] && s[i] == q)
				{
					arr2[count + 1] = i;
					count++;
					i++;
					arr2 = ft_realloc(arr2, sizeof(int) * (count + 1));
					exitIF(arr2 == NULL, "allocation failed");
				}
				else 
					i++;
			}
			arr2[0] = count + 1;
			if (q2 == '\'' && (q2_index && !q2_index2) || (!q2_index && q2_index2))
			{
				
			}
			if (arr[0] == arr2[0])
			{
				// printf("i'm here everything is ok\n");
				int end = arr2[arr2[0] - 1] + 1;

				split = ft_realloc(split, sizeof(char *) * j + 1);
				split[j] = ft_substr(s, arr[1], end);
				tmp = ft_strtrim(split[j], " ");
				free(split[j]);
				split[j] = ft_strdup(tmp);
				if (split[j] == NULL)
					exitFree(split, j);
				j++;
				i = end + 1;
				// exit(0);
				// printf("i now at %d | %s \n", i, );
			}
			else 
			{
				if (arr[0] > arr2[0])
				{
					int end = arr2[arr2[0] - 1] + 1;
					split = ft_realloc(split, sizeof(char *) * j + 2);
					split[j] = ft_substr(s, arr[1], arr[arr[0] - arr2[0] + 1]);
					tmp = ft_strtrim(split[j], " ");
					free(split[j]);
					split[j] = ft_strdup(tmp);
					j++;
					split[j] = ft_substr(s, arr[arr[0] - arr2[0] + 1], end);
					tmp = ft_strtrim(split[j], " ");
					free(split[j]);
					split[j] = ft_strdup(tmp);
					if (split[j] == NULL || split[j - 1] == NULL)
						exitFree(split, j);
					j++;
					i = end + 1;
				}
				else 
				{
	
					int start = arr2[arr[0]];
					int end = arr2[arr2[0] - 1] + 1;
					split = ft_realloc(split, sizeof(char *) * j + 2);
					split[j] = ft_substr(s, arr[1], start);
					tmp = ft_strtrim(split[j], " ");
					free(split[j]);
					split[j] = ft_strdup(tmp);
					// printf("%s\n", split[j]);
					j++;
					split[j] = ft_substr(s, start, end);
					tmp = ft_strtrim(split[j], " ");
					free(split[j]);
					split[j] = ft_strdup(tmp);
					// printf("%s\n", split[j]);
					if (split[j] == NULL || split[j - 1] == NULL)
						exitFree(split, j);
					j++;
					i = end + 1;
					// printf("i now at %zu | %s \n", i, &s[i]);
				}
			}
		}
		if (s[i] != c)
		{
			if (!cond)
			{
				index = i;
				cond = 1;
			}
			while (s[i] && s[i] != c)
				i++;
			// printf("i now at %zu | %s \n", i, &s[i]);
		}
		if ((s[i] == c  && cond) || i == ft_strlen(s))
		{
			while (s[i] && s[i] == c)
				i++;
				
			// printf("i now at %zu | %s \n", i, &s[i]);
			// printf("starting at %s and ending at %s\n", &s[index], &s[i]);
			// printf("j: %d\n", j);
			split = ft_realloc(split, sizeof(char *) * j + 1);
			split[j] = ft_substr(s, index, i);
			tmp = ft_strtrim(split[j], " ");
			free(split[j]);
			split[j] = ft_strdup(tmp);
			if (split[j] == NULL)
				exitFree(split, j);
			
			// printf("%s\n", split[j]);
			j++;
			index = i;
			cond = 0;
		}
		else
			i++;
	}
	split[j] = NULL;
	return (split);
}


int main(void)
{
	char *str = "\"\"\" \" ' \" ls \"\"\"\"'\" ";
	char **split = ft_splitq(str, ' ');
	for (int i =0; split[i]; i++)
		printf("%s\n", split[i]);
}