/* ------------------------------------------------------------------------- */
/*                                  LIBRARY                                  */
/* ------------------------------------------------------------------------- */

#include "ABtn.h"

/* ------------------------------------------------------------------------- */
/*                                CONSTRUCTOR                                */
/* ------------------------------------------------------------------------- */

// Initialization and Default Values

/**
 * @brief Initialize the "ABtn" library.
 * The pin default used is "DEFAULT_BTN_PIN".
 */
ABtn::ABtn(void)
{
  _pin = DEFAULT_BTN_PIN;
}

/**
 * @brief Initialize the "ABtn" library.
 * @param pin The pin is used as the INPUT from the "AnalogButton" module.
 */
ABtn::ABtn(const uint8_t pin)
{
  _pin = pin;
}

/* ------------------------------------------------------------------------- */
/*                          FUNCTION CONFIG (PUBLIC)                         */
/* ------------------------------------------------------------------------- */

/**
 * @brief Explicitly set the number of millisec.
 * That have to pass by before a click is assumed stable.
 */
void ABtn::setDebounceMs(const unsigned int ms)
{
  _debounce_ms = ms;
}

/**
 * @brief Explicitly set the number of millisec.
 * That have to pass by before a click is detected.
 */
void ABtn::setClickMs(const unsigned int ms)
{
  _click_ms = ms;
}

/**
 * @brief Explicitly set the number of millisec.
 * That have to pass by before a long button press is detected.
 */
void ABtn::setPressMs(const unsigned int ms)
{
  _press_ms = ms;
}

/* ------------------------------------------------------------------------- */
/*                          FUNCTION EVENT (PUBLIC)                          */
/* ------------------------------------------------------------------------- */

/* -------------------------------- Button A ------------------------------- */

void ABtn::attachClickA(callbackFunction newFunction)
{
  _clickA_Func = newFunction;
}
void ABtn::attachClickA(parameterizedCallbackFunction newFunction, void *parameter)
{
  _paramClickA_Func = newFunction;
  _clickA_FuncParam = parameter;
}

void ABtn::attachDoubleClickA(callbackFunction newFunction)
{
  _doubleClickA_Func = newFunction;
  _maxClicks = max(_maxClicks, 2);
}
void ABtn::attachDoubleClickA(parameterizedCallbackFunction newFunction, void *parameter)
{
  _paramDoubleClickA_Func = newFunction;
  _doubleClickA_FuncParam = parameter;
  _maxClicks = max(_maxClicks, 2);
}

void ABtn::attachLongPress_A_Start(callbackFunction newFunction)
{
  _longPressA_StartFunc = newFunction;
}
void ABtn::attachLongPress_A_Start(parameterizedCallbackFunction newFunction, void *parameter)
{
  _paramLongPressA_StartFunc = newFunction;
  _longPressA_StartFuncParam = parameter;
}

void ABtn::attachDuringLongPress_A(callbackFunction newFunction)
{
  _duringLongPressA_Func = newFunction;
}
void ABtn::attachDuringLongPress_A(parameterizedCallbackFunction newFunction, void *parameter)
{
  _paramDuringLongPressA_Func = newFunction;
  _duringLongPressA_FuncParam = parameter;
}

void ABtn::attachLongPress_A_Stop(callbackFunction newFunction)
{
  _longPressA_StopFunc = newFunction;
}
void ABtn::attachLongPress_A_Stop(parameterizedCallbackFunction newFunction, void *parameter)
{
  _paramLongPressA_StopFunc = newFunction;
  _longPressA_StopFuncParam = parameter;
}

/* -------------------------------- Button B ------------------------------- */

void ABtn::attachClickB(callbackFunction newFunction)
{
  _clickB_Func = newFunction;
}
void ABtn::attachClickB(parameterizedCallbackFunction newFunction, void *parameter)
{
  _paramClickB_Func = newFunction;
  _clickB_FuncParam = parameter;
}

void ABtn::attachDoubleClickB(callbackFunction newFunction)
{
  _doubleClickB_Func = newFunction;
  _maxClicks = max(_maxClicks, 2);
}
void ABtn::attachDoubleClickB(parameterizedCallbackFunction newFunction, void *parameter)
{
  _paramDoubleClickB_Func = newFunction;
  _doubleClickB_FuncParam = parameter;
  _maxClicks = max(_maxClicks, 2);
}

