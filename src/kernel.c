void kernel_main(void)
{
    char *vga = (char*)0xB8000;

	vga[0] = '4';
	vga[1] = 0x07;

	vga[2] = '2';
	vga[3] = 0x07;

    while (1)
    {
    }
}