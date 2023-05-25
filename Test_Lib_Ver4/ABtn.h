#ifndef ABtn_h
#define ABtn_h

/**
 * @file ABtn.h
 * @author TrungKuro
 * @brief
 * @version 0.4
 * @date 2023-05-25
 *
 * @copyright Copyright (c) 2023
 *
 * Mô tả cách sử dụng thư viện:
 *
 * 1) Khởi tạo đối tượng "ABtn", có 2 cách:
 * ABtn <nameObj>();    // Chọn chân mặc định là A0
 * ABtn <nameObj>(pin); // Chọn chân "pin"
 *
 * 2) Cấu hình đối tượng "ABtn", có 3 thông số có thể tùy chỉnh:
 * ABtn <nameObj>.setDebounceMs(ms); // Mặc định là DEFAULT_DEBOUNCE
 * ABtn <nameObj>.setClickMs(ms);    // Mặc định là DEFAULT_CLICK
 * ABtn <nameObj>.setPressMs(ms);    // Mặc định là DEFAULT_PRESS
 */

/* ------------------------------------------------------------------------- */
/*                                  LIBRARY                                  */
/* ------------------------------------------------------------------------- */

#include "Arduino.h"

/* ------------------------------------------------------------------------- */
/*                                   DEFINE                                  */
/* ------------------------------------------------------------------------- */

#define DEFAULT_BTN_PIN A0

#define DEFAULT_DEBOUNCE 20 // (ms)
#define DEFAULT_CLICK 200   // (ms)
#define DEFAULT_PRESS 300   // (ms)

/**
 * @brief If this is just button Digital.
 * The level of the input pin when the button is "released" is HIGH (~ 1023).
 * Vice versa, the button connects the input pin to GND when "pressed", mean LOW (~ 0).
 * With button Analog, we have many value when "pressed" buttons.
 */
#define DEFAULT_BTN_RELEASE 1023 // (ADC)
//
#define DEFAULT_BTN_1_MIN 501
#define DEFAULT_BTN_1_MAX 522
//
#define DEFAULT_BTN_2_MIN 675
#define DEFAULT_BTN_2_MAX 696
//
#define DEFAULT_BTN_3_MIN 757
#define DEFAULT_BTN_3_MAX 777
//
#define DEFAULT_BTN_4_MIN 808
#define DEFAULT_BTN_4_MAX 829

/**
 * @brief Used for combination of 2 buttons.
 *    [1]     |    [A]
 * [2] - [4]  | [B] - [D]
 *    [3]     |    [C]
 * Here, I only use 4 combine, include:
 * (1) - Button A+B = 1+2
 * (2) - Button C+B = 3+2
 * (3) - Button C+D = 3+4
 * (4) - Button A+D = 1+4
 */
#define DEFAULT_BTN_12_MIN 399
#define DEFAULT_BTN_12_MAX 419
//
#define DEFAULT_BTN_32_MIN 552
#define DEFAULT_BTN_32_MAX 573
//
#define DEFAULT_BTN_34_MIN 634
#define DEFAULT_BTN_34_MAX 655
//
#define DEFAULT_BTN_14_MIN 440
#define DEFAULT_BTN_14_MAX 460

/**
 * @brief This are value status of button Analog.
 */
#define STATUS_BTN_INIT (-1)
//
#define STATUS_BTN_RELEASE 0
#define STATUS_BTN_1_PRESS 1
#define STATUS_BTN_2_PRESS 2
#define STATUS_BTN_3_PRESS 3
#define STATUS_BTN_4_PRESS 4
//
#define STATUS_BTN_12_PRESS 5
#define STATUS_BTN_32_PRESS 6
#define STATUS_BTN_34_PRESS 7
#define STATUS_BTN_14_PRESS 8

/**
 * @brief Max number of clicks of interest.
 */
#define MAX_CLICK_VALID 2

/**
 * @brief Maximum number of buttons per module.
 */
#define MAX_BUTTON 4

/* ------------------------------------------------------------------------- */
/*                                  FUNCTION                                 */
/* ------------------------------------------------------------------------- */

/**
 * @brief Callback function types.
 *
 * What is the effect of extern "C" in C++?
 * → https://stackoverflow.com/questions/1041866/what-is-the-effect-of-extern-c-in-c
 */
extern "C"
{
  typedef void (*callbackFunction)(void);
  typedef void (*parameterizedCallbackFunction)(void *);
}

/* ------------------------------------------------------------------------- */
/*                                   CLASS                                   */
/* ------------------------------------------------------------------------- */

