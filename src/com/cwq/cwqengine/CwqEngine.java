/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.5
 *
 * cwq: modify SWIG generated file
 * ----------------------------------------------------------------------------- */
package com.cwq.cwqengine;

import android.content.res.AssetManager;

class CwqEngine {
    private long swigCPtr;
    private boolean swigCMemOwn;

    private CwqEngine(long cPtr, boolean cMemoryOwn) {
        swigCMemOwn = cMemoryOwn;
        swigCPtr = cPtr;
    }

    public static long getCPtr(CwqEngine obj) {
        return (obj == null) ? 0 : obj.swigCPtr;
    }

    protected void finalize() {
        //delete();
    }

    public synchronized void delete() {
        if (swigCPtr != 0) {
            if (swigCMemOwn) {
                swigCMemOwn = false;
                CwqEngineJNI.delete_CwqEngine(swigCPtr);
            }
            swigCPtr = 0;
        }
    }

    public CwqEngine() {
        this(CwqEngineJNI.new_CwqEngine(), true);
    }
    
    public void setJavaWeakEngine(Object jWeakEngine) {
        CwqEngineJNI.CwqEngine_setJavaWeakEngine(swigCPtr, this, jWeakEngine);
    }

    public void setAssetManager(final AssetManager pAssetManager) {
        CwqEngineJNI.CwqEngine_setAssetManager(swigCPtr, this, pAssetManager);
    }
    
    public void postEventToEngine(boolean handleOnGLThread, int what, int arg1, int arg2, Object obj) {
        CwqEngineJNI.CwqEngine_postEventToEngine(swigCPtr, this, handleOnGLThread, what, arg1, arg2, obj);
    }

    public void onSurfaceCreated(int width, int height) {
        CwqEngineJNI.CwqEngine_onSurfaceCreated(swigCPtr, this, width, height);
    }

    public void onSurfaceChanged(int width, int height) {
        CwqEngineJNI.CwqEngine_onSurfaceChanged(swigCPtr, this, width, height);
    }

    public void onDrawFrame() {
        CwqEngineJNI.CwqEngine_onDrawFrame(swigCPtr, this);
    }

    public void onResume() {
        CwqEngineJNI.CwqEngine_onResume(swigCPtr, this);
    }

    public void onPause() {
        CwqEngineJNI.CwqEngine_onPause(swigCPtr, this);
    }
    
    public void onExit() {
        CwqEngineJNI.CwqEngine_onExit(swigCPtr, this);
    }

    public void onKeyDown(int keyCode) {
        CwqEngineJNI.CwqEngine_onKeyDown(swigCPtr, this, keyCode);
    }

    public void onTouchesBegin(final int pID, final float pX, final float pY) {
        CwqEngineJNI.CwqEngine_onTouchesBegin(swigCPtr, this, pID, pX, pY);
    }

    public void onTouchesEnd(final int pID, final float pX, final float pY) {
        CwqEngineJNI.CwqEngine_onTouchesEnd(swigCPtr, this, pID, pX, pY);
    }

    public void onTouchesMove(final int[] pIDs, final float[] pXs, final float[] pYs, final int pNum) {
        CwqEngineJNI.CwqEngine_onTouchesMove(swigCPtr, this, pIDs, pXs, pYs, pNum);
    }

    public void onTouchesCancel(final int[] pIDs, final float[] pXs, final float[] pYs, final int pNum) {
        CwqEngineJNI.CwqEngine_onTouchesCancel(swigCPtr, this, pIDs, pXs, pYs, pNum);
    }

}
