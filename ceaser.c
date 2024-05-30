
unsigned char PT[8]={"SECURITY"};
unsigned char K,CT[8],DT[8];


int main(void) {
  unsigned char i;
   K=7;
   for(i=0;i<8;i++)
   {
   CT[i] = (((PT[i]-0x41)+K)%26)+65;
		 
		 if((CT[i]-K)< 'A')
		 {
   DT[i] = ((CT[i]-0x41+(26-K))%26)+0x41;
    }
		else
		{
			DT[i] = ((CT[i]-K-0x41)%26)+0x41;
		}
	}
	 return 0;
}

