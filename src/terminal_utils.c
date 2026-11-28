#include <terminal_utils.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>


void vDrawBox(int iX, int iY, int iWidth, int iHeight){
  vGotoXY(iX, iY);
  printf(BOX_TOP_LEFT);

  vDrawHLine(iX, iY + 1, iWidth - 2);
  printf(BOX_TOP_RIGHT);

  vDrawVLine(iX + 1, iY, iHeight);
  vDrawVLine(iX + 1, iY + iWidth - 1, iHeight);

  vGotoXY(iX + iHeight + 1, iY);
  printf(BOX_BOTTOM_LEFT);

  vDrawHLine(iX + iHeight + 1, iY + 1, iWidth - 2);
  printf(BOX_BOTTOM_RIGHT);
}

void vDrawVLine(int iX, int iY, int iHeight){
  int ii;

  for(ii = 0; ii < iHeight; ii++){
    vGotoXY(iX + ii, iY);
    printf("%s", BOX_VERTICAL);
  }
}

void vDrawHLine(int iX, int iY, int iWidth){
  int ii;

  vGotoXY(iX, iY);
  for(ii = 0; ii < iWidth; ii++)
    printf("%s", BOX_HORIZONTAL);
}

void vUpdateHP(int iHP, int iMaxHP){
  if(iHP < 0) iHP = 0;
  if(iMaxHP < 0) iMaxHP = 0;
  if(iHP > iMaxHP) iHP = iMaxHP;

  printf("HP: %d/%d\n", iHP, iMaxHP);
    vPrintBar(iHP, iMaxHP, 20, BGCOLOR_RED);
}

void vUpdateStatus(const char *pszStatus){
  vClearLine();
  printf("STATUS: %s", pszStatus);
}

void vDrawInterface(void){
  vPrintSeparator('=', 32);
  vPrintCentered("RPG STATUS", 32, BGCOLOR_WHITE, TCOLOR_BLACK, ITALIC_TEXT);
  vPrintSeparator('=', 32);
  vPrintLine("", 1);


  printf("%-12s %9s\n", "Nome:", "Guerreiro");
  printf("%-12s %9d\n", "Nivel:", 5);
  printf("%-12s %9d\n", "Ataque:", 25);
  printf("%-12s %9d\n", "Defesa:", 12);
  
  vPrintLine("", 1);
}

void vShowCursor(int bShow){
  if(bShow)
    printf(CUR_SHOW);
  else
    printf(CUR_HIDE);
}

void vSaveCursor(void){
  printf(CUR_SAVE);
}

void vRestoreCursor(void){
  printf(CUR_RESTORE);
}

void vClearLine(void){
  printf(CLEAR_FULL_LINE);
}

void vClearScreen(void){
  printf(CLEAR_SCREEN);
  vGotoXY(1,1);
}

void vGotoXY(int iX, int iY){
  printf("%s%d;%d%s", ANSI_PREFIX_INIT, iX, iY, CUR_LINE_END);
}

void vPrintColor(const char *pszColor){
  printf("%s%s%s", ANSI_PREFIX_INIT, pszColor, ANSI_LINE_END);
}

int bIsBGColor(const char *pszColor){
  if(atoi(pszColor) < atoi(BGCOLOR_BLACK) || atoi(pszColor) > atoi(BGCOLOR_WHITE)) return 0;
  
  return 1;
}

int bIsTColor (const char *pszColor){
  if(atoi(pszColor) < atoi(TCOLOR_BLACK) || atoi(pszColor) > atoi(TCOLOR_WHITE)) return 0;
  
  return 1;
}

void vPrintFormatted(const char *pszText, ...){
  va_list args;
  const char *pszAttr;

  if (pszText == NULL)
    return;

  va_start(args, pszText);

  while ((pszAttr = va_arg(args, const char *)) != ANSI_END){
    if(bIsTColor(pszAttr) || bIsBGColor(pszAttr))
      vPrintColor(pszAttr);

    else
      printf(pszAttr);
  }

  va_end(args);
  printf(pszText);
  printf(ANSI_RESET);
}

void vPrintProgress(int iPercent){
  char szPercent[4];
  if(iPercent < 0) iPercent = 0;
  if(iPercent > 100) iPercent = 100;

  vPrintLine("Progresso: ", 0);
  snprintf(szPercent, sizeof(szPercent), "%d", iPercent);

  printf("%3.3s%%\r", szPercent);

  fflush(stdout);
}

void vPrintCentered(const char *pszText, int iWidth, ...){
  int iSpaces;
  va_list args;
  const char *pszAttr;

  if (pszText == NULL)
    return;

  va_start(args, iWidth);
  
  if(iWidth <= 0 || pszText == NULL) return;

  if((int)strlen(pszText) >= iWidth){
    while ((pszAttr = va_arg(args, const char *)) != ANSI_END) {
      if(bIsTColor(pszAttr) || bIsBGColor(pszAttr))
      vPrintColor(pszAttr);
      
      else
        printf(pszAttr);
    }
    printf("%s\n", pszText);
    va_end(args);
    printf(ANSI_RESET);
    return;
  }
  iSpaces = (iWidth - strlen(pszText)) / 2;

  for(; iSpaces > 0; iSpaces--)
    printf(" ");
  
  while ((pszAttr = va_arg(args, const char *)) != ANSI_END) {
    if(bIsTColor(pszAttr) || bIsBGColor(pszAttr))
      vPrintColor(pszAttr);
      
    else
      printf(pszAttr);
  }
  va_end(args);
  vPrintLine(pszText, 1);

  printf(ANSI_RESET);
}
void vPrintSeparator(char cChar, int iWidth){
  for(; iWidth >= 0; iWidth--)
    iWidth ? printf("%c", cChar) : printf("\n");
}

void vPrintLine(const char *pszText, int bNewLine){
  bNewLine ? printf("%s\n", pszText) : printf("%s", pszText);
}
void vPrintBar(int iValue, int iMax, int iWidth, const char *pszColor){
  double dFullBar;
  char *szBar;
  int ii = 0;
  
  if(!bIsBGColor(pszColor))return;

  if(iWidth > 100) iWidth = 100;
  if(iMax <= 0 || iWidth <= 0) return;

  if(iValue < 0) iValue = 0;
  if(iValue > iMax) iValue = iMax;

  szBar = calloc(iWidth + 3, sizeof(char));
  if(szBar == NULL) return;
 
  dFullBar = ((double)iValue / (double)iMax) * iWidth;    /*deu até fome*/

  szBar[ii] = '[';

  for(ii = 1; ii <= iWidth; ii++)
      szBar[ii] = ' ';

  szBar[ii] = ']';

  for(ii = 0; ii <= iWidth +1; ii++){
    printf(ANSI_RESET);
    if(ii <= dFullBar && szBar[ii] == ' ')
      vPrintColor(pszColor);
      
    printf("%c", szBar[ii]);
  }
  free(szBar);
}