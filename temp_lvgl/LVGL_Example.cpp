#include "LVGL_Example.h"





void IRAM_ATTR example1_increase_lvgl_tick(lv_timer_t * t);
/**********************
 *  STATIC VARIABLES
 **********************/


static lv_obj_t * tv;

static lv_obj_t * label;
static lv_obj_t * temp1;
static lv_obj_t * temp2;

static lv_timer_t * auto_step_timer;


void init_screen(){

tv = lv_obj_create(NULL); // New screen

lv_obj_set_style_bg_color(tv, lv_color_hex(0x000000), LV_PART_MAIN);
lv_obj_set_style_text_color(tv, lv_color_hex(0xffffff), LV_PART_MAIN);

lv_obj_set_scrollbar_mode(tv , LV_SCROLLBAR_MODE_OFF); // no scrollbar
lv_scr_load(tv);

// https://lvgl.io/tools/fontconverter
LV_FONT_DECLARE(switz222);
LV_FONT_DECLARE(switz180);

  
temp1 = lv_label_create(tv);
lv_label_set_text(temp1, "88");
lv_obj_align(temp1, LV_ALIGN_BOTTOM_RIGHT, -102, 0);
lv_obj_set_style_text_font(temp1, &switz222, 0);


temp2 = lv_label_create(tv);
lv_label_set_text(temp2, "8");
lv_obj_align(temp2, LV_ALIGN_BOTTOM_RIGHT, 7, -1);
lv_obj_set_style_text_font(temp2, &switz180, 0);


// Dot between number
static lv_obj_t * my_Cir = lv_obj_create(tv);
lv_obj_set_size(my_Cir , 16, 16);
lv_obj_set_pos(my_Cir , 217, 156);

}



void show_screen(float temp){
	
int tempint = int(temp);
int temp_rest = (temp-tempint)*10+.1;


char buffer1[4];
char buffer2[4];
itoa(tempint, buffer1, 10);
itoa(temp_rest, buffer2, 10);

lv_label_set_text( temp1, buffer1);
lv_label_set_text( temp2, buffer2);
}

