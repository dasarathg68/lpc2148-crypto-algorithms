//As integer input variables are 16-bit in 8051 i=0 to 15
//As integer input variables are 32-bit in ARM compiler i=0 to 31
unsigned char HD,i;
unsigned int X,Y,temp;

void main()
{
HD=0;
X=0x23AF;
Y=0xB52E;
temp= X ^ Y; //for Hamming Distance
for(i=0;i<16;i++)	 //HAMMING WEIGHT
{
if(temp&1)
{
HD++;
}
temp=temp>>1;
}
}
