#ifndef __ANSIGL_WINDOW_H__
#define __ANSIGL_WINDOW_H__

/*
 * window.h
 *
 * A surface lineage with features designed around containing information and presentation (titles, borders, scrollbars, etc) rather than being "meaningful content".
 */

#include <bitset>

#include "context.h"
#include "image.h"
#include "text.h"


namespace AnsiGL
{
    //
    // These defines are generic enough that they should probably go elsewhere...
    //
    #define MIN( a, b )		((a) < (b) ? (a) : (b))
    #define MAX( a, b )		((a) > (b) ? (a) : (b))


    class Window : public Content
    {
    public:
	typedef boost::shared_ptr< Window >	Ptr;

    protected:
	Surface::Ptr		m_RenderBuf;
	Context::Ptr		m_Layout;

	Text::Ptr		m_Title;
	Text::Ptr		m_StatusText;

	Context::Ptr		m_Contents;

	Image::Ptr		m_Borders;

	Image::Ptr		m_VerticalScrollbar;
	Image::Ptr		m_HorizontalScrollbar;

    public:
	bool			TransparentSpaces;			// True to not render blank spaces (allows the "background" to bleed through in whitespace)

    public:
	Window();
	Window( const astring &windowTitle, const Area2D &windowSize = Area2D(80,24), const Point3D &viewportPos = Point3D(), bool transparentSpaces = false );
	virtual ~Window();

	virtual const astring &Title() const;
	virtual void Title( const astring &title );

	virtual const astring &StatusText() const;
	virtual void StatusText( const astring &text );

	virtual const tSizeType &Width() const;
	virtual void Width( tSizeType width );
	virtual const tSizeType &Height() const;
	virtual void Height( tSizeType height );
	virtual void Resize( const Area2D &size );

	// These functions set the size of the window based on the desired size of content visible, rinstead of total window size
	virtual void SetContentWidth( tSizeType width );
	virtual void SetContentHeight( tSizeType height );
	virtual void SetContentSize( Area2D size );

	virtual const Point3D &CurViewportPos() const;
	virtual void MoveViewportTo( const Point3D &pos );
	virtual void MoveViewportTo( const Point2D &pos );

	virtual void ResizeViewport( const Area2D &size );

	virtual Context::Ptr Contents() const;
	virtual void AddContent( Content::Ptr content, const Point3D &pos = Point3D() );
	virtual void RemoveContent( Content::Ptr content );
	virtual void RemoveContentFrom( tPointType depth, Content::Ptr content );

	virtual void RecalculateTotalContentSize();

	virtual std::string str();
	virtual std::string Render() const;
	virtual void RenderToSurface( Surface::Ptr dest, const Point2D &pos = Point2D() ) const;

    protected:
	void updateWindow();
	void updateWindowBorders();
	void updateScrollbars();
	void updateScrollbarSize();
	void updateScrollbarPosition();
    };
}


#endif // __ANSIGL_WINDOW_H__

