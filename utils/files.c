#include "../minishell.h"

int is_infile(t_element *elem)
{
    if (!ft_strncmp(elem->token, "INFILE", ft_strlen(elem->token)))
        return (1);
    return (0);
}

int is_outfile(t_element *elem)
{
    if (!ft_strncmp(elem->token, "OUTFILE", ft_strlen(elem->token)))
        return (1);
    if (!ft_strncmp(elem->token, "OUTFILE-APPEND", ft_strlen(elem->token)))
        return (1);
    return (0);
}

int get_open_mode(t_element *elem)
{
    if (!ft_strncmp(elem->token, "OUTFILE", ft_strlen(elem->token)))
        return (O_RDWR);
    if (!ft_strncmp(elem->token, "OUTFILE-APPEND", ft_strlen(elem->token)))
        return (O_RDWR | O_APPEND);
    return (NULL);
}

char *get_file_content(int fd)
{
    char *res;
    int bytes;

    bytes = 1;
    while(bytes > 0)
        bytes = read(fd, res, 1);
    return (res);
}
