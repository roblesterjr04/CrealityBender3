/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2023 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

/**
 * lcd/extui/anycubic_vyper/vyper_extui.cpp
 *
 * Anycubic Dgus TFT support for Marlin
 */

#include "../../../inc/MarlinConfigPre.h"

#if ENABLED(ANYCUBIC_LCD_VYPER)

#include "../ui_api.h"
#include "dgus_tft.h"

using namespace Anycubic;

namespace ExtUI {

<<<<<<< HEAD
  void onStartup() { Dgus.Startup(); }

  void onIdle() { Dgus.IdleLoop(); }

  void onPrinterKilled(FSTR_P const error, FSTR_P const component) {
    Dgus.PrinterKilled(error, component);
  }

  void onMediaInserted() { Dgus.MediaEvent(AC_media_inserted); }
  void onMediaError()    { Dgus.MediaEvent(AC_media_error);    }
  void onMediaRemoved()  { Dgus.MediaEvent(AC_media_removed);  }
=======
  void onStartup() { dgus.startup(); }

  void onIdle() { dgus.idleLoop(); }

  void onPrinterKilled(FSTR_P const error, FSTR_P const component) {
    dgus.printerKilled(error, component);
  }

  void onMediaInserted() { dgus.mediaEvent(AC_media_inserted); }
  void onMediaError()    { dgus.mediaEvent(AC_media_error);    }
  void onMediaRemoved()  { dgus.mediaEvent(AC_media_removed);  }
>>>>>>> bugfix-2.1.x

  void onPlayTone(const uint16_t frequency, const uint16_t duration) {
    #if ENABLED(SPEAKER)
      ::tone(BEEPER_PIN, frequency, duration);
    #endif
  }

<<<<<<< HEAD
  void onPrintTimerStarted() { Dgus.TimerEvent(AC_timer_started); }
  void onPrintTimerPaused()  { Dgus.TimerEvent(AC_timer_paused);  }
  void onPrintTimerStopped() { Dgus.TimerEvent(AC_timer_stopped); }
  void onPrintDone() {}

  void onFilamentRunout(const extruder_t)            { Dgus.FilamentRunout();             }

  void onUserConfirmRequired(const char * const msg) { Dgus.ConfirmationRequest(msg);     }
  void onStatusChanged(const char * const msg)       { Dgus.StatusChange(msg);            }

  void onHomingStart()    { Dgus.HomingStart(); }
  void onHomingDone()     { Dgus.HomingComplete(); }

