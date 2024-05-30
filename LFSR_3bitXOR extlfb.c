unsigned char LFSR[8]; //XOR based  X3+X+1   (X3 - LSB)
int main()
{
unsigned char i,j;
unsigned char qn,seed,q,q0,q1,q2;
	seed=5;
	q=seed;

LFSR[0]=0;
for(i=1;i<8;i++)
	{
		q0=q&1;
		q>>=1;
		q1=q&1;
		q>>=1;
		q2=q&1;
		
		qn=(((q2^q0)<<2)|(q2<<1)|q1);  // paper LFSR
	
		LFSR[i]=qn;
		q = qn;
	}

return 0;
}
