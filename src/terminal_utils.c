#include <terminal_utils.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void vPrintProgress(int iPercent){
  char szPercent[4];
  if(iPercent < 0) iPercent = 0;
  if(iPercent > 100) iPercent = 100;

  vPrintLine("Progresso: ", 0);
  snprintf(szPercent, sizeof(szPercent), "%d", iPercent);

  printf("%3.3s%%\r", szPercent);
  fflush(stdout);

}

void vPrintCentered(const char *pszText, int iWidth){
  int iSpaces;
  
  if(iWidth <= 0 || pszText == NULL) return;
  if((int)strlen(pszText) >= iWidth){
    printf("%s\n", pszText);
    return;
  }
  iSpaces = (iWidth - strlen(pszText)) / 2;

  for(; iSpaces > 0; iSpaces--)
    printf(" ");
  
  vPrintLine(pszText, 1);
  
}

void vPrintSeparator(char cChar, int iWidth){
  for(; iWidth >= 0; iWidth--)
    iWidth ? printf("%c", cChar) : printf("\n");
}

void vPrintLine(const char *pszText, int bNewLine){
  bNewLine ? printf("%s\n", pszText) : printf("%s", pszText);
}

void vPrintBar(int iValue, int iMax, int iWidth){
  double dFullBar;
  char *szBar;
  int ii = 0;
  
  if(iWidth > 100) iWidth = 100;
  if(iMax <= 0 || iWidth <= 0) return;

  if(iValue < 0) iValue = 0;
  if(iValue > iMax) iValue = iMax;

  szBar = calloc(iWidth + 1, sizeof(char));
  if(szBar == NULL) return;
 
  dFullBar = ((double)iValue / (double)iMax) * iWidth;    /*deu até fome*/

  szBar[ii] = '[';

  for(ii = 1; ii <= iWidth; ii++){
    if(ii <= dFullBar)
      szBar[ii] = '#';
    else
      szBar[ii] = '-';
  }
  szBar[ii] = ']';
  printf("%s\n", szBar);
  free(szBar);
}