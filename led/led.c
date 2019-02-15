

void delay(volatile int d)
{
	while (d--)
		;
}

int main(int argc, char *argv[])
{
	volatile unsigned int *pGPFCON = (volatile unsigned int *)0x56000050;
	volatile unsigned int *pGPFDAT = (volatile unsigned int *)0x56000054;

	*pGPFCON &= ~((3 << 8) | (3 << 10) | (3 << 12));
	*pGPFCON |= ((1 << 8) | (1 << 10) | (1 << 12));

	while (1)
	{
		*pGPFDAT &= ~(7 << 4);
		delay(100000);
		*pGPFDAT |= (7 << 4);
	};
	return 0;
}
