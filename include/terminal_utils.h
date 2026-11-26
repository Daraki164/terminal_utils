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

  #define COLOR_PREFIX ((const char *)"\033[")
  #define ANSI_LINE_END "m"

 
  #define BOLD_TEXT      ((const char *)"\033[1m")
  #define DIM_TEXT       ((const char *)"\033[2m")
  #define ITALIC_TEXT    ((const char *)"\033[3m")
  #define UNDERLINE_TEXT ((const char *)"\033[4m")
  #define INVERTION_TEXT ((const char *)"\033[7m")
  #define TAXED_TEXT     ((const char *)"\033[9m")

  void vPrintFormatted(const char *pszText, ...);

  void vPrintLine     (const char *pszText, int bNewLine);
  void vPrintSeparator(char cChar, int iWidth);
  void vPrintCentered (const char *pszText, int iWidth, ...);
  void vPrintProgress (int iPercent);
  void vPrintBar      (int iValue, int iMax, int iWidth, const char *pszColor);
  void vPrintColor    (const char *pszColor);
  
  int bIsTColor (const char *pszColor);
  int bIsBGColor(const char *pszColor);

#endif