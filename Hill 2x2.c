
//I/P must be in the range of 0-25 indicating alphabets A-Z
unsigned char p[2][2]={{7,11},{4,15}},k[2][2]={{3,3},{2,5}},kinv[2][2]={{15,17},{20,9}};
unsigned char c[2][2],ct[4],d[2][2];


int main(void) {

	//encryption
c[0][0] = (k[0][0]*p[0][0] + k[0][1]*p[1][0]) % 26;
c[0][1] = (k[0][0]*p[0][1] + k[0][1]*p[1][1]) % 26;
c[1][0] = (k[1][0]*p[0][0] + k[1][1]*p[1][0]) % 26;
c[1][1] = (k[1][0]*p[0][1] + k[1][1]*p[1][1]) % 26;
	
//to display as ASCII (alphabets)
/*
ct[0] = c[0][0] + 0x41;
ct[1] = c[0][1] + 0x41;
ct[2] = c[1][0] + 0x41;
ct[3] = c[1][1] + 0x41;
*/
	
	//decryption
d[0][0] = (kinv[0][0]*c[0][0] + kinv[0][1]*c[1][0]) % 26;
d[0][1] = (kinv[0][0]*c[0][1] + kinv[0][1]*c[1][1]) % 26;
d[1][0] = (kinv[1][0]*c[0][0] + kinv[1][1]*c[1][0]) % 26;
d[1][1] = (kinv[1][0]*c[0][1] + kinv[1][1]*c[1][1]) % 26;

	
return 0;
}

