/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:52:53 by mtomomit          #+#    #+#             */
/*   Updated: 2024/04/10 22:09:02 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <unistd.h> // for sbrk

void *malloc(size_t size) {
	ft_putstr_fd("malloc\n", 1);
    void *mem = sbrk(size);
    if (mem == (void *) -1) {
        return NULL; // sbrk failed
    } else {
        return mem;
    }
	ft_putstr_fd("malloc\n", 1);
}
