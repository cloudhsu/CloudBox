/*
 *  PngManager.java
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2012/1/17.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

package com.clouddevelop.cloudbox;
import android.content.res.AssetManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;

public class PngManager
{
    private AssetManager mAssetManager;

    public Bitmap open(String path)
    {
        try
        {
            return BitmapFactory.decodeStream(mAssetManager.open(path));
        }
        catch (Exception e) { }
        return null;
    }

    public int getWidth(Bitmap bmp) { return bmp.getWidth(); }
    public int getHeight(Bitmap bmp) { return bmp.getHeight(); }

    public void getPixels(Bitmap bmp, int[] pixels)
    {
        int w = bmp.getWidth();
        int h = bmp.getHeight();
        bmp.getPixels(pixels, 0, w, 0, 0, w, h);
    }

    public void close(Bitmap bmp)
    {
        bmp.recycle();
    }
}
