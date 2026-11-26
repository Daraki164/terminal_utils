#include <stdio.h>
#include <unistd.h>
#include <terminal_utils.h>


int main(void){

  const char *pszName = "Guerreiro";
  int iLevel = 5;
  int iAttack = 25;
  int iDefense = 12;
  int iHP = 75;
  int iMaxHP = 100;
  int iWidth = 32;
  int iPercent;

  vPrintSeparator('=', iWidth);
  vPrintCentered("RPG STATUS", iWidth);
  vPrintSeparator('=', iWidth);
  vPrintLine("", 1);

  printf("%-12s %9s\n", "Nome:", pszName);
  printf("%-12s %9d\n", "Nivel:", iLevel);
  printf("%-12s %9d\n", "Ataque:", iAttack);
  printf("%-12s %9d\n", "Defesa:", iDefense);

  vPrintLine("", 1);
  printf("HP: %d/%d\n", iHP, iMaxHP);
  vPrintBar(iHP, iMaxHP, 20, BGCOLOR_GREEN);
  vPrintLine("", 1);
  vPrintLine("", 1);

  vPrintSeparator('-', iWidth);
  vPrintLine("Carregando inventario...", 1);

  for(iPercent = 0; iPercent <= 100; iPercent += 10){
    vPrintBar(iPercent, 100, 20, BGCOLOR_RED);
    vPrintProgress(iPercent);
    if (iPercent < 100)
      usleep(500000);
  }

  vPrintLine("", 1);
  vPrintLine("Carregamento concluido!", 1);

  printf("%d %d\n", bIsTColor(TCOLOR_BLUE),bIsTColor(BGCOLOR_BLACK));
  printf("%d %d\n", bIsBGColor(TCOLOR_BLUE),bIsBGColor(BGCOLOR_BLACK));
 

  return 0;
}