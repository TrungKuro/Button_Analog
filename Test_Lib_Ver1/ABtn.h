#ifndef ABtn_h
#define ABtn_h

/**
 * @file ABtn.h
 * @author TrungKuro
 * @brief
 * @version 0.1
 * @date 2023-05-24
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

#define DEFAULT_DEBOUNCE 50 // (ms)
#define DEFAULT_CLICK 400   // (ms)
#define DEFAULT_PRESS 800   // (ms)

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
//
#define BTN_MIN DEFAULT_BTN_1_MIN
#define BTN_MAX DEFAULT_BTN_4_MAX

/**
 * @brief This are value status of button Analog.
 */
#define STATUS_BTN_INIT (-1)
#define STATUS_BTN_RELEASE 0
#define STATUS_BTN_1_PRESS 1
#define STATUS_BTN_2_PRESS 2
#define STATUS_BTN_3_PRESS 3
#define STATUS_BTN_4_PRESS 4

/**
 * @brief Max number of clicks of interest.
 */
#define MAX_CLICK_VALID 1

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
  ABtn();

  /**
   * @brief Initialize the "ABtn" library.
   * @param pin The pin is used as the INPUT from the "AnalogButton" module.
   */
  ABtn(const uint8_t pin);

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

  /**
   * @return Number of clicks in any case: single or multiple clicks.
   */
  // int getNumberClicks(void);

  /**
   * @return True if we are currently handling button press flow.
   * (This allows power sensitive applications to know when it is safe to power down the main CPU)
   */
  bool isIdle() const { return _state == OCS_INIT; }

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

  callbackFunction _clickA_Func = NULL;
  parameterizedCallbackFunction _paramClickA_Func = NULL;
  void *_clickA_FuncParam = NULL;

  callbackFunction _clickB_Func = NULL;
  parameterizedCallbackFunction _paramClickB_Func = NULL;
  void *_clickB_FuncParam = NULL;

  callbackFunction _clickC_Func = NULL;
  parameterizedCallbackFunction _paramClickC_Func = NULL;
  void *_clickC_FuncParam = NULL;

  callbackFunction _clickD_Func = NULL;
  parameterizedCallbackFunction _paramClickD_Func = NULL;
  void *_clickD_FuncParam = NULL;

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
    INIT = STATUS_BTN_INIT,    //
    NONE = STATUS_BTN_RELEASE, // Không có nút nào được nhấn
    BTN1 = STATUS_BTN_1_PRESS, // Đang nhấn nút 1
    BTN2 = STATUS_BTN_2_PRESS, // Đang nhấn nút 2
    BTN3 = STATUS_BTN_3_PRESS, // Đang nhấn nút 3
    BTN4 = STATUS_BTN_4_PRESS, // Đang nhấn nút 4
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
  unsigned long _startTime = 0;   // Start of current input change to checking debouncing
  int _nClicks[MAX_BUTTON] = {0}; // Count the number of clicks with this variable
  int _maxClicks = 1;             // Max number (1, 2, multi=3) of clicks of interest by registration of event functions

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