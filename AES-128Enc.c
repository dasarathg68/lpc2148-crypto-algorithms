unsigned char text[16]={"plain text input"}; 	  
unsigned char sbox[256]={
0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76, 
0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0, 
0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15, 
0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75, 
0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84, 
0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf, 
0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8, 
0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2, 
0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73, 
0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb, 
0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79, 
0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08, 
0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a, 
0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e, 
0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf, 
0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
}; 
unsigned char rkey[176];
unsigned char cnt,cnt1,cnt2,x,idx,xr,fnl,in;
unsigned char temp[4];
unsigned char rcon[10] = {1,2,4,8,16,32,64,128,0x1b,0x36};
unsigned char srres[16],mcres[16];
unsigned char flag;


void roundkey(void);
void addround(void);
void subbytes(void);
void shiftrow(void);
void mixcol(void);

int main()
{
cnt=0x00;

in=0;

rkey[0] = 's';
rkey[1] = 'y';
rkey[2] = 'm';
rkey[3] = 'e';
rkey[4] = 't';
rkey[5] = 'r';
rkey[6] = 'i';
rkey[7] = 'c';
rkey[8] = ' ';
rkey[9] = 'k';
rkey[10] = 'e';
rkey[11] = 'y';
rkey[12] = ' ';
rkey[13] = 'i';
rkey[14] = '/';
rkey[15] = 'p';	
	
roundkey();

addround();								/*initial add round*/
for(fnl=0;fnl<9;fnl++)					/*9 rounds with mix column*/	
{
subbytes();
shiftrow();
xr=0x1b;
mixcol();
addround();
}										/*10 round without mixcolumn*/
subbytes();
shiftrow();
addround();
return 0;
}



void roundkey(void)
{
x=0;
for(cnt=0; cnt<160; cnt=cnt+16) 
{
temp[0]=rkey[cnt+7];								/*shift row*/
temp[1]=rkey[cnt+11];
temp[2]=rkey[cnt+15];
temp[3]=rkey[cnt+3];

for(cnt1 = 0; cnt1<4; cnt1++)
{													/*sub bytes*/
idx = temp[cnt1];
temp[cnt1]=sbox[idx];
}
/*first column of each key - xor with Rcon*/
idx=rkey[cnt] ^ rcon[x];
rkey[cnt+16]=temp[0] ^ idx;
rkey[cnt+20]=temp[1] ^ rkey[cnt+4];
rkey[cnt+24]=temp[2] ^ rkey[cnt+8];
rkey[cnt+28]=temp[3] ^ rkey[cnt+12];
x++;
/*last 3 column of the each key*/
for(cnt2=0;cnt2<3;cnt2++)
{
rkey[cnt+17+cnt2]=rkey[cnt2+cnt+1] ^ rkey[cnt+16+cnt2];
rkey[cnt+21+cnt2]=rkey[cnt2+cnt+5] ^ rkey[cnt+20+cnt2];
rkey[cnt+25+cnt2]=rkey[cnt2+cnt+9] ^ rkey[cnt+24+cnt2];
rkey[cnt+29+cnt2]=rkey[cnt2+cnt+13] ^ rkey[cnt+28+cnt2];
}
}

}



void addround(void)
{
for(cnt =0;cnt<16;cnt++)
{

text[cnt]=text[cnt] ^ rkey[in];
in++;
}
return;
}

void subbytes(void)
{

for(cnt = 0; cnt<16;cnt++)
{
idx = text[cnt];
text[cnt]=sbox[idx];
}
return;
}

void shiftrow()
{

srres[0]=text[0];
srres[1]=text[1];
srres[2]=text[2];
srres[3]=text[3];

srres[4]=text[5];
srres[5]=text[6];
srres[6]=text[7];
srres[7]=text[4];

srres[8]=text[10];
srres[9]=text[11];
srres[10]=text[8];
srres[11]=text[9];

srres[12]=text[15];
srres[13]=text[12];
srres[14]=text[13];
srres[15]=text[14];

for(cnt1=0;cnt1<16;cnt1++)
text[cnt1]=srres[cnt1];
return;
}


void mixcol(void)
{
idx = 0x0b;

for(cnt=0;cnt<4;cnt++)				/*columns of sr result * row0 of constant*/
{
	idx= idx-0x0b;
	flag= srres[idx];
	temp[0]=srres[idx] << 1;
	if(flag&0x80)
		{
		temp[0]=temp[0] ^ xr;
		}

	idx= idx+4;
	flag = srres[idx];
	temp[1]=srres[idx] << 1;
	if(flag&0x80)
		{
		temp[1]=temp[1] ^ xr;
		}

	temp[1]=temp[1] ^ srres[idx];

	idx= idx+4;
	temp[2]=srres[idx];
	
	idx= idx+4;
	temp[3]=srres[idx];


	flag=temp[0] ^ temp[1];
	flag =flag ^ temp[2];
	mcres[cnt]=flag ^ temp[3];

}
								/* row1*/
idx=0x0b;
for(cnt=4;cnt<8;cnt++)
{
	idx= idx-0x0b;
	temp[0]=srres[idx];

	idx= idx+4;
	flag=srres[idx];
	temp[1]=srres[idx] << 1;
	if(flag&0x80)
		{
		temp[1]=temp[1] ^ xr;
		}

	idx=idx+4;
	flag = srres[idx];
	temp[2]=srres[idx] << 1;
	if(flag&0x80)
		{
		temp[2]=temp[2] ^ xr;
		}

	temp[2]=temp[2] ^ srres[idx];
	
	
	idx=idx+4;
	temp[3]=srres[idx];

	flag=temp[0] ^ temp[1];
	flag =flag ^ temp[2];
	mcres[cnt]=flag ^ temp[3];
}



											/*row 2*/
idx=0x0b;
for(cnt=8;cnt<12;cnt++)
{
idx=idx-0x0b;
temp[0]=srres[idx];

	idx=idx+4;
	temp[1]=srres[idx];

	idx=idx+4;
	flag=srres[idx];
	temp[2]=srres[idx] << 1;
	if(flag&0x80)
		{
		temp[2]=temp[2] ^ xr;
		}


    idx= idx+4;
    flag = srres[idx];
	temp[3]=srres[idx] << 1;
	if(flag&0x80)
		{
		temp[3]=temp[3] ^ xr;
		}
	temp[3] = temp[3] ^ srres[idx] ;




	flag=temp[0] ^ temp[1];
	flag =flag ^ temp[2];
	mcres[cnt]=flag ^ temp[3];
}
										/*row 3*/
idx=0x0b;
for(cnt=12;cnt<16;cnt++)
{
	idx=idx-0x0b;
	flag=srres[idx];
	temp[0]=srres[idx] << 1;
	if(flag&0x80)
		{
		temp[0]=temp[0] ^ xr;
		}
	temp[0]=temp[0] ^ srres[idx];

	idx=idx+4;
	temp[1]=srres[idx];

	idx=idx+4;
	temp[2]=srres[idx];


	idx=idx+4;
	flag=srres[idx];
	temp[3]=srres[idx] << 1;
	if(flag&0x80)
		{
		temp[3]=temp[3] ^ xr;
		}

	
	
	flag=temp[0] ^ temp[1];
	flag =flag ^ temp[2];
	mcres[cnt]=flag ^ temp[3];
}

for(cnt1=0;cnt1<16;cnt1++)
{text[cnt1]=mcres[cnt1];}
}