class ABtn
{
public:
  /* ----------------------------------------------------------------------- */
  /*                                  PUBLIC                                 */
  /* ----------------------------------------------------------------------- */

  /**
   * @brief Initialize the "ABtn" library.
   * The pin default used is "DEFAULT_BTN_PIN".
   */
  ABtn(void);

  /**
   * @brief Initialize the "ABtn" library.
   * @param pin The pin is used as the INPUT from the "AnalogButton" module.
   */
  explicit ABtn(const uint8_t pin);

  /* ------------------------ Set runtime parameters ----------------------- */

  /**
   * C attribute: deprecated (since C23)
   * → https://en.cppreference.com/w/c/language/attributes/deprecated
   *
   * |--------->|------>|------>|--> (ms)
   * | Debounce | Click | Press |
   */

  /**
   * @brief set # millisec after safe click is assumed.
   */
  void setDebounceMs(const unsigned int ms);

  /**
   * @brief set # millisec after single click is assumed.
   */
  void setClickMs(const unsigned int ms);

  /**
   * @brief set # millisec after press is assumed.
   */
  void setPressMs(const unsigned int ms);

  /* ----------------------- Attach events functions ----------------------- */

  /**
   * @brief Attach an event to be called when a single click is detected.
   * @param newFunction This function will be called when the event has been detected.
   */
  void attachClickA(callbackFunction newFunction);
  void attachClickA(parameterizedCallbackFunction newFunction, void *parameter);
  //
  void attachClickB(callbackFunction newFunction);
  void attachClickB(parameterizedCallbackFunction newFunction, void *parameter);
  //
  void attachClickC(callbackFunction newFunction);
  void attachClickC(parameterizedCallbackFunction newFunction, void *parameter);
  //
  void attachClickD(callbackFunction newFunction);
  void attachClickD(parameterizedCallbackFunction newFunction, void *parameter);

  /**
   * Attach an event to be called after a double click is detected.
   * @param newFunction This function will be called when the event has been detected.
   */
  void attachDoubleClickA(callbackFunction newFunction);
  void attachDoubleClickA(parameterizedCallbackFunction newFunction, void *parameter);
  //
  void attachDoubleClickB(callbackFunction newFunction);
  void attachDoubleClickB(parameterizedCallbackFunction newFunction, void *parameter);
  //
  void attachDoubleClickC(callbackFunction newFunction);
  void attachDoubleClickC(parameterizedCallbackFunction newFunction, void *parameter);
  //
  void attachDoubleClickD(callbackFunction newFunction);
  void attachDoubleClickD(parameterizedCallbackFunction newFunction, void *parameter);

  /**
   * Attach an event to fire when the button is pressed and held down.
   * @param newFunction
   */
  void attachLongPress_A_Start(callbackFunction newFunction);
  void attachLongPress_A_Start(parameterizedCallbackFunction newFunction, void *parameter);
  //
  void attachLongPress_B_Start(callbackFunction newFunction);
  void attachLongPress_B_Start(parameterizedCallbackFunction newFunction, void *parameter);
  //
  void attachLongPress_C_Start(callbackFunction newFunction);
  void attachLongPress_C_Start(parameterizedCallbackFunction newFunction, void *parameter);
  //
  void attachLongPress_D_Start(callbackFunction newFunction);
  void attachLongPress_D_Start(parameterizedCallbackFunction newFunction, void *parameter);
  /* ----------------------------------------------------------------------- */
  void attachLongPress_AB_Start(callbackFunction newFunction);
  void attachLongPress_AB_Start(parameterizedCallbackFunction newFunction, void *parameter);
  //
  void attachLongPress_CB_Start(callbackFunction newFunction);
  void attachLongPress_CB_Start(parameterizedCallbackFunction newFunction, void *parameter);
  //
  void attachLongPress_CD_Start(callbackFunction newFunction);
  void attachLongPress_CD_Start(parameterizedCallbackFunction newFunction, void *parameter);
  //
  void attachLongPress_AD_Start(callbackFunction newFunction);
  void attachLongPress_AD_Start(parameterizedCallbackFunction newFunction, void *parameter);

