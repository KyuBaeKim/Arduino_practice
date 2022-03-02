#include "Button.h"

Button::Button(int pin): pin(pin) //멤버 초기화 리스트 <- 생성자에서만 쓸 수  있음
{
    pinMode(pin, INPUT_PULLUP);
    callback = NULL;
}

void Button::setCallback(button_callback_t callback)
{
    this -> callback = callback; // this를 이용하여 멤버변수로 사용 this가 없으면 지역변수가 된다.
}

int Button::read()
{
    return !digitalRead(pin);
}

// polling 방식으로 버튼이 눌렷는지 체크
void Button::check()
{
    bool o_sw , n_sw;

    o_sw = read();
    delay(10); // 디바운스를 위한 지연시간
    n_sw = read();

    if(o_sw == 0 && n_sw == 1){ //버튼을 누른 시점
    
    if(callback != NULL){ 
        callback(); // 버튼의 일반화
    }
    }
}
