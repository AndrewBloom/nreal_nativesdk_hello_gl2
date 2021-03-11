//
// Created by Andrea Fiorito on 26/01/2021.
//

#ifndef A6CLOUDXR_NATIVEHEADTRACKING_H
#define A6CLOUDXR_NATIVEHEADTRACKING_H

#include "types.h"
#include "../glm.h"
#include <cstring>

extern "C" {
NativeResult NRHeadTrackingCreate(uint64_t tracking_handle, uint64_t* outHeadTrackingHandle);
NativeResult NRTrackingGetHMDTimeNanos(uint64_t tracking_handle, uint64_t* out_hmd_time_nanos);
NativeResult NRHeadTrackingGetRecommendPredictTime( uint64_t tracking_handle, uint64_t head_tracking_handle, uint64_t* out_predict_time_nanos);
NativeResult NRHeadTrackingAcquireTrackingPose(uint64_t sessionHandle, uint64_t head_tracking_handle, uint64_t hmd_time_nanos, uint64_t* out_tracking_pose_handle);
NativeResult NRTrackingPoseGetPose(uint64_t tracking_handle, uint64_t tracking_pose_handle, NativeMat4f out_pose);
NativeResult NRTrackingPoseGetTrackingReason(uint64_t tracking_handle, uint64_t tracking_pose_handle, LostTrackingReason* out_tracking_reason);
NativeResult NRTrackingPoseDestroy(uint64_t tracking_handle, uint64_t tracking_pose_handle);
NativeResult NRHeadTrackingDestroy(uint64_t tracking_handle, uint64_t head_tracking_handle);
};

class NativeHeadTracking {
private:
    uint64_t ptr;
    uint64_t mTrackingHandle;
public:
    NativeResult Create(uint64_t tracking_handle){
        mTrackingHandle = tracking_handle;
        return NRHeadTrackingCreate(tracking_handle, &ptr);
    }
    bool GetHeadPose(NativeMat4f pose, uint64_t timestamp = 0, uint64_t predict = 0)
    {
        if (ptr == 0)
        {
            memcpy((float*)pose, glm::value_ptr(glm::mat4(1.0f)), 16*sizeof(float));
            return false;
        }
        uint64_t headPoseHandle = 0;
        uint64_t hmd_nanos = 0;
        auto result = NRTrackingGetHMDTimeNanos(mTrackingHandle, &hmd_nanos);
        if (result != NativeResult::Success)
        {
            return false;
        }
        if (timestamp != 0)
        {
            hmd_nanos = timestamp;
        }
        else if (predict != 0)
        {
            hmd_nanos += predict;
        }
        else
        {
            uint64_t predict_time = 0;
            NRHeadTrackingGetRecommendPredictTime(mTrackingHandle, ptr, &predict_time);
            hmd_nanos += predict_time;
        }

        auto acquireTrackingPoseResult = NRHeadTrackingAcquireTrackingPose(mTrackingHandle, ptr, hmd_nanos, &headPoseHandle);
        if (acquireTrackingPoseResult != NativeResult::Success)
        {
            return false;
        }

        auto getPoseResult = NRTrackingPoseGetPose(mTrackingHandle, headPoseHandle, pose);

        if (getPoseResult != NativeResult::Success)
        {
            return false;
        }
        NRTrackingPoseDestroy(mTrackingHandle, headPoseHandle);
        return (acquireTrackingPoseResult == NativeResult::Success) && (getPoseResult == NativeResult::Success);
    }

    NativeResult PoseGetTrackingReason(uint64_t tracking_pose_handle, LostTrackingReason* out_tracking_reason) {
        return NRTrackingPoseGetTrackingReason(mTrackingHandle, tracking_pose_handle, out_tracking_reason);
    }
    NativeResult PoseDestroy(uint64_t tracking_pose_handle){ return NRTrackingPoseDestroy(mTrackingHandle, tracking_pose_handle);}
    NativeResult Destroy(){ return NRHeadTrackingDestroy(mTrackingHandle, ptr);}

};

#endif //A6CLOUDXR_NATIVEHEADTRACKING_H
