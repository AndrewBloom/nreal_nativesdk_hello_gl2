//
// Created by Andrea Fiorito on 26/01/2021.
//

#ifndef A6CLOUDXR_NATIVETRACKING_H
#define A6CLOUDXR_NATIVETRACKING_H

#include "types.h"

extern "C" {
NativeResult NRTrackingCreate(uint64_t* out_tracking_handle);
NativeResult NRTrackingInitSetTrackingMode(uint64_t tracking_handle, TrackingMode tracking_mode);
NativeResult NRTrackingStart(uint64_t tracking_handle);
NativeResult NRTrackingSetTrackingMode(uint64_t tracking_handle, TrackingMode tracking_mode);
NativeResult NRTrackingDestroy(uint64_t tracking_handle);
NativeResult NRTrackingPause(uint64_t tracking_handle);
NativeResult NRTrackingResume(uint64_t tracking_handle);
NativeResult NRTrackingRecenter(uint64_t tracking_handle);
NativeResult NRTrackingUpdateTrackables(uint64_t tracking_handle, TrackableType trackable_type, uint64_t out_trackable_list_handle);
};

class NativeTracking {
private:
    uint64_t ptr;
public:
    uint64_t getPtr() { return ptr; }
    NativeResult Create() { return NRTrackingCreate(&ptr); }
    NativeResult InitSetTrackingMode(TrackingMode tracking_mode) { return NRTrackingInitSetTrackingMode(ptr, tracking_mode); }
    NativeResult Start() { return NRTrackingStart(ptr); }
    NativeResult SetTrackingMode(TrackingMode tracking_mode) { return NRTrackingSetTrackingMode(ptr, tracking_mode); }
    NativeResult Destroy() { return NRTrackingDestroy(ptr); }
    NativeResult Pause() { return NRTrackingPause(ptr); }
    NativeResult Resume() { return NRTrackingResume(ptr); }
    NativeResult Recenter() { return NRTrackingRecenter(ptr); }
    NativeResult UpdateTrackables(TrackableType trackable_type, uint64_t out_trackable_list_handle)
    { return NRTrackingUpdateTrackables(ptr, trackable_type, out_trackable_list_handle); }
};

#endif //A6CLOUDXR_NATIVETRACKING_H
