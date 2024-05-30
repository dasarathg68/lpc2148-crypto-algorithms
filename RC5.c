unsigned char A,B,A1,A2,B1,B2,s0,s1,s2,s3,r,dA,dB,dA1,dA2,dB1,dB2;


encrypt_rc5()
{
	A1 = (A+s0)%256;
	B1 = (B+s1)%256;
	
	r=(B1%8);
	A2 = A1 ^ B1;
	A2 = (((A2<<r)|(A2>>(8-r)))+s2)%256;
	
	r=(A2%8);
	B2 = B1 ^ A2;
	B2 = (((B2<<r)|(B2>>(8-r)))+s3)%256;
}


decrypt_rc5()
{
	r=(dA2%8);
	dB2 = (dB2-s3)%256;
	dB1 = (((dB2>>r)|(dB2<<(8-r)))^dA2);
	dB = (dB1 - s1)%256;
	
	r=(dB1%8);
	dA2 = (dA2-s2)%256;
	dA1 = (((dA2>>r)|(dA2<<(8-r)))^dB1);
	dA = (dA1 - s0)%256;
}

int main()
{
	A=0x90;
	B=0xb7;
	
	s0=0xa0;
	s1=0xf0;
	s2=0xfa;
	s3=0xf9;
	encrypt_rc5();
	dA2=A2;
	dB2=B2;
	decrypt_rc5();
	
	return 0;
}
