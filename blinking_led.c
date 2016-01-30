#define F_CPU 16000000UL //CPU frequency defined by the user
#define PORTB *(volatile unsigned int *)(0x25) // 0x25 is the address of PORTB Register
#define DDRB *(volatile unsigned int *)(0x24) //0x24 is the address of DDRB Register

void delay(unsigned int time)                 //delay function
{
    volatile unsigned int rate=F_CPU/17500;//rate is the num of times the for loop should execute for 1ms delay				
    volatile unsigned int i;
    while(time--)						
    {
	for(i=0;i<=rate;i++)
	{
	    __asm__ __volatile__ ("nop");//nop is used for "No Operation" i.e to not change the state of any register during execution
        }
    }
}
int main()
{   
    DDRB |= (1 << 5); // Left Shift 6 to define PIN5 of PortB as output
    while(1) 
    {
        PORTB ^= (1 << 5);// Left Shift 6 to Set PIN5 of PortB High to turn on LED
        delay(1000);  // Delay of 1s
    }
    return 0;
}  
