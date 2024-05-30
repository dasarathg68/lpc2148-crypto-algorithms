unsigned char PT[8]={"PlainTxt"};
unsigned char CT[8],DT[8];

int main()
{
unsigned char i;

//Encryption
for (i=0;i<4;i++)
{
CT[i] = PT[i*2];
CT[i+4] = PT[(i*2)+1];
}


//Decryption
for (i=0;i<4;i++)
{
DT[i*2] = CT[i];
DT[(i*2)+1] = CT[i+4];
}
return 0;
}