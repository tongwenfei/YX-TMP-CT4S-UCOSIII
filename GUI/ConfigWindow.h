#ifndef __CONFIG_WINDOW__H
#define __CONFIG_WINDOW__H
#include "gui.h"

extern uint8_t Config_Num;
void Disp_ConfigWindow(void);
void Disp_TimeSetWindow(void);
void Disp_BaudSetWindow(void);
void Config_Select(void);
void Config_Enter(void);
void ConfigSub_Select(void);
#endif