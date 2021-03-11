//
// Created by Andrea Fiorito on 26/01/2021.
//

#ifndef A6CLOUDXR_NREALMANAGER_H
#define A6CLOUDXR_NREALMANAGER_H

#include "types.h"
#include "NRDevice.h"
#include "NativeTracking.h"
#include "NativeHeadTracking.h"
#include "NativeRendering.h"

class NRealManager {
public:
    NRDevice device;
    NativeTracking tracking;
    NativeHeadTracking headTracking;
    NativeRendering rendering;
public:
    void onCreate(jobject appPtr) {
        device.Create(appPtr);
        tracking.Create();
        headTracking.Create(tracking.getPtr());
        rendering.Create();
        rendering.Start();
    }

    void onResume() {
        device.Resume();
        tracking.Resume();
        rendering.Resume();
    }

    void onPause() {
        device.Pause();
        tracking.Pause();
        rendering.Pause();
    }

    void onDestroy() {
        device.Destroy();
        tracking.Destroy();
        headTracking.Destroy();
        rendering.Destroy();
    }

    bool getPose(float *pose, uint64_t predict = 0) {
        return headTracking.GetHeadPose(pose, 0, predict);
    }
};

#endif //A6CLOUDXR_NREALMANAGER_H
