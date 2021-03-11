//
// Created by Andrea Fiorito on 25/01/2021.
//

#ifndef A6CLOUDXR_NATIVEGLASSESCONTROLLER_H
#define A6CLOUDXR_NATIVEGLASSESCONTROLLER_H

#include "types.h"

extern "C" {
/// <summary>
/// Create the GlassesControl object.
/// </summary>
/// <param name="out_glasses_control_handle">The handle of GlassesControl.</param>
/// <returns>The result of operation.</returns>
NativeResult NRGlassesControlCreate(uint64_t* out_glasses_control_handle);

/// <summary>
/// Start the GlassesControl system.
/// </summary>
/// <param name="glasses_control_handle">The handle of GlassesControl.</param>
/// <returns>The result of operation.</returns>
NativeResult NRGlassesControlStart(uint64_t glasses_control_handle);

/// <summary>
/// Pause the GlassesControl system.
/// </summary>
/// <param name="glasses_control_handle">The handle of GlassesControl.</param>
/// <returns>The result of operation.</returns>
NativeResult NRGlassesControlPause(uint64_t glasses_control_handle);

/// <summary>
/// Resume the GlassesControl system.
/// </summary>
/// <param name="glasses_control_handle">The handle of GlassesControl.</param>
/// <returns>The result of operation.</returns>
NativeResult NRGlassesControlResume(uint64_t glasses_control_handle);

/// <summary>
/// Stop the GlassesControl system.
/// </summary>
/// <param name="glasses_control_handle">The handle of GlassesControl.</param>
/// <returns>The result of operation.</returns>
NativeResult NRGlassesControlStop(uint64_t glasses_control_handle);

/// <summary>
/// Release memory used by the GlassesControl.
/// </summary>
/// <param name="glasses_control_handle">The handle of GlassesControl.</param>
/// <returns>The result of operation.</returns>
NativeResult NRGlassesControlDestroy(uint64_t glasses_control_handle);

NativeResult NRGlassesControlGetTemperatureLevel(uint64_t glasses_control_handle, GlassesTemperatureLevel* temperature_level);

/// <summary>
/// Set the callback method when put on or take off glasses.
/// </summary>
/// <param name="glasses_control_handle">The handle of GlassesControl.</param>
/// <param name="data_callback">The callback method.</param>
/// <param name="user_data">The data which will be returned when callback is triggered.</param>
/// <returns>The result of operation.</returns>
NativeResult NRGlassesControlSetGlassesWearingCallback(
        uint64_t glasses_control_handle, NRGlassesControlWearCallback data_callback, uint64_t user_data);

NativeResult NRGlassesControlSetNotifyQuitAppCallback(uint64_t glasses_control_handle,
                                                                           NRGlassesControlNotifyQuitAppCallback callback, uint64_t user_data);

/// <summary>
/// Set the callback method when plug off the glasses.
/// </summary>
/// <param name="glasses_control_handle">The handle of GlassesControl.</param>
/// <param name="data_callback">The callback method.</param>
/// <param name="user_data">The data which will be returned when callback is triggered.</param>
/// <returns>The result of operation.</returns>
NativeResult NRGlassesControlSetGlassesDisconnectedCallback(
        uint64_t glasses_control_handle, NRGlassesControlPlugOffCallback data_callback, uint64_t user_data);

};

class NativeGlassesController {
    uint64_t ptr = {0};
public:
    NativeResult Create() { return NRGlassesControlCreate(&ptr); }
    NativeResult Start() { return NRGlassesControlStart(ptr); }
    NativeResult Pause() { return NRGlassesControlPause(ptr); }
    NativeResult Resume() { return NRGlassesControlResume(ptr); }
    NativeResult Stop() { return NRGlassesControlStop(ptr); }
    NativeResult Destroy() { return NRGlassesControlDestroy(ptr); }

    NativeResult GetTemperatureLevel(GlassesTemperatureLevel* temperature_level) {
        return NRGlassesControlGetTemperatureLevel(ptr, temperature_level);
    }

    NativeResult SetGlassesWearingCallback(NRGlassesControlWearCallback data_callback, uint64_t user_data) {
        return NRGlassesControlSetGlassesWearingCallback(ptr, data_callback, user_data);
    }

    NativeResult SetNotifyQuitAppCallback(NRGlassesControlNotifyQuitAppCallback callback, uint64_t user_data) {
        return NRGlassesControlSetNotifyQuitAppCallback(ptr, callback, user_data);
    }

    NativeResult SetGlassesDisconnectedCallback(NRGlassesControlPlugOffCallback data_callback, uint64_t user_data) {
        return NRGlassesControlSetGlassesDisconnectedCallback(ptr, data_callback, user_data);
    }
};

#endif //A6CLOUDXR_NATIVEGLASSESCONTROLLER_H