void ABtn::attachLongPress_B_Start(callbackFunction newFunction)
{
  _longPressB_StartFunc = newFunction;
}
void ABtn::attachLongPress_B_Start(parameterizedCallbackFunction newFunction, void *parameter)
{
  _paramLongPressB_StartFunc = newFunction;
  _longPressB_StartFuncParam = parameter;
}

void ABtn::attachDuringLongPress_B(callbackFunction newFunction)
{
  _duringLongPressB_Func = newFunction;
}
void ABtn::attachDuringLongPress_B(parameterizedCallbackFunction newFunction, void *parameter)
{
  _paramDuringLongPressB_Func = newFunction;
  _duringLongPressB_FuncParam = parameter;
}

void ABtn::attachLongPress_B_Stop(callbackFunction newFunction)
{
  _longPressB_StopFunc = newFunction;
}
void ABtn::attachLongPress_B_Stop(parameterizedCallbackFunction newFunction, void *parameter)
{
  _paramLongPressB_StopFunc = newFunction;
  _longPressB_StopFuncParam = parameter;
}

/* -------------------------------- Button C ------------------------------- */

void ABtn::attachClickC(callbackFunction newFunction)
{
  _clickC_Func = newFunction;
}
void ABtn::attachClickC(parameterizedCallbackFunction newFunction, void *parameter)
{
  _paramClickC_Func = newFunction;
  _clickC_FuncParam = parameter;
}

void ABtn::attachDoubleClickC(callbackFunction newFunction)
{
  _doubleClickC_Func = newFunction;
  _maxClicks = max(_maxClicks, 2);
}
void ABtn::attachDoubleClickC(parameterizedCallbackFunction newFunction, void *parameter)
{
  _paramDoubleClickC_Func = newFunction;
  _doubleClickC_FuncParam = parameter;
  _maxClicks = max(_maxClicks, 2);
}

void ABtn::attachLongPress_C_Start(callbackFunction newFunction)
{
  _longPressC_StartFunc = newFunction;
}
void ABtn::attachLongPress_C_Start(parameterizedCallbackFunction newFunction, void *parameter)
{
  _paramLongPressC_StartFunc = newFunction;
  _longPressC_StartFuncParam = parameter;
}

void ABtn::attachDuringLongPress_C(callbackFunction newFunction)
{
  _duringLongPressC_Func = newFunction;
}
void ABtn::attachDuringLongPress_C(parameterizedCallbackFunction newFunction, void *parameter)
{
  _paramDuringLongPressC_Func = newFunction;
  _duringLongPressC_FuncParam = parameter;
}

void ABtn::attachLongPress_C_Stop(callbackFunction newFunction)
{
  _longPressC_StopFunc = newFunction;
}
void ABtn::attachLongPress_C_Stop(parameterizedCallbackFunction newFunction, void *parameter)
{
  _paramLongPressC_StopFunc = newFunction;
  _longPressC_StopFuncParam = parameter;
}

/* -------------------------------- Button D ------------------------------- */

void ABtn::attachClickD(callbackFunction newFunction)
{
  _clickD_Func = newFunction;
}
void ABtn::attachClickD(parameterizedCallbackFunction newFunction, void *parameter)
{
  _paramClickD_Func = newFunction;
  _clickD_FuncParam = parameter;
}

void ABtn::attachDoubleClickD(callbackFunction newFunction)
{
  _doubleClickD_Func = newFunction;
  _maxClicks = max(_maxClicks, 2);
}
void ABtn::attachDoubleClickD(parameterizedCallbackFunction newFunction, void *parameter)
{
  _paramDoubleClickD_Func = newFunction;
  _doubleClickD_FuncParam = parameter;
  _maxClicks = max(_maxClicks, 2);
}

void ABtn::attachLongPress_D_Start(callbackFunction newFunction)
{
  _longPressD_StartFunc = newFunction;
}
void ABtn::attachLongPress_D_Start(parameterizedCallbackFunction newFunction, void *parameter)
{
  _paramLongPressD_StartFunc = newFunction;
  _longPressD_StartFuncParam = parameter;
}

