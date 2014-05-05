#include<iostream>
#include<math.h>
#include "SDL/SDL.h"
#include <SDL/SDL_gfxPrimitives.h>
#include<vector>

//using namespace std;
SDL_Event event;
int up=0,right=1,down=2,left=3;
SDL_Surface* screen=SDL_SetVideoMode(700,500,32,0);

struct snakepart{
	int x,y;
	snakepart(int col,int row){
	x=col;
	y=row;}
};

struct Tirpart{
	int x,y;
	Tirpart(int corx,int cory){
	x=corx;
	y=cory;}
	
};


std::vector <snakepart> snake;
std::vector <Tirpart> tir;

class Snake{
public:
	void move(int dir){
	if(dir==down){
	snake.push_back(snakepart(snake[8].x,snake[8].y+5));
	filledEllipseRGBA(screen, snake[0].x, snake[0].y, 5, 5, 0, 0, 0, 255);
	snake.erase(snake.begin());}
	if(dir==up){
	snake.push_back(snakepart(snake[8].x,snake[8].y-5));
	filledEllipseRGBA(screen, snake[0].x, snake[0].y, 5, 5, 0, 0, 0, 255);
	snake.erase(snake.begin());}
	if(dir==right){
	snake.push_back(snakepart(snake[8].x+5,snake[8].y));
	filledEllipseRGBA(screen, snake[0].x, snake[0].y, 5, 5, 0, 0, 0, 255);
	snake.erase(snake.begin());}
	if(dir==left){
	snake.push_back(snakepart(snake[8].x-5,snake[8].y));
	filledEllipseRGBA(screen, snake[0].x, snake[0].y, 5, 5, 0, 0, 0, 255);
	snake.erase(snake.begin());}
	for(int i=0;i<9;i++){
        	filledEllipseRGBA(screen, snake[i].x, snake[i].y, 5, 5, 200, 100, 70, 255);
		SDL_Flip(screen);
        }}
};


class Map{
public:
	void draw(){
	lineRGBA(screen,700,420,470,420,255,255,255,255);
	lineRGBA(screen,470,420,470,170,255,255,255,255);
	lineRGBA(screen,470,170,260,170,255,255,255,255);
	lineRGBA(screen,260,170,260,420,255,255,255,255);
	lineRGBA(screen,260,420,120,420,255,255,255,255);
	lineRGBA(screen,120,420,120,30,255,255,255,255);
	lineRGBA(screen,120,30,700,30,255,255,255,255);
	lineRGBA(screen,700,380,510,380,255,255,255,255);
	lineRGBA(screen,510,380,510,130,255,255,255,255);
	lineRGBA(screen,510,130,220,130,255,255,255,255);
	lineRGBA(screen,220,130,220,380,255,255,255,255);
	lineRGBA(screen,220,380,160,380,255,255,255,255);
	lineRGBA(screen,160,380,160,70,255,255,255,255);
	lineRGBA(screen,160,70,700,70,255,255,255,255);	
}};

class Tower{
public:
	void draw(int x,int y){
	tir.push_back(Tirpart(x,y));
	filledEllipseRGBA(screen,x,y,10,10,0,255,0,100);
}	
};
 
int main(){	
	int qqq,count=0;
	for(int i=1;i<10;i++)
        snake.push_back(snakepart(700+5*i,400));
	Snake s;
	Map m;
	Tower t;
	while(true){
	if(SDL_PollEvent(&event))
	if(event.type==SDL_MOUSEBUTTONDOWN && tir.size()<=10)
	t.draw(event.motion.x,event.motion.y);
        if(event.type==SDL_QUIT)
	break;
	for(int i=0;i<tir.size();i++)
	if(pow(snake[snake.size()/2].x-tir[i].x,2)+pow(snake[snake.size()/2].y-tir[i].y,2)<1000)
	qqq++;
	if(qqq==5){
	qqq=0;
	snake.erase(snake.begin()+snake.size()-1);}
	m.draw();
	if(count<=50)
	s.move(left);
	else if(count<=100)
	s.move(up);
	else if(count<=150)
	s.move(left);
	else if(count<=200)
	s.move(down);
	else if(count<=220)
	s.move(left);
	else if(count<=290)
	s.move(up);
	else
	s.move(right);
	count++;
}}
