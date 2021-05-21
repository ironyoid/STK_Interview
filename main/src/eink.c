/**
  ******************************************************************************
  * @file    eink.c
  * @author  Pichugin Nickita
  * @version V0.0.1
  * @date    21.05.2021
  * @brief   This file contains all the functions for work with e-ink display
  *         ported from oficial arduino c++ lib.
  ******************************************************************************
  */
 #include "eink.h"
 #include "defines.h"
#include "images.h"
/**
 *  @brief: basic function for sending commands
 */
static void SendCommand(uint8_t command)
{
	DC_LOW;
	SPI_SendDataByte(command);
}

/**
 *  @brief: basic function for sending data
 */
static void SendData(uint8_t data)
{
	DC_HIGH;
	SPI_SendDataByte(data);
}

/**
 *  @brief: Wait until the busy_pin goes HIGH
 */
static void WaitUntilIdle(void)
{
	while(BUSY_PIN == 1) {      //LOW: idle, HIGH: busy
		delay_ms_sp(100);
	}
	delay_ms_sp(200);
}

void HDirInit(void)
{
	Reset();

	WaitUntilIdle();
	SendCommand(0x12);  //SWRESET
	WaitUntilIdle();

	SendCommand(0x01); //Driver output control
	SendData(0xC7);
	SendData(0x00);
	SendData(0x01);

	SendCommand(0x11); //data entry mode
	SendData(0x01);

	SendCommand(0x44); //set Ram-X address start/end position
	SendData(0x00);
	SendData(0x18);    //0x0C-->(18+1)*8=200

	SendCommand(0x45); //set Ram-Y address start/end position
	SendData(0xC7);   //0xC7-->(199+1)=200
	SendData(0x00);
	SendData(0x00);
	SendData(0x00);

	SendCommand(0x3C); //BorderWavefrom
	SendData(0x01);

	SendCommand(0x18);
	SendData(0x80);

	SendCommand(0x22); // //Load Temperature and waveform setting.
	SendData(0XB1);
	SendCommand(0x20);

	SendCommand(0x4E);   // set RAM x address count to 0;
	SendData(0x00);
	SendCommand(0x4F);   // set RAM y address count to 0X199;
	SendData(0xC7);
	SendData(0x00);
	WaitUntilIdle();
	/* EPD hardware init end */
}

/**
 *  @brief: module reset.
 *          often used to awaken the module in deep sleep,
 *          see Epd::Sleep();
 */
static void Reset(void)
{
	RST_HIGH;
	delay_ms_sp(200);
	RST_LOW;
	delay_ms_sp(10);
	RST_HIGH;
	delay_ms_sp(200);
}
/**
 *  @brief: module eink.
 */
void Clear(void)
{
	int w, h;
	w = (EPD_WIDTH % 8 == 0)? (EPD_WIDTH / 8 ): (EPD_WIDTH / 8 + 1);
	h = EPD_HEIGHT;
 
	SendCommand(0x24);
	for (int j = 0; j < h; j++) {
		for (int i = 0; i < w; i++) {
			SendData(0xff);
		}
	}
	DisplayFrame();
}

/**
 *  @brief: update the display
 *          there are 2 memory areas embedded in the e-paper display
 *          but once this function is called,
 *          the the next action of SetFrameMemory or ClearFrame will
 *          set the other memory area.
 */
void DisplayFrame(void)
{
	//DISPLAY REFRESH
	SendCommand(0x22);
	SendData(0xF7);
	SendCommand(0x20);
	WaitUntilIdle();
}

void SetFrameMemory(
        const unsigned char* image_buffer,
        int x,
        int y,
        int image_width,
        int image_height
)
{
	int x_end;
	int y_end;
	
	RST_LOW;
	delay_ms_sp(10);
	RST_HIGH;
	delay_ms_sp(10);
	SendCommand(0x3c);
	SendData(0x80);

	if (
	        image_buffer == NULL ||
	        x < 0 || image_width < 0 ||
	        y < 0 || image_height < 0
	) {
		return;
	}
	/* x point must be the multiple of 8 or the last 3 bits will be ignored */
	x &= 0xF8;
	image_width &= 0xF8;
	if (x + image_width >= this->width) {
		x_end = this->width - 1;
	} else {
		x_end = x + image_width - 1;
	}
	if (y + image_height >= this->height) {
		y_end = this->height - 1;
	} else {
		y_end = y + image_height - 1;
	}
	SetMemoryArea(x, y, x_end, y_end);
	SetMemoryPointer(x, y);
	SendCommand(0x24);
	/* send the image data */
	for (int j = 0; j < y_end - y + 1; j++) {
		for (int i = 0; i < (x_end - x + 1) / 8; i++) {
			SendData(image_buffer[i + j * (image_width / 8)]);
		}
	}
}

