/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.5
 *
 * cwq: modify SWIG generated file
 * ----------------------------------------------------------------------------- */
package com.cwq.cwqengine;

import android.content.res.AssetManager;

class CwqEngineJNI {
    public final static native long new_CwqEngine();

    public final static native void delete_CwqEngine(long ptr);
    
    public final static native void CwqEngine_setJavaWeakEngine(long ptr,
            CwqEngine jengine, Object jWeakEngine);

    public final static native void CwqEngine_setAssetManager(long ptr,
            CwqEngine jengine, final AssetManager pAssetManager);
    
    public final static native void CwqEngine_postEventToEngine(long ptr,
            CwqEngine jengine, boolean handleOnGLThread, int what, int arg1, int arg2, Object obj);

    public final static native void CwqEngine_onSurfaceCreated(long ptr,
            CwqEngine jengine, int jarg2, int jarg3);

    public final static native void CwqEngine_onSurfaceChanged(long ptr,
            CwqEngine jengine, int jarg2, int jarg3);

    public final static native void CwqEngine_onDrawFrame(long ptr,
            CwqEngine jengine);

    public final static native void CwqEngine_onResume(long ptr,
            CwqEngine jengine);

    public final static native void CwqEngine_onPause(long ptr,
            CwqEngine jengine);
    
    public final static native void CwqEngine_onExit(long ptr,
            CwqEngine jengine);

    public final static native void CwqEngine_onKeyDown(long ptr,
            CwqEngine jengine, int keyCode);

    public final static native void CwqEngine_onTouchesBegin(long ptr,
            CwqEngine jengine, final int pID, final float pX, final float pY);

    public final static native void CwqEngine_onTouchesEnd(long ptr,
            CwqEngine jengine, final int pID, final float pX, final float pY);

    public final static native void CwqEngine_onTouchesMove(long ptr,
            CwqEngine jengine, final int[] pIDs, final float[] pXs, final float[] pYs, final int pNum);

    public final static native void CwqEngine_onTouchesCancel(long ptr,
            CwqEngine jengine, final int[] pIDs, final float[] pXs, final float[] pYs, final int pNum);
}
