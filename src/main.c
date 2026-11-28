#include <stdio.h>
#include <unistd.h>
#include <terminal_utils.h>


int main(void){

  const char *pszName = "Guerreiro";
  int iLevel = 5;
  int iAttack = 25;
  int iDefense = 12;
  int iHP = 100;
  int iMaxHP = 100;
  int iWidth = 32;
  int iPercent;
  
  vDrawBox(TITLE_BOX_INITX, TITLE_BOX_INITY, 40, 3);
  vFillRect(2, 2, 38, 3, BGCOLOR_RED);
  vPrintLine("", 1);
  vSaveCursor();
  vGotoXY(3, 2);
  
  vPrintCentered("RPG STATUS", 38, BGCOLOR_RED, TCOLOR_GREEN, ITALIC_TEXT, ANSI_END);
  vRestoreCursor();
  vPrintLine("", 1);


  printf("%-12s %9s\n", "Nome:", pszName);
  printf("%-12s %9d\n", "Nivel:", iLevel);
  printf("%-12s %9d\n", "Ataque:", iAttack);
  printf("%-12s %9d\n", "Defesa:", iDefense);
  
  vPrintSeparator('-', iWidth);
  
  vPrintLine("", 1);
  vShowCursor(0);
  do{
    vSaveCursor();
    vClearLine();

    vUpdateHP(iHP, iMaxHP);
    
    //variavel = cor(iHP, iMaxHP)
    //vPrintBar(iHP, iMaxHP, 20, variavel);

    vPrintLine("", 1);
    vPrintLine("", 1);
    vPrintSeparator('-', iWidth);
  
    if(iHP == 100){
      vUpdateStatus("Pronto");
      iHP-=25;
    }else if(iHP == 75){
      vUpdateStatus("Dano recebido");
      iHP-=25;
    }else if(iHP == 50){
      vUpdateStatus("Em perigo");
      iHP += 40;
    }else if(iHP == 90){
      iHP += 1;
      vUpdateStatus("Curado");
    }

    vPrintLine("", 1);
    vPrintSeparator('=', iWidth);
    usleep(1000000);
    
    if(iHP <= 90)
      vRestoreCursor();

  }while(iHP <= 90);
  vShowCursor(1);

  vPrintLine("Carregando inventario...", 1);
  
  vShowCursor(0);

  for(iPercent = 0; iPercent <= 100; iPercent += 10){
    vPrintBar(iPercent, 100, 20, BGCOLOR_GREEN);
    vPrintProgress(iPercent);
    if (iPercent < 100)
    usleep(200000);
  }
  vShowCursor(1);

  vPrintLine("", 1);
  vPrintLine("Carregamento concluido!", 1);
  
  return 0;
}