  /**
   * Attach an event to fire periodically while the button is held down.
   * @param newFunction
   */
  void attachDuringLongPress_A(callbackFunction newFunction);
  void attachDuringLongPress_A(parameterizedCallbackFunction newFunction, void *parameter);
  //
  void attachDuringLongPress_B(callbackFunction newFunction);
  void attachDuringLongPress_B(parameterizedCallbackFunction newFunction, void *parameter);
  //
  void attachDuringLongPress_C(callbackFunction newFunction);
  void attachDuringLongPress_C(parameterizedCallbackFunction newFunction, void *parameter);
  //
  void attachDuringLongPress_D(callbackFunction newFunction);
  void attachDuringLongPress_D(parameterizedCallbackFunction newFunction, void *parameter);
  /* ----------------------------------------------------------------------- */
  void attachDuringLongPress_AB(callbackFunction newFunction);
  void attachDuringLongPress_AB(parameterizedCallbackFunction newFunction, void *parameter);
  //
  void attachDuringLongPress_CB(callbackFunction newFunction);
  void attachDuringLongPress_CB(parameterizedCallbackFunction newFunction, void *parameter);
  //
  void attachDuringLongPress_CD(callbackFunction newFunction);
  void attachDuringLongPress_CD(parameterizedCallbackFunction newFunction, void *parameter);
  //
  void attachDuringLongPress_AD(callbackFunction newFunction);
  void attachDuringLongPress_AD(parameterizedCallbackFunction newFunction, void *parameter);

  /**
   * Attach an event to fire as soon as the button is released after a long press.
   * @param newFunction
   */
  void attachLongPress_A_Stop(callbackFunction newFunction);
  void attachLongPress_A_Stop(parameterizedCallbackFunction newFunction, void *parameter);
  //
  void attachLongPress_B_Stop(callbackFunction newFunction);
  void attachLongPress_B_Stop(parameterizedCallbackFunction newFunction, void *parameter);
  //
  void attachLongPress_C_Stop(callbackFunction newFunction);
  void attachLongPress_C_Stop(parameterizedCallbackFunction newFunction, void *parameter);
  //
  void attachLongPress_D_Stop(callbackFunction newFunction);
  void attachLongPress_D_Stop(parameterizedCallbackFunction newFunction, void *parameter);
  /* ----------------------------------------------------------------------- */
  void attachLongPress_AB_Stop(callbackFunction newFunction);
  void attachLongPress_AB_Stop(parameterizedCallbackFunction newFunction, void *parameter);
  //
  void attachLongPress_CB_Stop(callbackFunction newFunction);
  void attachLongPress_CB_Stop(parameterizedCallbackFunction newFunction, void *parameter);
  //
  void attachLongPress_CD_Stop(callbackFunction newFunction);
  void attachLongPress_CD_Stop(parameterizedCallbackFunction newFunction, void *parameter);
  //
  void attachLongPress_AD_Stop(callbackFunction newFunction);
  void attachLongPress_AD_Stop(parameterizedCallbackFunction newFunction, void *parameter);

  /* ----------------------- State machine functions ----------------------- */

  /**
   * @brief Call this function every some milliseconds.
   * For checking the input level at the initialized digital pin.
   */
  void tick(void);

  /**
   * @brief Reset the button state machine.
   */
  void reset(void);

private:
  /* ----------------------------------------------------------------------- */
  /*                                 PRIVATE                                 */
  /* ----------------------------------------------------------------------- */

  uint8_t _pin = DEFAULT_BTN_PIN; // Hardware pin number.

  unsigned int _debounce_ms = DEFAULT_DEBOUNCE; // Number of (msecs) for debounce times.
  unsigned int _click_ms = DEFAULT_CLICK;       // Number of (msecs) before a click is detected.
  unsigned int _press_ms = DEFAULT_PRESS;       // Number of (msecs) before a long button press is detected.

  /* ----------------------------------------------------------------------- */

  /**
   * These variables will hold functions acting as event source.
   */

  //// 1 Click ////

  callbackFunction _clickA_Func = NULL;
  parameterizedCallbackFunction _paramClickA_Func = NULL;
  void *_clickA_FuncParam = NULL;
  //
  callbackFunction _clickB_Func = NULL;
  parameterizedCallbackFunction _paramClickB_Func = NULL;
  void *_clickB_FuncParam = NULL;
  //
  callbackFunction _clickC_Func = NULL;
  parameterizedCallbackFunction _paramClickC_Func = NULL;
  void *_clickC_FuncParam = NULL;
  //
  callbackFunction _clickD_Func = NULL;
  parameterizedCallbackFunction _paramClickD_Func = NULL;
  void *_clickD_FuncParam = NULL;

  //// 2 Click ////

