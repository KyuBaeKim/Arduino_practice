

#include <Arduino.h>
// 매개변수 없는 void 함수에 대한 포인터를 button_callback_t로 정의
typedef void (*button_callback_t)(); // void(*button_callback_t)() 를 사용자 정의함
// 사용자 정의를 해줌으로써 button_callback_t가 타입 명이 된다.

class Button
{
protected:
    int pin;
    button_callback_t callback; // 사용자 정의에 의해 void(*callback)(); 이 된다.
public:
    Button(int pin);
    void setCallback(button_callback_t callback);
    int read();
    void check();
};
