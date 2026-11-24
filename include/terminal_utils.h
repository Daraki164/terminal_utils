#ifndef TERMINAL_UTILS_H
  #define TERMINAL_UTILS_H

  #define ANSI_RESET         "\033[0m"
  #define ANSI_END           ((const char *)0)
  #define TEXT_COLOR_BLACK   ((const char *)"\033[30m")
  #define TEXT_COLOR_RED     ((const char *)"\033[31m")
  #define TEXT_COLOR_GREEN   ((const char *)"\033[32m")
  #define TEXT_COLOR_YELLOW  ((const char *)"\033[33m")
  #define TEXT_COLOR_BLUE    ((const char *)"\033[34m")
  #define TEXT_COLOR_MAGENTA ((const char *)"\033[35m")
  #define TEXT_COLOR_CIAN    ((const char *)"\033[36m")
  #define TEXT_COLOR_WHITE   ((const char *)"\033[37m")
 
  #define BACKGROUND_COLOR_BLACK   ((const char *)"\033[40m")
  #define BACKGROUND_COLOR_RED     ((const char *)"\033[41m")
  #define BACKGROUND_COLOR_GREEN   ((const char *)"\033[42m")
  #define BACKGROUND_COLOR_YELLOW  ((const char *)"\033[43m")
  #define BACKGROUND_COLOR_BLUE    ((const char *)"\033[44m")
  #define BACKGROUND_COLOR_MAGENTA ((const char *)"\033[45m")
  #define BACKGROUND_COLOR_CIAN    ((const char *)"\033[46m")
  #define BACKGROUND_COLOR_WHITE   ((const char *)"\033[47m")

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
  void vPrintBar      (int iValue, int iMax, int iWidth);

#endif