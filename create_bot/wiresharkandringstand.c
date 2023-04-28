#include <kipr/wombat.h>

int threshold_A = 2000;
int threshold = 2000;

int lineFollowIgnore(int speed, int turnSpeed) {
    int threshold = 2000;
    //int time = 0;
    while ((get_create_lbump() == 0) && (get_create_rbump() == 0)){ //while loop for while nothing is being hit by bumper
        if (get_create_lfcliff_amt() < threshold) { //if the re is a black line
            while(get_create_lfcliff_amt() < threshold) { //while there is a black line, keep moving
                create_drive_direct(speed, speed + turnSpeed);
                msleep(1);
            }
            create_stop();
        } else if (get_create_rfcliff_amt() < threshold) { //if there is a black line
            while(get_create_rfcliff_amt() < threshold) { //while there isn't a black line
                create_drive_direct(speed + turnSpeed, speed); //turning one wheel slowly to look for the black line
                msleep(1);
            }
            create_stop();
        } else { //else createbot keeps driving forwards
            create_drive_straight(speed);
            msleep(1);
        }
    }
    create_stop(); //stops createbot from moving
    return 0;
}


void turn(int dir, int deg){ //dir is 1 for right, -1 for left		deg is = (degrees to turn)/90
    int speed = 200;
    create_drive_direct(dir*speed,-dir*speed);
    msleep(920*deg);
	create_stop();
}

void turn_until_line(int dir){ //dir is 1 for right, -1 for left
    int speed = 200;
    while (get_create_lfcliff_amt() > threshold_A && get_create_rfcliff_amt() > threshold_A){
        create_drive_direct(dir*speed,-dir*speed);
    }
    while (get_create_lfcliff_amt() < threshold_A || get_create_rfcliff_amt() < threshold_A){
        create_drive_direct(dir*0.25*speed,-dir*0.25*speed);
    }
    msleep(10);
    create_stop();

}

void smoothspeedup(int speed, int speed_current){
    if (speed < speed_current){
        while (speed_current > speed){
        speed_current -= 100;
        create_drive_straight(speed_current);
        msleep(100);
    }
    }
	else{
        while (speed_current < speed){
            speed_current += 100;
            create_drive_straight(speed_current);
            msleep(100);
        }
    }
}

int main()
{
    int speed = 200;
    create_connect();
    printf("Connected\n");
    //wait_for_light(0);
    //shut_down_in(119);
    enable_servos();
	set_servo_position(0, 300);
    create_drive_straight(-100);
    msleep(1000);
    //Go to black line bit
    create_drive_straight(200);
    while (get_create_lcliff_amt() > threshold && get_create_rcliff_amt() > threshold){
    	msleep(10);
    }
    msleep(400);
    create_stop();
    turn(-1,1);
    create_drive_straight(-100);
    msleep(1500);
    //Go to black line bit
    create_drive_straight(200);
    while (get_create_lcliff_amt() > threshold && get_create_rcliff_amt() > threshold){
    	msleep(10);
    }
    msleep(400);
    create_stop();
    turn(1,1);
	//turn_until_line(1);
    //Ring Stand bit
    set_servo_position(0, 852);
    smoothspeedup(300, 0);
    create_drive_straight(300);
    msleep(2500);
    smoothspeedup(0, 300);
    create_stop();
    set_servo_position(0, 1045);
    smoothspeedup(-300, 0);
    create_drive_straight(-300);
    msleep(2500);
    smoothspeedup(0, -300);
    create_stop();
	int rightanglewiresharkarm = 1420; //the final position for the servo of the wireshark arm to be in to grab the wireshark
    int armservo = 0; // the port of the wireshark arm servo
    set_servo_position(armservo, 0);
    msleep(1500);
    smoothspeedup(300, 0);
    create_drive_straight(300);
    msleep(5000);
    smoothspeedup(100,300);
    create_drive_straight(100);
    while ((get_create_lbump() == 0) && (get_create_rbump() == 0)){
        continue;
    }
    create_stop();
    smoothspeedup(-400, 0);
    create_drive_straight(-400);
    msleep(1500);
    smoothspeedup(0, -400);
    lineFollowIgnore(100, 40);
    create_drive_straight(-100);
    msleep(300);
    turn(-1,1);
    set_servo_position(armservo, rightanglewiresharkarm);
    //create_drive_straight(-100);
    msleep(1000);
    turn(-1, 1);
	lineFollowIgnore(200, 15);
    create_drive_straight(-100);
    msleep(1200);
	while (get_create_rcliff_amt() > threshold_A){
        create_drive_direct(-0.25*200,0.25*200);

    }
    msleep(1200);
    create_stop();

    msleep(4000);
    turn(-1, 1);
    create_drive_straight(200);
    msleep(3000);
    create_stop();
    turn(1,1);
    create_drive_straight(200);
    msleep(1000);
    create_stop(); //stops createbot from moving
    create_disconnect();
    return 0;
}
