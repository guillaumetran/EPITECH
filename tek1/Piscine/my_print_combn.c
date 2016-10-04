#include <stdio.h>

void clean_tab(int n, int *tab)
{
	int count = 1;
	
	while (count < n)
	{
		if (tab[n - count] == (11 - count))
		{
			tab[n - count - 1]++;
			tab[n - count] = tab[n - count - 1] + 1;
		}
		count++;
	}
	count = 1;
	while (count < n)
	{
		if (tab[count] == (11 - (n - count)))
		{
			tab[count] = tab[count - 1] + 1;
		}
		count++;
	}
}

void init_tab(int n, int *tab)
{
    int count = 0;
	
    while (count < n)
	{
		tab[count] = count;
		count++;
	}
}

void print_tab(int n, int *tab, int end)
{
    int count = 0;
    
    while (count < n)
    {
        printf("%d", tab[count]);
        count++;
    }
    if (end == 0)
        printf(", ");
}

int check_end(int n, int *tab)
{
	int count = 0;
	
	while (count < n)
	{
		if (tab[count] >= 10 - (n - count))
			count++;
		else
			return 1;
	}
	return 0;
}

int my_print_combn(int n)
{
	int tab[n];
	
	init_tab(n, tab);
	while (check_end(n, tab) != 0)
	{
	    while (tab[n - 1] <= 9)
    	{
    	    print_tab(n, tab, 0);
    		tab[n - 1]++;
    	}
	    clean_tab(n, tab);
	}
	print_tab(n, tab, 1);
}
