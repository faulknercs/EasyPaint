/*
 * This source file is part of EasyPaint.
 *
 * Copyright (c) 2012 EasyPaint <https://github.com/Gr1N/EasyPaint>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "additionaltools.h"
#include "imagearea.h"

#include <QtGui/QImage>
#include <QtGui/QPainter>
#include <QtGui/QLabel>

AdditionalTools::AdditionalTools(ImageArea *pImageArea, QObject *parent) :
    QObject(parent)
{
    mPImageArea = pImageArea;
}

AdditionalTools::~AdditionalTools()
{

}

void AdditionalTools::resizeArea(int width, int height)
{
    if(width < 5 || height < 5)
        return;
    QImage *tempImage = new QImage(width, height, QImage::Format_ARGB32_Premultiplied);
    QPainter painter(tempImage);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(Qt::white));
    painter.drawRect(QRect(0, 0, width, height));
    painter.drawImage(0, 0, *mPImageArea->getImage());
    painter.end();

    mPImageArea->setImage(*tempImage);

    mPImageArea->resize(mPImageArea->getImage()->rect().right() + 6,
                        mPImageArea->getImage()->rect().bottom() + 6);
    mPImageArea->setEdited(true);
//    mPImageArea->update();
}
