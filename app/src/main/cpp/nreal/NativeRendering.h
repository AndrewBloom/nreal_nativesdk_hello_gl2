//
// Created by Andrea Fiorito on 10/03/2021.
//

#ifndef A6CLOUDXR_NATIVERENDERING_H
#define A6CLOUDXR_NATIVERENDERING_H

#include "types.h"

extern "C" {
NativeResult NRRenderingCreate(uint64_t* out_rendering_handle);
NativeResult NRRenderingInitSetTextureColorSpace(uint64_t rendering_handle, NativeColorSpace color_space);
NativeResult NRRenderingStart(uint64_t rendering_handle);
NativeResult NRRenderingDestroy(uint64_t rendering_handle);
NativeResult NRRenderingPause(uint64_t rendering_handle);
NativeResult NRRenderingResume(uint64_t rendering_handle);
NativeResult NRRenderingInitSetAndroidSurface(
        uint64_t rendering_handle, int* android_surface);
NativeResult NRRenderingDoRender(uint64_t rendering_handle,
                                                      GLuint left_eye_texture, GLuint right_eye_texture, NativeMat4f head_pose);
};

class NativeRendering {
    uint64_t ptr = { 0 };
    //FrameInfo frameInfo;
public:
    NativeResult Create() { return NRRenderingCreate(&ptr); };
    NativeResult Pause() { return NRRenderingPause(ptr); };
    NativeResult Resume() { return NRRenderingResume(ptr); };
    NativeResult Destroy() { return NRRenderingDestroy(ptr); };
    NativeResult Start() { return NRRenderingStart(ptr); };
    NativeResult initSetTextureColorSpace(NativeColorSpace colorSpace) { return NRRenderingInitSetTextureColorSpace(ptr, colorSpace); };
    NativeResult initSetAndroidSurface(int* surface) { return NRRenderingInitSetAndroidSurface(ptr, surface); };
    NativeResult doRender(GLuint left_eye_texture, GLuint right_eye_texture, NativeMat4f head_pose) {
        return NRRenderingDoRender(ptr, left_eye_texture, right_eye_texture, head_pose);
    };
};
#endif //A6CLOUDXR_NATIVERENDERING_H
