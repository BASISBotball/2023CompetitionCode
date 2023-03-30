#include <kipr/wombat.h>
#include <stdbool.h>
int counter = 0;
int lineFollowIgnore(int timetotal, bool ignorebranch, int forward) { //timetotal is time in milliseconds, forward is 1 for forward -1 for back
    int threshold = 2000;
	int speed = forward * 200;
    int turnSpeed = 50;
    int timer = 0;
	while (timer < timetotal){ //while loop for while nothing is being hit by bumper
        if (counter == 2 && (get_create_lfcliff_amt() > threshold || get_create_rcliff_amt() > threshold))//TODO: FINISH
        {
            if (get_create_lfcliff_amt() > threshold && get_create_rcliff_amt() > threshold)//TODO: FINISH
        	{
            	counter = 0;
        	}
            else {
                counter = 1;}
        }
        if (counter == 1 && get_create_lfcliff_amt() > threshold && get_create_rcliff_amt() > threshold)//TODO: FINISH
        {
            counter = 0;
        }
		if (ignorebranch && (get_create_lcliff_amt() < threshold || get_create_rcliff_amt() < threshold)) {
            create_drive_straight(speed); 
            counter = 1;
            if (get_create_lcliff_amt() < threshold && get_create_rcliff_amt() < threshold) {
            	counter = 2;
            }
        }
        if (get_create_lfcliff_amt() < threshold && !(counter == 1 || counter == 2)) { //if the re is a black line
            while(get_create_lfcliff_amt() < threshold) { //while there is a black line, keep moving
                create_drive_direct(forward * (-turnSpeed), forward * turnSpeed);
            }
            create_stop();
		} else if (get_create_rfcliff_amt() < threshold && !(counter == 1 || counter == 2)) { //if there is a black line
            while(get_create_rfcliff_amt() < threshold) { //while there is a black line
                create_drive_direct(forward * turnSpeed, forward * (-turnSpeed)); //turning one wheel slowly to look for the black line
            }
            create_stop();
		} else { //else createbot keeps driving forwards
            create_drive_straight(speed); 
        }
        msleep(10); //increments of 10 milliseconds
        timer += 10;
	}
	//ao();
    //create_stop(); //stops createbot from moving
    //create_disconnect();
    return 0;
}

int main() {
    printf("Hello World\n");
    create_connect();
    printf("Connected\n");
    //wait_for_light(0);
    //shut_down_in(119);
    lineFollowIgnore(10000, true, -1);
    ao();
    create_stop(); //stops createbot from moving
    create_disconnect();
    return 0;
}
