
#include "Display_ST7789.h"
#include "LVGL_Driver.h"
#include "LVGL_Example.h"


float i;
void setup()
{       

  LCD_Init();
  Lvgl_Init();
  init_screen();
  i=0;
}

void loop()
{
i+=.1;
show_screen(i);
lv_timer_handler();
delay(100);

if(i>40)i=0;
}
