/*************************************************************************
 * Copyright (C) 2014 by Hugo Pereira Da Costa <hugo.pereira@free.fr>    *
 *                                                                       *
 * This program is free software; you can redistribute it and/or modify  *
 * it under the terms of the GNU General Public License as published by  *
 * the Free Software Foundation; either version 2 of the License, or     *
 * (at your option) any later version.                                   *
 *                                                                       *
 * This program is distributed in the hope that it will be useful,       *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 * GNU General Public License for more details.                          *
 *                                                                       *
 * You should have received a copy of the GNU General Public License     *
 * along with this program; if not, write to the                         *
 * Free Software Foundation, Inc.,                                       *
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 *************************************************************************/


#include "hellosizegrip.h"

#include <KDecoration3/DecoratedWindow>

#include <QPainter>
#include <QPolygon>
#include <QTimer>

namespace Hello
{

    //* scoped pointer convenience typedef
    template <typename T> using ScopedPointer = QScopedPointer<T, QScopedPointerPodDeleter>;

    //_____________________________________________
    SizeGrip::SizeGrip( Decoration* decoration ):QWidget(nullptr)
        ,m_decoration( decoration )
    {

        setAttribute(Qt::WA_NoSystemBackground );
        setAutoFillBackground( false );

        // cursor
        setCursor( Qt::SizeFDiagCursor );

        // size
        setFixedSize( QSize( GripSize, GripSize ) );

        // mask
        setMask( QRegion( QVector<QPoint>{
            QPoint( 0, GripSize ),
            QPoint( GripSize, 0 ),
            QPoint( GripSize, GripSize ),
            QPoint( 0, GripSize )} ) );



        // connections
        auto w = decoration->window();
        connect( w, &KDecoration3::DecoratedWindow::activeChanged, this, &SizeGrip::updateActiveState );

        // show
        show();

    }

    //_____________________________________________
    SizeGrip::~SizeGrip()
    {}

    //_____________________________________________
    void SizeGrip::updateActiveState()
    {
        update();
    }

    //_____________________________________________
    void SizeGrip::paintEvent( QPaintEvent* )
    {

        if( !m_decoration ) return;

        // get relevant colors
        const QColor backgroundColor( m_decoration.data()->titleBarColor() );

        // create and configure painter
        QPainter painter(this);
        painter.setRenderHints(QPainter::Antialiasing );

        painter.setPen( Qt::NoPen );
        painter.setBrush( backgroundColor );

        // polygon
        painter.drawPolygon( QVector<QPoint> {
            QPoint( 0, GripSize ),
            QPoint( GripSize, 0 ),
            QPoint( GripSize, GripSize ),
            QPoint( 0, GripSize )} );
    }

    //_____________________________________________
    void SizeGrip::mousePressEvent( QMouseEvent* event )
    {

        switch (event->button())
        {

            case Qt::RightButton:
            {
                hide();
                QTimer::singleShot(5000, this, SLOT(show()));
                break;
            }

            case Qt::MiddleButton:
            {
                hide();
                break;
            }

            case Qt::LeftButton:
            break;

            default: break;

        }

        
    }

}
