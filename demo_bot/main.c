#include <kipr/wombat.h>
void follow_Line() {// 2 line-following sensor
	  	while (analog(1) > 0 && analog(0) > 0) {
            while(analog(1) > 3200) {
                motor(1,-100);
                motor(0,100);
            }
            while(analog(1) > 3200) {
                    motor(1,100);
                    motor(0,-100);
            } 
            while(analog(1)<300&&analog(0)<300){
                motor(0,80);
                motor(1,80);
        	}
		}
}

void extend_claw(){
    motor(3,100);
    msleep(6500);
}

void close_claw(){
    motor(3,-100);
    msleep(6500);
}

void Forward(int speed, int time){
    motor(0,speed);
    motor(3,speed);
    msleep(time);
}

void Backward(int speed, int time){
    motor(0,speed);
    motor(3,speed);
    msleep(time);
}

int main(){
	follow_Line();
    Forward(100,500);
    follow_Line();
    Backward(-100,500);
    extend_claw();
    close_claw();
}