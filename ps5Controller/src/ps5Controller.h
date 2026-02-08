#ifndef ps5Controller_h
#define ps5Controller_h

#include "Arduino.h"

extern "C" {
#include "ps5.h"
}

class ps5Controller {
 public:
  typedef void (*callback_t)();

  ps5_t data;
  ps5_event_t event;
  ps5_cmd_t output;

  ps5Controller();

  bool begin();
  bool begin(const char* mac);
  void end();

  bool isConnected();

  void setLed(uint8_t r, uint8_t g, uint8_t b);
  void setRumble(uint8_t small, uint8_t large);
  void setFlashRate(uint8_t onTime, uint8_t offTime);

  void sendToController();

  void attach(callback_t callback);
  void attachOnConnect(callback_t callback);
  void attachOnDisconnect(callback_t callback);

  uint8_t* LatestPacket() { return data.latestPacket; }

public:
  bool Right() { return data.button.right; }
  bool Down() { return data.button.down; }
  bool Up() { return data.button.up; }
  bool Left() { return data.button.left; }

  bool Square() { return data.button.square; }
  bool Cross() { return data.button.cross; }
  bool Circle() { return data.button.circle; }
  bool Triangle() { return data.button.triangle; }

  bool UpRight() { return data.button.upright; }
  bool DownRight() { return data.button.downright; }
  bool UpLeft() { return data.button.upleft; }
  bool DownLeft() { return data.button.downleft; }

  bool L1() { return data.button.l1; }
  bool R1() { return data.button.r1; }
  bool L2() { return data.button.l2; }
  bool R2() { return data.button.r2; }

  bool Share() { return data.button.share; }
  bool Options() { return data.button.options; }
  bool L3() { return data.button.l3; }
  bool R3() { return data.button.r3; }

  bool PSButton() { return data.button.ps; }
  bool Touchpad() { return data.button.touchpad; }

  uint8_t L2Value() { return data.analog.button.l2; }
  uint8_t R2Value() { return data.analog.button.r2; }

  int8_t LStickX() { return data.analog.stick.lx; }
  int8_t LStickY() { return data.analog.stick.ly; }
  int8_t RStickX() { return data.analog.stick.rx; }
  int8_t RStickY() { return data.analog.stick.ry; }

    // /**
    //      * Used to get the analog value from button presses.
    //      * @param  b The ::ButtonEnum to read.
    //      * The supported buttons are:
    //      * ::L2 and ::R2.
    //      * @return   Analog value in the range of 0-255.
    //      */
    //     uint8_t getAnalogButton(ButtonEnum b);

    //     /**
    //      * Used to read the analog joystick.
    //      * @param  a ::LeftHatX, ::LeftHatY, ::RightHatX, and ::RightHatY.
    //      * @return   Return the analog value in the range of 0-255.
    //      */
    //     uint8_t getAnalogHat(AnalogHatEnum a);

  uint8_t Battery() { return data.status.battery; }
  bool Charging() { return data.status.charging; }
  bool Audio() { return data.status.audio; }
  bool Mic() { return data.status.mic; }

 private:
  static void _event_callback(void* object, ps5_t data, ps5_event_t event);
  static void _connection_callback(void* object, uint8_t isConnected);

  callback_t _callback_event = nullptr;
  callback_t _callback_connect = nullptr;
  callback_t _callback_disconnect = nullptr;
};

//void PS5Parser::Reset() {
//        uint8_t i;
//        for (i = 0; i < sizeof(ps5Data.hatValue); i++)
//                ps5Data.hatValue[i] = 127; // Center value
//        ps5Data.btn.val = 0;
//        oldButtonState.val = 0;
//        for (i = 0; i < sizeof(ps5Data.trigger); i++)
//                ps5Data.trigger[i] = 0;
//        for (i = 0; i < sizeof(ps5Data.xy.finger)/sizeof(ps5Data.xy.finger[0]); i++)
//                ps5Data.xy.finger[i].touching = 1; // The bit is cleared if the finger is touching the touchpad
//
//        ps5Data.btn.dpad = DPAD_OFF;
//        oldButtonState.dpad = DPAD_OFF;
//        buttonClickState.dpad = 0;
//        oldDpad = 0;
//
//        leftTrigger.Reset();
//        rightTrigger.Reset();
//
//        ps5Output.bigRumble = ps5Output.smallRumble = 0;
//        ps5Output.microphoneLed = 0;
//        ps5Output.disableLeds = 0;
//        ps5Output.playerLeds = 0;
//        ps5Output.r = ps5Output.g = ps5Output.b = 0;
//        ps5Output.reportChanged = false;
//};
#ifndef NO_GLOBAL_INSTANCES
extern ps5Controller ps5;
#endif

#endif
