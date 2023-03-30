#include <kipr/wombat.h>
#include <stdbool.h>

void collect_poms(int speed, int dir /* 0 is left; 1 is right */, pom_selector_left, pom_selector_right, pom_selector){
    int time = /*insert time here*/;
    if (dir == 1){
        set_servo_position(pom_selector, pom_selector_right);
        msleep(time);
    else {
        set_servo_position(pom_selector, pom_selector_left);
        msleep(time);
    }
    }
}

void deflect_poms(int speed, int dir /* 0 is left; 1 is right */, pom_deflector_left, pom_deflector_right, pom_deflector){
    int time = /*insert time here*/;
    if (dir == 1){
        set_servo_position(pom_deflector, pom_deflector_right);
        msleep(time);
    else {
        set_servo_position(pom_deflector, pom_deflector_left);
        msleep(time);
    }
    }
}

int poms(int pom_selector, int pom_deflector){
    int speed = /* enter speed value here */;
    int pom_deflector_neutral = /* enter pom deflector neutral position here */;
    int pom_selector_right= /* enter pom selector right position here */;
    int pom_selector_left= /* enter pom selector left position here */;
    int pom_deflector_right= /* enter pom deflector right position here */;
    int pom_deflector_left= /* enter pom deflector left position here */;
    create_connect();
    enable_servos();
    set_servo_position(pom_deflector, pom_deflector_neutral);
    set_servo_position(pom_selector, pom_selector_right);
    create_drive_direct(speed,speed);
    collect_poms(speed, 1, pom_selector_left, pom_selector_right, pom_selector);
    collect_poms(speed, 0, pom_selector_left, pom_selector_right, pom_selector);
    collect_poms(speed, 1, pom_selector_left, pom_selector_right, pom_selector);
    collect_poms(speed, 0, pom_selector_left, pom_selector_right, pom_selector);
    collect_poms(speed, 1, pom_selector_left, pom_selector_right, pom_selector);
    collect_poms(speed, 0, pom_selector_left, pom_selector_right, pom_selector);
    collect_poms(speed, 1, pom_selector_left, pom_selector_right, pom_selector);
    collect_poms(speed, 0, pom_selector_left, pom_selector_right, pom_selector);
    deflect_poms(speed, 1, pom_deflector_left, pom_deflector_right, pom_deflector);
    deflect_poms(speed, 0, pom_deflector_left, pom_deflector_right, pom_deflector);

}
