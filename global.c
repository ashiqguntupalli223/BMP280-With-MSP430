#include "global.h"

void Dec2Str(s32 dec, u8* str)
{
  u32 temp[10],l=0,Minus_Sign=0,i;
  
  if(dec<0)
  {
    Minus_Sign=1;
    dec=-dec;
  }

  do{
    temp[l]=dec;
    l++;
    dec=(u32)(dec/10);
  }while(dec>0);
  
  for(i=0;i<l-1;i++)
    temp[i]=temp[i]-10*temp[i+1];
  
  if(Minus_Sign==1)    str[0]='-';
  for(i=0;i<l;i++)
    str[Minus_Sign+i]=temp[l-i-1]+'0';
  
  str[Minus_Sign+l]='\0';
}

//------------------------------------------------------------------------------------------------------------------------------------------
void Double2Str(double x, u8* str)
{
  u32 temp[10],l=0,Minus_Sign=0,i,t;
  
  if(x<0)
  {
    Minus_Sign=1;
    x=-x;
  }
  
  t=(u32)x;
  x=x-t;
  do{
    temp[l]=t;
    l++;
    t=(u32)(t/10);
  }while(t>0);
  for(i=0;i<l-1;i++)
    temp[i]=temp[i]-10*temp[i+1];
  
  if(Minus_Sign==1)    str[0]='-';
  for(i=0;i<l;i++)
    str[Minus_Sign+i]=temp[l-i-1]+'0';
  str[Minus_Sign+l]='.';
  for(i=0;i<10;i++)
  {
    x=x*10;
    t=(u8)x;
    x-=t;
    str[Minus_Sign+l+1]=t+'0';
    l++;
  }
  
  str[Minus_Sign+l+1]='\0';
}


//------------------------------------------------------------------------------------------------------------------------------------------
void bin2Hex(char value, u8 *destbuf)
{
    u8 temp_v;
    destbuf[0] = '0';
    destbuf[1] = 'x';

    temp_v = (value >> 4) & 0x0F;
    if (temp_v  <= 9)
    {
        destbuf[2] = temp_v + '0';
    }
    else
    {
        temp_v -= 10;
        destbuf[2] = temp_v + 'A';
    }

    temp_v = value & 0x0F;
    if (temp_v  <= 9)
    {
        destbuf[3] = temp_v + '0';
    }
    else
    {
        temp_v -= 10;
        destbuf[3] = temp_v + 'A';
    }
    destbuf[4] = 0x00;

}



//------------------------------------------------------------------------------------------------------------------------------------------
void bin2Chars(int value, u8 *destbuf)
{
    u8 tenthousand=0;
    u8 thousand=0;
    u8 hundred=0;
    u8 ten=0;
    u8 one=0;

    while (value-10000 >= 0)
    {
        value -= 10000;
        tenthousand++;
    }
    while (value-1000 >= 0)
    {
        value -= 1000;
        thousand++;
    }
    while (value-100 >= 0)
    {
        value -= 100;
        hundred++;
    }
    while (value-10 >= 0)
    {
        value -= 10;
        ten++;
    }
    while (value-1 >= 0)
    {
        value--;
        one++;
    }

    if (tenthousand)
    {
        destbuf[0]=tenthousand + '0';
        destbuf[1]=thousand + '0';
        destbuf[2]=hundred + '0';
        destbuf[3]=ten + '0';
        destbuf[4]=one + '0';
        destbuf[5]=0x00;
    }
    else if (thousand)
    {
        destbuf[0]=thousand + '0';
        destbuf[1]=hundred + '0';
        destbuf[2]=ten + '0';
        destbuf[3]=one + '0';
        destbuf[4]=0x00;
    }
    else if (hundred)
    {
        destbuf[0]=hundred + '0';
        destbuf[1]=ten + '0';
        destbuf[2]=one + '0';
        destbuf[3]=0x00;
    }
    else if (ten)
    {
        destbuf[0]=ten + '0';
        destbuf[1]=one + '0';
        destbuf[2]=0x00;
    }
    else if (one)
    {
        destbuf[0]=one + '0';
        destbuf[1]=0x00;
    }
    else
    {
        destbuf[0]='0';
        destbuf[1]=0x00;
    }
}



//------------------------------------------------------------------------------------------------------------------------------------------
void delay(u16 kCycles)
{
  for(u16 iiii=0;iiii<kCycles;iiii++)
    for(u16 jjjj=0;jjjj<1000;jjjj++);
}