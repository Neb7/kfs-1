#include "kernel.h"

void	keyboard_handler(void)
{
	inb(0x60);
}
