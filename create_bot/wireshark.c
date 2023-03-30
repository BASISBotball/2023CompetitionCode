#include <kipr/wombat.h>

void turn(int dir, int deg){ //dir is 1 for right, -1 for left		deg is = (degrees to turn)/90
    int speed = 200;
    create_drive_direct(dir*speed,-dir*speed);
    msleep(950*deg);
	create_stop(); 
}

int main(){
    int rightanglewiresharkarm = 1420; //the final position for the servo of the wireshark arm to be in to grab the wireshark
    int armservo = 0; // the port of the wireshark arm servo
    int speed = 1500;
    printf("Hello World\n");
    create_connect();
    printf("Connected\n");  
    //wait_for_light(0);
    //shut_down_in(119);
    enable_servos();
    set_servo_position(armservo, 0);
    //create_drive_straight(speed);
    msleep(1500);
    while ((get_create_lbump() == 0) && (get_create_rbump() == 0)){
        continue;
    }
    turn(-1,1);
    set_servo_position(armservo, rightanglewiresharkarm);
    //create_drive_straight(-100);
    msleep(4000);
    turn(-1,1);
    ao();
    create_stop(); //stops createbot from moving
    create_disconnect();
    return 0;
    }