  void onFactoryReset() {
    Dgus.page_index_now = 121;
    Dgus.lcd_info.audio_on = DISABLED(SPEAKER);
=======
  void onPrintTimerStarted() { dgus.timerEvent(AC_timer_started); }
  void onPrintTimerPaused()  { dgus.timerEvent(AC_timer_paused);  }
  void onPrintTimerStopped() { dgus.timerEvent(AC_timer_stopped); }
  void onPrintDone() {}

  void onFilamentRunout(const extruder_t)            { dgus.filamentRunout();         }

  void onUserConfirmRequired(const char * const msg) { dgus.confirmationRequest(msg); }
  void onStatusChanged(const char * const msg)       { dgus.statusChange(msg);        }

  void onHomingStart()    { dgus.homingStart(); }
  void onHomingDone()     { dgus.homingComplete(); }

  void onFactoryReset() {
    dgus.page_index_now = 121;
    dgus.lcd_info.audio_on = DISABLED(SPEAKER);
>>>>>>> bugfix-2.1.x
  }

  void onStoreSettings(char *buff) {
    // Called when saving to EEPROM (i.e. M500). If the ExtUI needs
    // permanent data to be stored, it can write up to eeprom_data_size bytes
    // into buff.

<<<<<<< HEAD
    static_assert(sizeof(Dgus.lcd_info) <= ExtUI::eeprom_data_size);
    memcpy(buff, &Dgus.lcd_info, sizeof(Dgus.lcd_info));
=======
    static_assert(sizeof(dgus.lcd_info) <= ExtUI::eeprom_data_size);
    memcpy(buff, &dgus.lcd_info, sizeof(dgus.lcd_info));
>>>>>>> bugfix-2.1.x
  }

  void onLoadSettings(const char *buff) {
    // Called while loading settings from EEPROM. If the ExtUI
    // needs to retrieve data, it should copy up to eeprom_data_size bytes
    // from buff

<<<<<<< HEAD
    static_assert(sizeof(Dgus.lcd_info) <= ExtUI::eeprom_data_size);
    memcpy(&Dgus.lcd_info, buff, sizeof(Dgus.lcd_info));
    memcpy(&Dgus.lcd_info_back, buff, sizeof(Dgus.lcd_info_back));
=======
    static_assert(sizeof(dgus.lcd_info) <= ExtUI::eeprom_data_size);
    memcpy(&dgus.lcd_info, buff, sizeof(dgus.lcd_info));
    memcpy(&dgus.lcd_info_back, buff, sizeof(dgus.lcd_info_back));
>>>>>>> bugfix-2.1.x
  }

  void onPostprocessSettings() {
    // Called after loading or resetting stored settings
<<<<<<< HEAD
    Dgus.ParamInit();
    Dgus.PowerLoss();
=======
    dgus.paramInit();
    dgus.powerLoss();
>>>>>>> bugfix-2.1.x
  }

  void onSettingsStored(const bool success) {
    // Called after the entire EEPROM has been written,
    // whether successful or not.
  }

  void onSettingsLoaded(const bool success) {
    // Called after the entire EEPROM has been read,
    // whether successful or not.
  }

<<<<<<< HEAD
  #if HAS_MESH
    void onLevelingStart() {}
    void onLevelingDone() {}

=======
  #if HAS_LEVELING
    void onLevelingStart() {}
    void onLevelingDone() {}
  #endif

  #if HAS_MESH
>>>>>>> bugfix-2.1.x
    void onMeshUpdate(const int8_t xpos, const int8_t ypos, const_float_t zval) {
      // Called when any mesh points are updated
      //SERIAL_ECHOLNPGM("onMeshUpdate() x:", xpos, " y:", ypos, " z:", zval);
    }

    void onMeshUpdate(const int8_t xpos, const int8_t ypos, const probe_state_t state) {
      // Called to indicate a special condition
      //SERIAL_ECHOLNPGM("onMeshUpdate() x:", xpos, " y:", ypos, " state:", state);
    }
  #endif

  #if ENABLED(POWER_LOSS_RECOVERY)
    // Called when power-loss is enabled/disabled
<<<<<<< HEAD
    void onSetPowerLoss(const bool) { Dgus.PowerLoss(); }
    // Called when power-loss state is detected
    void onPowerLoss() { /* handled internally */ }
    // Called on resume from power-loss
    void onPowerLossResume() { Dgus.PowerLossRecovery(); }
=======
    void onSetPowerLoss(const bool) { dgus.powerLoss(); }
    // Called when power-loss state is detected
    void onPowerLoss() { /* handled internally */ }
    // Called on resume from power-loss
    void onPowerLossResume() { dgus.powerLossRecovery(); }
>>>>>>> bugfix-2.1.x
  #endif

  #if HAS_PID_HEATING
    void onPidTuning(const result_t rst) {
      // Called for temperature PID tuning result
      switch (rst) {
        case PID_STARTED:        break;
        case PID_BAD_HEATER_ID:  break;
        case PID_TEMP_TOO_HIGH:  break;
        case PID_TUNING_TIMEOUT: break;
        case PID_DONE:           break;
      }
    }
  #endif

  void onSteppersDisabled() {}
  void onSteppersEnabled()  {}
}

#endif // ANYCUBIC_LCD_VYPER
