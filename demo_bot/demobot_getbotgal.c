#include <kipr/wombat.h>
int main()
{
    enable_servos();
    set_servo_position(0, 910); //lower
    set_servo_position(3, 1200); //hook
    // wait_for_light(9);
    //shut_down_in(119);
    set_servo_position(3,40);
    motor(0,50);
    motor(3,-51);
    msleep(678.5);
    while ((digital(0) == 0) || (digital(1) == 0)) {
        if(analog (0) < 2500 && analog (1) < 2500)
        {
            motor(0,100);
            motor(3,100);
        }
        else if(analog (0) > 2500 && analog (1) < 2500)  {
            motor(0,25);
            motor(3,100);
        }
        else if(analog (0) < 2500 && analog (1) > 2500)  {
            motor(0,100);
            motor(3,25);
        }
    }
    set_servo_position(3, 1599);
    msleep(1000);
    motor(0,-50);
    motor(3,-50);
    msleep(2000);
    motor(0,75);
    motor(3,-75);
    msleep(500);
    while(analog(1) < 2500) {
        motor(0,25);
        motor(3,-25);
    }
    cmpc(0);
    cmpc(3);
    motor(0,75);
    motor(3,75);
    msleep(3000);
    set_servo_position(0,1250);
    msleep(1000);
    while(analog(1) < 2500) {
        motor(0,-75);
        motor(3,75);
    }
    while(analog(1) > 2500) {
        motor(0,-100);
        motor(3,100);
    }
    motor(0,-100);
    motor(3,100);
    msleep(400);
    set_servo_position(0, 910);
    set_servo_position(3,40);
    while ((digital(0) == 0) && (digital(1) == 0)) {
        motor(0,100);
        motor(3,100);
    }
    return 0;
}

int ignoreBranch() {
    while (digital(0) == 0) {
        while(analog (0) < 2500 && analog (1) < 2500)
        {
            motor(0,100);
            motor(3,100);
        }
        while(analog (0) > 2500 && analog (1) < 2500)  {
            motor(0,75);
            motor(3,100);
        }
        while(analog (0) < 2500 && analog (1) > 2500)  {
            motor(0,100);
            motor(3,75);
        }
    }
    return 0;
}
