#include <raylib.h>
#include <raymath.h>
#include <math.h>
#include "background.h"

#include "save.h"

#include <sys/cdefs.h>
#include <arch/types.h>
#include <dc/fmath_base.h>
#include <arch/arch.h>


#define MAX_TRIANGLES 8

Texture2D saveImage;
Texture2D bgExclaim;

static float clSin;
Color blueLerp;
Color redLerp;
Color yellowLerp;



void init_background(){
    static bool ranOnce = 0;
    if(ranOnce == 0){
        saveImage = LoadTexture("rd/test2.png");
        bgExclaim = LoadTexture("rd/exclaim.png");
        ranOnce = 1;
    }
    return;
}


void saveSine(){
    static float rotation;
    static float time;
    static float speed;
    time += GetFrameTime();
    speed = fabsf(sinf(time)) * 9.012f;
    DrawTexturePro(saveImage,
    (Rectangle){0, 0, (float)saveImage.width, (float)saveImage.height}, 
    (Rectangle){ 535, 370, (float)saveImage.width/2, (float)saveImage.height/2 },
    (Vector2){ saveImage.width/4, saveImage.height/4 },
    //I hate that raylib texture origin vector2 works this way lol
    rotation,
    WHITE);
    rotation = (rotation + speed);
}



void colorLerping(){
    
    clSin = (sinf(GetTime()) + 1.0f) / 2.0f;

    blueLerp = ColorLerp(BLUE, SKYBLUE, clSin);
    redLerp = ColorLerp(RED, ORANGE, clSin);
    yellowLerp = ColorLerp(YELLOW, WHITE, clSin);
    
    
}


void draw_background() {
    init_background();
    colorLerping();
    ClearBackground(redLerp);
    DrawRectangle(0,0,200,480,blueLerp);
    static float triY = 0.f;
    static float spacing = 79.f;
    const float speed = 2.f;
    // if you change the above you'll have to fix a graphical issue
    // i am too lazy to come up with a better solution :pregnant_man:
    for (int i=0;i<MAX_TRIANGLES;i++) {
        float newTriY = triY+i*spacing;
        newTriY=fmodf(newTriY,480+72)-72;
        Vector2 pos1={260.0f,newTriY+36.f},pos2={200.0f,newTriY},pos3={200.0f,newTriY+72.f};
        DrawTriangle((Vector2){pos1.x,pos1.y+7},(Vector2){pos2.x,pos2.y+7},(Vector2){pos3.x,pos3.y+7},yellowLerp);
        DrawTriangle(pos1,pos2,pos3,blueLerp); 
    }
    triY += speed;
    if (isSaving){
        saveSine();
        DrawText("Loading...", 470, 400, 32, BLACK);
    };
}

void draw_rain(){

}