void ABtn::attachDuringLongPress_D(callbackFunction newFunction)
{
  _duringLongPressD_Func = newFunction;
}
void ABtn::attachDuringLongPress_D(parameterizedCallbackFunction newFunction, void *parameter)
{
  _paramDuringLongPressD_Func = newFunction;
  _duringLongPressD_FuncParam = parameter;
}

void ABtn::attachLongPress_D_Stop(callbackFunction newFunction)
{
  _longPressD_StopFunc = newFunction;
}
void ABtn::attachLongPress_D_Stop(parameterizedCallbackFunction newFunction, void *parameter)
{
  _paramLongPressD_StopFunc = newFunction;
  _longPressD_StopFuncParam = parameter;
}

/* ------------------------------------------------------------------------- */
/*                      STATE MACHINE FUNCTION (PUBLIC)                      */
/* ------------------------------------------------------------------------- */

void ABtn::tick(void)
{
  /**
   * @brief Check input of the configured pin.
   * Debounce input pin level and then.
   * Advance the finite state machine (FSM).
   */
  if (_pin >= 0)
  {
    /**
     * Để lấy giá trị trạng thái hiện tại của nút và lưu vào "_status"
     * Hàm debounce() sẽ xác nhận giá trị đó có hợp lệ để sử dụng hay không
     */
    checkADC();

    /**
     * Hàm (_fsm) nhận giá trị:
     * → True  : nút đang được nhấn
     * → False : không có nhấn nút
     */
    _fsm(debounce() != ABtn::NONE);
  }
}

void ABtn::reset(void)
{
  _state = ABtn::OCS_INIT;

  _startTime = 0;
  for (int index = 0; index < MAX_BUTTON; index++)
  {
    _nClicks[index] = 0;
  }
}

/* ------------------------------------------------------------------------- */
/*                           FUNCTION INFO (PUBLIC)                          */
/* ------------------------------------------------------------------------- */

/**
 * @brief Debounce input pin level.
 * @param value mapping ADC value read from that pin.
 */
int ABtn::debounce(void)
{
  now = millis(); // Current (relative) time in msecs

  if (_lastDebouncePinLevel == _status)
  {
    /**
     * Nếu giá trị trạng thái của nút không có thay đổi
     * Tức có thể đang nhấn nút hoặc không nhấn nút
     *
     * Sau khi vượt qua khoảng thời gian "Debounce"
     * Giá trị trạng thái của nút được xác nhận đáng tin cậy để sử dụng
     */
    if (now - _lastDebounceTime >= _debounce_ms)
    {
      debouncedPinLevel = _status;
    }
  }
  else
  {
    /**
     * Đoạn code này sẽ thực thi
     * Khi phát hiện sự thay đổi trạng thái của nút (dựa theo giá trị ADC)
     * Đây là giai đoạn xảy ra "cạnh lên" hoặc "cạnh xuống"
     *
     * Lúc này sẽ ghi nhận mốc thời gian bắt đầu của sự thay đổi này
     * Cũng như ghi nhận tạm thời giá trị trạng thái lúc này của nút
     */
    _lastDebounceTime = now;
    _lastDebouncePinLevel = _status;
  }

  return debouncedPinLevel;
}

/* ------------------------------------------------------------------------- */
/*                              FUNCTION PRIVATE                             */
/* ------------------------------------------------------------------------- */

/**
 * @brief Run the finite state machine (FSM) using the given level.
 */
