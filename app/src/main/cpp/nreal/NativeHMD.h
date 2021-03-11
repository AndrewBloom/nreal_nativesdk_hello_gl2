//
// Created by Andrea Fiorito on 22/01/2021.
//

#ifndef A6CLOUDXR_NATIVEHMD_H
#define A6CLOUDXR_NATIVEHMD_H

#include "types.h"

extern "C" {
NativeResult NRHMDCreate(uint64_t *out_hmd_handle);
NativeResult NRHMDPause(uint64_t hmd_handle);
NativeResult NRHMDResume(uint64_t hmd_handle);
NativeResult NRHMDGetEyePoseFromHead(uint64_t hmd_handle, int eye, NativeMat4f outEyePoseFromHead);
NativeResult NRHMDGetEyeFov(uint64_t hmd_handle, int eye, NativeFov4f* out_eye_fov);
NativeResult NRHMDGetCameraIntrinsicMatrix(uint64_t hmd_handle, int eye, NativeMat3f out_intrinsic_matrix);
NativeResult NRHMDGetCameraDistortionParams(uint64_t hmd_handle, int eye, NRDistortionParams* out_params);
NativeResult NRHMDGetEyeResolution(uint64_t hmd_handle, int eye, NativeResolution* out_eye_resolution);
NativeResult NRHMDDestroy(uint64_t hmd_handle);
};

class NativeHMD {
    uint64_t ptr = { 0 };
public:
NativeResult Create() { return NRHMDCreate(&ptr); };
NativeResult Pause() { return NRHMDPause(ptr); };
NativeResult Resume() { return NRHMDResume(ptr); };
NativeResult GetEyePoseFromHead(NativeEye eye, NativeMat4f outEyePoseFromHead) { return NRHMDGetEyePoseFromHead(ptr, eye, outEyePoseFromHead); };
NativeResult GetEyeFov(NativeEye eye, NativeFov4f* out_eye_fov) { return NRHMDGetEyeFov(ptr, eye, out_eye_fov); };
NativeResult GetCameraIntrinsicMatrix(NativeEye eye, NativeMat3f out_intrinsic_matrix) { return NRHMDGetCameraIntrinsicMatrix(ptr, eye, out_intrinsic_matrix); };
NativeResult GetCameraDistortionParams(NativeEye eye, NRDistortionParams* out_params) { return NRHMDGetCameraDistortionParams(ptr, eye, out_params); };
NativeResult GetEyeResolution(NativeEye eye, NativeResolution* out_eye_resolution) { return NRHMDGetEyeResolution(ptr, eye, out_eye_resolution); };
NativeResult Destroy() { return NRHMDDestroy(ptr); };
};

#endif //A6CLOUDXR_NATIVEHMD_H
