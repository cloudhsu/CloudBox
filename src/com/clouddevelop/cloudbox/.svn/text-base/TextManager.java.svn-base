/*
 *  TextManager.java
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2012/1/17.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

package com.clouddevelop.cloudbox;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Paint.FontMetrics;

public class TextManager
{
	public Bitmap create(String text, float size)
    {
        try
        {
        	Paint paint = new Paint();
            paint.setColor(Color.WHITE);
            paint.setTextSize(size);
            paint.setAlpha(255);
            paint.setFlags(Paint.ANTI_ALIAS_FLAG);
            paint.setTextAlign(Paint.Align.LEFT);
            paint.setAntiAlias(true);
            float[] widths = new float[text.length()];;
            paint.getTextWidths(text, widths);
            float width = 0;
            for(int i = 0 ;i < widths.length ; i++)
            	width += widths[i];
            FontMetrics fm = paint.getFontMetrics();
            int mFontHeight = (int) (Math.ceil(fm.descent - fm.top) + 2); 
            Bitmap textImg = Bitmap.createBitmap((int)width, mFontHeight, Bitmap.Config.ARGB_8888);
            Canvas c = new Canvas(textImg);
            if(fm.ascent < 0)
            	c.drawText(text,0,(float)Math.abs(fm.ascent),paint);
            else
            	c.drawText(text,0,fm.ascent* -1,paint);
            
            return textImg;
        }
        catch (Exception e)
        {
        	e.printStackTrace();
        }
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
