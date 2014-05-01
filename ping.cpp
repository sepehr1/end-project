#include <iostream>
#include "SDL/SDL.h"
#include <SDL/SDL_gfxPrimitives.h>

using namespace std;
SDL_Event event;
int main()
{
    SDL_Surface* screen = SDL_SetVideoMode(800, 600 ,32, 0);
    int first=0,second=0,end=0;
while(true){
	int x=10,y=10,dx=1,dy=1;
	int a1=0,a2=100,a3=10,a4=200;
        int b1=790,b2=100,b3=800,b4=200;
	boxRGBA(screen,a1,a2,a3,a4,0,0,255,255);
        boxRGBA(screen,b1,b2,b3,b4,0,0,255,255);
	if(end==1)
	break;
while(true)
    {
	if((x==790 && (y>=b2 && y<=b4))||(x==10 &&(y>=a2 && y<=a4)))
	dx*=-1;
	if(y<=0 || y>=600)
	dy*=-1;
	if(SDL_PollEvent(&event))
        if(event.type==SDL_QUIT){
	end=1;
        break;} 
	if(event.type==SDL_KEYDOWN){
        if(event.key.keysym.sym==SDLK_UP && b2>0){
        boxRGBA(screen,b1,b2,b3,b4,0,0,0,255);
	b2-=10;b4-=10;}
	if(event.key.keysym.sym==SDLK_DOWN && b4<600){
	boxRGBA(screen,b1,b2,b3,b4,0,0,0,255);
	b2+=10;b4+=10;}
	if(event.key.keysym.sym==SDLK_w && a2>0){
        boxRGBA(screen,a1,a2,a3,a4,0,0,0,255);
        a2-=10;a4-=10;}
	if(event.key.keysym.sym==SDLK_s && a4<600){
        boxRGBA(screen,a1,a2,a3,a4,0,0,0,255);
        a2+=10;a4+=10;}}
       
	boxRGBA(screen,a1,a2,a3,a4,0,0,255,255);
        boxRGBA(screen,b1,b2,b3,b4,0,0,255,255);
    	filledEllipseRGBA(screen, x, y, 5, 5, 0, 0, 0, 255);
	x+=dx*5;
        y+=dy*5;
        filledEllipseRGBA(screen, x, y, 5, 5, 200, 100, 70, 255);
	SDL_Flip(screen);
        SDL_Delay(5);
	if(x<0){
        first++;
	boxRGBA(screen,a1,a2,a3,a4,0,0,0,255);
        boxRGBA(screen,b1,b2,b3,b4,0,0,0,255);
        break;}
        if(x>800){
        second++;
	boxRGBA(screen,a1,a2,a3,a4,0,0,0,255);
        boxRGBA(screen,b1,b2,b3,b4,0,0,0,255);
        break;}
}
 	if(first==11){
	cout<<"first win\n";
	break;}
	if(second==11){
	cout<<"second win\n";
	break;}	
}
	return 0;
}
