#include "adc.h"
#include "defines.h"
#include "buttons.h"
#include "eink.h"
#include "zigbee.h"

int main (void)
{
    MCUInit();
    uint err_flag   = 0;
    pause_state     = 0;
    wheels_state    = 0;
    status          = 0;
    mode            = 0;
    robot_charge    = 0;
    upd_flag        = 0;
    
    EinkDrawStatic();
    while(1)
    {
        if(request_upd_flag)
        {
            SendRequest();
            WaitForAnsver();
            ParseAnswer();
            EinkRedraw();
            EinkDrawStatic();
            request_upd_flag = 0;
        }
        if(button_upd_flag)
        {
            SendConfig();
            WaitForAnsver();
            ParseAnswer();
            EinkRedraw();
            EinkDrawStatic();
            button_upd_flag = 0;
        }
    }
}