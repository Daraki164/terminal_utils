#ifndef TERMINAL_UTILS_H
  #define TERMINAL_UTILS_H

  void vPrintLine(const char *pszText, int bNewLine);
  void vPrintSeparator(char cChar, int iWidth);
  void vPrintCentered(const char *pszText, int iWidth);
  void vPrintProgress(int iPercent);
  void vPrintBar(int iValue, int iMax, int iWidth);

#endif