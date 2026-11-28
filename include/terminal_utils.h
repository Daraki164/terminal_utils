#ifndef TERMINAL_UTILS_H
  #define TERMINAL_UTILS_H

  #define ANSI_RESET  "\033[0m"
  #define ANSI_END   ((const char *)0)

  #define  TCOLOR_BLACK   "30"
  #define  TCOLOR_RED     "31"
  #define  TCOLOR_GREEN   "32"
  #define  TCOLOR_YELLOW  "33"
  #define  TCOLOR_BLUE    "34"
  #define  TCOLOR_MAGENTA "35"
  #define  TCOLOR_CIAN    "36"
  #define  TCOLOR_WHITE   "37"

  #define  BGCOLOR_BLACK   "40"
  #define  BGCOLOR_RED     "41"
  #define  BGCOLOR_GREEN   "42"
  #define  BGCOLOR_YELLOW  "43"
  #define  BGCOLOR_BLUE    "44"
  #define  BGCOLOR_MAGENTA "45"
  #define  BGCOLOR_CIAN    "46"
  #define  BGCOLOR_WHITE   "47"

  #define ANSI_PREFIX_INIT ((const char *)"\033[")
  #define ANSI_LINE_END "m"
  #define CUR_LINE_END "H"

  #define CUR_CLEAR_SCREEN_FINAL ((const char *)"\033[0J")
  #define CUR_CLEAR_SCREEN_INIT  ((const char *)"\033[1J")
  #define CLEAR_SCREEN           ((const char *)"\033[2J")
  #define CLEAR_FULL_LINE        ((const char *)"\033[2K")
  #define CUR_CLEAR_LINE_FINAL   ((const char *)"\033[K")
  #define CUR_SAVE               ((const char *)"\033[s")
  #define CUR_RESTORE            ((const char *)"\033[u")
  #define CUR_HIDE               ((const char *)"\033[?25l")
  #define CUR_SHOW               ((const char *)"\033[?25h")

  #define BOLD_TEXT      ((const char *)"\033[1m")
  #define DIM_TEXT       ((const char *)"\033[2m")
  #define ITALIC_TEXT    ((const char *)"\033[3m")
  #define UNDERLINE_TEXT ((const char *)"\033[4m")
  #define INVERTION_TEXT ((const char *)"\033[7m")
  #define TAXED_TEXT     ((const char *)"\033[9m")

  #define BOX_HORIZONTAL   "─"
  #define BOX_VERTICAL     "│"
  #define BOX_TOP_LEFT     "╭"
  #define BOX_TOP_RIGHT    "╮"
  #define BOX_BOTTOM_LEFT  "╰"
  #define BOX_BOTTOM_RIGHT "╯"

  #define TITLE_BOX_INITX 1 
  #define TITLE_BOX_INITY 1
  

  void vGotoXY       (int iX, int iY);
  void vClearScreen  (void);
  void vClearLine    (void);
  void vSaveCursor   (void);
  void vRestoreCursor(void);
  void vShowCursor   (int bShow);

  void vPrintFormatted(const char *pszText, ...);

  void vPrintLine     (const char *pszText, int bNewLine);
  void vPrintSeparator(char cChar, int iWidth);
  void vPrintCentered (const char *pszText, int iWidth, ...);
  void vPrintProgress (int iPercent);
  void vPrintBar      (int iValue, int iMax, int iWidth, const char *pszColor);
  void vPrintColor    (const char *pszColor);

  void vDrawInterface(void);
  void vUpdateHP     (int iHP, int iMaxHP);
  void vUpdateStatus (const char *pszStatus);

  void vDrawHLine(int iX, int iY, int iWidth);
  void vDrawVLine(int iX, int iY, int iHeight); 
  void vDrawBox  (int iX, int iY, int iWidth, int iHeight);
  
  int bIsTColor (const char *pszColor);
  int bIsBGColor(const char *pszColor);

#endif