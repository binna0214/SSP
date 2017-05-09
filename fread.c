#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
  unsigned char abType[2];
  char flag1;
  char abData[6];
  char flag2;
  char abMSG[10];
  char a0a;
}DATA;

typedef struct {
  char abType[2];
  int cnt;
}INFO;

int main()
{
  FILE *fp = NULL;
  DATA data[1024];
  INFO info[3];
  DATA tmpData;
  int i, j;
  int nReadSize;
  int nCnt = 0;
  
  memset(&data, 0x00, sizeof(data));
  
  fp = fopen("test.txt", "rb");
  
  i=0;
  while( !feof(fp))
  {
    memset(&tmpData, 0x00, sizeof(DATA));
    nReadSize = fread(&tmpData, sizeof(DATA), 1, fp);
    memcpy( data[i].abType, tmpData.abType, sizeof(tmpData.abType));
    memcpy( data[i].abData, tmpData.abData, sizeof(tmpData.abData));
    memcpy( data[i].abMSG, tmpData.abMSG, sizeof(tmpData.abMSG));
    i++;
    nCnt++;
  }
  
  for(i=0; i<nCnt-1; i++)
  {
    printf("#d. %s %s %s \n",i, data[i].abType, data[i].abData, data[i].abMSG);
    
    
  }
  
  for(i=0; i<nCnt-1; i++)
  {
    if(strcmp("AA", data[i].anType) == 0 )
    {
      info[0].cnt++;
    }
    else if ("BB", data[i].anType) == 0 )
    {
      info[1].cnt++;
    }
    else
      info[2].cnt++;
  }
  
  fclose(fp);
  
  fp = fopen("result.txt", "wb");
  
  fprintf(fp, "AA:%d\n", info[0].cnt);
  
}