/**
 *  @brief: private function to specify the memory area for data R/W
 */
static void SetMemoryArea(int x_start, int y_start, int x_end, int y_end)
{
	SendCommand(0x44);
	/* x point must be the multiple of 8 or the last 3 bits will be ignored */
	SendData((x_start >> 3) & 0xFF);
	SendData((x_end >> 3) & 0xFF);
	SendCommand(0x45);
	SendData(y_start & 0xFF);
	SendData((y_start >> 8) & 0xFF);
	SendData(y_end & 0xFF);
	SendData((y_end >> 8) & 0xFF);
}

/**
 *  @brief: private function to specify the start point for data R/W
 */
static void SetMemoryPointer(int x, int y)
{
	SendCommand(0x4e);
	/* x point must be the multiple of 8 or the last 3 bits will be ignored */
	SendData((x >> 3) & 0xFF);
	SendCommand(0x4F);
	SendData(y & 0xFF);
	SendData((y >> 8) & 0xFF);
	WaitUntilIdle();
}

/**
 *  @brief: After this command is transmitted, the chip would enter the
 *          deep-sleep mode to save power.
 *          The deep sleep mode would return to standby by hardware reset.
 *          The only one parameter is a check code, the command would be
 *          executed if check code = 0xA5.
 *          You can use Epd::Init() to awaken
 */
void Sleep()
{
	SendCommand(0x10); //enter deep sleep
	SendData(0x01);
	delay_ms_sp(200);
    RST_LOW;
}

void EinkRedrawMode(void)
{
    switch(mode)
    {
        case WAIT:
            SetFrameMemory(wait_ico, 68, 68, 64, 64);
        break;
        case IN_PROGRESS:
            SetFrameMemory(in_progress_ico, 68, 68, 64, 64);
        break;
        case DISINFECTION:
            SetFrameMemory(desinfection_ico, 68, 68, 64, 64);
        break;
        case FINISH:
            SetFrameMemory(finish_ico, 68, 68, 64, 64);
        break;
        case PAUSE:
            SetFrameMemory(pause_ico, 68, 68, 64, 64);
        break;
    }
    DisplayFrame();
}

void EinkRedrawStatus(void)
{
    
    switch(status)
    {
        case OK:
            SetFrameMemory(ok_ico, 130, 160, 64, 20);
        break;
        case ERR_1:
            SetFrameMemory(err1_ico, 130, 160, 64, 20);
        break;
        case ERR_2:
            SetFrameMemory(err2_ico, 130, 160, 64, 20);
        break;
        case ERR_3:
            SetFrameMemory(err3_ico, 130, 160, 64, 20);
        break;
        case ERR_4:
            SetFrameMemory(err4_ico, 130, 160, 64, 20);
        break;
    }
    DisplayFrame();
}

void EinkDrawStatic(void)
{
    SetFrameMemory(robot_ico, 5, 5, 16, 16);
    DisplayFrame();
    SetFrameMemory(controller_ico, 179, 5, 16, 16);
    DisplayFrame();
}

void EinkRedrawControllerCharge(uint8_t* charge)
{
    uint8_t i = 0;
    uint8_t x_step = 5;
    while((charge[i] != '\0') && (i < 4))
    {
        SetFrameMemory(numbers[(charge[i] - '0')], x_step, 25, 16, 16);
        DisplayFrame();
        x_step += 18;
        i++;
    }  
}

void EinkRedrawRobotCharge(uint8_t* charge)
{
    uint8_t i = 0;
    uint8_t x_step = 141;
    while((charge[i] != '\0') && (i < 4))
    {
        SetFrameMemory(numbers[(charge[i] - '0')], x_step, 25, 16, 16);
        DisplayFrame();
        x_step += 18;
        i++;
    }  
}