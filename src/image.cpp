/*
 * image.cpp
 *
 * A content-based surface
 */


#include "AnsiGL/image.h"


namespace AnsiGL
{
    Image::Image():
	TransparentSpaces(false)
    {
    }

    Image::Image( const Area2D &size ):
	TransparentSpaces(false)
    {
	Image::Resize( size );
    }

    Image::~Image()
    {
    }

    const Area2D &Image::Size() const
    {
	return Content::m_Size;
    }

    const tSizeType &Image::Width() const
    {
	return Content::m_Size.Width();
    }

    const tSizeType &Image::Height() const
    {
	return Content::m_Size.Height();
    }

    void Image::Width( tSizeType width )
    {
	Content::Width( width );
	Surface::Width( width );
    }

    void Image::Height( tSizeType height )
    {
	Content::Height( height );
	Surface::Height( height );
    }

    void Image::Resize( const Area2D &size )
    {
	Content::Resize( size );
	Surface::Resize( size );
    }

    std::string Image::str()
    {
	return Surface::str();
    }

    std::string Image::Render() const
    {
	return Surface::Render();
    }

    void Image::RenderToSurface( Surface::Ptr dest, const Point2D &pos ) const
    {
	Surface::RenderToSurface( dest, pos + Offset, TransparentSpaces );
    }
}




