/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtGui module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain
** additional rights. These rights are described in the Nokia Qt LGPL
** Exception version 1.0, included in the file LGPL_EXCEPTION.txt in this
** package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at http://www.qtsoftware.com/contact.
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QBMPHANDLER_P_H
#define QBMPHANDLER_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include "QtGui/qimageiohandler.h"

#ifndef QT_NO_IMAGEFORMAT_BMP

QT_BEGIN_NAMESPACE

struct BMP_FILEHDR {                     // BMP file header
    char   bfType[2];                    // "BM"
    qint32  bfSize;                      // size of file
    qint16  bfReserved1;
    qint16  bfReserved2;
    qint32  bfOffBits;                   // pointer to the pixmap bits
};

struct BMP_INFOHDR {                     // BMP information header
    qint32  biSize;                      // size of this struct
    qint32  biWidth;                     // pixmap width
    qint32  biHeight;                    // pixmap height
    qint16  biPlanes;                    // should be 1
    qint16  biBitCount;                  // number of bits per pixel
    qint32  biCompression;               // compression method
    qint32  biSizeImage;                 // size of image
    qint32  biXPelsPerMeter;             // horizontal resolution
    qint32  biYPelsPerMeter;             // vertical resolution
    qint32  biClrUsed;                   // number of colors used
    qint32  biClrImportant;              // number of important colors
};

class QBmpHandler : public QImageIOHandler
{
public:
    QBmpHandler();
    bool canRead() const;
    bool read(QImage *image);
    bool write(const QImage &image);

    QByteArray name() const;

    static bool canRead(QIODevice *device);

    QVariant option(ImageOption option) const;
    void setOption(ImageOption option, const QVariant &value);
    bool supportsOption(ImageOption option) const;

private:
    bool readHeader();
    enum State {
        Ready,
        ReadHeader,
        Error
    };
    State state;
    BMP_FILEHDR fileHeader;
    BMP_INFOHDR infoHeader;
    int startpos;
};

QT_END_NAMESPACE

#endif // QT_NO_IMAGEFORMAT_BMP

#endif // QBMPHANDLER_P_H
