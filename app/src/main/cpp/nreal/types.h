//
// Created by Andrea Fiorito on 22/01/2021.
//

#ifndef A6CLOUDXR_TYPES_H
#define A6CLOUDXR_TYPES_H

#include <cstdint>

enum NativeResult
{
    Success = 0,
    Failure = 1,
    InvalidArgument = 2,
    NotEnoughMemory = 3,
    UnSupported = 4,
    GlassesDisconnect = 5,
    SdkVersionMismatch = 6,
    SdcardPermissionDeny = 7,
    RGBCameraDeviceNotFind = 8,
    DPDeviceNotFind = 9,
    TrackingNotRunning = 10,
    GetDisplayFailure = 11,
    GetDisplayModeMismatch = 12,
};
typedef float* NativeMat4f;
typedef float* NativeMat3f;

struct NativeFov4f{
    /// The tangent of the angle between the viewing vector and the left edge of the field of view. The value is positive.
float left_tan;
    /// The tangent of the angle between the viewing vector and the right edge of the field of view. The value is positive.
float right_tan;
    /// The tangent of the angle between the viewing vector and the top edge of the field of view. The value is positive.
float top_tan;
    /// The tangent of the angle between the viewing vector and the bottom edge of the field of view. The value is positive.
float bottom_tan;
};

enum NRCameraModel
{
    NR_CAMERA_MODEL_RADIAL = 1,
    NR_CAMERA_MODEL_FISHEYE = 2,
};

enum NativeEye
{
    LEFT = 0,
    RIGHT = 1,
    RGB = 2,
};

/**
 * if camera_model == NR_CAMERA_MODEL_RADIAL,the first 4 value of distortParams is:
 * radial_k1、radial_k2、radial_r1、radial_r2.
 * else if camera_model == NR_CAMERA_MODEL_FISHEYE:
 * fisheye_k1、fisheye_k2、fisheye_k3、fisheye_k4.
 */
struct NRDistortionParams
{
NRCameraModel cameraModel;
float distortParams1;
float distortParams2;
float distortParams3;
float distortParams4;
float distortParams5;
float distortParams6;
float distortParams7;
};

class NativeResolution
{
int width;
int height;

NativeResolution(int w, int h)
    {
        width = w;
        height = h;
    }
};

enum GlassesTemperatureLevel
{
    TEMPERATURE_LEVEL_NORMAL = 0,
    TEMPERATURE_LEVEL_WARM,
    TEMPERATURE_LEVEL_HOT,
};

enum GlassesDisconnectReason
{
    GLASSES_DEVICE_DISCONNECT = 1,
    NOTIFY_TO_QUIT_APP = 2,
};

typedef void(*NRGlassesControlWearCallback) (uint64_t glasses_control_handle, int wearing_status, uint64_t user_data);
typedef void (*NRGlassesControlPlugOffCallback) (uint64_t glasses_control_handle, uint64_t user_data);
typedef void (*NRGlassesControlNotifyQuitAppCallback) (uint64_t glasses_control_handle, uint64_t* user_data, GlassesDisconnectReason reason);

enum TrackableType
{
    TRACKABLE_BASE = 0,
    TRACKABLE_PLANE = 1,
    TRACKABLE_IMAGE = 2,
};

enum TrackableImageFindingMode
{
    DISABLE = 0,
    ENABLE = 1,
};

enum TrackingState
{
    Tracking = 0,
    Paused = 1,
    Stopped = 2
};

enum TrackingMode
{
    MODE_6DOF = 0,
    MODE_3DOF = 1,
    MODE_0DOF = 2,
};

enum LostTrackingReason
{
    NONE = 0,
    INITIALIZING = 1,
    EXCESSIVE_MOTION = 2,
    INSUFFICIENT_FEATURES = 3,
    RELOCALIZING = 4,
    ENTER_VRMODE = 5,
};

struct FrameInfo
{
int* leftTex;
int* rightTex;
NativeMat4f pose;
FrameInfo(int* left, int* right, NativeMat4f p) : leftTex(left), rightTex(right), pose(p) { };
};

enum NativeColorSpace
{
    COLOR_SPACE_LINEAR = 0,
    COLOR_SPACE_GAMMA = 1
};

#endif //A6CLOUDXR_TYPES_H
