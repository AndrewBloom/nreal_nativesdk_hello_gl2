//
// Created by Andrea Fiorito on 25/01/2021.
//

#ifndef A6CLOUDXR_NRDEVICE_H
#define A6CLOUDXR_NRDEVICE_H

#include "types.h"
#include "NativeHMD.h"
#include "NativeGlassesController.h"

extern "C" {
    NativeResult NRSDKInitSetAndroidActivity(jobject android_activity);
};

class NRDevice {
private:
    NativeHMD mNativeHMD;
    NativeGlassesController mNativeGlassController;
public:
    void Create(jobject app_pointer) {
        NRSDKInitSetAndroidActivity(app_pointer);
        mNativeGlassController.Create();
        mNativeGlassController.Start();
        mNativeHMD.Create();
    }
    void Destroy() {
        mNativeGlassController.Stop();
        mNativeGlassController.Destroy();
        mNativeHMD.Destroy();
    }
    void Pause() {
        mNativeGlassController.Pause();
        mNativeHMD.Pause();
    }
    void Resume() {
        mNativeGlassController.Resume();
        mNativeHMD.Resume();
    }
};

#endif //A6CLOUDXR_NRDEVICE_H