  callbackFunction _doubleClickA_Func = NULL;
  parameterizedCallbackFunction _paramDoubleClickA_Func = NULL;
  void *_doubleClickA_FuncParam = NULL;
  //
  callbackFunction _doubleClickB_Func = NULL;
  parameterizedCallbackFunction _paramDoubleClickB_Func = NULL;
  void *_doubleClickB_FuncParam = NULL;
  //
  callbackFunction _doubleClickC_Func = NULL;
  parameterizedCallbackFunction _paramDoubleClickC_Func = NULL;
  void *_doubleClickC_FuncParam = NULL;
  //
  callbackFunction _doubleClickD_Func = NULL;
  parameterizedCallbackFunction _paramDoubleClickD_Func = NULL;
  void *_doubleClickD_FuncParam = NULL;

  //// Start Hold ////

  callbackFunction _longPressA_StartFunc = NULL;
  parameterizedCallbackFunction _paramLongPressA_StartFunc = NULL;
  void *_longPressA_StartFuncParam = NULL;
  //
  callbackFunction _longPressB_StartFunc = NULL;
  parameterizedCallbackFunction _paramLongPressB_StartFunc = NULL;
  void *_longPressB_StartFuncParam = NULL;
  //
  callbackFunction _longPressC_StartFunc = NULL;
  parameterizedCallbackFunction _paramLongPressC_StartFunc = NULL;
  void *_longPressC_StartFuncParam = NULL;
  //
  callbackFunction _longPressD_StartFunc = NULL;
  parameterizedCallbackFunction _paramLongPressD_StartFunc = NULL;
  void *_longPressD_StartFuncParam = NULL;
  /* ----------------------------------------------------------------------- */
  callbackFunction _longPressAB_StartFunc = NULL;
  parameterizedCallbackFunction _paramLongPressAB_StartFunc = NULL;
  void *_longPressAB_StartFuncParam = NULL;
  //
  callbackFunction _longPressCB_StartFunc = NULL;
  parameterizedCallbackFunction _paramLongPressCB_StartFunc = NULL;
  void *_longPressCB_StartFuncParam = NULL;
  //
  callbackFunction _longPressCD_StartFunc = NULL;
  parameterizedCallbackFunction _paramLongPressCD_StartFunc = NULL;
  void *_longPressCD_StartFuncParam = NULL;
  //
  callbackFunction _longPressAD_StartFunc = NULL;
  parameterizedCallbackFunction _paramLongPressAD_StartFunc = NULL;
  void *_longPressAD_StartFuncParam = NULL;

  //// During Hold ////

  callbackFunction _duringLongPressA_Func = NULL;
  parameterizedCallbackFunction _paramDuringLongPressA_Func = NULL;
  void *_duringLongPressA_FuncParam = NULL;
  //
  callbackFunction _duringLongPressB_Func = NULL;
  parameterizedCallbackFunction _paramDuringLongPressB_Func = NULL;
  void *_duringLongPressB_FuncParam = NULL;
  //
  callbackFunction _duringLongPressC_Func = NULL;
  parameterizedCallbackFunction _paramDuringLongPressC_Func = NULL;
  void *_duringLongPressC_FuncParam = NULL;
  //
  callbackFunction _duringLongPressD_Func = NULL;
  parameterizedCallbackFunction _paramDuringLongPressD_Func = NULL;
  void *_duringLongPressD_FuncParam = NULL;
  /* ----------------------------------------------------------------------- */
  callbackFunction _duringLongPressAB_Func = NULL;
  parameterizedCallbackFunction _paramDuringLongPressAB_Func = NULL;
  void *_duringLongPressAB_FuncParam = NULL;
  //
  callbackFunction _duringLongPressCB_Func = NULL;
  parameterizedCallbackFunction _paramDuringLongPressCB_Func = NULL;
  void *_duringLongPressCB_FuncParam = NULL;
  //
  callbackFunction _duringLongPressCD_Func = NULL;
  parameterizedCallbackFunction _paramDuringLongPressCD_Func = NULL;
  void *_duringLongPressCD_FuncParam = NULL;
  //
  callbackFunction _duringLongPressAD_Func = NULL;
  parameterizedCallbackFunction _paramDuringLongPressAD_Func = NULL;
  void *_duringLongPressAD_FuncParam = NULL;

  //// Stop Hold ////

