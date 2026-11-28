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
  
  vDrawBox(TITLE_BOX_INITX, FIRST_COL, 40, 1);
  
  vPrintLine("", 1);
  vSaveCursor();
  vGotoXY(2, 2);
  
  vPrintCentered("RPG STATUS", 38, BGCOLOR_RED, TCOLOR_GREEN, ITALIC_TEXT, ANSI_END);
  vRestoreCursor();
  vPrintLine("", 1);

  vDrawBox(STATUS_BOX_INITX, FIRST_COL, 24, 4);
  vPrintLine("", 1);
  vSaveCursor();

  vGotoXY(STATUS_BOX_INITX + 1, FIRST_COL + 1);
  printf("%-12s %9s\n", "Nome:", pszName);
  
  vGotoXY(STATUS_BOX_INITX + 2, FIRST_COL + 1);
  printf("%-12s %9d\n", "Nivel:", iLevel);
  
  vGotoXY(STATUS_BOX_INITX + 3, FIRST_COL + 1);
  printf("%-12s %9d\n", "Ataque:", iAttack);
  
  vGotoXY(STATUS_BOX_INITX + 4, FIRST_COL + 1);
  printf("%-12s %9d\n", "Defesa:", iDefense);

  vRestoreCursor();
   
  vPrintLine("", 1);
  vShowCursor(0);
  
  do{
    vSaveCursor();

    vGotoXY(HP_BOX_INITX + 1, HP_BOX_COL + 1);
    printf(CUR_CLEAR_LINE_FINAL);
    
    vUpdateHP(iHP, iMaxHP, HP_BOX_INITX + 1, HP_BOX_COL + 1);
    vDrawBox(HP_BOX_INITX, HP_BOX_COL, 26, 2);
    
    //variavel = cor(iHP, iMaxHP)
    //vPrintBar(iHP, iMaxHP, 20, variavel);

    vPrintLine("", 1);
    vPrintLine("", 1);
    vPrintLine("", 1);
  
    if(iHP == 100){
      vGotoXY(HP_BOX_INITX + 5, HP_BOX_COL + 1);
      vUpdateStatus("Pronto");
      vDrawBox(HP_BOX_INITX + 4, HP_BOX_COL, 26, 1);
      iHP-=25;
    }else if(iHP == 75){
      vGotoXY(HP_BOX_INITX + 5, HP_BOX_COL + 1);
      vUpdateStatus("Dano recebido");
      vDrawBox(HP_BOX_INITX + 4, HP_BOX_COL, 26, 1);
      iHP-=25;
    }else if(iHP == 50){
      vGotoXY(HP_BOX_INITX + 5, HP_BOX_COL + 1);
      vUpdateStatus("Em perigo");
      vDrawBox(HP_BOX_INITX + 4, HP_BOX_COL, 26, 1);
      iHP += 40;
    }else if(iHP == 90){
      vGotoXY(HP_BOX_INITX + 5, HP_BOX_COL + 1);
      iHP += 1;
      vUpdateStatus("Curado");
      vDrawBox(HP_BOX_INITX + 4, HP_BOX_COL, 26, 1);
    }

    vPrintLine("", 1);
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