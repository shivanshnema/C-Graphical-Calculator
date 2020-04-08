#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

union REGS in,out;
void main(){
	char *ch[3][3] = {"9","8","7","4","5","6","1","2","3"};
	char *ch2[2][2] = {"+","-","*","/"};
	int obtx = 120;
	int obty = 40;
	int obbx = 400;
	int obby = 320;
	int i,j,mov=40;
	int gd=DETECT,gm;
	int x,y,jmp=0;
	char ch3[100]= "";
	int valcount=0;
	double val[20]={0.0};
	int dec,sign;
	double rst;
	char op='\0';
	char str[2] = "\0";



	clrscr();

	initgraph(&gd,&gm,"C:\\TC\\BGI");
	f:
	outtextxy(obtx+10+5,obty+60-10,ch3);
	delay(400);

	e:
	in.x.ax = 1;
	int86(0X33,&in,&out);
	in.x.ax = 7;
	in.x.cx = 120;
	in.x.dx = 400;
	int86(0X33,&in,&out);
	in.x.ax = 8;
	in.x.cx = 40;
	in.x.dx = 320;
	int86(0X33,&in,&out);
	in.x.ax = 4;
	in.x.cx = obtx+10+5;
	in.x.dx = obty+10+5;
	int86(0X33,&in,&out);

	if(op!='\0'){
		//outtext(str);
		outtextxy(obtx+10+5,obty+60-10,ch3);
		delay(400);
	}

	delay(400);
	//setbkcolor(RED);
	//setcolor(WHITE);
	setfillstyle(1,WHITE);
	rectangle(obtx,obty,obbx,obby); //Outer Box
	rectangle(obtx+10,obty+10,obbx-10,obty+60); //Output Screen
	setfillstyle(1,LIGHTGREEN);
	bar((obtx+10),(obty+50+30),((obbx)/2-10+50+15),(obty+50+30+20));//Clear
	//setbkcolor(GREEN);

	setcolor(BLACK);
	outtextxy(((obtx+10)+((obbx)/2-10+50+15))/2,((obty+50+30)+(obty+50+30+20))/2,"C");
	setfillstyle(1,RED);
	bar(((obbx)/2-10+50+10+15),(obty+50+30),(obbx-10),(obty+50+30+20));//All Clear
	outtextxy((((obbx)/2-10+50+10+15)+(obbx-10))/2,((obty+50+30)+(obty+50+30+20))/2,"AC");
	setfillstyle(1,BLUE);
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			bar(obtx+10+(j*mov),(obty+50+30+20+20+(i*mov)),obtx+10+30+(j*mov),(obty+50+30+20+20+20+(i*mov)));//1-9 Digits
			outtextxy(((obtx+10+(j*mov))+(obtx+10+30+(j*mov)))/2,((obty+50+30+20+20+(i*mov)-5)+(obty+50+30+20+20+20+(i*mov)-5))/2,ch[i][j]);
		}
	}

	setfillstyle(1,DARKGRAY);
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			bar(((obbx)/2-10+50+10+15)+(j*50),obty+50+30+20+20+(i*60),((obbx)/2-10+50+10+15)+30+(j*50),obty+50+30+20+20+40+(i*60));//+,-,*,/
			outtextxy(((((obbx)/2-10+50+10+15)+(j*50))+(((obbx)/2-10+50+10+15)+30+(j*50)))/2,((obty+50+30+20+20+(i*60)-5)+(obty+50+30+20+20+40+(i*60)-5))/2,ch2[i][j]);

		}
	}
	setfillstyle(1,YELLOW);
	bar((obtx+10),(obty+50+30+20+20+20+80+20),((obbx)/2-10+50+15)/2+50+10,(obty+50+30+20+20+20+80+20+20));//.
	outtextxy(((obtx+10)+(((obbx)/2-10+50+15)/2+50+10))/2,((obty+50+30+20+20+20+80+20-5)+(obty+50+30+20+20+20+80+20+20-5))/2,".");
	bar(((obbx)/2-10+50+15)/2+50+10+10,(obty+50+30+20+20+20+80+20),((obbx)/2-10+50+15),(obty+50+30+20+20+20+80+20+20));//0
	outtextxy(((((obbx)/2-10+50+15)/2+50+10+10)+((obbx)/2-10+50+15))/2,((obty+50+30+20+20+20+80+20-5)+(obty+50+30+20+20+20+80+20+20-5))/2,"0");

	bar(((obbx)/2-10+50+10+15),(obty+50+30+20+20+20+80+20),(obbx-10),(obty+50+30+20+20+20+80+20+20));// =
	outtextxy((((obbx)/2-10+50+10+15)+(obbx-10))/2,((obty+50+30+20+20+20+80+20-5)+(obty+50+30+20+20+20+80+20+20-5))/2,"=");

	setcolor(WHITE);
	while(!kbhit()){
		in.x.ax = 3;
		int86(0X33,&in,&out);

		if(out.x.bx == 1){
			x = out.x.cx;
			y = out.x.dx;

			if(((x>=obtx+10) && (x<=obtx+10+30+80)) && ((y>=obty+50+30+20+20) && (y<=obty+50+30+20+20+20+80))){

				for(i=0;i<3;i++){
					for(j=0;j<3;j++){
						if(((x>=obtx+10+(j*mov)) && (x<=obtx+10+30+(j*mov))) && ((y>=obty+50+30+20+20+(i*mov)) && (y<=obty+50+30+20+20+20+(i*mov)))){
							//outtextxy((obtx+(10*jmp++)),obty+60-10,ch[i][j]);
							ch3[jmp] = ch[i][j][0];
							outtextxy(obtx+10+5,obty+60-10,ch3);
							jmp++;
							delay(400);
						}
					}
				}
			}

			//else if (((x>=265) && (x<=390)) && ((y>=280) && (y<=300))){
				//outtext("1");
				//delay(400);
		   //}

		   else if(((x>=(obbx)/2-10+50+10+15)&&(x<=(obbx-10))&&((y>=obty+50+30)&&(y<=obty+50+30+20)))){
				outtext("2");
				//for(i=jmp-1;i>=0;i--){
					//ch3[i] = '\0';
				//}
				//ch3[0] = '\0';
				//strcpy(ch3,"");
				memset(ch3,0,strlen(ch3));
				jmp=0;
				valcount = 0;
				op = '\0';
				cleardevice();
				goto e;

		   }

		   else if(((x>=obtx+10)&&(x<=(obbx)/2-10+50+15))&&((y>=obty+50+30)&&(y<=obty+50+30+20))){
				outtext("1");
				cleardevice();
				ch3[jmp-1]='\0';
				jmp--;
				goto f;

		   }

		   else if(((x>=((obbx/2)-10+50+10+15)) && (x<=(obbx-10))) && ((y>=obty+50+30+20+20+20+80+20) && (y<=obty+50+30+20+20+20+80+20+20))){
					//outtext("1");
					sscanf(ch3,"%lf",&val[valcount++]);
					//closegraph();
					//printf("%ld",val[valcount]);
					//getch();
					for(i=jmp-1;i>=0;i--){
					ch3[i] = '\0';
					}
					jmp=0;
					switch(op){
					case '+' : rst = val[0]+val[1];
							   break;
					case '-' : rst = val[0]-val[1];
							   break;
					case '*' : rst = val[0]*val[1];
							   break;
					case '/' : rst = val[0]/val[1];
							   break;
					}
				valcount=0;
				sprintf(ch3,"%lf",rst);
				cleardevice();
				goto e;

			}

			else if(((x>=(obbx)/2-10+50+10+15) && (x<=((obbx)/2-10+50+10+15)+30+100)) && ((y>=obty+50+30+20+20) && y<=(obty+50+30+20+20+40+120))){
				for(i=0;i<2;i++){
					for(j=0;j<2;j++){
						if(((x>=((obbx)/2-10+50+10+15)+(j*50)) && (x<=((obbx)/2-10+50+10+15)+30+(j*50))) && ((y>=obty+50+30+20+20+(i*60)) && (y<=obty+50+30+20+20+40+(i*60)))){
							op = ch2[i][j][0];
							//str[0] = op;
							sscanf(ch3,"%lf",&val[valcount++]);
							//closegraph();
							//printf("%ld",val[valcount]);
							//getch();
							for(i=jmp-1;i>=0;i--){
								ch3[i] = '\0';
							}
							jmp=0;

							cleardevice();
							goto e;
						}
					}
				}
			}

			else if(((x>=obtx+10) && (x<=((obbx)/2-10+50+15)/2+50+10)) && ((y>=obty+50+30+20+20+20+80+20) && (y<=obty+50+30+20+20+20+80+20+20))){
				ch3[jmp++] = '.';
				outtextxy(obtx+10+5,obty+60-10,ch3);
				delay(400);
			}

			else if(((x>=((obbx)/2-10+50+15)/2+50+10+10) && (x<=(obbx)/2-10+50+15)) && ((y>=obty+50+30+20+20+20+80+20) && (y<=obty+50+30+20+20+20+80+20+20))){
				ch3[jmp++] = '0';
				outtextxy(obtx+10+5,obty+60-10,ch3);
				delay(400);
			}

		   /*	else if(((x>=((obbx/2)-10+50+10+15)) && (x<=(obbx-10))) && ((y>=obty+50+30+20+20+20+80+20) && (y<=obty+50+30+20+20+20+80+20+20))){
					outtext("1");
					switch(op){
					case '+' : rst = val[0]+val[1];
							   break;
					}
				valcount=0;
				ptr = fcvt(rst,5,&dec,&sign);
				delay(1000);
				cleardevice();
				goto e;

			}*/

		   //else if (((x>=265) && (x<=390)) && ((y>=280) && (y<=300))){
				//outtext("1");
		   //}
		}
	}
	getch();
	closegraph();
}