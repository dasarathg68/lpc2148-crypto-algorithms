
//I/P must be in the range of 0-25 indicating alphabets A-Z
unsigned char p[2][2]={{7,11},{4,15}},k[2][2]={{3,3},{2,5}},kinv[2][2]={{15,17},{20,9}};
unsigned char ct[4],d[2][2],c[2][2]={{0,0},{0,0}};


int main(void) {
unsigned char row,col,temp;
	//encryption
	for(row=0;row<2;row++)
	{
		for(col=0;col<2;col++)
		{
			for(temp=0;temp<2;temp++)
			{
				c[row][col] = (c[row][col] + k[row][temp] * p[temp][col]) %26;
			}
		}
		
	}
	
	//decryption
for(row=0;row<2;row++)
	{
		for(col=0;col<2;col++)
		{
			for(temp=0;temp<2;temp++)
			{
				d[row][col] = (d[row][col] + kinv[row][temp] * c[temp][col]) % 26;
			}
		}
		
	}
return 0;
}