  callbackFunction _longPressA_StopFunc = NULL;
  parameterizedCallbackFunction _paramLongPressA_StopFunc = NULL;
  void *_longPressA_StopFuncParam = NULL;
  //
  callbackFunction _longPressB_StopFunc = NULL;
  parameterizedCallbackFunction _paramLongPressB_StopFunc = NULL;
  void *_longPressB_StopFuncParam = NULL;
  //
  callbackFunction _longPressC_StopFunc = NULL;
  parameterizedCallbackFunction _paramLongPressC_StopFunc = NULL;
  void *_longPressC_StopFuncParam = NULL;
  //
  callbackFunction _longPressD_StopFunc = NULL;
  parameterizedCallbackFunction _paramLongPressD_StopFunc = NULL;
  void *_longPressD_StopFuncParam = NULL;
  /* ----------------------------------------------------------------------- */
  callbackFunction _longPressAB_StopFunc = NULL;
  parameterizedCallbackFunction _paramLongPressAB_StopFunc = NULL;
  void *_longPressAB_StopFuncParam = NULL;
  //
  callbackFunction _longPressCB_StopFunc = NULL;
  parameterizedCallbackFunction _paramLongPressCB_StopFunc = NULL;
  void *_longPressCB_StopFuncParam = NULL;
  //
  callbackFunction _longPressCD_StopFunc = NULL;
  parameterizedCallbackFunction _paramLongPressCD_StopFunc = NULL;
  void *_longPressCD_StopFuncParam = NULL;
  //
  callbackFunction _longPressAD_StopFunc = NULL;
  parameterizedCallbackFunction _paramLongPressAD_StopFunc = NULL;
  void *_longPressAD_StopFuncParam = NULL;

  /* ----------------------------------------------------------------------- */

  /**
   * These variables that hold information across the upcoming tick calls.
   * They are initialized once on program start.
   * And are updated every time the tick function is called.
   */

  // Define FiniteStateMachine
  enum stateMachine_t : int
  {
    OCS_INIT = 0,     //
    OCS_DOWN = 1,     // Button is down (pressed)
    OCS_UP = 2,       // Button is up (released)
    OCS_COUNT = 3,    //
    OCS_PRESS = 6,    // Button is hold down (holding)
    OCS_PRESSEND = 7, //
  };
  stateMachine_t _state = OCS_INIT;

  // Run the finite state machine (FSM) using the given level.
  void _fsm(bool activeLevel);

  // Advance to a new state.
  void _newState(stateMachine_t nextState);

  // Process (ADC).
  enum statusButton_t : int
  {
    INIT = STATUS_BTN_INIT,
    //
    NONE = STATUS_BTN_RELEASE, // Không có nút nào được nhấn
    BTN1 = STATUS_BTN_1_PRESS, // Đang nhấn nút 1
    BTN2 = STATUS_BTN_2_PRESS, // Đang nhấn nút 2
    BTN3 = STATUS_BTN_3_PRESS, // Đang nhấn nút 3
    BTN4 = STATUS_BTN_4_PRESS, // Đang nhấn nút 4
    //
    BTN_12 = STATUS_BTN_12_PRESS, // Combo A+B
    BTN_32 = STATUS_BTN_32_PRESS, // Combo C+B
    BTN_34 = STATUS_BTN_34_PRESS, // Combo C+D
    BTN_14 = STATUS_BTN_14_PRESS, // Combo A+D
  };
  statusButton_t _status = INIT;
  statusButton_t _storeStatus = INIT;
  //
  int tempADC = 0;     // Lưu giá trị ADC đo được
  void checkADC(void); // Đo giá trị ADC và ánh xạ sang trạng thái nút tương ứng

  // Process "Debounce".
  statusButton_t debouncedPinLevel = INIT;     // Lưu giá trị trạng thái của nút được xác nhận sau Debounce
  statusButton_t _lastDebouncePinLevel = INIT; // Lưu giá trị trạng thái của nút ở thời điểm xảy ra "cạnh lên" hoặc "cạnh xuống"
  //
  unsigned long _lastDebounceTime = 0; // millis() - lưu thời điểm xảy ra "cạnh lên" hoặc "cạnh xuống"
  unsigned long now = 0;               // millis() - cập nhập thời điểm hiện tại mỗi khi kiểm tra nút (tick)

  // Process "Click".
  unsigned long _startTime = 0;     // Start of current input change to checking debouncing
  int _nClicks[MAX_BUTTON] = {0};   // Count the number of clicks with this variable
  int _maxClicks = MAX_CLICK_VALID; // Max number (1, 2, multi=3) of clicks of interest by registration of event functions

public:
  /* ----------------------------------------------------------------------- */
  /*                                  PUBLIC                                 */
  /* ----------------------------------------------------------------------- */

  uint8_t pin() const { return _pin; };
  stateMachine_t state() const { return _state; };
  int debounce(void);
  int debouncedValue() const { return debouncedPinLevel; };
};

#endif