#pragma once

#include "raylib.h"
#include <math.h>
#include <stdlib.h> 
#include <time.h>
#include "raymath.h"
////TEMP/////////



/////////////////

#define MAX_FRAME_SPEED     15
#define MIN_FRAME_SPEED      1
#define screenWidth 1280
#define screenHeight 720
#define NUM_FRAMES  3 

typedef enum GameScreen { LOGO = 0, TITLE, First_level, Cutscena_Lv2, Second_level, ENDING } GameScreen;
typedef enum Button { Button_resume, Button_settings, Button_main_menu, Button_quit} Button;

typedef struct {
    int x;
    int y;
    Vector2 size;
    int char_fall_vel;
} characters;

typedef struct {
    Rectangle sourceRec;
    Rectangle destRec;
    Vector2 origin;
} GameObject;

typedef struct
{
    float Lifetime;
}Timer;

void colision_checks(Rectangle col1,Rectangle col2,Rectangle o1, Rectangle o2,float array []);

