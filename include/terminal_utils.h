#ifndef TERMINAL_UTILS_H
  #define TERMINAL_UTILS_H

  #define ANSI_RESET         "\033[0m"
  #define ANSI_END           ((const char *)0)

  #define STRINGIFY(x) #x 
  #define TOSTRING(x) STRINGIFY(x) 

  #define  TCOLOR_BLACK   30
  #define  TCOLOR_RED     31
  #define  TCOLOR_GREEN   32
  #define  TCOLOR_YELLOW  33
  #define  TCOLOR_BLUE    34
  #define  TCOLOR_MAGENTA 35
  #define  TCOLOR_CIAN    36
  #define  TCOLOR_WHITE   37

  #define  BGCOLOR_BLACK   40
  #define  BGCOLOR_RED     41
  #define  BGCOLOR_GREEN   42
  #define  BGCOLOR_YELLOW  43
  #define  BGCOLOR_BLUE    44
  #define  BGCOLOR_MAGENTA 45
  #define  BGCOLOR_CIAN    46
  #define  BGCOLOR_WHITE   47

  #define COLOR_PREFIX ((const char *)"\033[")
  #define ANSI_LINE_END "m"

  #define TEXT_COLOR_BLACK   ((const char *)"\033["TOSTRING(TCOLOR_BLACK  )"m")
  #define TEXT_COLOR_RED     ((const char *)"\033["TOSTRING(TCOLOR_RED    )"m")
  #define TEXT_COLOR_GREEN   ((const char *)"\033["TOSTRING(TCOLOR_GREEN  )"m")
  #define TEXT_COLOR_YELLOW  ((const char *)"\033["TOSTRING(TCOLOR_YELLOW )"m")
  #define TEXT_COLOR_BLUE    ((const char *)"\033["TOSTRING(TCOLOR_BLUE   )"m")
  #define TEXT_COLOR_MAGENTA ((const char *)"\033["TOSTRING(TCOLOR_MAGENTA)"m")
  #define TEXT_COLOR_CIAN    ((const char *)"\033["TOSTRING(TCOLOR_CIAN   )"m")
  #define TEXT_COLOR_WHITE   ((const char *)"\033["TOSTRING(TCOLOR_WHITE  )"m")
 
  #define _BACKGROUND_COLOR(x)   ((const char *)"\033["TOSTRING(x)"m") 
  #define BACKGROUND_COLOR(x)   _BACKGROUND_COLOR(x) 

  #define BACKGROUND_COLOR_BLACK   ((const char *)"\033["TOSTRING(BGCOLOR_BLACK  )"m")
  #define BACKGROUND_COLOR_RED     ((const char *)"\033["TOSTRING(BGCOLOR_RED    )"m")
  #define BACKGROUND_COLOR_GREEN   ((const char *)"\033["TOSTRING(BGCOLOR_GREEN  )"m")
  #define BACKGROUND_COLOR_YELLOW  ((const char *)"\033["TOSTRING(BGCOLOR_YELLOW )"m")
  #define BACKGROUND_COLOR_BLUE    ((const char *)"\033["TOSTRING(BGCOLOR_BLUE   )"m")
  #define BACKGROUND_COLOR_MAGENTA ((const char *)"\033["TOSTRING(BGCOLOR_MAGENTA)"m")
  #define BACKGROUND_COLOR_CIAN    ((const char *)"\033["TOSTRING(BGCOLOR_CIAN   )"m")
  #define BACKGROUND_COLOR_WHITE   ((const char *)"\033["TOSTRING(BGCOLOR_WHITE  )"m")

  #define BOLD_TEXT      ((const char *)"\033[1m")
  #define DIM_TEXT       ((const char *)"\033[2m")
  #define ITALIC_TEXT    ((const char *)"\033[3m")
  #define UNDERLINE_TEXT ((const char *)"\033[4m")
  #define INVERTION_TEXT ((const char *)"\033[7m")
  #define TAXED_TEXT     ((const char *)"\033[9m")

  void vPrintFormatted(const char *pszText, ...);

  void vPrintColor    (int iColor);
  void vPrintLine     (const char *pszText, int bNewLine);
  void vPrintSeparator(char cChar, int iWidth);
  void vPrintCentered (const char *pszText, int iWidth, ...);
  void vPrintProgress (int iPercent);
  void vPrintBar      (int iValue, int iMax, int iWidth, int iColor);
  
  int bIsTColor (int iColor);
  int bIsBGColor(int iColor);

#endif