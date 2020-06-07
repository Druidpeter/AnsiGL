/*
 * pixel.cpp
 *
 * Defines "Pixels" for use in a achar-based "Screen"
 */


#include <sstream>

#include "AnsiGL/pixel.h"


namespace AnsiGL
{

    //! Checks if the pixel has any ANSI attributes loaded into it
    //! that can be found in the enumerated list of ANSICodes given to
    //! it.
    //! @param[in] attrib The list of ANSI Codes to check against, as an enumeration.
    //! @return A boolean value. True if the pixel has any matched attributes, false if none.
    
    bool Pixel::HasAttribute( ENUM_ANSICodes attrib ) const
    {
        return _Attributes.Has( attrib );
    }

    //! Adds an ansi code attribute to the pixel, disallowing
    //! foreground and background colors.
    //! @param[in] attrib The ANSI code to add.
     
    void Pixel::AddAttribute( ENUM_ANSICodes attrib )
    {
        // Don't allow foreground colors
        if ( attrib >= ANSI_FG_Black && attrib <= ANSI_FG_Default )
            return;

        // And don't allow background colors either
        if ( attrib >= ANSI_BG_Black && attrib <= ANSI_BG_Default )
            return;

        _Attributes.Add( attrib );
    }

    //! Adds a list of ANSI attributes to the pixel, disallowing
    //! foreground and background colors.
    //! @param attributes The list of attributes to add.
    
    void Pixel::AddAttributes( ANSICodeList attributes )
    {
        _Attributes.Add( attributes );
    }

    //! Removes an ANSI attribute from the pixel.
    //! @param attrib The ANSI attribute to remove.
    
    void Pixel::RemoveAttribute( ENUM_ANSICodes attrib )
    {
        _Attributes.Remove( attrib );
    }

    //! Removes all attributes from the pixel and reset its
    //! state.
    
    void Pixel::Clear()
    {
        uchar::Clear();
        _Attributes.clear();
        PaletteIndex = 0;
        Bell = false;
    }

    //! Removes all attributes from the pixel, but does not reset its
    //! state.
    
    void Pixel::ClearAttributes()
    {
        _Attributes.clear();
    }
}


// vim: tabstop=4 shiftwidth=4
// astyle: --indent=tab=4 --style=ansi --indent-namespaces --indent-cases --indent-switches --pad-oper