void ABtn::_fsm(bool activeLevel)
{
  unsigned long waitTime = (now - _startTime);

  // Implementation of the state machine
  switch (_state)
  {
  /* ----------------- Waiting for level to become active. ----------------- */
  case ABtn::OCS_INIT:
  {
    if (activeLevel)
    {
      _newState(ABtn::OCS_DOWN);

      // Remember starting time
      _startTime = now;
      for (int index = 0; index < MAX_BUTTON; index++)
      {
        _nClicks[index] = 0;
      }

      /**
       * Để ghi nhận giá trị trạng thái nút nhấn hiện tại
       * Trước khi qua giai đoạn tiếp theo
       */
      _storeStatus = _status;
    }
    break;
  }
  /* ---------------- Waiting for level to become inactive. ---------------- */
  case ABtn::OCS_DOWN:
  {
    if (!activeLevel)
    {
      _newState(ABtn::OCS_UP);

      // Remember starting time
      _startTime = now;
    }
    else if ((activeLevel) && (waitTime > _press_ms))
    {
      _newState(ABtn::OCS_PRESS);

      // This was start hold the button
      switch (_storeStatus)
      {
      case ABtn::BTN1:
      {
        if (_longPressA_StartFunc)
          _longPressA_StartFunc();
        if (_paramLongPressA_StartFunc)
          _paramLongPressA_StartFunc(_longPressA_StartFuncParam);
        break;
      }
      case ABtn::BTN2:
      {
        if (_longPressB_StartFunc)
          _longPressB_StartFunc();
        if (_paramLongPressB_StartFunc)
          _paramLongPressB_StartFunc(_longPressB_StartFuncParam);
        break;
      }
      case ABtn::BTN3:
      {
        if (_longPressC_StartFunc)
          _longPressC_StartFunc();
        if (_paramLongPressC_StartFunc)
          _paramLongPressC_StartFunc(_longPressC_StartFuncParam);
        break;
      }
      case ABtn::BTN4:
      {
        if (_longPressD_StartFunc)
          _longPressD_StartFunc();
        if (_paramLongPressD_StartFunc)
          _paramLongPressD_StartFunc(_longPressD_StartFuncParam);
        break;
      }
      }
    }
    break;
  }
  /* -------------------------- Level is inactive. ------------------------- */
  case ABtn::OCS_UP:
  {
    _newState(ABtn::OCS_COUNT);

    // Count as a short button down
    _nClicks[_storeStatus - 1]++; // !!!
    break;
  }
  /* ----------------- Debounce time is over, count clicks. ---------------- */
  case ABtn::OCS_COUNT:
  {
    if (activeLevel)
    {
      // Button is down again
      _newState(ABtn::OCS_DOWN);

      // Remember starting time
      _startTime = now;
    }
    else if ((waitTime >= _click_ms) || (_nClicks[_storeStatus - 1] == _maxClicks))
    {
      // Now we know how many clicks have been made
      if (_nClicks[_storeStatus - 1] == 1)
      {
        // This was 1 click only
        switch (_storeStatus)
        {
        case ABtn::BTN1:
        {
          if (_clickA_Func)
            _clickA_Func();
          if (_paramClickA_Func)
            _paramClickA_Func(_clickA_FuncParam);
          break;
        }
        case ABtn::BTN2:
        {
          if (_clickB_Func)
            _clickB_Func();
          if (_paramClickB_Func)
            _paramClickB_Func(_clickB_FuncParam);
          break;
        }
        case ABtn::BTN3:
        {
          if (_clickC_Func)
            _clickC_Func();
          if (_paramClickC_Func)
            _paramClickC_Func(_clickC_FuncParam);
          break;
        }
        case ABtn::BTN4:
        {
          if (_clickD_Func)
            _clickD_Func();
          if (_paramClickD_Func)
            _paramClickD_Func(_clickD_FuncParam);
          break;
        }
        }
      }
      else if (_nClicks[_storeStatus - 1] == 2)
      {
        // This was a 2 click sequence
        switch (_storeStatus)
        {
        case ABtn::BTN1:
        {
          if (_doubleClickA_Func)
            _doubleClickA_Func();
          if (_paramDoubleClickA_Func)
            _paramDoubleClickA_Func(_doubleClickA_FuncParam);
          break;
        }
        case ABtn::BTN2:
        {
          if (_doubleClickB_Func)
            _doubleClickB_Func();
          if (_paramDoubleClickB_Func)
            _paramDoubleClickB_Func(_doubleClickB_FuncParam);
          break;
        }
        case ABtn::BTN3:
        {
          if (_doubleClickC_Func)
            _doubleClickC_Func();
          if (_paramDoubleClickC_Func)
            _paramDoubleClickC_Func(_doubleClickC_FuncParam);
          break;
        }
        case ABtn::BTN4:
        {
          if (_doubleClickD_Func)
            _doubleClickD_Func();
          if (_paramDoubleClickD_Func)
            _paramDoubleClickD_Func(_doubleClickD_FuncParam);
          break;
        }
        }
      }
      reset();
    }
    break;
  }
  /* ----------- Waiting for pin being release after long press. ----------- */
  case ABtn::OCS_PRESS:
  {
    if (!activeLevel)
    {
      _newState(ABtn::OCS_PRESSEND);

      // Remember starting time
      _startTime = now;
    }
    else
    {
      // Still the button is pressed
      switch (_storeStatus)
      {
      case ABtn::BTN1:
      {
        if (_duringLongPressA_Func)
          _duringLongPressA_Func();
        if (_paramDuringLongPressA_Func)
          _paramDuringLongPressA_Func(_duringLongPressA_FuncParam);
        break;
      }
      case ABtn::BTN2:
      {
        if (_duringLongPressB_Func)
          _duringLongPressB_Func();
        if (_paramDuringLongPressB_Func)
          _paramDuringLongPressB_Func(_duringLongPressB_FuncParam);
        break;
      }
      case ABtn::BTN3:
      {
        if (_duringLongPressC_Func)
          _duringLongPressC_Func();
        if (_paramDuringLongPressC_Func)
          _paramDuringLongPressC_Func(_duringLongPressC_FuncParam);
        break;
      }
      case ABtn::BTN4:
      {
        if (_duringLongPressD_Func)
          _duringLongPressD_Func();
        if (_paramDuringLongPressD_Func)
          _paramDuringLongPressD_Func(_duringLongPressD_FuncParam);
        break;
      }
      }
    }
    break;
  }
  /* ------------------------- Button was released. ------------------------ */
  case ABtn::OCS_PRESSEND:
  {
    // This was stop hold the button
    switch (_storeStatus)
    {
    case ABtn::BTN1:
    {
      if (_longPressA_StopFunc)
        _longPressA_StopFunc();
      if (_paramLongPressA_StopFunc)
        _paramLongPressA_StopFunc(_longPressA_StopFuncParam);
      break;
    }
    case ABtn::BTN2:
    {
      if (_longPressB_StopFunc)
        _longPressB_StopFunc();
      if (_paramLongPressB_StopFunc)
        _paramLongPressB_StopFunc(_longPressB_StopFuncParam);
      break;
    }
    case ABtn::BTN3:
    {
      if (_longPressC_StopFunc)
        _longPressC_StopFunc();
      if (_paramLongPressC_StopFunc)
        _paramLongPressC_StopFunc(_longPressC_StopFuncParam);
      break;
    }
    case ABtn::BTN4:
    {
      if (_longPressD_StopFunc)
        _longPressD_StopFunc();
      if (_paramLongPressD_StopFunc)
        _paramLongPressD_StopFunc(_longPressD_StopFuncParam);
      break;
    }
    }
    reset();
    break;
  }
  /* ----------------------------------------------------------------------- */
  default:
  {
    // Unknown state detected -> reset state machine.
    _newState(ABtn::OCS_INIT);
    break;
  }
  }
}

/**
 * @brief Advance to a new state and save the last one to come back in cas of bouncing detection.
 */
void ABtn::_newState(stateMachine_t nextState)
{
  _state = nextState;
}

/**
 * @brief Đọc ADC và ánh xạ sang giá trị trạng thái nút nhấn.
 */
void ABtn::checkADC(void)
{
  tempADC = analogRead(_pin);

  if (tempADC >= DEFAULT_BTN_1_MIN && tempADC <= DEFAULT_BTN_1_MAX)
  {
    _status = ABtn::BTN1;
  }
  else if (tempADC >= DEFAULT_BTN_2_MIN && tempADC <= DEFAULT_BTN_2_MAX)
  {
    _status = ABtn::BTN2;
  }
  else if (tempADC >= DEFAULT_BTN_3_MIN && tempADC <= DEFAULT_BTN_3_MAX)
  {
    _status = ABtn::BTN3;
  }
  else if (tempADC >= DEFAULT_BTN_4_MIN && tempADC <= DEFAULT_BTN_4_MAX)
  {
    _status = ABtn::BTN4;
  }
  else
  {
    _status = ABtn::NONE;
  }
}

// End.
